#include "SSD1306Wire.h"  // legacy include: `#include "SSD1306.h"` https://github.com/ThingPulse/esp8266-oled-ssd1306
#include <Arduino.h>
#include <SPI.h>

using namespace std;

#define     ETH_RST         4
#define     ETH_CS          5
#define     ETH_SCLK       18
#define     ETH_MISO       23
#define     ETH_MOSI       19
#define     OLED_SCL       22
#define     OLED_SDA       21

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, OLED_SDA, OLED_SCL);


void setup() {
  // put your setup code here, to run once:
  display.init(); // Initialize screen

  //display.invertDisplay(); // Inverted display mode

  display.setContrast(100, 50, 64);
  // Convenience method to access
  // display.setBrightness(15);

  Serial.begin(115200);
  Serial.println("ESP32 W5500 Start");

  display.setFont(ArialMT_Plain_16); // Font and size
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 0, "Hellow World!");

  display.display();
}


void loop() {
  // put your main code here, to run repeatedly:
}
