const int waterSensorPin = A0;  // Pin for the water level sensor
const int redPin = 11;         // Pin for the red LED
const int yellowPin = 10;      // Pin for the yellow LED
const int greenPin = 9;        // Pin for the green LED

void setup() {
  pinMode(waterSensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int waterLevel = digitalRead(waterSensorPin);

  // If the sensor detects water
  if (waterLevel == HIGH) {
    // Turn on the green LED
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
  } else {
    // Turn off the green LED and turn on the red LED
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    
    delay(1000);  // Add a delay of 1 second
    // Turn on the yellow LED for a short period
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    delay(500);  // Add a delay of 500 milliseconds
    digitalWrite(yellowPin, LOW);
  }
}
