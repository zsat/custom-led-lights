#include <FastLED.h>

#define NUM_LEDS 20
#define LED_PIN 2

// the LED strip is intuitively represented as an array
// with the FastLED library, and we'll increment hue each
// iteration of loop() to 'move' the rainbow
CRGB leds[NUM_LEDS];
uint8_t hue = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
  FastLED.setCorrection(TypicalPixelString);
}

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
