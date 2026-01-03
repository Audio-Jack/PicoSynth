#pragma once
#include <cstdint>
#include <array>

// Generic waveform structure
struct Waveform {
    const char* name;
    std::array<float, 256> samples; // 256-point lookup table
};

// Declare the Sine waveform
extern Waveform SineWave;

// Initialize waveforms (fills the sample tables)
void initWaveforms();
