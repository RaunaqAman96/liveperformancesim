/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


class FinalProjectAudioProcessorEditor  : public AudioProcessorEditor
	, private Slider::Listener, private TextButton::Listener, private ComboBox::Listener
{
public:
    FinalProjectAudioProcessorEditor (FinalProjectAudioProcessor&);
    ~FinalProjectAudioProcessorEditor();

    //==============================================================================
	void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FinalProjectAudioProcessor& processor;

	LookAndFeel_V4 otherLookAndFeel;
	Slider HoriDistSlider;
	Slider VertDistSlider;
	Slider gainSlider;
	Label HoriDistLabel;
	Label VertDistLabel;
	Label PluginLabel;
	Label gainLabel;
	ToggleButton muteToggle;
	ComboBox LocMenu;
	int val1=0;
	int val2=0;
	Image myimage;
	Image band;

	void sliderValueChanged (Slider* slider) override;
	void buttonClicked (Button*) override;
	void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FinalProjectAudioProcessorEditor)
};
