$DEV_PATH = "T:\Development"
$DOTFILES_PATH = "$DEV_PATH\dotfiles"

New-Item -ItemType SymbolicLink -Path $HOME\Development -Target $DEV_PATH

New-Item -ItemType SymbolicLink -Path $env:APPDATA\Local\nvim -Target $DOTFILES_PATH\vim
New-Item -ItemType SymbolicLink -Path $HOME\.vim -Target $DOTFILES_PATH\vim
New-Item -ItemType SymbolicLink -Path $HOME\.vsvimrc -Target $DOTFILES_PATH\vim\vsvimrc

New-Item -ItemType SymbolicLink -Path $env:APPDATA\Local\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json -Target $DOTFILES_PATH\windows_terminal\settings.json

New-Item -ItemType SymbolicLink -Path $env:APPDATA\Roaming\bat -Target $DOTFILES_PATH\bat

# New-Item -ItemType SymbolicLink -Path $HOME\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1 -Target $DOTFILES_PATH\windows\profile.ps1
New-Item -ItemType SymbolicLink -Path $HOME\Documents\PowerShell\Microsoft.PowerShell_profile.ps1 -Target $DOTFILES_PATH\windows\profile.ps1



