# Run in PowerShell as Administrator.
# Installs just the "Debugging Tools for Windows" (cdb.exe/windbg) feature
# from the Windows 10 SDK, needed to analyze .dmp crash dumps.

$ErrorActionPreference = "Stop"
$installer = "C:\Users\P425\AppData\Local\Temp\claude\c--Users-P425-Documents-OpenDBO-Core\a478433e-9f94-478a-b781-f24d5e1bc757\scratchpad\winsdksetup.exe"

Write-Host "Installing Debugging Tools for Windows (silent)..."
$proc = Start-Process -FilePath $installer -ArgumentList @(
    "/features", "OptionId.WindowsDesktopDebuggers",
    "/quiet", "/norestart"
) -Wait -PassThru
Write-Host "Install finished. ExitCode: $($proc.ExitCode)"
