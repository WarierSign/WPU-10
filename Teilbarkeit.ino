// Blink LED Example
// Toggles the built-in LED on pin 13
int bj = 0;
int bn = 0;
int djfn = 0;
int fjdn = 0;

int Start = 1;
int Ende = 30;

void setup() {
  Serial.begin(9600);
}

void loop() {
 for (int i = Start; i = i + 1;) {
  if(i%3==0&&i%5==0) {
    bj = bj + 1;
  }
  if(i%3==0&&i%5!=0) {
    djfn = djfn + 1;
  }
  if(i%3!=0&&i%5==0) {
    fjdn = fjdn + 1;
  }
  else
  {
    bn = bn + 1;
  }
 }
 Serial.print("Durch 3 und 5 teilbar:");
 Serial.println(bj);
 Serial.print("Durch 3 teilbar:");
 Serial.println(djfn);
 Serial.print("Durch 5 teilbar:");
 Serial.println(fjdn);
 Serial.print("Durch nichts teilbar:");
 Serial.println(bn);

 delay(10000);
}
