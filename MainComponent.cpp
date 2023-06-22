/*
  ==============================================================================

    MainComponent.cpp
    Created: 22 Jun 2023 5:08:00pm
    Author:  Püppi

  ==============================================================================
*/

#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(irLoader);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(juce::Graphics& g)
{
    // Customize the appearance of the main component if needed
}

void MainComponent::resized()
{
    // Position and size the irLoader component within the main component
    irLoader.setBounds(getLocalBounds());
}
