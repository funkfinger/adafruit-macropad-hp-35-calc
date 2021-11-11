// TODO: maybe move key lighting into the CalcButton class?

#include <Arduino.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_NeoPixel.h>
#include <HP-35Calc.h>
#include <Fonts/FreeSans9pt7b.h>

#include <PluggableUSBHID.h>
#include <USBKeyboard.h>

USBKeyboard Keyboard;

#include "CalcButton.h"
#include "CalcEncoder.h"
#include "sevenSegThinFont22.h"
#include "usbKeys.h"
#include "usbLogoImage.h"

/* Adafruit Macropad Definitions */
// LEDs
#define PIN_SWITCH            0
#define PIN_SPEAKER_ENABLE   14
#define PIN_SPEAKER          16
#define PIN_ROTB             17
#define PIN_ROTA             18
#define OLED_CS              22
#define OLED_RST             23
#define OLED_DC              24
#define OLED_MOSI            27
#define OLED_SCK             26
#define PIN_NEOPIXEL         19
#define PIXEL_INTERVAL       20

#define NUMPIXELS    12
#define PIN    19

HPCalc calc = HPCalc();

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, OLED_MOSI, OLED_SCK, OLED_DC, OLED_RST, OLED_CS);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

FfButton b(1);
CalcButton a(2, 55, 0, 0);

CalcEncoder encoder;

bool usbMode = false;

// declare functions...
void fadePixels(uint8_t, uint8_t);
void checkButtons(uint8_t);
void checkSwitchForLighting(uint8_t);
void checkEncoder();

void setup() {
  Serial.begin(115200);
  delay(1000);  // RP2040 delay is not a bad idea
  Serial.println("started...");

  pinMode(PIN_SPEAKER, OUTPUT);
  digitalWrite(PIN_SPEAKER, LOW);
  tone(PIN_SPEAKER, 988, 100);  // tone1 - B5
  delay(100);
  tone(PIN_SPEAKER, 1319, 200); // tone2 - E6
  delay(200);

  // Start OLED
  display.begin(0, true); // we dont use the i2c address but we will reset!
  display.display();
  display.setTextSize(1);
  display.setTextWrap(false);
  display.setTextColor(SH110X_WHITE, SH110X_BLACK); // white text, black background
  display.setFont(&sevenThinSegment);
  display.clearDisplay();
  // display.drawBitmap(0, 0, epd_bitmap_pi, 126, 64, 1);
  display.display();
  delay(5000);

  // leds...
  pixels.begin();
}

char buffer[40];

void loop() {
    
  display.clearDisplay();
  checkEncoder();

  if ( usbMode ) {
    pixels.fill( 0x0000FF ); // blue
    display.drawBitmap( 0, 0, usbLogoImage, 126, 64, 1);
  }

  for (uint8_t i = 0; i < NUM_OF_BUTTONS; i++) {
    fadePixels(i, 30);
    checkButtons(i);
    checkSwitchForLighting(i);
  }

  if ( !usbMode ) {
    if ( encoder.rotaryAwaitingCommand() ) {
      display.drawBitmap( 0, 0, encoder.getImage(), 126, 64, 1);
    } else {  
      display.setFont(&sevenThinSegment);
      display.setCursor(0,30);
      display.println(calc.getResultString());
      display.drawBitmap( 105, 50, encoder.getSmallImage(), 21, 13, 1);
    }    
  } else {
  }


  display.display();
  pixels.show();

}

void checkEncoder() {
  encoder.tick();
  if (encoder.doubleClicked()) {
    usbMode = !usbMode; // toggle usb mode
    for (uint8_t i = 0; i < NUM_OF_BUTTONS; i++) {
      if ( usbMode ) {
        calcButtons[i].setDoubleClickTime(0);
      } else {
        calcButtons[i].setDoubleClickTime( FFBUTTON_DOUBLE_CLICK_TIME );
      }
    }
  }
  if ( encoder.clicked() ) {
    calc.enterCommand(encoder.m_command);
  }
  if ( !digitalRead( 0 ) ) {
    pixels.fill( 0x00FF00 ); // green
  }
}

void checkButtons(uint8_t i) {
  calcButtons[i].m_button.update();
  if (calcButtons[i].m_button.click()) {
    if ( !usbMode ) {
      calc.enterCommand(calcButtons[i].m_singleClickKeyCode);
    } else {
      Keyboard.printf(usbKeys[i]);
    }
  }
  if (calcButtons[i].m_button.doubleClick()) {
    if ( !usbMode ) {
      calc.enterCommand(calcButtons[i].m_doubleClickKeyCode);
    }
    pixels.setPixelColor(i, 0xFFFF00);  // make yellow
  }
  if (calcButtons[i].m_button.longClick()) {
    if ( !usbMode ) {
      calc.enterCommand(calcButtons[i].m_longClickKeyCode);
    }
    pixels.setPixelColor(i, 0xFF0000);  // make red
  }
}

void checkSwitchForLighting(uint8_t i) {
  if ( !digitalRead( i ) ) {
    if ( calcButtons[i].m_button.longClick() ) {
      pixels.setPixelColor( i - 1, 0xFF0000 );  // make red
    } else {
      pixels.setPixelColor( i - 1, 255, 255, 255 );
    }
  }
}

unsigned long previousPixelMillis = 0; // for pixel animations...

void fadePixels(uint8_t i, uint8_t fadeBy) {
    // fade pixels...
    unsigned long currentPixelMillis = millis();
    if (currentPixelMillis - previousPixelMillis >= PIXEL_INTERVAL) {
      previousPixelMillis = currentPixelMillis;
      for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        uint32_t c = pixels.getPixelColor(i);
        uint8_t r = (uint8_t)(c >> 16);
        uint8_t g = (uint8_t)(c >> 8);
        uint8_t b = (uint8_t)(c);
        r = (int)r - fadeBy > 0 ? r - fadeBy : 0;
        g = (int)g - fadeBy > 0 ? g - fadeBy : 0;
        b = (int)b - fadeBy > 0 ? b - fadeBy : 0;
        pixels.setPixelColor(i, r, g, b);
      }
    }
}
