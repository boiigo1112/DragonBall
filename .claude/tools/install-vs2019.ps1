# Run this in PowerShell as Administrator.
# Installs Visual Studio 2019 Community with the workloads required by OpenDBO-Core's README:
#   - Desktop development with C++
#   - Game development with C++
#   - C++ Clang-cl for v142 build tools (x64/x86)
# Total download is roughly 15-20 GB and can take a long time depending on connection speed.

$ErrorActionPreference = "Stop"

$installer = "$env:TEMP\vs_community.exe"
Write-Host "Downloading Visual Studio 2019 Community bootstrapper..."
Invoke-WebRequest -Uri "https://aka.ms/vs/16/release/vs_community.exe" -OutFile $installer

Write-Host "Installing (silent, this may take 30-90 minutes)..."
$installArgs = @(
    "--quiet", "--wait", "--norestart",
    "--add", "Microsoft.VisualStudio.Workload.NativeDesktop",
    "--add", "Microsoft.VisualStudio.Workload.NativeGame",
    "--add", "Microsoft.VisualStudio.Component.VC.Llvm.ClangToolset",
    "--includeRecommended"
)
$proc = Start-Process -FilePath $installer -ArgumentList $installArgs -Wait -PassThru
Write-Host "Install finished. ExitCode: $($proc.ExitCode)"
