$DEV_PATH = "T:\Development"
$DOTFILES_PATH = "$DEV_PATH\dotfiles"

# Rg
$RIPGREP_CONFIG_PATH = "$DOTFILES_PATH\ripgrep\ripgreprc"

set-location $DEV_PATH

# Import-Module "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"
# Enter-VsDevShell -InstanceId 0f691196

# PSReadline
Set-PSReadlineOption -EditMode vi
Set-PSReadlineKeyHandler -Key Tab -Function MenuComplete
Set-PSReadlineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadlineKeyHandler -Key DownArrow -Function HistorySearchForward
Set-PSReadLineOption -PredictionSource History

# Fzf
Set-PsFzfOption -PSReadlineChordProvider 'Ctrl+p' 

# Aliases
function dot { cd $DOTFILES_PATH }
function dev { cd $DEV_PATH }
function down { cd $HOME\Downloads }
function .. { cd .. }
function ... { cd ..\.. }
function .... { cd ..\..\.. }
function cat { bat $args }
function v { nvim $args }
function gvim { nvim-qt $args }
function g { git $args }
function s { git status }
function d { git diff }
function clone { git clone $args }
New-Alias open ii

function vs($file) {
 Start-Process "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\IDE\devenv.exe" $file
}

function sudo {
  if ($args.Count -gt 0) {   
    $argList = "& '" + $args + "'"
    Start-Process "$psHome\powershell.exe" -Verb runAs -ArgumentList $argList
  } else {
    Start-Process "$psHome\powershell.exe" -Verb runAs
  }
}

# Modules
#Import-Module Get-ChildItemColor
# Import-Module -Name Terminal-Icons
# Set-Alias ls Get-ChildItem | Format-List

. $DOTFILES_PATH\windows\private.ps1
