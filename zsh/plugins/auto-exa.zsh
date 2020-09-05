#!/usr/bin/env zsh

auto_exa() {
  exa -a --icons
}

autoload -U add-zsh-hook
add-zsh-hook chpwd auto_exa
auto_exa
