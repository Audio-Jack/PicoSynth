#include "pico/stdlib.h"
#include "core/waveforms.h"
#include "AudioEngine/AudioEngine.h"
#include <cstdio>

int main() {
    stdio_init_all();

    AudioEngine engine;
    engine.init();
    engine.start();

    while (true) {
        // In the real firmware, I²S DMA handles streaming
        // Here we could simulate buffer filling if needed
        tight_loop_contents();
    }

    return 0;
}
