// Blink LED Example
// Toggles the built-in LED on pin 13

int energie = 60;


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (energie < 50)
  {
    Serial.println("Zu wenig Energie");
    delay(1000);
  }

  else
  {

    Serial.println("Systemtests:");

    for (
      int f = 1;
      f < 4;
      f++
    ) {
      Serial.println(f);
      delay (1000);
    }

    Serial.println("");
    Serial.println("Countdown:");

    int t = 4;
    while (t >= 2) {
      t= t - 1;
      Serial.println(t);
      delay(1000);
    }



    delay(3000);
    Serial.println("");
    Serial.println("");
  }
}
