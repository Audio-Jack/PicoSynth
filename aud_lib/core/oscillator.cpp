<<<<<<< HEAD
#include "oscillator.h"

Oscillator::Oscillator(uint32_t sr) : sampleRate(sr) { }

uint32_t Oscillator::frequencyToIncrement(float freq) {
    // Convert frequency to phase increment: (freq / sampleRate) * 2^32
    return static_cast<uint32_t>((freq / sampleRate) * 4294967296.0f);
}

void Oscillator::setFrequency(float freq) {
    phaseIncrement = frequencyToIncrement(freq);
=======
#include "oscillator.h"

Oscillator::Oscillator(uint32_t sr) : sampleRate(sr) { }

uint32_t Oscillator::frequencyToIncrement(float freq) {
    // Convert frequency to phase increment: (freq / sampleRate) * 2^32
    return static_cast<uint32_t>((freq / sampleRate) * 4294967296.0f);
}

void Oscillator::setFrequency(float freq) {
    phaseIncrement = frequencyToIncrement(freq);
>>>>>>> db68a4e3ae920ef63314933d141f5f7cae8b521e
};