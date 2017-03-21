#include <ArduinoJson.h>

int LED = 3;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(A1);
  //Ciando JSON
  //1. cria buffer
  StaticJsonBuffer<200> buffer;
  //2.Criar o obj JSON
  JsonObject& obj = buffer.createObject();
  //3.Preecher o objeto criado
  obj["luz"] = luz;
  //4. mandar pela porta serial
  obj.printTo(Serial);Serial.println();

  if(luz < 600){
    analogWrite(LED,255);
  }else{
    analogWrite(LED,0);
  }
  delay(500);
}
