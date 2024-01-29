// Definition of pins for RGB LEDs
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9; // Using pin 9 instead of 13 for blue
const int touchPin = 3;
// Color states for the RGB LED
enum ColorState { RED, GREEN, BLUE };
ColorState currentColor = RED; // Setting the initial color
 
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  int touchState = digitalRead(touchPin);

  if (touchState == HIGH) {
    // If the touch sensor is activated, change the color
    changeColor();
    delay(250); // Add a delay to avoid rapid color changes with a single touch
  }
}

void changeColor() {
  // Modify the current color state based on the next color
  switch (currentColor) {
    case RED:
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      currentColor = GREEN;
      break;
    case GREEN:
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
      currentColor = BLUE;
      break;
    case BLUE:
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      currentColor = RED;
      break;
    default:
      break;
  }
}
