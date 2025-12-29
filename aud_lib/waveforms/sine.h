#pragma once
#include "../core/oscillator.h"
class SineOscillator : public Oscillator {
    private:
    static const uint32_t TABLE_SIZE = 512;
    static float lookupTable[TABLE_SIZE];
    static bool tableInitialized;

    public:
    SineOscillator(uint32_t sampleRate);
    float getSample() override;
};