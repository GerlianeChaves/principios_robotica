//Robô Sumô
//Disciplina: Principios de Robótica      Professor: Daniel
//Alunos: Gerliane Chaves e Guilherme Abreu
//Referencia: https://blog.eletrogate.com/como-montar-e-programar-um-robo-lutador-de-sumo/

//bibliotecas
#include <AFMotor.h>//Biblioteca do motor shield
#include <Ultrasonic.h>//Bibloteca do sensor ultrassônico

float distancia; // distância em cm
float duracao; // duração entre a saída do sinal pelo trigger e volta pelo echo
float velocidade = 0.0172316; // Velocidade do som em cm/s e dividida por 2 (para compensar a medição da distância 2 vezes)

//pinos
#define sensor_direita A0 // sensor da frente e lado direito
#define sensor_esquerda A1 // senor da frente e lado esquerdo
#define sensor_traseira A2 // sensor traseiro
#define echo A3
#define trigger A4

//obejtos
AF_DCMotor motor_direita(3);
AF_DCMotor motor_esquerda(4);
Ultrasonic ultrasonic(trigger, echo);

void setup() {
  //Configuração de velocidade dos motores
  motor_esquerda.setSpeed(200);
  motor_direita.setSpeed(200);
  Serial.begin(9600); //Habilita a comunicação serial
  pinMode(sensor_esquerda, INPUT); // Configura o pino do sensor da esquerda como entrada
  pinMode(sensor_direita, INPUT); // Configura o pino do sensor da direita como entrada
  pinMode(sensor_traseira, INPUT); // Configura o pino do sensor da traseira como entrada
}

void loop() {
  digitalWrite(trigger, 0);
  delayMicroseconds(5);
  digitalWrite(trigger, 1);
  delayMicroseconds(10);
  digitalWrite(trigger, 0);
  duracao = pulseIn(echo, 1);
  distancia = duracao * velocidade;

  Serial.println(distancia);
  Serial.print("Sensor direita: ");
  Serial.println(digitalRead(sensor_direita));
  Serial.print("Sensor esquerda: ");
  Serial.println(digitalRead(sensor_esquerda));
  Serial.print("Sensor traseira: ");
  Serial.println(digitalRead(sensor_traseira));
  Serial.println(analogRead(sensor_traseira));
  
  //Verifica se tem alguma coisa na sua frente e se os sensor estão no branco
  if (distancia > 15 && distancia > 0 && digitalRead(sensor_direita) == 1 || digitalRead(sensor_esquerda) == 1 && digitalRead(sensor_traseira) == 1) {
    Serial.println("procurando oponente");
    //Duas formas de procurar o oponente na arena
    procura();//Procura em forma de quadrado
  }
   //Se caso encontrar algo na sua frente
  if (distancia < 15 && distancia > 0 && (digitalRead(sensor_direita) == 1 || digitalRead(sensor_esquerda) == 1) && digitalRead(sensor_traseira) == 1) {
    while (digitalRead(sensor_direita) == 1 || digitalRead(sensor_esquerda) == 1) { //Prende na condição até o sensor encotrar a borda da arena
      Serial.println("achei o oponente");
      frente();//Movimenta para frente
    }
    parada();
    delay(1000);
    tras();
    delay(1000);
  }
  //Se caso encontre a borda e não o oponente
  if (digitalRead(sensor_direita) == 0 && digitalRead(sensor_traseira) == 1) {
    Serial.println("Sensor da frente achou borda. Vá para trás!");
    tras();
    delay(500);
  }
  if (digitalRead(sensor_direita) == 1 && digitalRead(sensor_traseira) == 0) {
    Serial.println("Sensor de trás achou borda. Vá para frente!");
    frente();
    delay(500);
  }

}

void frente() {
  motor_esquerda.run(FORWARD);
  motor_direita.run(FORWARD); 
}
//********************Movimenta o robô para trás********************
void tras() {
  motor_esquerda.run(BACKWARD);
  motor_direita.run(BACKWARD); 
}
//********************Parada dos motores********************
void parada() {
  motor_esquerda.run(RELEASE);
  motor_direita.run(RELEASE); 
}
//********************Movimenta o robô para esquerda********************
void esquerda() {
  motor_direita.run(FORWARD);
  motor_esquerda.run(BACKWARD);
}
//********************Movimenta o robô em forma de quadrado********************
void procura() {
  frente();
  delay(300);
  esquerda();
  delay(300);
}
