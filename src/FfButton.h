// referenced for inspiration...
// https://www.sigmdel.ca/michel/program/esp8266/arduino/switch_debouncing_en.html

#ifndef FfButton_h
#define FfButton_h

#include <Arduino.h>

#define BUTTON_DOWN 0
#define BUTTON_UP 1
#define FFBUTTON_DOUBLE_CLICK_TIME 100

class FfButton {
  public:
    FfButton (
        uint8_t pin, 
        unsigned long debounceTime = 10, 
        unsigned long doubleClickTime = FFBUTTON_DOUBLE_CLICK_TIME,
        unsigned long longClickTime = 1200
      ) : m_pin( pin ) {

      m_debounceTime = debounceTime;
      m_doubleClickTime = doubleClickTime;
      m_longClickTime = longClickTime;

      if ( m_pin > 0 ) {
        pinMode( m_pin, INPUT_PULLUP );
      }
    }

    void setDoubleClickTime(unsigned long time) {
      m_doubleClickTime = time;
    }

    void update() {
      // if ( m_pin == 254 ) return; // bad pin means not set correctly...
      m_changed = false;
      unsigned long now = millis();
      bool nowPinState = digitalRead( m_pin );
      switch ( m_currentState ) {
        case WAIT_CLICK:
          m_clickCount = 0;
          if ( nowPinState == BUTTON_DOWN ) {
            m_currentState = DEBOUNCE_CLICK;
            m_eventTime = now;
          }
          break;

        case DEBOUNCE_CLICK:
          if ( now > m_eventTime + m_debounceTime ) {
            m_currentState = WAIT_RELEASE;
            m_eventTime = now;
          }
          break;
          
        case WAIT_RELEASE:
          if ( nowPinState == BUTTON_UP ) {
            if ( now > m_eventTime + m_longClickTime ) {
              m_clickCount = 100; // no multi-click over 99 - it means long click
            }
            m_currentState = DEBOUNCE_RELEASE;
            m_eventTime = now;
          }
          break;

        case DEBOUNCE_RELEASE:
          if ( now > m_eventTime + m_debounceTime ) {
            if (m_clickCount >= 100) {
              m_currentState = WAIT_CLICK;
              m_changed = true;
            }
            m_currentState = WAIT_MULTI_PRESS;
            m_eventTime = now;
            m_clickCount++;
            Serial.println(m_clickCount);
          }
          break;

        case WAIT_MULTI_PRESS:
          if ( nowPinState == BUTTON_DOWN ) {
            m_currentState = DEBOUNCE_CLICK;
            m_eventTime = now;
          } else {
            if ( now > m_eventTime + m_doubleClickTime ) {
              m_changed = true;
              m_currentState = WAIT_CLICK;
            }
          }
          break;

        // default:
          // nothing?
      }
    }

    bool pressed() {
      return m_changed && (m_clickCount == 1);
    }

    bool click() {
      return pressed();
    }

    // bool released() {
    //   return m_changed && (m_currentState == UP);
    // }

    bool doubleClick() {
      return m_changed && (m_clickCount > 1 && m_clickCount < 100);
    }

    bool longClick() {
      return m_changed && (m_clickCount >= 100);
    }

  private:
    enum buttonStates { WAIT_CLICK, WAIT_RELEASE, WAIT_MULTI_PRESS, DEBOUNCE_CLICK, DEBOUNCE_RELEASE };
    const uint8_t m_pin {};
    buttonStates m_currentState = WAIT_CLICK;
    unsigned long m_eventTime;
    unsigned long m_debounceTime;
    unsigned long m_doubleClickTime;
    unsigned long m_longClickTime;
    bool m_changed = false;
    int m_clickCount = 0;
};

#endif
