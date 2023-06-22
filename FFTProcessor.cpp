/*
  ==============================================================================

    FFTProcessor.cpp
    Created: 21 Jun 2023 4:46:44pm
    Author:  VAE Group

  ==============================================================================
*/

#include "FFTProcessor.h"


/*The constructor FFTProcessor::FFTProcessor() initializes the necessary variables and objects for the FFT processing. 
It sets the size of the FFT to 1024, creates an instance of juce::dsp::FFT called forwardFFT, 
and initializes two buffers: 
  fftBuffer to hold the input audio data and 
  fftOutputBuffer to store the magnitude spectrum output.*/

#include "FFTProcessor.h"

FFTProcessor::FFTProcessor()
{
    int fftSize = 1024;
    forwardFFT = new juce::dsp::FFT(fftSize);
    fftBuffer.setSize(1, fftSize);
    fftOutputBuffer.setSize(2, fftSize / 2 + 1);
}

FFTProcessor::~FFTProcessor()
{
}


/*The processAudio function takes in a pointer to the audio data (audioData) 
and the number of samples (numSamples) to process.*/

//void FFTProcessor::processAudio(float* audioData, int numSamples)
//{
 
    // Copy the audio data to the FFT input buffer
 //   fftBuffer.copyFrom(0, 0, audioData, numSamples);
    
    /*The forwardFFT->performFrequencyOnlyForwardTransform function is called to perform the forward FFT on the data in fftBuffer. 
    This function calculates the FFT in-place on the provided buffer.*/
 //   forwardFFT->performFrequencyOnlyForwardTransform(fftBuffer.getWritePointer(0));

    
    /*The magnitude spectrum is obtained by accessing 
    the write pointer of the fftOutputBuffer using fftOutputBuffer.getWritePointer(0).*/

    // Get the magnitude spectrum
    //juce::dsp::Complex<float>* fftData = forwardFFT.getOutputPointer();
    // Get the magnitude spectrum as a float array
 //   float* magnitudeData = fftOutputBuffer.getWritePointer(0);

    
    /*ATTTENTION!!!The next step, which is missing in the provided code, 
    would be to process the obtained magnitude spectrum. 
    It's likely that this is the part where any desired audio processing or filtering would take place.*/
    
    
    
    // Process the magnitude spectrum

    /*Finally, the magnitude spectrum is copied back to the fftOutputBuffer. 
    The for loop iterates over each sample in the fftOutputBuffer and applies normalization
    by using juce::jmin to limit the magnitude values to a maximum of 1.0. 
    This step may not be necessary depending on the specific requirements of the audio processing.*/

    // Copy the magnitude spectrum to the output buffer
//    for (int i = 0; i < fftOutputBuffer.getNumSamples(); ++i)
//        magnitudeData[i] = juce::jmin(magnitudeData[i], 1.0f);  // Normalize the values if needed

    
                                                                
    // Perform the inverse FFT to obtain the processed audio data
    //forwardFFT->performFrequencyOnlyInverseTransform(fftOutputBuffer.getWritePointer(0));
//    forwardFFT->performRealOnlyInverseTransform(fftOutputBuffer.getWritePointer(0));

    // Copy the processed audio data back to the output buffer
//   float* processedAudioData = fftBuffer.getWritePointer(0);
//    memcpy(audioData, processedAudioData, sizeof(float) * numSamples);


//}


void FFTProcessor::processAudio(float* audioData, int numSamples)
{
    int fftSize = 1024;
    const int hopSize = fftSize / 2;  // Choose hop size as half of FFT size for 50% overlap

    // Process each block of audio data
    for (int pos = 0; pos < numSamples; pos += hopSize)
    {
        // Copy the current block of audio data to the FFT input buffer
        fftBuffer.copyFrom(0, 0, audioData + pos, juce::jmin(numSamples - pos, fftSize));

        // Perform the forward FFT
        forwardFFT->performFrequencyOnlyForwardTransform(fftBuffer.getWritePointer(0));

        // Get the magnitude spectrum
        float* magnitudeData = fftOutputBuffer.getWritePointer(0);

        // Process the magnitude spectrum
        for (int i = 0; i < fftOutputBuffer.getNumSamples(); ++i)
            magnitudeData[i] = juce::jmin(magnitudeData[i], 1.0f);  // Normalize the values if needed

        // Perform the inverse FFT to obtain the processed block of audio data
        forwardFFT->performRealOnlyInverseTransform(fftOutputBuffer.getWritePointer(0));

        // Add the processed block of audio data to the output buffer with overlap-add
        for (int i = 0; i < fftSize; ++i)
        {
            if (pos + i < numSamples)
                audioData[pos + i] += fftBuffer.getReadPointer(0)[i];
        }
    }
}


/*n this updated code, we iterate over the audio data in blocks of size hopSize with a 50% overlap. 
For each block, the forward FFT, magnitude processing, and inverse FFT are performed as before.

However, instead of directly copying the processed audio block back to the output buffer, we use the OLA method. 
The processed block is added to the corresponding positions in the output buffer using the overlap-add approach. 
This ensures that the output blocks are combined properly, taking the overlap into account.*/