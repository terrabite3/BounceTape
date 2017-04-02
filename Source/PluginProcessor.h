/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class BounceTapeAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    BounceTapeAudioProcessor();
    ~BounceTapeAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;


	float getBufferLocationNorm() {
		return mTapes[0]->getSampleNorm();
	}

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BounceTapeAudioProcessor)

private:
	class Tape {
	public:

		Tape() 
			:
			length(0),
			buffer(new float[0]),
			index(0),
			direction(1)
		{}

		Tape(int length) 
			:
			length(length),
			buffer(new float[length]),
			index(0),
			direction(1)
		{
			for (int i = 0; i < length; ++i)
				buffer[i] = 0;
		}

		~Tape() {
			delete[] buffer;
		}

		float swapSample(float newSample) {
			float result = buffer[index];
			buffer[index] = newSample;

			index += direction;
			if (index >= length - 1 && direction >= 1) {
				direction = -1;
			}
			if (index <= 0 && direction <= -1) {
				direction = 1;
			}

			return result;
		}

		float getSampleNorm() {
			return 1.0f * index / length;
		}

	private:
		int length;
		float * buffer;
		int index;
		int direction;
	};

	Tape ** mTapes;

	//float ** mDelayBuffers;
	//int mDelayLength;
	//int * mDelayIndexes;
	//int * mDelayDirections;
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
