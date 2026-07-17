<#
.SYNOPSIS
    Continuous "live view" screenshot loop for visually verifying dev/test work on this
    project. Not a real video feed - Claude has no such tool - but it re-captures the
    target window every IntervalMs and overwrites one fixed file, so whatever Claude reads
    from that path is always a near-current frame of what the user sees on screen.

.DESCRIPTION
    Standing test-verification helper. Start this BEFORE testing a build (Client GUI,
    server console, etc.), let it run in the background while interacting with the app,
    then read the output PNG whenever a "current state" check is needed. Stop it (Ctrl+C,
    or kill the process / background task) when done testing.

.PARAMETER ProcessName
    Process name to find (e.g. "Client", "GameServer"). Default: Client

.PARAMETER OutFile
    Fixed path that gets overwritten every cycle. Default:
    .claude\tools\screenshots\live_<ProcessName>.png

.PARAMETER IntervalMs
    Milliseconds between captures. Default: 1000 (1/sec). Don't go far below ~500ms -
    GDI+ screen capture + PNG encode has real cost, and this loop should stay cheap
    enough to run for the whole testing session.

.PARAMETER DurationSec
    Optional auto-stop after N seconds (0 = run until killed). Default: 0

.EXAMPLE
    # Start a live view of the Client window, refreshing once a second, until stopped
    .\live-capture.ps1

.EXAMPLE
    # Live view a server console for 5 minutes then auto-stop
    .\live-capture.ps1 -ProcessName GameServer -DurationSec 300
#>
param(
    [string]$ProcessName = "Client",
    [string]$OutFile = "",
    [int]$IntervalMs = 1000,
    [int]$DurationSec = 0
)

Add-Type @"
using System;
using System.Runtime.InteropServices;
public class LiveCapture {
    [DllImport("user32.dll")]
    public static extern bool GetWindowRect(IntPtr hWnd, out RECT lpRect);
    public struct RECT { public int Left; public int Top; public int Right; public int Bottom; }
}
"@
Add-Type -AssemblyName System.Drawing

if ([string]::IsNullOrEmpty($OutFile)) {
    $shotDir = Join-Path $PSScriptRoot "screenshots"
    New-Item -ItemType Directory -Force -Path $shotDir | Out-Null
    $OutFile = Join-Path $shotDir "live_${ProcessName}.png"
}
$tmpFile = "$OutFile.tmp"

Write-Output "Live capture starting: process='$ProcessName' -> '$OutFile' every ${IntervalMs}ms"
Write-Output "(Ctrl+C to stop, or stop the background task this was launched from)"

$startTime = Get-Date
$frameCount = 0

while ($true) {
    if ($DurationSec -gt 0 -and ((Get-Date) - $startTime).TotalSeconds -ge $DurationSec) {
        Write-Output "Duration limit reached ($DurationSec s) - stopping. Frames captured: $frameCount"
        break
    }

    $proc = Get-Process -Name $ProcessName -ErrorAction SilentlyContinue | Select-Object -First 1
    if (-not $proc -or $proc.MainWindowHandle -eq [IntPtr]::Zero) {
        Start-Sleep -Milliseconds $IntervalMs
        continue
    }

    $rect = New-Object LiveCapture+RECT
    [LiveCapture]::GetWindowRect($proc.MainWindowHandle, [ref]$rect) | Out-Null
    $width = $rect.Right - $rect.Left
    $height = $rect.Bottom - $rect.Top

    if ($width -gt 0 -and $height -gt 0) {
        try {
            $bmp = New-Object System.Drawing.Bitmap $width, $height
            $graphics = [System.Drawing.Graphics]::FromImage($bmp)
            $graphics.CopyFromScreen($rect.Left, $rect.Top, 0, 0, $bmp.Size)
            # write to a temp file then rename, so a reader never sees a half-written PNG
            $bmp.Save($tmpFile, [System.Drawing.Imaging.ImageFormat]::Png)
            $graphics.Dispose()
            $bmp.Dispose()
            Move-Item -Force -Path $tmpFile -Destination $OutFile
            $frameCount++
        } catch {
            # window resized/closed mid-capture etc. - just skip this frame
        }
    }

    Start-Sleep -Milliseconds $IntervalMs
}
