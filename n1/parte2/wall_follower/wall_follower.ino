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
#define tigger A0
#define echo A1

Ultrasonic ultrasonic (tigger, echo);
//motores
AF_DCMotor M3(3);
AF_DCMotor M4(4);

void setup(){
  Serial.begin(9600);
  Serial.println("Lendo os dados do sensor...");
}

void seguir(){
  M3.run(FORWARD);
  M4.run(FORWARD);
  Serial.println("seguindo a parede");
}

void desvio(){
  Serial.println("Desviando");
  M3.run(BACKWARD); //girar o motor que está ao lado do sensor
  M4.run(RELEASE);
}
void ultrasonicSensor(){
  //  Lê as infos do sensor
  float distancia = ultrasonic.read();
  if (distancia <30){
    //  apresenta as infos no monitor
    Serial.println("Distância em cm: ");
    Serial.println(distancia);
    delay(1000);
  }
}

void loop(){
  float distancia = ultrasonic.read();
  if (distancia >20 && distancia <40){
    Serial.println("Distância em cm: ");
    Serial.println(distancia);
    seguir();  
  }if (distancia <20){
    Serial.println("Distância em cm: ");
    Serial.println(distancia);
    desvio();
  }else{
    Serial.println("Me perdi");
  }
  

//  motor.setSpeed(200);
//  M3.run(FORWARD);
//  motor3.run(FORWARD);
//  delay(5000);
}
