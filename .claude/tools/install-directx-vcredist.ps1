# Run in PowerShell as Administrator.
# Installs DirectX9 SDK (June 2010) and VC++ Redistributable x64,
# both required by OpenDBO-Core's Client build.

$ErrorActionPreference = "Stop"
$base = "C:\Users\P425\AppData\Local\Temp\claude\c--Users-P425-Documents-OpenDBO-Core\a478433e-9f94-478a-b781-f24d5e1bc757\scratchpad\3rdparty"

Write-Host "Installing VC++ Redistributable x64..."
$p1 = Start-Process -FilePath "$base\vcredist_x64.exe" -ArgumentList "/install", "/quiet", "/norestart" -Wait -PassThru
Write-Host "vcredist exit code: $($p1.ExitCode)"

Write-Host "Launching DirectX9 SDK (June 2010) installer - this is a GUI wizard, please click through it."
Write-Host "If you hit error S1023, run these two commands as admin afterwards, then re-run the installer:"
Write-Host '  MsiExec.exe /passive /X{F0C3E5D1-1ADE-321E-8167-68EF0DE699A5}'
Write-Host '  MsiExec.exe /passive /X{1D8E6291-B0D5-35EC-8441-6616F567A0F7}'
$p2 = Start-Process -FilePath "$base\DXSDK_Jun10.exe" -Wait -PassThru
Write-Host "DXSDK installer exit code: $($p2.ExitCode)"

Write-Host "Done."
