# Run in PowerShell as Administrator.
# Downloads and silently installs XAMPP 8.2.12 (Apache + MariaDB + PHP + phpMyAdmin)
# as required by OpenDBO-Core's README "Setting up the Server" section.

$ErrorActionPreference = "Stop"

$installer = "C:\Users\P425\AppData\Local\Temp\xampp_test2.exe"
if (-not (Test-Path $installer)) {
    Write-Host "Pre-downloaded installer not found at $installer - aborting."
    exit 1
}
$size = (Get-Item $installer).Length
if ($size -lt 50MB) {
    Write-Host "Installer file looks too small ($([math]::Round($size/1MB,2)) MB) - aborting."
    exit 1
}
Write-Host "Using pre-downloaded installer: $([math]::Round($size/1MB,1)) MB"

Write-Host "Installing XAMPP (silent)..."
$proc = Start-Process -FilePath $installer -ArgumentList @(
    "--mode", "unattended",
    "--unattendedmodeui", "minimal"
) -Wait -PassThru
Write-Host "Install finished. ExitCode: $($proc.ExitCode)"
