# Run in PowerShell as Administrator.
# Adds the missing "C++ MFC for v142 build tools" component to the existing
# Visual Studio 2019 Community install (required to compile DboClient's
# resource file, which includes afxres.h).

$ErrorActionPreference = "Stop"

$installer = "$env:TEMP\vs_community.exe"
if (-not (Test-Path $installer)) {
    Write-Host "Downloading VS2019 Community bootstrapper..."
    Invoke-WebRequest -Uri "https://aka.ms/vs/16/release/vs_community.exe" -OutFile $installer
}

$installPath = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community"
Write-Host "Modifying VS2019 install to add MFC/ATL for v142..."
$installArgs = @(
    "modify",
    "--installPath", "`"$installPath`"",
    "--quiet", "--wait", "--norestart",
    "--add", "Microsoft.VisualStudio.Component.VC.ATLMFC"
)
$proc = Start-Process -FilePath $installer -ArgumentList $installArgs -Wait -PassThru
Write-Host "Modify finished. ExitCode: $($proc.ExitCode)"
