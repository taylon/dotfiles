# Add .bin directory to $PATH
set PATH $PATH $HOME/.bin

# n
set -gx N_PREFIX $HOME/.node
set PATH $N_PREFIX/bin $PATH 

# Autojump
if test -f /usr/share/autojump/autojump.fish
  source /usr/share/autojump/autojump.fish
end

# rbenv
# set -gx PATH $PATH $HOME/.rbenv/bin
# status --is-interactive; and source (rbenv init -|psub)

# Golang
set -gx GOROOT /usr/lib/go
if test -d $GOROOT
  set -gx GOPATH $HOME/Development/go
  if test ! -d $GOPATH
    mkdir -p $GOPATH/bin
    mkdir -p $GOPATH/src
    mkdir -p $GOPATH/pkg
  end

  set PATH $PATH $GOROOT/bin $GOPATH/bin
end

# TODO: Apply this only on Arch Linux
# SSH Agent on systemd
set -gx SSH_AUTH_SOCK $XDG_RUNTIME_DIR/ssh-agent.socket

# Keep credentials in another file
source /home/taylon/.config/fish/credentials.fish

set -gx EDITOR vim

# Set Vi mode
fish_vi_key_bindings
set fish_cursor_default line blink
set fish_cursor_insert line blink
set fish_cursor_visual block

set fish_greeting
