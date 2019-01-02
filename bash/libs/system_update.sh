#!/usr/bin/env bash

source /home/taylon/Development/dotfiles/bash/libs/print.sh

system_update::common() {
  echo
  print::note "Updating Fisher..."
  sudo fish -c "fisher self-update"
  fish -c fisher

  echo
  print::note "Updating global Node packages"
  yarn global upgrade-interactive
}
