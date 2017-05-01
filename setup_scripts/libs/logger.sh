#!/usr/bin/env bash

LOG_FILE="./pkg_install.log"

logger::setup_file() {
  if [[ -f $LOG_FILE ]]; then
  	mv "$LOG_FILE" "$LOG_FILE.bkp"
  	touch "$LOG_FILE"

  	# Since this script has to run as root the log file will be created
  	# as such, so lets set it's permissions to 666
  	chmod 666 $LOG_FILE
  fi
}

logger::log() {
	echo -ne "============ $1 ============ \r $2 \r" >> $LOG_FILE
}
