int switchPin = 2;     // Pino do botão “push button”
int motor1Pin1 = 3;    // Pino 2 do CI L293D
int motor1Pin2 = 4;    // Pino 7 do CI L293D
int enablePin = 9;     // Pino 1 do CI L293D
bool motorState = false;  // Variável para rastrear o estado do motor

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  // Habilitar o pino 1 para ligar o motor
  digitalWrite(enablePin, HIGH);
}

void loop() {
  // Verifique se o botão está pressionado
  if (digitalRead(switchPin) == HIGH) {
    // Inverta o estado do motor
    motorState = !motorState;
    delay(500); // Pequeno atraso para evitar detecção múltipla do botão
    
    // Defina a direção do motor com base no estado atual
    if (motorState) {
      // Gire o motor em um sentido
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
    } else {
      // Gire o motor no sentido contrário
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
    }
  }
}
