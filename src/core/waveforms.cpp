#include "waveforms.h"
#include <cmath>

// Define the Sine waveform
Waveform SineWave = {
    "Sine",
    {}
};

// Initialize waveform(s)
void initWaveforms() {
    for (int i = 0; i < 256; ++i) {
        float t = i / 256.0f;
        SineWave.samples[i] = sinf(2.0f * 3.14159265f * t);
    }
}
