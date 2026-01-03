#include <cmath>
#include <cstdint>

#include "pico/stdlib.h"

// Pimoroni I2S audio driver
#include "pico_audio_i2s.hpp"

// --------------------
// Audio configuration
// --------------------
constexpr uint32_t SAMPLE_RATE = 44100;
constexpr uint32_t BUFFER_SIZE = 256;
constexpr float TONE_FREQUENCY = 440.0f;

// --------------------
// Audio state
// --------------------
static int16_t audio_buffer[BUFFER_SIZE];
static float phase = 0.0f;
static float phase_increment = 0.0f;

// --------------------
// Main
// --------------------
int main() {
    // Init Pico SDK (clocks, stdio, etc.)
    stdio_init_all();

    // Small delay so USB / power stabilizes
    sleep_ms(500);

    // Calculate phase increment
    phase_increment = 2.0f * M_PI * TONE_FREQUENCY / SAMPLE_RATE;

    // --------------------
    // I2S configuration
    // --------------------
    audio_i2s_config_t config;
    config.sample_rate = SAMPLE_RATE;
    config.bits_per_sample = 16;
    config.channels = 1;

    // Initialize I2S + DMA
    audio_i2s_init(&config);

    // Enable audio output
    audio_i2s_set_enabled(true);

    // --------------------
    // Audio loop
    // --------------------
    while (true) {
        // Fill buffer with sine wave
        for (uint32_t i = 0; i < BUFFER_SIZE; i++) {
            audio_buffer[i] = static_cast<int16_t>(sinf(phase) * 32767.0f);

            phase += phase_increment;
            if (phase >= 2.0f * M_PI) {
                phase -= 2.0f * M_PI;
            }
        }

        // Send buffer to I2S (DMA handles playback)
        audio_i2s_write(audio_buffer, BUFFER_SIZE);
    }

    return 0;
}
