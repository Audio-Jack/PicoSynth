cmake_minimum_required(VERSION 3.13)

# Pull in the Pico SDK (must come before project())
include(pico_sdk_import.cmake)

# Name of your project + languages
project(PicoSynth C CXX ASM)

# Language standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Create the firmware target
add_executable(PicoSynth
    src/main.cpp
)

# Enable stdio (USB for debug prints)
pico_enable_stdio_usb(PicoSynth 1)
pico_enable_stdio_uart(PicoSynth 0)

# Link required Pico libraries
target_link_libraries(PicoSynth
    pico_stdlib
)

# Generate .uf2, .elf, etc.
pico_add_extra_outputs(PicoSynth)
