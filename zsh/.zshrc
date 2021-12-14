export PATH="$N_PREFIX/bin:$PATH"

# Enable colors
autoload -U colors && colors

source "$ZDOTDIR"/plugins.zsh
source "$ZDOTDIR"/aliases.zsh
source "$ZDOTDIR"/history.zsh
source "$ZDOTDIR"/navigation.zsh
source "$ZDOTDIR"/vim-mode.zsh
source "$ZDOTDIR"/sdkman.zsh
source "$ZDOTDIR"/fzf.zsh

# prompt
# PS1="%B%{$fg[red]%}[%{$fg[yellow]%}%n%{$fg[green]%}@%{$fg[blue]%}%M %{$fg[magenta]%}%~%{$fg[red]%}]%{$reset_color%}$%b "

PURE_PROMPT_SYMBOL="⮞"
PURE_PROMPT_VICMD_SYMBOL="⮞"
PURE_GIT_STASH_SYMBOL="#"
zstyle :prompt:pure:git:stash show yes
zstyle :prompt:pure:prompt:success color default

fpath+="$ZDOTDIR"/prompt
autoload -U promptinit
promptinit
prompt pure

if [[ $(uname) == "Linux" ]]; then
  # start X at login
  if systemctl -q is-active graphical.target && [[ ! $DISPLAY && $XDG_VTNR -eq 1 ]]; then
    exec startx -- -keeptty > ~/.xorg.log 2>&1
  fi

  source /usr/share/autojump/autojump.zsh
else
  source /usr/local/share/autojump/autojump.zsh
fi

# Setup opam
test -r /home/taylon/.opam/opam-init/init.zsh && . /home/taylon/.opam/opam-init/init.zsh > /dev/null 2> /dev/null || true

source "$ZDOTDIR"/private.zsh
