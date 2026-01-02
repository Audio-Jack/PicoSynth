#pragma once
#include "pico/stdlib.h"
#include <cstdint>

class AudioEngine {
public:
    AudioEngine();
    ~AudioEngine();

    // Initialize audio hardware (I²S/DAC)
    void init();

    // Start audio streaming
    void start();

    // Stop audio streaming
    void stop();

    // Generate next sample (placeholder)
    int16_t generateSample();

private:
    // Example: audio buffer for DMA/I2S
    static constexpr size_t BUFFER_SIZE = 256;
    int16_t buffer[BUFFER_SIZE];
    size_t bufferIndex;

    void fillBuffer();
};
