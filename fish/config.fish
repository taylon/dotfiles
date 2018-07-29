# Common variables that I use often
set -gx DEV_PATH "$HOME/Development"
set -gx DOTFILES_PATH "$DEV_PATH/dotfiles"

# Set some variables to identify OS
set -l macos_uname "Darwin"
set -gx OSAMI (uname)

# Keep private stuff in another file which is not checked into git
source $HOME/.config/fish/private.fish

# Source aliases
source $HOME/.config/fish/aliases.fish

# Set VIM as default editor
set -gx EDITOR vim

# Add ~/.bin directory to $PATH
set PATH $PATH $HOME/.bin

# n
set -gx N_PREFIX $HOME/.node
set PATH $N_PREFIX/bin $PATH

# Set paths and other OS dependent things.
# The default will be the paths used in Arch Linux, we will set different
# ones when we are in MacOS
set -l autojump_path "/usr/share/autojump/autojump.fish"
set -l golang_path "/usr/lib/go"

# There are things that should be different or only executed in MacOS
if test $OSAMI = $macos_uname
  # Add GNU coreutils bin to PATH and MANPATH
  set PATH /usr/local/opt/coreutils/libexec/gnubin $PATH
  set MANPATH /usr/local/opt/coreutils/libexec/gnuman $MANPATH

  # Set Autojump's init script path
  set autojump_path "/usr/local/share/autojump/autojump.fish"

  # Set Go's instalation path
  set golang_path "/usr/local/opt/go/libexec"
end

# Source Autojump's init script
source $autojump_path

# Golang
set -gx GOROOT $golang_path
set -gx GOPATH $HOME/Development/go
set PATH $PATH $GOROOT/bin $GOPATH/bin

# TODO: Apply this only on Arch Linux
# SSH Agent on systemd
# set -gx SSH_AUTH_SOCK $XDG_RUNTIME_DIR/ssh-agent.socket

# Setup Fisherman to save plugins in a different folder
set -U fish_path $HOME/.fisherman_plugins

set fish_function_path $fish_path/functions $fish_function_path
set fish_complete_path $fish_path/completions $fish_complete_path

for file in $fish_path/conf.d/*.fish
  builtin source $file 2> /dev/null
end

# Disable greeting message
set fish_greeting
