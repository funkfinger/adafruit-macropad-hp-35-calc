#include <Arduino.h>
#include <RotaryEncoder.h>

#include "FfButton.h"
#include "calcEncoderImages.h"
#include "calcEncoderImages-small.h"

#define PIN_ROTB 17
#define PIN_ROTA 18
#define NUM_OF_ENCODER_POSITIONS 18


RotaryEncoder calcEncoder(PIN_ROTA, PIN_ROTB, RotaryEncoder::LatchMode::FOUR3);

// TODO: can this be a lambda function? trying to figure out C++ ugh...
void calcEncoderCheckPosition(uint gpio = -1, uint32_t events = -1) { // params are for pico sdk compatibility
  calcEncoder.tick();
}

class CalcEncoderPosition {
  private:
    uint8_t m_keyCode;
    uint8_t m_imageIndex;
  public:
    CalcEncoderPosition() {};
    CalcEncoderPosition( uint8_t keyCode, uint8_t imageIndex ) {
      m_keyCode = keyCode;
      m_imageIndex = imageIndex;
    }
    const unsigned char* getImage() {
      return calcDisplayBitmapArray[m_imageIndex];
    }
    uint8_t getKeycode() {
      return m_keyCode;
    }

};

class CalcEncoder {
  private:
    int m_encoderPosition = 0;
    int m_encoderIndex = 0;
    bool m_encoderChanged = false;
    bool m_enterCommandMode = false;
    unsigned long m_eventTime;
    unsigned long m_timeInCommandMode = 2000;


  public:
    FfButton m_encoderButton;
    uint8_t m_command;
    CalcEncoderPosition m_positions[NUM_OF_ENCODER_POSITIONS] = {
      CalcEncoderPosition( 14,  0 ),
      CalcEncoderPosition( 59,  1 ),
      CalcEncoderPosition(  0,  2 ),
      CalcEncoderPosition( 56,  3 ),
      CalcEncoderPosition( 42,  4 ),
      CalcEncoderPosition( 58,  5 ),
      CalcEncoderPosition(  2,  6 ),
      CalcEncoderPosition(  3,  7 ),
      CalcEncoderPosition(  4,  8 ),
      CalcEncoderPosition( 34,  9 ),
      CalcEncoderPosition( 11, 10 ),
      CalcEncoderPosition(  8, 11 ),
      CalcEncoderPosition( 43, 12 ),
      CalcEncoderPosition( 46, 13 ),
      CalcEncoderPosition( 10, 14 ),
      CalcEncoderPosition( 40, 15 ),
      CalcEncoderPosition( 12, 16 ),
      CalcEncoderPosition(  6, 17 )
    };
    CalcEncoder() : m_encoderButton( 0, 10, 200, 1200 ) {
      pinMode(PIN_ROTA, INPUT_PULLUP);
      pinMode(PIN_ROTB, INPUT_PULLUP);
      // this is RP2040 specific with this current arduino core - 
      // the arduino way doesn't seem to be working, so using the pico sdk way...
      gpio_set_irq_enabled_with_callback(PIN_ROTA, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &calcEncoderCheckPosition);
      gpio_set_irq_enabled_with_callback(PIN_ROTB, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &calcEncoderCheckPosition);
      // attachInterrupt(digitalPinToInterrupt(PIN_ROTA), calcEncoderCheckPosition, CHANGE);
      // attachInterrupt(digitalPinToInterrupt(PIN_ROTB), calcEncoderCheckPosition, CHANGE);
    };
    
    void tick() {
      calcEncoder.tick();
      m_encoderButton.update();
      unsigned long now = millis();
      if ( now > m_eventTime + m_timeInCommandMode ) {
        m_enterCommandMode = false;
      } 
      int newPos = calcEncoder.getPosition();
      if (m_encoderPosition != newPos) {
        m_eventTime = now;
        m_enterCommandMode = true;
        newPos > m_encoderPosition ? m_encoderIndex-- : m_encoderIndex++;
        m_encoderIndex = m_encoderIndex > NUM_OF_ENCODER_POSITIONS - 1 ? 0 : m_encoderIndex;
        m_encoderIndex = m_encoderIndex < 0 ? NUM_OF_ENCODER_POSITIONS - 1 : m_encoderIndex;
        m_encoderPosition = newPos;
        m_encoderChanged = true;
      } else {
        m_encoderChanged = false;
      }
    };

    bool changed() {
      return m_encoderChanged;
    }

    bool rotaryAwaitingCommand() {
      return m_enterCommandMode;
    }

    bool clicked() {
      bool clicked = m_encoderButton.click();
      if ( clicked ) {
        m_enterCommandMode = false;
        m_command = m_positions[m_encoderIndex].getKeycode();
      }
      return clicked;
    }

    bool clickedWhileAwaitingCommand() {
      if ( m_enterCommandMode && m_encoderButton.click() ) {
        m_command = m_positions[m_encoderIndex].getKeycode();
        m_enterCommandMode = false;
        return true;
      }
      return false;
    }

    bool doubleClicked() {
      return m_encoderButton.doubleClick();
    }

    int getPosition() {
      return m_encoderIndex;
    }
    
    const unsigned char * getImage() {
      return calcDisplayBitmapArray[m_encoderIndex];
    }

    const unsigned char * getSmallImage() {
      return calcDisplaySmallBitmapArray[m_encoderIndex];
    }
    

};