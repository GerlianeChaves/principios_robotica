#include <Servo.h>

Servo meuServo; // Crie um objeto Servo

void setup() {
  meuServo.attach(9); // Conecte o servo ao pino 9
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 15) { // Gire de 0° a 180° em incrementos de 15°
    meuServo.write(pos); // Defina a posição do servo
    delay(5000); // Espere 5 segundos
  }
  
  for (int pos = 180; pos >= 0; pos -= 15) { // Retorne de 180° a 0° em incrementos de 15°
    meuServo.write(pos); // Defina a posição do servo
    delay(5000); // Espere 5 segundos
  }
}

