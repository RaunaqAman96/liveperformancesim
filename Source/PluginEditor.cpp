/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
FinalProjectAudioProcessorEditor::FinalProjectAudioProcessorEditor (FinalProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	auto width = 800;
	auto height = 600;
    setSize (width, height);
	otherLookAndFeel.setColour(Slider::thumbColourId, Colours::white);

	//Horizontal distance slider
	HoriDistSlider.setLookAndFeel(&otherLookAndFeel);
	HoriDistSlider.setSliderStyle(Slider::LinearHorizontal);
	HoriDistSlider.setTextBoxStyle(Slider::TextBoxRight, true, width * 0.1, height * 0.05);
	HoriDistSlider.setTextBoxIsEditable(true);
	HoriDistSlider.setTextValueSuffix(" m");
	HoriDistSlider.setRange(0, 25, 0.1);
	HoriDistSlider.setValue(processor.HoriDist);
	addAndMakeVisible(HoriDistSlider);

	VertDistSlider.setLookAndFeel(&otherLookAndFeel);
	VertDistSlider.setSliderStyle(Slider::LinearVertical);
	VertDistSlider.setTextBoxStyle(Slider::TextBoxBelow, true, width * 0.1, height * 0.05);
	VertDistSlider.setTextBoxIsEditable(true);
	VertDistSlider.setTextValueSuffix(" m");
	VertDistSlider.setRange(0, 25, 0.1);
	VertDistSlider.setValue(processor.VertDist);
	addAndMakeVisible(VertDistSlider);

	muteToggle.setButtonText("Mute");
	muteToggle.setToggleState(processor.mute, dontSendNotification);
	muteToggle.setCentreRelative(0.48f, 0.45f);
	addAndMakeVisible(muteToggle);

	LocMenu.setText("Location");
	LocMenu.addItem("Outside", 1);
	LocMenu.addItem("Classroom", 2);
	LocMenu.addItem("Auditorium", 3);
	LocMenu.setJustificationType(Justification::centred);
	LocMenu.setCentreRelative(0.47f, 0.15f);
	LocMenu.setSelectedId(processor.Loc);
	addAndMakeVisible(LocMenu);

	gainSlider.setLookAndFeel(&otherLookAndFeel);
	gainSlider.setSliderStyle(Slider::LinearVertical);
	gainSlider.setTextBoxStyle(Slider::TextBoxRight, true, width * 0.2, height * 0.05);
	gainSlider.setTextBoxIsEditable(true);
	gainSlider.setTextValueSuffix(" dB");
	gainSlider.setRange(-50, 10, 0.1);
	gainSlider.setValue(processor.dBGain);
	addAndMakeVisible(gainSlider);

	HoriDistLabel.setText("Horizontal Displacement", dontSendNotification);
	HoriDistLabel.setFont(Font(16.0f, Font::plain));
	HoriDistLabel.setJustificationType(Justification::top);
	addAndMakeVisible(HoriDistLabel);

	VertDistLabel.setText("Vertical Displacement", dontSendNotification);
	VertDistLabel.setFont(Font(16.0f, Font::plain));
	VertDistLabel.setJustificationType(Justification::top);
	addAndMakeVisible(VertDistLabel);

	gainLabel.setText("Gain", dontSendNotification);
	gainLabel.setJustificationType(Justification::centredLeft);
	gainLabel.setFont(Font(16.0f, Font::plain));
	addAndMakeVisible(gainLabel);

	PluginLabel.setText("Live Performance Simulator", dontSendNotification);
	PluginLabel.setJustificationType(Justification::centred);
	PluginLabel.setFont(Font(70.0f, Font::italic));
	addAndMakeVisible(PluginLabel);

	myimage = ImageCache::getFromMemory(BinaryData::bg_jpg, BinaryData::bg_jpgSize);
	band = ImageCache::getFromMemory(BinaryData::Band1_png, BinaryData::Band1_pngSize);
	
	myimage = myimage.rescaled(800, 600, Graphics::ResamplingQuality::highResamplingQuality);
	band = band.rescaled(100, 50, Graphics::ResamplingQuality::highResamplingQuality);

	HoriDistSlider.addListener(this);
	VertDistSlider.addListener(this);
	gainSlider.addListener(this);
	LocMenu.addListener(this);
	muteToggle.addListener(this);
}

