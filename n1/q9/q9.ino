#define pin_sensor A0
#define pin_atuador 4

float erro = 0.0;
float temperatura;
float ultima_temperatura;
float setpoint = 28.0;
long lastProcess = 0;

float Kp = 1.0;
float Ki = 0.0;
float Kd = 0.0;

float P = 0;
float I = 0;
float D = 0;

float PID = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_sensor, INPUT);
  pinMode(pin_atuador, OUTPUT);
}

void loop() {
  temperatura = map(analogRead(pin_sensor), 20, 358, -40, 125);
  
  erro = setpoint - temperatura;
  
  float deltaTime = (millis() - lastProcess) / 1000.0;
  lastProcess = millis();
  
  P = erro * Kp;
  
  I += (erro * Ki) * deltaTime;
  
  D = (ultima_temperatura - temperatura) * Kd * deltaTime;
  ultima_temperatura = temperatura;
  
  PID = P + I + D;
  
  analogWrite(pin_atuador, PID);
  
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  Serial.print("Sinal de controle: ");
  Serial.println(PID);
  Serial.println("-----------------");
  delay(1000);
}