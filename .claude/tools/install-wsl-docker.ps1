# Run in PowerShell as Administrator.
# Enables WSL2 + installs a default Linux distro, then installs Docker Engine
# inside that distro (no Docker Desktop needed).
# NOTE: If WSL/VirtualMachinePlatform features were not previously enabled,
# Windows will require a REBOOT before WSL2 works. Run this script again
# after rebooting if it tells you to.

$ErrorActionPreference = "Stop"

Write-Host "Enabling WSL + installing default distro (Ubuntu)..."
wsl --install --no-launch

Write-Host ""
Write-Host "If this was the first time enabling WSL, a REBOOT is required."
Write-Host "After reboot, open a normal (non-admin) terminal and run:"
Write-Host "  wsl -d Ubuntu -- bash -lc `"curl -fsSL https://get.docker.com | sudo sh && sudo usermod -aG docker \$USER && sudo service docker start`""
Write-Host ""
Write-Host "Then verify from Windows with: wsl -d Ubuntu -- docker ps"
