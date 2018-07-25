all: build

clean:
	@rm -rf ./dist

build: clean
	@docker-compose run qmk_build

build-image:
	@docker-compose build

flash:
	@teensy-loader-cli -v -mmcu=atmega32u4 -w ./dist/ergodox_ez_taylon.hex
