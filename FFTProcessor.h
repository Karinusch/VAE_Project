/*
  ==============================================================================

    FFTProcessor.h
    Created: 21 Jun 2023 4:46:56pm
    Author:  Püppi

  ==============================================================================
*/

#pragma once
#include <juce_dsp/juce_dsp.h>

class FFTProcessor
{
public:
    FFTProcessor();
    ~FFTProcessor();

    void processAudio(float* audioData, int numSamples);

private:
    juce::dsp::FFT* forwardFFT;
    juce::AudioBuffer<float> fftBuffer;
    juce::AudioBuffer<float> fftOutputBuffer;
};
