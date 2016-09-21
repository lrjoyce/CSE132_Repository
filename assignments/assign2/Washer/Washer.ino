//Fill in the values below with the pins that you chose to use
/* PIN PLACES
 * 3 - button input, LOCK DOOR
 * 5 - yellow, DRY
 * 7 - red, HOT WASH
 * 9 - green, COLD WASH
 * A0 - potentiaomterer, CYCLE

*/
const int POT_PIN = A0; 
const int BUTTON_PIN = 3;

const int HOT_PIN = 7;
const int COLD_PIN = 9;
const int DRY_PIN = 5;
const int LOCK_PIN = 13;

enum State{initialState,coldWash,hotWash,medWash,shortDry,longDry};
State currentState= initialState;

void setup() {
  Serial.begin(9600);
  //potentiometer
  pinMode(A0, INPUT_PULLUP);
  //button
  pinMode(3,INPUT_PULLUP);
  
}
int econ = 740;
int sdeluxe = 330;
void loop() {
  switch (currentState) {
     case initialState:
     digitalWrite(LOCK_PIN, LOW);
     if(digitalRead(BUTTON_PIN) == 1){
        break;
        }
     else {
        if(analogRead(A0) > econ){
         currentState = coldWash;
       }
        else {
         currentState = hotWash;
       }
     }
  break;
  case coldWash:
     digitalWrite(LOCK_PIN, HIGH);
     digitalWrite(COLD_PIN, HIGH);
     delay(5000);
     digitalWrite(COLD_PIN, LOW);
        if(analogRead(A0) > econ){
           currentState = shortDry;
     }
     else {
    currentState = longDry;
   }
  break;
 case shortDry:
  digitalWrite(LOCK_PIN, HIGH);
  digitalWrite(DRY_PIN, HIGH);
  delay(2000);
  digitalWrite(DRY_PIN, LOW);
  currentState = initialState;
 break;
//TAKE NOTE MOFOS
   break;
   case hotWash:
     digitalWrite(LOCK_PIN, HIGH);
     digitalWrite(HOT_PIN, HIGH);
     delay(7000);
     digitalWrite(HOT_PIN, LOW);
      if(analogRead(A0)< sdeluxe ){
        currentState = medWash;
      }
      else if (analogRead(A0)>econ ){
        currentState = shortDry;
      }
      else {
        currentState = longDry;
      }
      break;
  case medWash:
    digitalWrite(LOCK_PIN, HIGH);
    digitalWrite(COLD_PIN, HIGH);
    digitalWrite(HOT_PIN, HIGH);
    delay(7000);
    digitalWrite(COLD_PIN,LOW);
    digitalWrite(HOT_PIN,LOW);
      if(analogRead(A0)<sdeluxe){
        currentState = longDry;
      }
      else{
  currentState = shortDry;
      }
   break;
  case longDry:
    digitalWrite(LOCK_PIN, HIGH);
    digitalWrite(DRY_PIN, HIGH);
    delay(7000);
    digitalWrite(DRY_PIN, LOW);
    currentState = initialState;
}
}
 
