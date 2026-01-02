#include "AudioEngine.h"

// Constructor
AudioEngine::AudioEngine() : bufferIndex(0) {
    // zero the buffer
    for (size_t i = 0; i < BUFFER_SIZE; ++i)
        buffer[i] = 0;
}

// Destructor
AudioEngine::~AudioEngine() {
    stop();
}

void AudioEngine::init() {
    // Initialize the Pico Audio Pack
    // Placeholder for now — will include i2s_init() and DMA setup when hardware is in
}

void AudioEngine::start() {
    // Start streaming samples — will be hooked to DMA/I2S callback
}

void AudioEngine::stop() {
    // Stop streaming
}

int16_t AudioEngine::generateSample() {
    // Placeholder: simple sine wave or zero for now
    // Replace with oscillator + effects later
    return 0;
}

void AudioEngine::fillBuffer() {
    for (size_t i = 0; i < BUFFER_SIZE; ++i) {
        buffer[i] = generateSample();
    }
}
