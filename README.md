# Adafruit Macropad RP2040 HP Calculator

!!! WORK IN PROGRESS !!!

It's not quite done, but - more coding to do, but I've been working on getting HP's first pocket calculator running as an emulator on the [Adafruit Macropad RP2040](https://www.adafruit.com/product/5100) keypad. The bulk of this code comes from an Instructables project where [enurdag](https://www.instructables.com/member/enurdag/) emulated the HP-35 with an Arduino and a TFTLCD touchscreen shield. Very cool!

The HP-35 has 35 keys, the macropad has 9, so I am using double clicks to access the more used features, and am using the rotary encoder to access everything else. Also, there is a USB input mode (entered by double clicking the encoder button) where you can turn the Macropad into what it was more intended to be, a computer interface - currently a number pad with the enter key.

I've abstracted the HP-35 core that [enurdag](https://www.instructables.com/member/enurdag/) created / adapted? into it's own [Arduino library](https://github.com/funkfinger/HP-35-Arduino-Calc) - so you should be able to use that in projects other than this one...

Also, I'm using [Platformio](https://platformio.org) for my dev stack - I prefer it far more than the Arduino IDE, but it does come with it's quirks... in this project, I had to make accommodations for the Raspberry Pi core that Platformio uses (VS the one that Adafruit uses) - if you're digging into the code, that may be one of the really weird things you notice - the others being my total mis-understanding of C and C++...

- Created my own 7-segment font using [this tool](https://tchapi.github.io/Adafruit-GFX-Font-Customiser/).
- [legends for relegendable caps](https://docs.google.com/document/d/1mupzLa-DK0bMKQjIS_BeLYIE813HpPON7XwUicwWx2c/edit?usp=sharing)
- Images were converted with [this tool](https://javl.github.io/image2cpp/)

### BOM

- [Adafruit MACROPAD RP2040](https://www.adafruit.com/product/5100) or [Here?](https://www.digikey.com/en/products?s=N4IgjCBcoLQBxVAYygMwIYBsDOBTANCAPZQDa4ArAEwIC6AvvYVWSBWAAwcgNA)
- [Relegendable Plastic Keycaps for MX Compatible Switches 10 pack](https://www.adafruit.com/product/5039)

## HP 35 calculator links...

- HP-35 Scientific Calculator Emulator With Arduino Uno: https://www.instructables.com/member/enurdag/
- About the HP-35: https://en.wikipedia.org/wiki/HP-35 - http://www.jacques-laporte.org/HP203520Saga.htm
- A HP-35 simulator (emulator?): https://www.hpmuseum.org/simulate/hp35sim/hp35sim.htm
- Reverse engineering the HP-35 ROM based on a photo of the physical chip - really cool!: http://www.pmonta.com/calculators/hp-35/
- HP Calculator microassembler and simulator: http://www.brouhaha.com/~eric/software/casmsim/ - replaced by https://nonpareil.brouhaha.com
- Some general cool info about the HP-35: https://www.keesvandersanden.nl/calculators/hp35.php
- HP-35 ROM: http://home.citycable.ch/pierrefleur/Jacques-Laporte/HP35%20ROM.htm
