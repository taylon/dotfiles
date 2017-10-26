#!/usr/bin/env bash

print::nocolor "Installing n-install: " "-n"

n_install_path="$BIN_PATH/n-install"
output="$(curl -L -s -o $n_install_path https://git.io/n-install 2>&1)"
if [[ $? -gt 0 ]]; then
	print::fail "[Failed]"
	logger::log "Error downloading file - client=curl file_name=n-install" "$output"

	# Let's make sure that the n-install file does not exists
	rm -f "$n_install_path"
else
	chmod 755 "$n_install_path"
	print::sucess "[OK]"

	print::nocolor "Installing n and Node.js: " "-n"

	export N_PREFIX="$HOME/n";
	output="$($BIN_PATH/n-install -y -n 2>&1)"
	if [[ $? -gt 0 ]]; then
		print::fail "[Failed]"
		logger::log "Error installing n and Node.js" "$output"
	else
		print::sucess "[OK]"
	fi
fi
