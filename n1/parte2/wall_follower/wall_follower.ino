//Robô Seguidor de Parede
//Disciplina: Principios de Robótica      Professor: Daniel
//Alunos: Gerliane Chaves e Guilherme Abreu


//parâmetros:
// muito perto = desviar da parede: de 0 a 20
//seguir: de 20 a 40
//procurar pela parede: maior de 40

//bibliotecas
#include <AFMotor.h>
#include <Ultrasonic.h>

//sensor ultrassonico
#define echo1 A0
#define trigger1 A1
#define echo2 A2
#define trigger2 A3

Ultrasonic ultrasonic1 (trigger1, echo1);
Ultrasonic ultrasonic2 (trigger2, echo2);
//motores
AF_DCMotor M1(1);
AF_DCMotor M4(4);

void setup(){
  Serial.begin(9600);
  M1.setSpeed(255);
  M4.setSpeed(255);
}

void seguir(){
  M1.run(BACKWARD);
  M4.run(BACKWARD);
  Serial.println("seguindo a parede");
}

void desvio(){
  Serial.println("Desviando");
  M1.run(FORWARD); //girar o motor que está ao lado do sensor
  M4.run(RELEASE);
}

void procurar_parede() {
  Serial.println("Me perdi, estou procurando uma parede");
  M4.run(RELEASE); //girar o motor que está ao lado do sensor
  M1.run(FORWARD);
}

void loop(){
  float dist_sensor1 = ultrasonic1.read();
  float dist_sensor2 = ultrasonic2.read();
  if (dist_sensor1 > 20 && dist_sensor1 < 40) {
    Serial.println("Distância em cm: ");
    //Serial.println(dist_sensor1);
    seguir();  
  } if (dist_sensor1 <= 20) {
    Serial.println("Distância em cm: ");
    //Serial.println(dist_sensor1);
    desvio();
  }// else{
  if (dist_sensor1 >= 40) {
    procurar_parede();
  }
  
  Serial.println(dist_sensor1);
}
