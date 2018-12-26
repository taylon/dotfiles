FROM debian:stretch

RUN apt-get update
RUN apt-get install --no-install-recommends -y \
  build-essential \
  gcc \
  unzip \
  wget \
  zip \
  gcc-avr \
  binutils-avr \
  avr-libc \
  dfu-programmer \
  dfu-util \
  gcc-arm-none-eabi \
  binutils-arm-none-eabi \
  libnewlib-arm-none-eabi \
  git \
  software-properties-common \
  avrdude

RUN rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/qmk/qmk_firmware.git /qmk
WORKDIR /qmk

# Copy Dactyl to a more standard folder, it will help with the
# build cli
RUN cp -r keyboards/handwired/dactyl/ keyboards/dactyl/

RUN make git-submodule
RUN make clean
