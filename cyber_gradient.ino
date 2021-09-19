#include <FastLED.h>

#define NUM_LEDS 25
#define LED_PIN 2

CRGB leds[NUM_LEDS];
uint8_t paletteIndex = 0;

 // FastLED can interpolate given RGB values at given positions
 // as a smooth gradient which we can then display on our LEDs.
 // The args for each line are: position, R, G, B (each 0-255)
DEFINE_GRADIENT_PALETTE (gradient) {
  0,   244, 0, 200, // purple-pink
  127, 246, 20, 0, // orange-ish yellow
  255, 244, 0, 200// purple-pink
  // need to wrap around at the end for smooth gradient
};

 // Making the color palette object
 CRGBPalette16 palette = gradient;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  FastLED.setCorrection(TypicalPixelString);
}

void loop() {

  // 3rd arg is the starting index
  // 4th arg is the delta, or how much the color should change from LED to LED, or how long
  // the gradient appears, which right now just fills NUM_LEDS on the strip
  // 6th arg is brightness
  // 7th arg is the type of blend, and linear is a 'smooth' blend instead of NOBLEND which is block-y
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, palette, 200, LINEARBLEND);

  // Shift the gradient 1 LED every 20 milliseconds
  // Note that EVERY_N_MILLISECONDS(n) isn't blocking, so other code on the Arduino can run while
  // this block of code is waiting
  EVERY_N_MILLISECONDS(20){
    paletteIndex++;
  }

  FastLED.show();
}
