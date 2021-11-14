#include <Arduino.h>
#include "FfButton.h"


// #define NUM_OF_BUTTONS 35
#define NUM_OF_BUTTONS 12

#define BUTTON_CODE_X_TO_Y      6
#define BUTTON_CODE_LOG         4
#define BUTTON_CODE_LN          3
#define BUTTON_CODE_E_TO_X      2
#define BUTTON_CODE_CLR         0
#define BUTTON_CODE_SQR_X       46
#define BUTTON_CODE_ARC         44
#define BUTTON_CODE_SIN         43
#define BUTTON_CODE_COS         42
#define BUTTON_CODE_TAN         40
#define BUTTON_CODE_ONE_OVER_X  14
#define BUTTON_CODE_X_SWAP_Y    12
#define BUTTON_CODE_ROLL_DOWN   11
#define BUTTON_CODE_STO         10
#define BUTTON_CODE_RCL         8
#define BUTTON_CODE_ENTER       62
#define BUTTON_CODE_CHS         59
#define BUTTON_CODE_EEX         58
#define BUTTON_CODE_CLX         56
#define BUTTON_CODE_MINUS       54
#define BUTTON_CODE_SEVEN       52
#define BUTTON_CODE_EIGHT       51
#define BUTTON_CODE_NINE        50
#define BUTTON_CODE_PLUS        22
#define BUTTON_CODE_FOUR        20
#define BUTTON_CODE_FIVE        19
#define BUTTON_CODE_SIX         18
#define BUTTON_CODE_TIMES       30
#define BUTTON_CODE_ONE         28
#define BUTTON_CODE_TWO         27
#define BUTTON_CODE_THREE       26
#define BUTTON_CODE_DIVIDED     38
#define BUTTON_CODE_ZERO        36
#define BUTTON_CODE_DECIMAL     35
#define BUTTON_CODE_PI          34

class CalcButton {
  private:
    uint8_t m_pin;
  public:
    FfButton m_button;
    CalcButton();
    CalcButton( uint8_t p, uint8_t sckc, uint8_t dckc, uint8_t lckc )  : m_button(p) {
      m_singleClickKeyCode = sckc;
      m_doubleClickKeyCode = dckc;
      m_longClickKeyCode = lckc;
      m_pin = p;
    }
    uint8_t m_singleClickKeyCode;
    uint8_t m_doubleClickKeyCode;
    uint8_t m_longClickKeyCode;

    void setDoubleClickTime(unsigned long time) {
      m_button.setDoubleClickTime( time );
    }

};

CalcButton calcButtons[NUM_OF_BUTTONS] = {
  CalcButton(1,   BUTTON_CODE_SEVEN,   BUTTON_CODE_PLUS, 0),
  CalcButton(2,   BUTTON_CODE_EIGHT,   BUTTON_CODE_PI, 0),
  CalcButton(3,   BUTTON_CODE_NINE,    BUTTON_CODE_CLR, 0),
  CalcButton(4,   BUTTON_CODE_FOUR,    BUTTON_CODE_MINUS, 0),
  CalcButton(5,   BUTTON_CODE_FIVE,    BUTTON_CODE_X_SWAP_Y, 0),
  CalcButton(6,   BUTTON_CODE_SIX,     BUTTON_CODE_STO, 0),
  CalcButton(7,   BUTTON_CODE_ONE,     BUTTON_CODE_DIVIDED, 0),
  CalcButton(8,   BUTTON_CODE_TWO,     BUTTON_CODE_ROLL_DOWN, 0),
  CalcButton(9,   BUTTON_CODE_THREE,   BUTTON_CODE_RCL, 0),
  CalcButton(10,  BUTTON_CODE_ZERO,    BUTTON_CODE_TIMES, 0),
  CalcButton(11,  BUTTON_CODE_DECIMAL, BUTTON_CODE_CHS, 0),
  CalcButton(12,  BUTTON_CODE_ENTER,   0, 0)
};