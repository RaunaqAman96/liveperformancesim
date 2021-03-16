/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FinalProjectAudioProcessor::FinalProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
	, vts(*this, nullptr, Identifier("FPP"), 
		{ std::make_unique<         
		AudioParameterFloat>(
					 "horidist",              // parameterID
					 "HoriDist",              // parameter name
					 0.0f,                 // minimum value
					 25.0f,              // maximum value
					 0.0f)                // default value
		,std::make_unique<
		AudioParameterFloat>(
					 "vertdist",                // parameterID
					 "VertDist",                // parameter name
					 0.0f,               // minimum value
					 25.0f,              // maximum value
					 0.0f)              // default value
		,std::make_unique<
		AudioParameterFloat>(
					 "gain",              // parameterID
					 "Gain",              // parameter name
					 -50.0f,                 // minimum value
					 30.0f,              // maximum value
					 -10.0f)                // default value
		,std::make_unique<
		AudioParameterFloat>(
					 "loc",                // parameterID
					 "Loc",                // parameter name
					 1,               // minimum value
					 3,              // maximum value
					 1)               // default value
		,std::make_unique<
		AudioParameterFloat>(
					 "mute",                // parameterID
					 "Mute",                // parameter name
					 0,               // minimum value
					 1,              // maximum value
					 0)               // default value
		}
	)

#endif
{
}

FinalProjectAudioProcessor::~FinalProjectAudioProcessor()
{
}

//==============================================================================
const String FinalProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FinalProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FinalProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FinalProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FinalProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FinalProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FinalProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FinalProjectAudioProcessor::setCurrentProgram (int index)
{
}

const String FinalProjectAudioProcessor::getProgramName (int index)
{
    return {};
}

void FinalProjectAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void FinalProjectAudioProcessor::UpdateParameters() 
{
	//vts.getRawParameterValue(<#StringRef parameterID#>)
	HoriDist = *vts.getRawParameterValue("horidist");
	VertDist = *vts.getRawParameterValue("vertdist");
	dBGain = *vts.getRawParameterValue("gain");
	Loc = *vts.getRawParameterValue("loc");
	mute = *vts.getRawParameterValue("mute");
	DBG("PluginProcessor updateParameters");
}

//==============================================================================
void FinalProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	spec.sampleRate = sampleRate;
	spec.maximumBlockSize = samplesPerBlock;
	spec.numChannels = getTotalNumInputChannels();
	audioEngine.prepare(spec);
	UpdateParameters();
	audioEngine.reset();
}

void FinalProjectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FinalProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FinalProjectAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
	
	audioEngine.getParam(HoriDist, VertDist, Loc);
	
	buffer.applyGain(1 - mute);
	buffer.applyGain(Decibels::decibelsToGain(dBGain));
	audioEngine.renderNextBlock(buffer, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
}

//==============================================================================
bool FinalProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FinalProjectAudioProcessor::createEditor()
{
    return new FinalProjectAudioProcessorEditor (*this);
}

//==============================================================================
void FinalProjectAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
	auto state = vts.copyState();
	std::unique_ptr<XmlElement> xml(state.createXml());   // xml
	copyXmlToBinary(*xml, destData);
	DBG("getStateInformation");
}

void FinalProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
	std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	if (xmlState.get() != nullptr)
		if (xmlState->hasTagName(vts.state.getType()))
			vts.replaceState(ValueTree::fromXml(*xmlState));
	DBG("setStateInformation");
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FinalProjectAudioProcessor();
}
