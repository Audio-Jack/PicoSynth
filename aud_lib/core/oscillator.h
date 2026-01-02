// Base class for oscillators
#pragma once
#include <cstdint>

class Oscillator {
protected:
        // phase accumulator: tracks position in waveform cycle (0 to 2^32)
        uint32_t phaseAccumulator = 0;

        //Phase increment: added each smple to change frequency
        uint32_t phaseIncrement = 0;

        // Audio sample sample rate ( e.g., `44100` for 44.1kHz)
        uint32_t sampleRate;

        // Converts frequency in Hz to phase increment value
        virtual uint32_t frequencyToIncrement(float freq);

public:
    // Constructor: requires sample rate
    Oscillator(uint32_t sr);

    // Destructor (virttual for proper cleanup)
    virtual ~Oscillator() = default;

    // Pure virtual function: each waveform MUST implement this
    // Returns a single audio sample between -1.0 and 1.0
    virtual float getSample() = 0;

    // Sets oscillator frequency in Hz
    void setFrequency(float freq);

    // Resets phase to start waveform
    void resetPhase() { phaseAccumulator = 0; }

    // Get current sample rate
    uint32_t getSampleRate() const { return sampleRate; }

    //Disable copying
    Oscillator(const Oscillator&) = delete;
    Oscillator& operator=(const Oscillator&) = delete;
};