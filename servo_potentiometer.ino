#include <Servo.h>
 
const int potPin = 2;        // Pin for the potentiometer
const int servoPin9 = 9;     // Pin for servo motor 9
const int servoPin6 = 6;     // Pin for servo motor 6
const int servoPin5 = 5;     // Pin for servo motor 5
const int servoPin3 = 3;     // Pin for servo motor 3

Servo servo9;                // Servo object for servo motor 9
Servo servo6;                // Servo object for servo motor 6
Servo servo5;                // Servo object for servo motor 5
Servo servo3;                // Servo object for servo motor 3

void setup() {
  servo9.attach(servoPin9);  // Initialize servo motor 9
  servo6.attach(servoPin6);  // Initialize servo motor 6
  servo5.attach(servoPin5);  // Initialize servo motor 5
  servo3.attach(servoPin3);  // Initialize servo motor 3
  Serial.begin(9600);        // Initialize serial communication
}

void loop() {
  int potValue = analogRead(potPin);  // Read the value from the potentiometer
  int servoAngle = map(potValue, 0, 1023, 0, 180);  // Map the potentiometer value to servo motor angle
  
  // Set the angle for the four servo motors
  servo9.write(servoAngle);
  servo6.write(servoAngle);
  servo5.write(servoAngle);
  servo3.write(servoAngle);

  delay(15);  // Add a delay to stabilize the angle
}
