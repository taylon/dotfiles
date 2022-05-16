$DEV_PATH = "$HOME\programming"
# $DEV_PATH = "T:\programming"
$DOTFILES_PATH = "$DEV_PATH\dotfiles"

set-location $DEV_PATH

. $DOTFILES_PATH\windows\private.ps1

# Import-Module "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"
# Enter-VsDevShell -InstanceId 0f691196

# PSReadline
Set-PSReadlineOption -EditMode vi
Set-PSReadlineKeyHandler -Key Tab -Function MenuComplete
Set-PSReadlineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadlineKeyHandler -Key DownArrow -Function HistorySearchForward
Set-PSReadLineOption -PredictionSource History

# fzf
$FZF_DEFAULT_COMMAND = "fd --type f --hidden --follow --exclude .git --exclude External --exclude tmp"
# Set-PsFzfOption -PSReadlineChordProvider 'Ctrl+p' 

# Rg
$RIPGREP_CONFIG_PATH = "$DOTFILES_PATH\ripgrep\ripgreprc"

# Aliases
function dot { cd $DOTFILES_PATH }
function dev { cd $DEV_PATH }
function down { cd $HOME\Downloads }
function .. { cd .. }
function ... { cd ..\.. }
function .... { cd ..\..\.. }
function gvim { nvim-qt $args }
function v { nvim $args }
function s { git status $args }
function d { git diff $args }
function clone { git clone $args }
New-Alias g git
New-Alias touch New-Item
New-Alias which Get-Command
New-Alias open ii
Set-Alias cat bat

function Private:rg {
  rg `
    --glob="!.git/*" `
    --glob="!yarn.lock" `
    --glob="!*.min.js" `
    --glob="!External/*" `
    --glob="!vendor/*" `
    --glob="!tmp/*" `
    $args
}

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

function prompt {
    Write-Host $($(Get-Location) -replace "$DEV_PATH\".Replace('\','\\'), "" -replace ("$HOME\").Replace('\','\\'), "~\") -NoNewline -ForegroundColor Blue
    Write-Host ""

    return "⮞ "
}

# Modules
Import-Module Get-ChildItemColor
Set-Alias ls Get-ChildItemColorFormatWide
Set-Alias ll Get-ChildItem 
# Import-Module -Name Terminal-Icons
# Set-Alias ls Get-ChildItem | Format-List

