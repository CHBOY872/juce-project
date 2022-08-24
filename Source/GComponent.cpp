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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GComponent::GComponent () : juce::AudioAppComponent(otherDeviceManager)
{
    //[Constructor_pre] You can add your own custom stuff here..
    state = stopped;
    otherDeviceManager.initialise(2, 2, nullptr, true);
    audioSettings.reset(new AudioDeviceSelectorComponent(otherDeviceManager, 0, 2, 0, 2, true, true, true, true));
    addAndMakeVisible(audioSettings.get());
    setAudioChannels(2, 2);
    //[/Constructor_pre]

    music_name.reset (new juce::Label ("Music Header",
                                       TRANS("label text")));
    addAndMakeVisible (music_name.get());
    music_name->setFont (juce::Font (30.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    music_name->setJustificationType (juce::Justification::centred);
    music_name->setEditable (false, false, false);
    music_name->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    music_name->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    music_name->setBounds (352, 296, 432, 48);

    music_slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (music_slider.get());
    music_slider->setRange (0, 10, 0);
    music_slider->setSliderStyle (juce::Slider::LinearHorizontal);
    music_slider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    music_slider->addListener (this);

    music_slider->setBounds (247, 416, 688, 32);

    volume_slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (volume_slider.get());
    volume_slider->setRange (0, 10, 0);
    volume_slider->setSliderStyle (juce::Slider::LinearVertical);
    volume_slider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    volume_slider->addListener (this);

    volume_slider->setBounds (792, 184, 103, 216);

    volume_label.reset (new juce::Label ("new label",
                                         TRANS("Volume")));
    addAndMakeVisible (volume_label.get());
    volume_label->setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    volume_label->setJustificationType (juce::Justification::centred);
    volume_label->setEditable (false, false, false);
    volume_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    volume_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    volume_label->setBounds (800, 120, 88, 24);

    play_stop_button.reset (new juce::TextButton ("play stop button"));
    addAndMakeVisible (play_stop_button.get());
    play_stop_button->setButtonText (TRANS("Play"));
    play_stop_button->addListener (this);
    play_stop_button->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff73b7ff));
    play_stop_button->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xff32542b));

    play_stop_button->setBounds (576, 368, 64, 24);

    volume_val_label.reset (new juce::Label ("new label",
                                             juce::String()));
    addAndMakeVisible (volume_val_label.get());
    volume_val_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    volume_val_label->setJustificationType (juce::Justification::centred);
    volume_val_label->setEditable (false, false, false);
    volume_val_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    volume_val_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    volume_val_label->setBounds (800, 152, 80, 24);

    music_length_label.reset (new juce::Label ("new label",
                                               juce::String()));
    addAndMakeVisible (music_length_label.get());
    music_length_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    music_length_label->setJustificationType (juce::Justification::centred);
    music_length_label->setEditable (false, false, false);
    music_length_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    music_length_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    music_length_label->setBounds (152, 416, 94, 32);

    open_button.reset (new juce::TextButton ("open button"));
    addAndMakeVisible (open_button.get());
    open_button->setButtonText (TRANS("Open"));
    open_button->addListener (this);
    open_button->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff767770));
    open_button->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xff32542b));

    open_button->setBounds (496, 368, 64, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
    formatManager.registerBasicFormats();
    transport.addChangeListener(this);
    play_stop_button->setEnabled(false);
    //[/Constructor]
}

GComponent::~GComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    music_name = nullptr;
    music_slider = nullptr;
    volume_slider = nullptr;
    volume_label = nullptr;
    play_stop_button = nullptr;
    volume_val_label = nullptr;
    music_length_label = nullptr;
    open_button = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    shutdownAudio();
    //[/Destructor]
}

