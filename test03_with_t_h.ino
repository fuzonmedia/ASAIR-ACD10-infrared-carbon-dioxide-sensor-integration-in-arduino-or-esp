#include "DHT20.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#define Addr 0x2A
u8 i2C[6]={0};
int CO2=0;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2); 
DHT20 DHT(&Wire);
void setup()
{ 
   // initialize the LCD
  lcd.begin(); // Init with pin default ESP8266 or ARDUINO
  // lcd.begin(0, 2); //ESP8266-01 I2C with pin 0-SDA 2-SCL
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Setting Up..");
  lcd.setCursor(0, 1);
  lcd.print("");
  Wire.begin();       
  Serial.begin(115200); 
    // for sensor 
  #if defined(ESP8266) || defined(ESP32)
  DHT.begin(4, 5);  //  select your pin numbers here
#else
  DHT.begin();
#endif
  delay (100);
}
void loop()
{
  Wire.beginTransmission(Addr);
  Wire.write(0x03);
  Wire.write(0x00);
  Wire.endTransmission();
  delay (80);
  Wire.requestFrom(Addr, 9);
  if (Wire.available() > 0)
  Wire.readBytes(i2C, 6);
  CO2=((i2C[0])<<24)|((i2C[1])<<16)|((i2C[3])<<8)|(i2C[4]);
  Serial.print("CO2：");
  Serial.print(CO2);
  Serial.print("PPM");
  lcd.clear();
  lcd.setCursor(0, 0);
      // print message
  lcd.print("Co2: "+String(CO2)+ " PPM");
  Serial.println();
  int status = DHT.read();
  if(status == DHT20_OK) {
    float temperature = DHT.getTemperature();
    float humidity = DHT.getHumidity();
    Serial.println(temperature);
    lcd.setCursor(0, 1);
    lcd.print("T: "+String(temperature,2)+ " C");
  }
  delay(5000);
} 
