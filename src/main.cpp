/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (18)
#define BMP_MISO (23)
#define BMP_MOSI (19)
#define BMP_CS1   (5)
#define BMP_CS2   (17)
#define BMP_CS3   (16)

//Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
Adafruit_BMP280 bmp1(BMP_CS1, BMP_MOSI, BMP_MISO,  BMP_SCK);
Adafruit_BMP280 bmp2(BMP_CS2, BMP_MOSI, BMP_MISO,  BMP_SCK);
Adafruit_BMP280 bmp3(BMP_CS3, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if (!bmp1.begin()) {
    Serial.println(F("Could not find a valid BMP280-1 sensor, check wiring!"));
   // while (1);
  }

  /* Default settings from datasheet. */
  bmp1.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  delay(1000);
  if (!bmp2.begin()) {
    Serial.println(F("Could not find a valid BMP280-2 sensor, check wiring!"));
    //while (1);
  }

  /* Default settings from datasheet. */
  bmp2.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  delay(1000);
if (!bmp3.begin()) {
    Serial.println(F("Could not find a valid BMP280-3 sensor, check wiring!"));
    //while (1);
  }

  /* Default settings from datasheet. */
  bmp3.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  delay(1000);
//-------------------------------------------------------------------------

} 
void loop() {
    Serial.print(F("Temperature = "));
    Serial.print(bmp1.readTemperature());
    Serial.println(" *C");
    Serial.print(F("Temperature = "));
    Serial.print(bmp2.readTemperature());
    Serial.println(" *C");
    Serial.print(F("Temperature = "));
    Serial.print(bmp3.readTemperature());
    Serial.println(" *C");
    //----------------------------------
    Serial.print(F("Pressure = "));
    Serial.print(bmp1.readPressure());
    Serial.println(" Pa");
    Serial.print(F("Pressure = "));
    Serial.print(bmp2.readPressure());
    Serial.println(" Pa");
    Serial.print(F("Pressure = "));
    Serial.print(bmp3.readPressure());
    Serial.println(" Pa");
    //---------------------------------
    Serial.print(F("Approx altitude = "));
    Serial.print(bmp1.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");
    Serial.print(F("Approx altitude = "));
    Serial.print(bmp2.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");
    Serial.print(F("Approx altitude = "));
    Serial.print(bmp3.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");
    //---------------------------------
    Serial.println();
    delay(2000);
}