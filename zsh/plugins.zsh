# load zgen
source "$ZDOTDIR"/.zgen/zgen.zsh

# auto-ls
auto-ls-custom_function() {
  exa -a --icons
}
AUTO_LS_COMMANDS=(custom_function)

# if the init script doesn't exist
if ! zgen saved; then
  echo "Creating a zgen save"

  zgen load zdharma/fast-syntax-highlighting
  zgen load zsh-users/zsh-history-substring-search

  zgen load olets/zsh-abbr
  zgen load zsh-users/zsh-completions src
  zgen load desyncr/auto-ls
  zgen load hlissner/zsh-autopair

  zgen load zsh-users/zsh-autosuggestions

  # generate the init script from plugins above
  zgen save
fi

# autosuggestions
ZSH_AUTOSUGGEST_STRATEGY=(history completion)

# history-substring-search
bindkey '^[[A' history-substring-search-up
bindkey '^[[B' history-substring-search-down

# Include dotfiles in completions
_comp_options+=(globdots)