//==============================================================================
void GComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == music_slider.get())
    {
        //[UserSliderCode_music_slider] -- add your slider handling code here..
        if (state == playing)
            transport.setPosition(music_slider->getValue());
        //[/UserSliderCode_music_slider]
    }
    else if (sliderThatWasMoved == volume_slider.get())
    {
        //[UserSliderCode_volume_slider] -- add your slider handling code here..
        juce::String new_val = std::to_string((int)(volume_slider->getValue() * 10));
        new_val += " %";
        volume_val_label->setText(new_val, juce::dontSendNotification);
        // change the value of volume_val_label
        //[/UserSliderCode_volume_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == play_stop_button.get())
    {
        //[UserButtonCode_play_stop_button] -- add your button handler code here..
        if (play_stop_button->getButtonText() == "Play") // start or stop music depending on state
        {
            transportStateChanged(starting);
            play_stop_button->setButtonText("Stop");
        }
        else
        {
            transportStateChanged(stopping);
            play_stop_button->setButtonText("Play");
        }
        //[/UserButtonCode_play_stop_button]
    }
    else if (buttonThatWasClicked == open_button.get())
    {
        //[UserButtonCode_open_button] -- add your button handler code here..
        // opening a file

        FileChooser chooser ("Choose a Wav or AIFF File", File::getSpecialLocation(File::userDesktopDirectory), "*.wav; *.mp3");

            //if the user chooses a file
        if (chooser.browseForFileToOpen())
        {
            File myFile;
            //what did the user choose?
            myFile = chooser.getResult();

            //read the file
            AudioFormatReader* reader = formatManager.createReaderFor(myFile);

            if (reader != nullptr)
            {
                //get the file ready to play
                std::unique_ptr<AudioFormatReaderSource> tempSource (new AudioFormatReaderSource (reader, true));

                transport.setSource(tempSource.get());
                transportStateChanged(stopped);

                playSource.reset(tempSource.release());
                music_name->setText(myFile.getFileName(), juce::dontSendNotification);
                music_length_label->setText(std::to_string(transport.getLengthInSeconds()), juce::dontSendNotification);
                play_stop_button->setEnabled(true);
                play_stop_button->setButtonText("Play");
                music_slider->setRange(0, transport.getLengthInSeconds());
            }
        }
        //[/UserButtonCode_open_button]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void GComponent::moved()
{
    //[UserCode_moved] -- Add your code here...
    //[/UserCode_moved]
}

void GComponent::mouseMove (const juce::MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...
    //[/UserCode_mouseMove]
}

void GComponent::mouseEnter (const juce::MouseEvent& e)
{
    //[UserCode_mouseEnter] -- Add your code here...
    //[/UserCode_mouseEnter]
}

void GComponent::mouseExit (const juce::MouseEvent& e)
{
    //[UserCode_mouseExit] -- Add your code here...
    //[/UserCode_mouseExit]
}

void GComponent::mouseDown (const juce::MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    //[/UserCode_mouseDown]
}

void GComponent::mouseDrag (const juce::MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    //[/UserCode_mouseDrag]
}

void GComponent::mouseUp (const juce::MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    //[/UserCode_mouseUp]
}

void GComponent::mouseDoubleClick (const juce::MouseEvent& e)
{
    //[UserCode_mouseDoubleClick] -- Add your code here...
    //[/UserCode_mouseDoubleClick]
}

void GComponent::mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...
    //[/UserCode_mouseWheelMove]
}

void GComponent::focusGained (FocusChangeType cause)
{
    //[UserCode_focusGained] -- Add your code here...

    //[/UserCode_focusGained]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void GComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    transport.prepareToPlay(samplesPerBlockExpected, sampleRate);
}


void GComponent::transportStateChanged(TransportState newState)
{
    if (newState != state)
    {
        state = newState;

        switch (state) {
            case stopped:
                transport.setPosition(0.0);
                break;

            case playing:
                break;

            case starting:
                transport.start();
                break;

            case stopping:
                transport.stop();
                break;
        }

        // Stoppend
    }
}

void GComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();

    transport.getNextAudioBlock(bufferToFill);
}

void GComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

void GComponent::changeListenerCallback (juce::ChangeBroadcaster *source)
{
    if (source == &transport)
    {
        if (transport.isPlaying())
            transportStateChanged(playing);
        else
            transportStateChanged(stopped);
    }
}


void GComponent::changePosition()
{

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1024" initialHeight="768">
  <METHODS>
    <METHOD name="moved()"/>
    <METHOD name="mouseMove (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseEnter (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseExit (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseDoubleClick (const juce::MouseEvent&amp; e)"/>
    <METHOD name="mouseWheelMove (const juce::MouseEvent&amp; e, const juce::MouseWheelDetails&amp; wheel)"/>
    <METHOD name="focusGained (FocusChangeType cause)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="Music Header" id="da2613bad7a614b7" memberName="music_name"
         virtualName="" explicitFocusOrder="0" pos="352 296 432 48" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="30.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="1ca99c450ef81760" memberName="music_slider"
          virtualName="" explicitFocusOrder="0" pos="247 416 688 32" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="e4ce20f64c0a516f" memberName="volume_slider"
          virtualName="" explicitFocusOrder="0" pos="792 184 103 216" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="3afc5a6a1f4358f2" memberName="volume_label"
         virtualName="" explicitFocusOrder="0" pos="800 120 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="18.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="play stop button" id="cc4e974e73f44263" memberName="play_stop_button"
              virtualName="" explicitFocusOrder="0" pos="576 368 64 24" bgColOff="ff73b7ff"
              bgColOn="ff32542b" buttonText="Play" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="8e7119f264b4a84f" memberName="volume_val_label"
         virtualName="" explicitFocusOrder="0" pos="800 152 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="faf96084d3aa4a68" memberName="music_length_label"
         virtualName="" explicitFocusOrder="0" pos="152 416 94 32" edTextCol="ff000000"
         edBkgCol="0" labelText="" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="open button" id="c4c506879a71ecc5" memberName="open_button"
              virtualName="" explicitFocusOrder="0" pos="496 368 64 24" bgColOff="ff767770"
              bgColOn="ff32542b" buttonText="Open" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

