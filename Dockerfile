# Fetch ubuntu image
FROM ubuntu:22.04

# Install prerequisites
RUN \
    apt update && \
    apt install -y cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential && \
    apt install -y binutils-arm-none-eabi openocd make libusb-1.0-0-dev git python3
    
# create a directory for the project
RUN \
    mkdir -p /project/ && \
    cd /project && \
    git clone https://github.com/libopencm3/libopencm3 && \
    cd /project/libopencm3 && \
    make

# Copy project sources into image
COPY main.c                     /project/dac_sampling/
COPY Makefile                   /project/dac_sampling/
COPY drivers                    /project/dac_sampling/drivers/
COPY rules.mk                   /project/dac_sampling/
COPY stm32-clicker.ld           /project/dac_sampling

# Build project
RUN \
    cd /project/dac_sampling && \
    make all
    
# Command that will be invoked when the container starts
ENTRYPOINT ["/bin/bash"]