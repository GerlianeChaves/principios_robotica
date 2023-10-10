const int sensorPin = A0; // Pino analógico ao qual o sensor está conectado
const int threshold = 400; // Valor de referência para determinar proximidade

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  // Verifique se a leitura está abaixo do limite (objeto próximo)
  if (sensorValue < threshold) {
    Serial.println("Objeto Próximo");
  } else {
    Serial.println("Objeto Próximo");
  }

  delay(1000); // Aguarde um segundo antes de realizar a próxima leitura
}
