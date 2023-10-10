#include <IRremote.hpp>
#TESTE
#define motor 3 
#define RECV_PIN 7

IRrecv irrecv(RECV_PIN);
decode_results results;

int pwm = 100;

void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  irrecv.enableIRIn();
}

void loop()
{
  if (IrReceiver.decode()){
    auto value = IrReceiver.decodedIRData.decodedRawData;
    if (value == 3994140416) { // button 2
      pwm = 30;
    } else if (value == 3977428736) { // button 3
      pwm = 60;
    } else if (value == 3944005376) { // button 4
      pwm = 90;
    } else if (value == 3927293696) { // button 5
      pwm = 120;
    } else if (value == 3910582016) { // button 6
      pwm = 150;
    } else if (value == 3877158656) { // button 7
      pwm = 180;
    } else if (value == 3860446976) { // button 8
      pwm = 210;
    } else if (value == 3843735296) { // button 9
      pwm = 240;
    } 
    IrReceiver.resume();
  }
  analogWrite(motor, pwm);
  Serial.println(pwm);
}