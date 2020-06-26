# Variables
set -gx DEV_PATH "$HOME/Development"
set -gx DOTFILES_PATH "$DEV_PATH/dotfiles"
set -gx XDG_CONFIG_HOME "$HOME/.config"

# Keep private stuff in another file which is not checked into git
source $HOME/.config/fish/private.fish

# Source aliases and abbreviations
source $HOME/.config/fish/aliases.fish
source $HOME/.config/fish/abbreviations.fish

# Set NeoVim as default editor
set -gx EDITOR nvim

# Add ~/.bin directory to $PATH
set PATH $PATH $HOME/.bin

# n
set -gx N_PREFIX $HOME/.node
set PATH $N_PREFIX/bin $PATH

# fzf
set -gx FZF_DEFAULT_COMMAND 'fd --type f --hidden --follow --exclude .git --exclude esy.lock'
set -gx FZF_CTRL_T_COMMAND $FZF_DEFAULT_COMMAND
set -gx FZF_CTRL_T_OPTS "--preview 'bat --style=numbers --color=always {} | head -500'"

# Rg
set -gx RIPGREP_CONFIG_PATH $HOME/.config/ripgreprc

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
if test (uname) = "Darwin"
    # Add GNU stuff to PATH and MANPATH
    set PATH /usr/local/opt/coreutils/libexec/gnubin $PATH
    set MANPATH /usr/local/opt/coreutils/libexec/gnuman $MANPATH
    set PATH /usr/local/opt/gnu-sed/libexec/gnubin $PATH
    set MANPATH /usr/local/opt/gnu-sed/libexec/gnuman $MANPATH
    set PATH /usr/local/opt/findutils/libexec/gnubin $PATH
    set MANPATH /usr/local/opt/findutils/libexec/gnuman $MANPATH
    set PATH /usr/local/opt/gnu-tar/libexec/gnubin $PATH
    set MANPATH /usr/local/opt/gnu-tar/libexec/gnuman $MANPATH
    set PATH /usr/local/opt/gnu-which/libexec/gnubin $PATH
    set MANPATH /usr/local/opt/gnu-which/libexec/gnuman $MANPATH
    set PATH /usr/local/opt/make/libexec/gnubin $PATH
    set MANPATH /usr/local/opt/make/libexec/gnuman $MANPATH

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
set -gx GOPATH $DEV_PATH/go
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

# If on Arch, start X at login
if test (uname) = "Linux"
    if status is-login
        if test -z "$DISPLAY" -a $XDG_VTNR = 1
            exec startx -- -keeptty > ~/.xorg.log 2>&1
        end
    end
end

# Rust
set PATH $PATH $HOME/.cargo/bin

# opam configuration
source /home/taylon/.opam/opam-init/init.fish > /dev/null 2> /dev/null; or true
