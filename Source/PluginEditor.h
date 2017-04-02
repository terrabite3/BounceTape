/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class BounceTapeAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    BounceTapeAudioProcessorEditor (BounceTapeAudioProcessor&);
    ~BounceTapeAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BounceTapeAudioProcessor& processor;

	Slider mBufferSlider;


	class RepaintTimer : public Timer {
	public:
		RepaintTimer(BounceTapeAudioProcessorEditor *parent) :
			Timer(),
			mParent(parent) {}

		void timerCallback() {
			mParent->repaint();
		}

	private:
		BounceTapeAudioProcessorEditor *mParent;
	};

	RepaintTimer mTimer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BounceTapeAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
