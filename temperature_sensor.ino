#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2 // Connect the sensor pin to Arduino pin 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  sensors.requestTemperatures();
  float temperatureCelsius = sensors.getTempCByIndex(0);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureCelsius);
  lcd.print(" C");

  delay(1000);
}
