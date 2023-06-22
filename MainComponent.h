/*
  ==============================================================================

    MainComponent.h
    Created: 22 Jun 2023 5:08:13pm
    Author:  Püppi

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "IRLoaderComponent.h"

class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent();

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    IRLoaderComponent irLoader;
};