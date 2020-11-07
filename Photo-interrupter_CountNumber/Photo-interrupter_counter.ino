//photo-interrupter sample
//Designed by Jin-Woo Kim

const int photoPin = 2; //input pin for the interrupter
const int buzzer = 9;
const int RedLed = 5;
int count = 0;
int val;

void setup() {
  Serial.begin(9600);
  pinMode (photoPin, INPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (RedLed, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), objectDetection, HIGH);
  //fuction for creating exteranl interrupts at pin2 on Rising (LOW to HIGH)
}

void loop() {
  val = digitalRead(photoPin); 
  Serial.print("Encoder State");
  Serial.print(val);
  Serial.println();
  Serial.print("Count");
  Serial.println(count);
  delay(100);
}


void objectDetection() {
  if (val == LOW) {
    count++ ; //counting number of detection
    tone(buzzer, 1000, 100);
    digitalWrite(RedLed, HIGH);
  }
  else {
    digitalWrite(RedLed, LOW);
  }
}
