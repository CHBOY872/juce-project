/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GComponent  : public juce::AudioAppComponent,
                    public juce::Slider::Listener,
                    public juce::Button::Listener
{
public:
    //==============================================================================
    GComponent ();
    ~GComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void moved() override;
    void mouseMove (const juce::MouseEvent& e) override;
    void mouseEnter (const juce::MouseEvent& e) override;
    void mouseExit (const juce::MouseEvent& e) override;
    void mouseDown (const juce::MouseEvent& e) override;
    void mouseDrag (const juce::MouseEvent& e) override;
    void mouseUp (const juce::MouseEvent& e) override;
    void mouseDoubleClick (const juce::MouseEvent& e) override;
    void mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    
    enum TransportState
    {
        stopped,
        starting,
        stopping
    };
    
    TransportState state;
    
    std::unique_ptr<juce::AudioFormatManager> formatManager;
    std::unique_ptr<juce::AudioFormatReaderSource> playSource;
    std::unique_ptr<juce::FileChooser> fileChooser;
    juce::AudioTransportSource transport;
    
    void transportStateChanged(TransportState newState);
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> music_name;
    std::unique_ptr<juce::Slider> music_slider;
    std::unique_ptr<juce::Slider> volume_slider;
    std::unique_ptr<juce::Label> volume_label;
    std::unique_ptr<juce::TextButton> play_stop_button;
    std::unique_ptr<juce::Label> volume_val_label;
    std::unique_ptr<juce::Label> music_length_label;
    std::unique_ptr<juce::TextButton> open_button;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

