#include <Servo.h>

Servo myservo;
int sensorPin = A0;
int val;
int servoAngle;

void setup() {
  myservo.attach(9);
}

void loop() {
  val = analogRead(sensorPin);
  // Mapeie o valor lido do sensor para a faixa de ângulos do servo (0 a 180)
  servoAngle = map(val, 0, 1023, 0, 180);
  myservo.write(servoAngle);
  delay(15);
}
