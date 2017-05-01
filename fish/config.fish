# Add .bin directory to $PATH
set PATH $PATH $HOME/.bin

# n
# set -gx N_PREFIX $HOME/n
# if not contains $N_PREFIX/bin $PATH; set PATH $PATH $N_PREFIX/bin; end

# Autojump - Only for Debian based distros
# if test -f /usr/share/autojump/autojump.fish
#   source /usr/share/autojump/autojump.fish
# end

# rbenv
# set -gx PATH $PATH $HOME/.rbenv/bin
# status --is-interactive; and source (rbenv init -|psub)

# Golang
# if test -f /usr/local/go/bin/go
#   set -gx GOPATH $HOME/Development/go
#   set PATH $PATH /usr/local/go/bin $GOPATH/bin
# end

# TODO: Apply this only on Arch Linux
# SSH Agent on systemd
set -gx SSH_AUTH_SOCK $XDG_RUNTIME_DIR/ssh-agent.socket

# Keep credentials in another file
source /home/taylon/.config/fish/credentials.fish

set -gx EDITOR vim

set fish_greeting
