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
using namespace juce;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GComponent  : public AudioAppComponent,
                    public ChangeListener,
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
    void focusGained (FocusChangeType cause) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AudioDeviceManager otherDeviceManager;
    std::unique_ptr <AudioDeviceSelectorComponent> audioSettings;

    enum TransportState
    {
        stopped,
        playing,
        starting,
        stopping
    };

    double current_position_sec;
    double k; // k in defining current music position for slider
    TransportState state;


    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> playSource;
    AudioTransportSource transport;

    void transportStateChanged(TransportState newState);
    void changeListenerCallback (juce::ChangeBroadcaster *source) override;

    void changePosition();
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

