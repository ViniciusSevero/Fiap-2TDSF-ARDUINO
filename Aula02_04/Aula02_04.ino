#include <ArduinoJson.h>

int LED = 3;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(A1);
 if(Serial.available()){
  char texto[200];
  Serial.readBytesUntil('\n',texto,200);
  //Tentar decodificar o JSON
  StaticJsonBuffer<200> buffer;
  JsonObject& obj = buffer.parseObject(texto);
  if(obj.success() && obj.containsKey("led")){
    analogWrite(LED,255);
  }
  delay(500);
 }
}
