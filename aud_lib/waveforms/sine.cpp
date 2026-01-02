#include "sine.h"
#include<cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

// Satic member initialization required for static variables
float SineOscillator::lookupTable[SineOscillator::TABLE_SIZE];
bool SineOscillator::tableInitialized = false;

// Constructor
SineOscillator::SineOscillator(uint32_t sampleRate) : Oscillator(sampleRate) {
    // Build Sine lookupTable if it's the first time
    if (!tableInitialized) {
        for (uint16_t i = 0; i < TABLE_SIZE; i++) {
            // Create one perfect cycle sin(2pi * i / TABLE_SIZE)
            // Result scaled to -11.0 to 1.0
            lookupTable[i] = sinf(2.0f * M_PI * i / TABLE_SIZE);
        }
        tableInitialized = true;
    }
}
// Core sample generation
float SineOscillator::getSample() {
    // First se the TOP 9 bits of the 32-bit phase accumulator as table index
    // because TABLE_SIZE = 512 = 2^9
    // phase accumulator >> 23 (32 - 9) leaves the highest 9 bits
    uint16_t index = phaseAccumulator >> 23;

    // Then look up the sine value
    float sample = lookupTable[index];

    //Advance phase for next call
    phaseAccumulator += phaseIncrement;
    // Sauce: 32-bit overflow creates, automatic seamless looping

    return sample;
};