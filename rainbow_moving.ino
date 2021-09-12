#include <FastLED.h>

#define NUM_LEDS 20
#define LED_PIN 2

// the LED strip is intuitively represented as an array
// with the FastLED library, and we'll increment hue each
// iteration of loop() to 'move' the rainbow
CRGB leds[NUM_LEDS];
uint8_t hue = 0;

// initial code block that runs once; sets up info for type
// of LED strip we're using + other info to make colors look better
void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
  FastLED.setCorrection(TypicalPixelString);
}

// function that we noted loops infinitely unless coded to stop at event
void loop() {

  // CHSV wraps given HSV value from 255 back to 0
  // if you can imagine the rainbow spectrum wrapping back
  // around at red
  for (int i=0; i < NUM_LEDS; i++){
    leds[i] = CHSV(hue + (i*5), 255, 100);
  }

  // increments hue every 20 miliseconds in another thread
  // while loop() runs in its own thread, accessing whichever
  // version of hue it saw at start of execution
  EVERY_N_MILLISECONDS(20){
    hue++;
  }

  // actually send updated color data to LED strip
  FastLED.show();
}
