New-Item -ItemType SymbolicLink -Path $HOME\programming -Target $env:DEV_PATH

New-Item -ItemType SymbolicLink -Path $env:LOCALAPPDATA\nvim -Target $env:DOTFILES_PATH\vim
New-Item -ItemType SymbolicLink -Path $HOME\.vim -Target $env:DOTFILES_PATH\vim
New-Item -ItemType SymbolicLink -Path $HOME\.vsvimrc -Target $env:DOTFILES_PATH\vim\vsvimrc
New-Item -ItemType SymbolicLink -Path $HOME\.ideavimrc -Target $env:DOTFILES_PATH\vim\ideavimrc

New-Item -ItemType SymbolicLink -Path $env:APPDATA\Local\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json -Target $env:DOTFILES_PATH\windows_terminal\settings.json

New-Item -ItemType SymbolicLink -Path $env:APPDATA\bat -Target $env:DOTFILES_PATH\bat

New-Item -ItemType SymbolicLink -Path $HOME\Documents\PowerShell\Microsoft.PowerShell_profile.ps1 -Target $env:DOTFILES_PATH\windows\profile.ps1

New-Item -ItemType SymbolicLink -Path $env:APPDATA\Microsoft\Windows\"Start Menu"\Programs\Startup\app_switcher.ahk -Target $env:DOTFILES_PATH\autohotkey\app_switcher.ahk

New-Item -ItemType SymbolicLink -Path $HOME\.gitconfig -Target $env:DOTFILES_PATH\git\gitconfig
