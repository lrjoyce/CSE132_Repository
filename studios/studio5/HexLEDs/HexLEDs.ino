const int pinA = 3;
const int pinB = 5;
const int pinC = 7;
const int pinD = 9;


void setup() {
  Serial.begin(9600);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
}


void loop(){
  int inputVar = Serial.read();
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);

  if(Serial.available() > 0){
    char MyVar = Serial.read();
    Serial.println(MyVar);
  }
}

