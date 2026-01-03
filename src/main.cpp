#include "pico/stdlib.h"
#include "pico/audio_i2s.h"
#include "core/waveforms.h"
#include "AudioEngine/AudioEngine.h"

int main() {
    // Initialize stdio for debugging
    stdio_init_all();

    // Create the audio engine
    AudioEngine engine;
    engine.init(); // assumes you have an init() method in AudioEngine

    // Create a sine waveform
    Waveform sine;
    sine.setType(Waveform::SINE); // your enum for SINE
    sine.setFrequency(440.0f);    // A4 note

    // Attach waveform to engine
    engine.addWaveform(&sine);

    // Start audio output (Pimoroni Audio Pack handles I2S internally)
    engine.start();

    printf("Audio engine running! Playing sine wave...\n");

    while (true) {
        // In a real engine, you would call engine.update() if needed
        tight_loop_contents(); // low-power idle while audio runs on DMA
    }

    return 0;
}
