/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/


template <typename Type>
class CabSimulator
{
public:
	//==============================================================================
	CabSimulator()
	{
		
		
	
	}


	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec)
	{
		// Call the prepare function of the convolver in the processor chain [4].
		processorChain.prepare(spec); // [4]
	}

	//==============================================================================
	template <typename ProcessContext>
	void process(const ProcessContext& context) noexcept
	{
		// Call the process function of the convolver in the processor chain [7]. => Go to the constructor of the Distortion class.
		processorChain.process(context); // [7]
	}

	//==============================================================================
	void reset() noexcept {
		// Call the reset function of the convolver in the processor chain [3].
		processorChain.reset();        // [3]
	}
	void updateIR(float x, float y, float loc)
	{
		if (loc == 1)
		{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::courtyard_recorded_ir_wav, BinaryData::courtyard_recorded_ir_wavSize, true, false, 1024,true);
			DBG("out");
		}
		else if (loc == 2)
		{
			if (x >= 0 && x < 1.8 && y >= 0 && y <= 2)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_00x00y_wav, BinaryData::_00x00y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 1.8 && x < 3.6 && y >= 0 && y < 2)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_15x00y_wav, BinaryData::_15x00y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 3.6 && x < 5.4 && y >= 0 && y < 2)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_30x00y_wav, BinaryData::_30x00y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 5.4 && x < 7.2 && y >= 0 && y < 2)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_45x00y_wav, BinaryData::_45x00y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 7.2 && y >= 0 && y < 2)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_60x00y_wav, BinaryData::_60x00y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 0 && x < 1.8 && y >= 2 && y < 4)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_00x15y_wav, BinaryData::_00x15y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 1.8 && x < 3.6 && y >= 2 && y < 4)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_15x15y_wav, BinaryData::_15x15y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 3.6 && x < 5.4 && y >= 2 && y < 4)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_30x15y_wav, BinaryData::_30x15y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 5.4 && x < 7.2 && y >= 2 && y < 4)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_45x15y_wav, BinaryData::_45x15y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 7.2 && y >= 2 && y < 4)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();

				convolution.loadImpulseResponse(BinaryData::_60x15y_wav, BinaryData::_60x15y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 0 && x < 1.8 && y >= 4 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();

				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_00x30y_wav, BinaryData::_00x30y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 1.8 && x < 3.6 && y >= 4 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();

				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_15x30y_wav, BinaryData::_15x30y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 3.6 && x < 5.4 && y >= 4 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_30x30y_wav, BinaryData::_30x30y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 5.4 && x < 7.2 && y >= 4 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_45x30y_wav, BinaryData::_45x30y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 7.2 && y >= 4 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_60x30y_wav, BinaryData::_60x30y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 0 && x < 1.8 && y >= 6 )
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::_00x45y_wav, BinaryData::_00x45y_wavSize, true, false, 1024, true);
				DBG("Class");
			}
			else if (x >= 1.8 && x < 3.6 && y >= 6)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::_15x45y_wav, BinaryData::_15x45y_wavSize, true, false, 1024, true);
			DBG("Class");
			}
			else if (x >= 3.6 && x < 5.4 && y >= 6)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::_30x45y_wav, BinaryData::_30x45y_wavSize, true, false, 1024, true);
			DBG("Class");
			}
			else if (x >= 5.4 && x < 7.2 && y >= 6)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::_45x45y_wav, BinaryData::_45x45y_wavSize, true, false, 1024, true);
			DBG("Class");
			}
			else if (x >= 7.2 && y >= 6)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::_60x45y_wav, BinaryData::_60x45y_wavSize, true, false, 1024, true);
			DBG("Class");
			}
		}

		else if (loc == 3)
		{
			if (x >= 0 && x < 3 && y >= 0 && y < 3)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x00y00_wav, BinaryData::x00y00_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 3 && x < 6 && y >= 0 && y < 3)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x03y00_wav, BinaryData::x03y00_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 6 && x < 9 && y >= 0 && y < 3)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x06y00_wav, BinaryData::x06y00_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 9 && x<=12 && y >= 0 && y < 3)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x09y00_wav, BinaryData::x09y00_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 12 && y >= 0 && y < 3)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x12y00_wav, BinaryData::x12y00_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 0 && x < 3 && y >= 3 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x00y03_wav, BinaryData::x00y03_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 3 && x < 6 && y >= 0 && y < 3)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x03y03_wav, BinaryData::x00y03_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 6 && x < 9 && y >= 3 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x06y03_wav, BinaryData::x06y03_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 9 && x < 12 && y >= 3 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x09y03_wav, BinaryData::x09y03_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 12 && y >= 3 && y < 6)
			{
				auto dir = File::getCurrentWorkingDirectory();

				int numTries = 0;

				while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
					dir = dir.getParentDirectory();
				auto& convolution = processorChain.template get<convolutionIndex>();
				convolution.loadImpulseResponse(BinaryData::x12y03_wav, BinaryData::x12y03_wavSize, true, false, 1024, true);
				DBG("Hall");
			}
			else if (x >= 0 && x < 3 && y >= 6 && y <= 9)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x00y06_wav, BinaryData::x00y06_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 3 && x < 6 && y >= 6 && y <= 9)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x03y06_wav, BinaryData::x03y06_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 6 && x < 9 && y >= 6 && y <= 9)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x06y06_wav, BinaryData::x06y06_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 9 && x < 12 && y >= 6 && y <= 9)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x09y06_wav, BinaryData::x09y06_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 12 && y >= 6 && y <= 9)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x12y06_wav, BinaryData::x12y06_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 0 && x < 3 && y >= 9 && y <= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x00y09_wav, BinaryData::x00y09_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 3 && x < 6 && y >= 9 && y <= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x03y09_wav, BinaryData::x03y09_wavSize, true, false, 0, true);
			DBG("Hall");
			}
			else if (x >= 6 && x < 9 && y >= 9 && y <= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x06y09_wav, BinaryData::x06y09_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 9 && x < 12 && y >= 9 && y <= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x09y09_wav, BinaryData::x09y09_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 12 && y >= 9 && y <= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x12y09_wav, BinaryData::x12y09_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 0 && x < 3 && y >= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x00y12_wav, BinaryData::x00y12_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 3 && x < 6 && y >= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x03y12_wav, BinaryData::x03y12_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 6 && x < 9 && y >= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x06y12_wav, BinaryData::x06y12_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 9 && x < 12 && y >= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x09y12_wav, BinaryData::x09y12_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
			else if (x >= 12 && y >= 12)
			{
			auto dir = File::getCurrentWorkingDirectory();

			int numTries = 0;

			while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
				dir = dir.getParentDirectory();
			auto& convolution = processorChain.template get<convolutionIndex>();
			convolution.loadImpulseResponse(BinaryData::x12y12_wav, BinaryData::x12y12_wavSize, true, false, 1024, true);
			DBG("Hall");
			}
		}
	}