FinalProjectAudioProcessorEditor::~FinalProjectAudioProcessorEditor()
{
}

//==============================================================================
void FinalProjectAudioProcessorEditor::paint(Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(AudioProcessorEditor::getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
	g.setColour(AudioProcessorEditor::getLookAndFeel().findColour(Slider::thumbColourId));
	g.drawImageAt(myimage, 0, 0);
	g.drawImageAt(band, 400, 200);
	g.setFont(15.0f);
	val1 = 290 + HoriDistSlider.getValue() * 254 / (HoriDistSlider.getMaximum());
	val2 = 260 + VertDistSlider.getValue() * 282 / (VertDistSlider.getMaximum());
	Point<float> p1(val1, val2);
	g.fillEllipse(p1.x, p1.y, 15, 15);
}


void FinalProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	auto border = 5;
	auto area = getLocalBounds().reduced(border * 4);
	auto areaWidth = area.getWidth();
	auto areaHeight = area.getHeight();
	auto LabelArea = area.removeFromTop(0.1 * areaHeight);
	auto GainArea = area.removeFromLeft(0.2 * areaWidth);
	auto LocArea = area.removeFromLeft(0.6 * areaWidth);
	auto SelArea = area.removeFromTop(0.1 * areaHeight);
	auto MuteArea = area;
	auto GainLabelArea = GainArea.removeFromTop(0.2 * GainArea.getHeight());
	auto HoriDistArea = LocArea.removeFromTop(0.3 * LocArea.getHeight());
	auto HoriLabelArea = HoriDistArea.removeFromBottom(0.6 * HoriDistArea.getHeight());
	auto VertDistArea = LocArea.removeFromLeft(0.2 * LocArea.getWidth());
	auto VertLabelArea = VertDistArea.removeFromTop(0.1 * VertDistArea.getHeight());

	muteToggle.setBounds(MuteArea.reduced(border));
	PluginLabel.setBounds(LabelArea.reduced(border));
	gainLabel.setBounds(GainLabelArea.reduced(border));
	gainSlider.setBounds(GainArea.reduced(border));
	LocMenu.setBounds(SelArea.reduced(border));
	HoriDistSlider.setBounds(HoriDistArea.reduced(border));
	VertDistSlider.setBounds(VertDistArea.reduced(border));
	HoriDistLabel.setBounds(HoriLabelArea.reduced(border));
	VertDistLabel.setBounds(VertLabelArea.reduced(border));
	
}

void FinalProjectAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	if (slider == &gainSlider)
	{
		processor.dBGain = gainSlider.getValue();
	}
	else if (slider == &HoriDistSlider)
	{
		processor.HoriDist = HoriDistSlider.getValue();
		repaint();
	}
	else if (slider == &VertDistSlider)
	{
		processor.VertDist = VertDistSlider.getValue();
		repaint();
	}
}
void FinalProjectAudioProcessorEditor::buttonClicked(Button* button)
{
	if (button == &muteToggle)
	{
		if (muteToggle.getToggleState() == true)
		{
			processor.mute = true;
		DBG("mute");
		}
	else
		processor.mute = false;
	}
	else 
	{     
	}

}

void FinalProjectAudioProcessorEditor::comboBoxChanged(ComboBox* comboBoxThatHasChanged) 
{
	int val;
	val = comboBoxThatHasChanged->getSelectedId();
	if (val == 1)
	{
		processor.Loc = 1;
		DBG("out");
	}
	else if (val == 2)
	{
		processor.Loc = 2;
		DBG("Class");
		HoriDistSlider.setRange(0, 10, 0.1);
		VertDistSlider.setRange(0, 10, 0.1);
	}
	else if (val == 3)
	{
		processor.Loc = 3;
		DBG("Hall");
		HoriDistSlider.setRange(0, 18, 0.1);
		VertDistSlider.setRange(0, 18, 0.1);
	}
}


