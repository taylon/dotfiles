#!/usr/bin/env bash

# Add a repository.
# Return "ok" if sucess and the apt-add-repository command output if fail
apt::add_repo() {
	local output

	output="$(sudo apt-add-repository -y "$1" 2>&1)"
	if [[ $? -gt 0 ]]; then
		echo "$output"
	else
		echo "ok"
	fi
}

# Executes a apt-get update.
# Return "ok" if sucess and the apt-get update command output if fail
apt::update() {
	local output

	output="$(sudo apt-get update -y 2>&1)"
	if [[ $? -gt 0 ]]; then
		echo "$output"
	else
		echo "ok"
	fi
}

apt::install() {
	local pkg="$1"
	local pkg_name="$2"
	local quiet="$3"

	if [[ "$quiet" != "quiet" ]]; then
		print::nocolor "Installing $pkg_name: " "-n"
	fi

	apt_output="$(sudo apt-get install -y $pkg 2>&1)"
	if [[ "$?" -gt 0 ]]; then
		print::fail "[Failed]"
		logger::log "Error installing package - pkg=$pkg name=$pkg_name" "$apt_output"
	elif [[ "$(echo $apt_output | grep 'is already')" != "" ]]; then
		print::note "[Already installed]"
	else
		print::sucess "[OK]"
	fi
}

apt::install_with_repo() {
	local repo="$1"
	local pkg="$2"
	local pkg_name="$3"

	local err

	print::nocolor "Installing $pkg_name: "
	print::nocolor "   -- Adding repo: " "-n"

	err=$(apt_add_repo "$1")
	if [[ $err != "ok" ]]; then
		print::fail "[Failed]"
		logger::log "Failed adding repository - repo=$repo" "$err"
	else
		print_sucess "[OK]"
		print::nocolor "   -- Updating sources: " "-n"

		err=$(apt_update)
		if [[ $err != "ok" ]]; then
			print::fail "[Failed]"
			logger::log "Failed on apt-get update" "$err"
		else
			print::sucess "[OK]"
			print::nocolor "   -- Installing package: " "-n"

			apt::install "$pkg" "$pkg_name" "quiet"
		fi
	fi
}
