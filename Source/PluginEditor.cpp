/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Pfmproject0AudioProcessorEditor::Pfmproject0AudioProcessorEditor (Pfmproject0AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    cacheByColor = processor.byColor->get();
    
    addAndMakeVisible(processor.leftBufferAnalyzer);
    addAndMakeVisible(processor.rightBufferAnalyzer);

processor.leftBufferAnalyzer.setInterceptsMouseClicks(false, false);
processor.rightBufferAnalyzer.setInterceptsMouseClicks(false, false);
    
    setSize (400, 300);
    
    startTimerHz(24);
}

Pfmproject0AudioProcessorEditor::~Pfmproject0AudioProcessorEditor()
{
    Pfmproject0AudioProcessor::UpdateAutomatableParameter(processor.shouldPlaySound, false);
 //   processor.shouldPlaySound = false;
      // processor.shouldPlaySound->beginChangeGesture(); processor.shouldPlaySound->setValueNotifyingHost(false);
       // processor.shouldPlaySound->endChangeGesture();
}

void Pfmproject0AudioProcessorEditor::timerCallback()
{
    update();
}
void Pfmproject0AudioProcessorEditor::update()
{
    cacheByColor = processor.byColor->get();
    repaint();
}

//==============================================================================
void Pfmproject0AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId).interpolatedWith(Colours::seagreen, cacheByColor));

    g.setColour (Colours::rebeccapurple);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
    getLocalBounds().reduced(4).removeFromBottom(3).expanded(2); //rectangle class
}

void Pfmproject0AudioProcessorEditor::resized()
{
    
    processor.leftBufferAnalyzer.setBounds(0, 0, getWidth(), getHeight() * 0.5);
    
    processor.rightBufferAnalyzer.setBounds(0, getHeight() * 0.5, getWidth(), getHeight() * 0.5);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
void Pfmproject0AudioProcessorEditor::mouseUp(const MouseEvent &e)
{
   
Pfmproject0AudioProcessor::UpdateAutomatableParameter(processor.shouldPlaySound, !processor.shouldPlaySound->get());
   // processor.shouldPlaySound->beginChangeGesture();
    //processor.shouldPlaySound->setValueNotifyingHost( !processor.shouldPlaySound->get());
    //processor.shouldPlaySound->endChangeGesture();
}
    //DBG( "mouseUp" );
   // processor.shouldPlaySound = false;
   
    /**
    if( processor.shouldPlaySound)
    {
        processor.shouldPlaySound = false;
    }
    else
    {
        processor.shouldPlaySound = true;
    }
     
     */

void Pfmproject0AudioProcessorEditor::mouseDown(const MouseEvent &e)
{
    //DBG( "mouseDown" );
   //     processor.shouldPlaySound = true;
    lastClickPos = e.getPosition();
}

void Pfmproject0AudioProcessorEditor::mouseDrag(const MouseEvent &e)
{
    auto clickPos = e.getPosition();
    //DBG(clickPos.toString() );
    auto difY = jlimit (-1.0, 1.0, -(clickPos.y - lastClickPos.y) / 200.0);
    difY = jmap(difY, -1.0, 1.0, 0.0, 1.0);
    DBG("difY:" << difY);
    
    Pfmproject0AudioProcessor::UpdateAutomatableParameter(processor.byColor, difY);
    cacheByColor = processor.byColor->get();
    repaint();
    update();
}
