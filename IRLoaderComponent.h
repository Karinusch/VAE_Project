/*
  ==============================================================================

    IRLoaderComponent.h
    Created: 22 Jun 2023 4:36:35pm
    Author:  Püppi

  ==============================================================================
*/

#pragma once
#include <juce_dsp/juce_dsp.h>
#include <JuceHeader.h>

class IRLoaderComponent : public juce::Component
{
public:
    IRLoaderComponent();
    ~IRLoaderComponent();

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    void loadIRFile();

    juce::TextButton loadButton;
};


