cmake_minimum_required(VERSION 3.13)

# =========================
# Include the Pico SDK
# =========================
include($ENV{PICO_SDK_PATH}/pico_sdk_import.cmake)
pico_sdk_init()

# =========================
# Include Pimoroni Pico (Audio Pack)
# =========================
include($ENV{PIMORONI_PICO_PATH}/pimoroni_pico_import.cmake)

# =========================
# Project
# =========================
project(PicoSynth C CXX ASM)

# =========================
# Gather all source files
# =========================
file(GLOB_RECURSE SRC_FILES
    "src/*.cpp"
)

add_executable(PicoSynth ${SRC_FILES})

# =========================
# Include directories
# =========================
target_include_directories(PicoSynth PRIVATE
    src
    src/AudioEngine
    src/core
)

# =========================
# Link libraries
# =========================
target_link_libraries(PicoSynth
    pico_stdlib        # Pico standard library
    hardware_i2s       # I2S peripheral (handled internally by Pimoroni)
    pimoroni_pico      # Pimoroni Audio Pack library
)

# =========================
# Extra outputs (UF2, map file, etc.)
# =========================
pico_add_extra_outputs(PicoSynth)
