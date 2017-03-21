
int LED = 3;
int LED2 = 10;
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
    if(nextChar == '1'){
      analogWrite(LED,255);
    }else if(nextChar == '2'){
      analogWrite(LED2,255);
    }
  }
}

