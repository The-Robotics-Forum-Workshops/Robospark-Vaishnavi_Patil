#define pot A5
#define m1 13
#define m2 12
#define en 9
int potVal = 0;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(en, OUTPUT);
  Serial.begin(9600);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
}

void loop() {
  
  potVal=analogRead(pot);
  analogWrite(en, potVal/4);
  Serial.print("| Pot - ");
  Serial.print(potVal);
  Serial.print(" | PWM - ");
  Serial.print(potVal/4);
  Serial.println(" |");

}
