// Snapshot Jan20a

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

#include "amrled.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix(); 

void drawGlyph(const byte* glyph, int startCol) {
    matrix.clear();

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (bitRead(glyph[row], 2 - col) == 1) {
                matrix.drawPixel(startCol + col, row, LED_ON);
            }
        }
    }

    matrix.writeDisplay();
}

void setup() {
  matrix.begin(0x70); 
}

void loop() {
  drawGlyph(char0, 0);
  drawGlyph(char1, 4);
  delay(1000);
}