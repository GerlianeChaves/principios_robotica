#include <IRremote.hpp>

#define RECV_PIN 4

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // inicializa o receptor
}

void loop()
{
  if (IrReceiver.decode()){
    auto value = IrReceiver.decodedIRData.decodedRawData;
    switch (value) {
      case 4077698816:
      	Serial.println("Button 0 was pressed");
      	break;
      case 4010852096:
      	Serial.println("Button 1 was pressed");
      	break;
      case 3994140416:
      	Serial.println("Button 2 was pressed");
      	break;
      case 3977428736:
      	Serial.println("Button 3 was pressed");
      	break;
      case 3944005376:
      	Serial.println("Button 4 was pressed");
      	break;
      case 3927293696:
      	Serial.println("Button 5 was pressed");
      	break;
      case 3910582016:
      	Serial.println("Button 6 was pressed");
      	break;
      case 3877158656:
      	Serial.println("Button 7 was pressed");
      	break;
      case 3860446976:
      	Serial.println("Button 8 was pressed");
      	break;
      case 3843735296:
      	Serial.println("Button 9 was pressed");
      	break;
      default: Serial.println(value);
    }
    IrReceiver.resume();
  }
}