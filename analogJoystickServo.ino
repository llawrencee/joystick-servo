#include <Servo.h>

// Joystick Pins
const int joystickX = A0;
const int joystickY = A1;
const int joystickSW = 2;

// Servo Pins
const int servoX = 9;
const int servoY = 10;

Servo xServo;
Servo yServo;

void setup() {
  Serial.begin(9600);

  xServo.attach(servoX);
  yServo.attach(servoY);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int xValue = analogRead(joystickX);
  int yValue = analogRead(joystickY);
  int xMap = map(xValue, 0, 1023, 10, 170);
  int yMap = map(yValue, 0, 1023, 10, 170);

  Serial.print(xMap);
  Serial.print("\t");
  Serial.println(yMap);

  // xMap > 92, right
  // xMap < 88, left
  // yMap > 94, down
  // yMap < 90, up

  xServo.write(xMap);
  yServo.write(yMap);
  delay(100);

}