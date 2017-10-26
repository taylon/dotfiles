#!/usr/bin/env bash

print::color() {
	local color="$1"
	local text="$2"
	local color_reset
	color_reset=$(tput sgr0)

	echo "${color}$text${color_reset}"
}

print::sucess() {
	print::color "$(tput setaf 2)$1"
}

print::fail() {
	print::color "$(tput setaf 1)$1"
}

print::note() {
	print::color "$(tput setaf 4)$1"
}

print::nocolor() {
	local text="$1"
	local echo_args="$2"

	echo "$echo_args" "$text"
}
