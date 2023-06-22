/*
  ==============================================================================

    IRLoaderComponent.cpp
    Created: 22 Jun 2023 4:36:07pm
    Author:  Püppi

  ==============================================================================
*/

#include "IRLoaderComponent.h"
#include <JuceHeader.h>

#include "IRLoaderComponent.h"

IRLoaderComponent::IRLoaderComponent()
{
    loadButton.setButtonText("Load IR File");
    loadButton.onClick = [this]() { loadIRFile(); };

    addAndMakeVisible(loadButton);
}

IRLoaderComponent::~IRLoaderComponent()
{
}

void IRLoaderComponent::paint(juce::Graphics& g)
{
    // Customize the appearance of the component if needed
}

void IRLoaderComponent::resized()
{
    // Position and size the loadButton within the component
    loadButton.setBounds(getLocalBounds().reduced(10));
}

void IRLoaderComponent::loadIRFile()
{
    juce::FileChooser fileChooser("Select an IR file...", {}, "*.wav");

    if (fileChooser.browseForFileToOpen())
    {
        juce::File selectedFile = fileChooser.getResult();
        // Process the selected file (load the IR, perform any necessary operations, etc.)
        // Example: Display the selected file path
        juce::String filePath = selectedFile.getFullPathName();
        juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::InfoIcon,
            "Selected IR File",
            "File path: " + filePath);
    }
}

