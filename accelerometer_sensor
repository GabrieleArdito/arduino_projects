#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

// Library initialization with 16x2 size settings
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

    Wire.begin();
  Serial.begin(9600);
  accelgyro.initialize();

}

void loop() {
     // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    //float pitch = accToAngle(ay, ax, az);
    float roll = accToAngle(ax, ay, az);

    //Serial.print("Pitch: "); Serial.print(pitch);
    Serial.print("\tRoll: "); Serial.print(roll);
    Serial.print("\n");
    lcd.setCursor(0,0);
    lcd.print(roll);
    delay(500);

}
float accToAngle(float a, float b, float c){
  float d = sqrt(a*a + c*c);
  float ang = atan2(b, d);
  ang = (ang * 180.0)/ PI;
  return ang;
}
