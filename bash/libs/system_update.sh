#!/usr/bin/env bash

source /home/taylon/Development/dotfiles/bash/libs/print.sh

system_update::common() {
  echo
  print::note "Updating Fish plugins..."
  fish -c "fisher update"

  echo
  print::note "Updating global Node packages"
  yarn global upgrade-interactive
}
