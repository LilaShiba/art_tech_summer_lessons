#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 2

// here you set how many led's are in your strip, what pin your connected to, and type of neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// set color by addressing
void loop() {
  ringColor(strip.Color(0,0,255),50);
  ringColor(strip.Color(0,255,255),25);
  ringColor(strip.Color(0,255,100),10);
  ringColor(strip.Color(0,255,0),25);
}

// a loop to automate calling nth neopixels 
void ringColor ( uint32_t color, uint8_t wait ) {
    for ( int i=0 ; i < 24 ; i++ ) {
        strip.setPixelColor( i, color );
        strip.show();
        delay(wait);
    }
}
