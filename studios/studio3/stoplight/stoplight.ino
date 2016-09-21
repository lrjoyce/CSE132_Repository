/* stoplight
 *  
 *  CSE 132 - Studio 3
 *  
 *  Fill this out so we know whose studio this is.
 *  
 *  Name: liam joyce 
 *  WUSTL Key: 436678 
 *  
 *  Name: Michael Billington (partner)
 *  WUSTL Key:
 */
 // EW RYG 5,4,3
 // NS RYG 10,9,8
 // WALK 6
 // DONT WALK 7
enum State{NSG, NSY, EWG, EWY, PED};
State currentState = EWG;

const int NSG_PIN = 10;
const int NSY_PIN = 9;
const int NSR_PIN = 8;
const int EWR_PIN = 5;
const int EWY_PIN = 4;
const int EWG_PIN = 3;
const int WALK = 6;
const int NOWALK = 7;
unsigned long Tnsg = 1087;
unsigned long Tnsy = 457;
unsigned long Tewg = 1087;
unsigned long Tewy = 373;
unsigned long Tped = 3041;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}
//currently stuck on first state
void loop() {
  switch(currentState) {
    case EWG:
      while (millis() > Tewg){
        //Tewg += Tewg;
       digitalWrite(EWG_PIN, HIGH);
       digitalWrite(NSR_PIN, HIGH);
       digitalWrite(NOWALK, HIGH);
       }
    digitalWrite(EWG_PIN, LOW);
    digitalWrite(NSR_PIN, LOW);
    currentState = EWY;
    break;
    
    case EWY:
      while (millis() > Tewy){
        //Tewg += Tewg;
       digitalWrite(EWY_PIN, HIGH);
       digitalWrite(NSR_PIN, HIGH);
       digitalWrite(NOWALK, HIGH);
       }
    digitalWrite(EWY_PIN, LOW);
    digitalWrite(NSR_PIN, LOW);
    currentState = PED;
    break;
    
    case PED:
      while (millis() > Tped){
       digitalWrite(WALK, HIGH);
       digitalWrite(EWR_PIN, HIGH);
       digitalWrite(NSR_PIN, HIGH);
       }
       digitalWrite(WALK, LOW);
       digitalWrite(EWR_PIN, LOW);
       digitalWrite(NSR_PIN, LOW);
    currentState = NSG;   
    break;
         
    case NSG:
      while (millis() > Tnsg){
        digitalWrite(NSG_PIN, HIGH);
        digitalWrite(EWR_PIN, HIGH);
        digitalWrite(NOWALK, HIGH);
      }
    digitalWrite(NSG_PIN, LOW);
    digitalWrite(EWR_PIN, LOW);
    currentState = NSY;
    break;

    case NSY:
      while (millis() > Tnsy){
        digitalWrite(NSY_PIN, HIGH);
        digitalWrite(EWR_PIN, HIGH);
        digitalWrite(NOWALK, HIGH);
      }
      digitalWrite(NSY_PIN, LOW);
      digitalWrite(EWR_PIN, LOW);
      currentState = EWG;
      break;
  }
}

