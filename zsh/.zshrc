# Enable colors
autoload -U colors && colors

# Completion
autoload -Uz compinit
compinit
_comp_options+=(globdots)

# Navigation
setopt AUTO_CD # Go to folder path without using cd

setopt AUTO_PUSHD        # Push the old directory onto the stack on cd
setopt PUSHD_IGNORE_DUPS # Do not store duplicates in the stack
setopt PUSHD_SILENT      # Do not print the directory stack after pushd or popd

setopt CORRECT # Spelling correction
setopt CORRECT_ALL
setopt CDABLE_VARS   # Change directory to a path stored in a variable
setopt EXTENDED_GLOB # Use extended globbing syntax

# History
setopt EXTENDED_HISTORY # Write the history file in the ':start:elapsed;command' format
setopt SHARE_HISTORY    # Share history between all sessions
setopt APPEND_HISTORY
setopt INC_APPEND_HISTORY
setopt HIST_EXPIRE_DUPS_FIRST # Expire a duplicate event first when trimming history
setopt HIST_IGNORE_DUPS       # Do not record an event that was just recorded again
setopt HIST_IGNORE_ALL_DUPS   # Delete an old recorded event if a new event is a duplicate
setopt HIST_FIND_NO_DUPS      # Do not display a previously found event
setopt HIST_IGNORE_SPACE      # Do not record an event starting with a space
setopt HIST_SAVE_NO_DUPS      # Do not write a duplicate event to the history file
setopt HIST_VERIFY            # Do not execute immediately upon history expansion
setopt HIST_REDUCE_BLANKS     # Remove blank lines from history

source "$ZDOTDIR"/aliases.zsh
source "$ZDOTDIR"/vim-mode.zsh
source "$ZDOTDIR"/sdkman.zsh

# FZF
source /usr/share/fzf/completion.zsh
source /usr/share/fzf/key-bindings.zsh

# autocomplete
zstyle ':autocomplete:list-choices:*' max-lines 100%
zstyle ':autocomplete:*' groups always
zstyle ':autocomplete:list-choices:*' min-input 2
zstyle ':autocomplete:*:no-matches-yet' message ''
zstyle ':autocomplete:tab:*' completion fzf
source /usr/share/zsh/plugins/zsh-autocomplete/zsh-autocomplete.zsh

# autosuggestions
ZSH_AUTOSUGGEST_STRATEGY=(history completion)
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh

# auto-ls
AUTO_LS_COMMANDS=(ls)
source "$ZDOTDIR"/plugins/auto-ls/auto-ls.zsh

# autopair
# source "$ZDOTDIR"/plugins/zsh-autopair/autopair.zsh
# autopair-init

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

# autojump
source /usr/share/autojump/autojump.zsh

# source "$XDG_CONFIG_HOME"/broot/launcher/bash/br

# Set paths and other OS dependent things.
# The default will be the paths used in Arch Linux, we will set different
# ones when we are in MacOS
# export autojump_path "/usr/share/autojump/autojump.fish"
# export golang_path "/usr/lib/go"

if [[ $(uname) == "Linux" ]]; then
  if systemctl -q is-active graphical.target && [[ ! $DISPLAY && $XDG_VTNR -eq 1 ]]; then
    exec startx -- -keeptty > ~/.xorg.log 2>&1
  fi
fi

# syntax-highlighting
source /usr/share/zsh/plugins/fast-syntax-highlighting/fast-syntax-highlighting.plugin.zsh
# source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
