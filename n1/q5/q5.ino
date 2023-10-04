#define trigger 4
#define echo 5
#define led_vermelho 2
#define led_verde 3

float distancia; // distância em cm
float duracao; // duração entre a saída do sinal pelo trigger e volta pelo echo
float velocidade = 0.0172316; // Velocidade do som em cm/s e dividida por 2 (para compensar a medição da distância 2 vezes)

void setup()
{
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);
}

void loop()
{
  digitalWrite(trigger, 0);
  delayMicroseconds(5);
  digitalWrite(trigger, 1);
  delayMicroseconds(10);
  digitalWrite(trigger, 0);
  duracao = pulseIn(echo, 1);
  distancia = duracao * velocidade;
  if (distancia <= 10) {
    digitalWrite(led_vermelho, 1);
    digitalWrite(led_verde, 0);
  } else {
    digitalWrite(led_verde, 1);
    digitalWrite(led_vermelho, 0);
  }
  Serial.print("Distancia em cm: ");
  Serial.println(distancia);
  delay(100);
}