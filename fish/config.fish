# Variables
set -gx DEV_PATH "$HOME/Development"
set -gx DOTFILES_PATH "$DEV_PATH/dotfiles"
set -gx XDG_CONFIG_HOME "$HOME/.config"

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

# Temporary workaround for supporting Trash on electon apps
# This might no longer be necessary after apps adopt
# Electon 3.0 so keep an eye on it
set -gx ELECTRON_TRASH gio

# Set paths and other OS dependent things.
# The default will be the paths used in Arch Linux, we will set different
# ones when we are in MacOS
set -l autojump_path "/usr/share/autojump/autojump.fish"
set -l golang_path "/usr/lib/go"

# There are things that should be different or only executed in MacOS
if test (uname) == "Darwin"
    # Add GNU coreutils bin to PATH and MANPATH
    set PATH /usr/local/opt/coreutils/libexec/gnubin $PATH
    set MANPATH /usr/local/opt/coreutils/libexec/gnuman $MANPATH

    # Set Autojump's init script path
    set autojump_path "/usr/local/share/autojump/autojump.fish"

    # Set Go's instalation path
    set golang_path "/usr/local/opt/go/libexec"

    # This is not necessary on MacOS
    set -e ELECTRON_TRASH
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

# Setup Fisher to save plugins in a different location
set -g fisher_path $HOME/.fisher_plugins

set fish_function_path $fish_function_path[1] $fisher_path/functions $fish_function_path[2..-1]
set fish_complete_path $fish_complete_path[1] $fisher_path/completions $fish_complete_path[2..-1]

for file in $fisher_path/conf.d/*.fish
    builtin source $file 2>/dev/null
end

# Disable greeting message
set fish_greeting
