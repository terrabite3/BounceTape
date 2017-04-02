/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
BounceTapeAudioProcessorEditor::BounceTapeAudioProcessorEditor (BounceTapeAudioProcessor& p)
    : 
	AudioProcessorEditor (&p), 
	processor (p),
	mTimer(RepaintTimer(this))
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);

	mBufferSlider.setSliderStyle(Slider::LinearBar);
	mBufferSlider.setRange(0.0, 1.0, 0);
	mBufferSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	mBufferSlider.setPopupDisplayEnabled(false, this);

	addAndMakeVisible(&mBufferSlider);

	mTimer.startTimerHz(30);
}

BounceTapeAudioProcessorEditor::~BounceTapeAudioProcessorEditor()
{
}

//==============================================================================
void BounceTapeAudioProcessorEditor::paint (Graphics& g)
{
	mBufferSlider.setValue(processor.getBufferLocationNorm());

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);

	//g.drawText("Hello World!", getLocalBounds(), Justification::centred, true);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
	
}

void BounceTapeAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	mBufferSlider.setBounds(40, 30, getWidth() - 60, 20);
}
