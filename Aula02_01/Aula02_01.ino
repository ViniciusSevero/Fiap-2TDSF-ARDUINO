
int LED = 3;
char nextChar = 0;
bool lendo = false;
String valor = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    nextChar = Serial.read();
    if(nextChar == 'B') {
      lendo = true;
      valor = "";
    } else if(nextChar == 'E') {
      lendo = false;
      analogWrite(LED,valor.toInt());
      Serial.println(String("Potencia do LED: ") + valor);
    } else if(lendo && nextChar >= '0' && nextChar <= '9') {
      valor += nextChar;
   }
  }
}

