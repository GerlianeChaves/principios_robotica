const int potenciometroPin = A5;  // Pino analógico para ler o potenciômetro
const int motorPin = 10;          // Pino PWM para controlar o motor DC

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potenciometroPin);  // Lê o valor do potenciômetro (0-1023)
  int motorSpeed = map(potValue, 0, 1023, 0, 255);  // Mapeia o valor para a faixa de velocidade do motor (0-255)
  
  analogWrite(motorPin, motorSpeed);  // Define a velocidade do motor com PWM
  Serial.print("Velocidade do Motor: ");
  Serial.println(motorSpeed);
  delay(100);  // Pequeno atraso para evitar flutuações
}