private:
	// add a juce::dsp::Convolution processor to the processor chain [1] and add its corresponding index in the enum [2].
	enum
	{
		convolutionIndex // [2]
	};

	juce::dsp::ProcessorChain<juce::dsp::Convolution> processorChain; // [1]
};

class AudioEngine
{
public:

	//==============================================================================
	AudioEngine()
	{
	}

	//==============================================================================
	void prepare(const juce::dsp::ProcessSpec& spec) noexcept
	{
		fxChain.prepare(spec);
	}
	void reset() noexcept
	{
		fxChain.reset();
	}

	void getParam(float HoriDist, float VertDist, int Location)
	{
		x = HoriDist;
		y = VertDist;
		loc = Location; 
	}
	void renderNextBlock(AudioBuffer<float>& outputAudio, int startSample, int numSamples)
	{
		auto block = juce::dsp::AudioBlock<float>(outputAudio);
		auto context = juce::dsp::ProcessContextReplacing<float>(block);
		fxChain.get<cabSimulatorIndex>().updateIR(x, y, loc);
		fxChain.process(context);
	}

private:
	//==============================================================================
	enum    /* check here */
	{
		cabSimulatorIndex
	};

	float x =0;
	float y=0;
	int loc=1;
	juce::dsp::ProcessorChain<CabSimulator<float>> fxChain;

	//==============================================================================
};


class FinalProjectAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    FinalProjectAudioProcessor();
    ~FinalProjectAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
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

	float dBGain=-10;
	float HoriDist=0;
	float VertDist=0;
	int Loc=1;
	bool mute=false;
	AudioEngine audioEngine;

	AudioProcessorValueTreeState vts;
	void UpdateParameters();

private:
    //==============================================================================
	dsp::ProcessSpec spec;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FinalProjectAudioProcessor)
};

