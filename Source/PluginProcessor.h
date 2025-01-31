/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include <map>

//==============================================================================
/**
 * For now, this just does round-robin up. In the future, we shall add random
 * and round-robin down
 */
class MidiSelectProcessor  : public juce::AudioProcessor
{
    // The begin and end of the range that we want to select from
    int lowerNote;
    int upperNote;
    
    // Maps input midi to midi that will be spat out
    std::map<int, int> transformations;
    
    // Note to use for output next
    int currentNote;
    
    // Tries to find a note in the range to map new incoming note to true, on success
    // false on failure. Changes value of currentNote on success∫
    bool findNextNote();
    
public:
    //==============================================================================
    MidiSelectProcessor();
    ~MidiSelectProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (juce::AudioSampleBuffer &, juce::MidiBuffer &) override;

    //==============================================================================
    juce::AudioProcessorEditor *createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const juce::String getParameterName (int index) override;
    const juce::String getParameterText (int index) override;

    const juce::String getInputChannelName (int channelIndex) const override;
    const juce::String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation(juce::MemoryBlock &destData) override;
    void setStateInformation(const void *data, int sizeInBytes) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiSelectProcessor)
};
