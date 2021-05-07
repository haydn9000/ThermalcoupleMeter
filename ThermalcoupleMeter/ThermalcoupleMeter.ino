#include <Adafruit_MAX31855.h>
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"` https://github.com/ThingPulse/esp8266-oled-ssd1306
#include <Arduino.h>
#include <SPI.h>

using namespace std;

// Thermocouple instance with software SPI on these three digital IO pins bellow.
#define MAXCLK 5
#define MAXCS 18
#define MAXDO 19

#define OLED_SDA 21
#define OLED_SCL 22

// initialize the Thermocouple
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

// Initialize the OLED display using Wire library
SSD1306Wire display(0x3c, OLED_SDA, OLED_SCL);


void setup()
{
  Serial.begin(9600);

  while (!Serial)
    delay(1); // wait for Serial on Leonardo/Zero, etc

  Serial.println("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
  Serial.print("Initializing sensor...");
  if (!thermocouple.begin())
  {
    Serial.println("ERROR.");
    while (1)
      delay(10);
  }
  Serial.println("DONE.");

  //  =======================================================
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


void loop()
{
  // put your main code here, to run repeatedly:

  // basic readout test, just print the current temp
  Serial.print("Internal Temp = ");
  Serial.println(thermocouple.readInternal());

  double c = thermocouple.readCelsius();
  if (isnan(c))
  {
    Serial.println("Something wrong with thermocouple!");
  }
  else
  {
    Serial.print("C = ");
    Serial.println(c);
  }
  //Serial.print("F = ");
  //Serial.println(thermocouple.readFahrenheit());

  delay(1000);
}
