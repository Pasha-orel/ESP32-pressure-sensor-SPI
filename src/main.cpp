#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 18
#define BMP_MISO 19
#define BMP_MOSI 23

#define BMP_CS1 5
#define BMP_CS2 33
#define BMP_CS3 25

//-------------------------------------------------------
Adafruit_BMP280 bmp1(BMP_CS1, BMP_MOSI, BMP_MISO, BMP_SCK);
Adafruit_BMP280 bmp2(BMP_CS2, BMP_MOSI, BMP_MISO, BMP_SCK);
Adafruit_BMP280 bmp3(BMP_CS3, BMP_MOSI, BMP_MISO, BMP_SCK);
//-------------------------------------------------------
static const int spiClk = 1000000; // 1 MHz
//uninitalised pointers to SPI objects
SPIClass * vspi = NULL;
SPIClass * hspi = NULL;
//-------------------------------------------------------
void setup() {
  Serial.begin(9600);
  //-----------------------------------------------------
  vspi = new SPIClass(VSPI);
  //initialise vspi with default pins
  //SCLK = 18, MISO = 19, MOSI = 23, SS = 5
  vspi->begin();
  //SPI.begin();
  //----------------------------------------------------  
  Serial.println("Starting BMP280 device 1...");
  bmp1.begin();
  if (!bmp1.begin()) {
    Serial.println("Sensor BMP280 device 1 was not found.");
    //while (1);
  }
  Serial.println("Initialize BMP280 1 completed.");
  delay(2000);

  Serial.println("Starting BMP280 device 2...");

  if (!bmp2.begin()) {
    Serial.println("Sensor BMP280 device 2 was not found.");
    //while (1);
  }
  Serial.println("Initialize BMP280 2 completed.");
  delay(2000);

  Serial.println("Starting BMP280 device 3...");

  if (!bmp3.begin()) {
    Serial.println("Sensor BMP280 device 3 was not found.");
    //while (1);
  }
  Serial.println("Initialize BMP280 3 completed.");
  delay(2000);
}  

void loop() {
  float pressure = bmp1.readPressure() / 100.0;
  Serial.print("Pressure 1 = ");
  Serial.print(pressure);
  Serial.print("Pa,   ");
  delay(100);

  float pressure2 = bmp2.readPressure() / 100.0;
  Serial.print("Pressure 2 = ");
  Serial.print(pressure2);
  Serial.print("Pa,   ");
  delay(100);

  float pressure3 = bmp3.readPressure() / 100.0;
  Serial.print("Pressure 3 = ");
  Serial.print(pressure3);
  Serial.print("Pa");
  Serial.println();
  delay(1000);
  // for test home

}
