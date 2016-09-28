/* cricket

    CSE 132 - Assignment 3

    Fill this out so we know whose assignment this is.

    Name: Michael Billington
    WUSTL Key: mbillington

    and if two are partnered together

    Name: Liam Joyce
    WUSTL Key:joyce.l
*/

unsigned long loopEndTime = 0;
long loopEndTimeTwo = 0;
//unsigned long loopEndTimeThree = 0;
const unsigned long deltaTime = 250;
const float twentyFive = 25;
const int FILTER_COUNTS = 6;
int count = 0;
float temps[FILTER_COUNTS];
unsigned long BLINK_DURATION = 200;
unsigned long interval = 0;
const int thousand = 1000;
const int thirty = 30;
float temperature;
boolean cricket;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(A0, INPUT_PULLUP);
  pinMode(4, OUTPUT);
}

void loop() {
  while (true) {
    if (millis() > loopEndTime) {
      loopEndTime += deltaTime;
      Serial.println(interval);
      Serial.println(loopEndTimeTwo);
      readTemp();
    }

    if (millis() > 3000) {
      if (millis() > loopEndTimeTwo) {
        if (cricket) {
          loopEndTimeTwo += BLINK_DURATION;
          digitalWrite(4, HIGH);
          Serial.print("off");
          cricket = false;
        }
        else {
          loopEndTimeTwo += (interval - BLINK_DURATION);
          digitalWrite(4, LOW);
          cricket = true;
        }
      }
    }
  }
}

void readTemp() {
  temperature = (twentyFive + ((analogRead(A0) - 750) * .1));
  float total;
  temps[count % FILTER_COUNTS] = temperature;
  count++;
  if (count > 6) {
    for (int i = 0; i < FILTER_COUNTS; ++i) {
      total = total + temps[i];
    }
  }
  float rollingAverage = total / FILTER_COUNTS;
  interval = 100 * (thousand * (1 / (7 * temperature - thirty)));
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print(temperature);
  Serial.print(" ");
  Serial.print(rollingAverage);
  Serial.println();
}
