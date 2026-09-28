void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println("--- Taschenrechner ---");
}

void loop() {
  // 1. Erste Zahl
  Serial.println("Gib die erste Zahl ein:");
  while (Serial.available() == 0) {}
  float num1 = Serial.parseFloat();
  clearSerialBuffer();
  Serial.print("> Erste Zahl: ");
  Serial.println(num1);

  // 2. Operator
  Serial.println("Gib den Operator ein (+, -, *, /):");
  while (Serial.available() == 0) {}
  char op = Serial.read();
  clearSerialBuffer();
  Serial.print("> Operator: ");
  Serial.println(op);

  // 3. Zweite Zahl
  Serial.println("Gib die zweite Zahl ein:");
  while (Serial.available() == 0) {}
  float num2 = Serial.parseFloat();
  clearSerialBuffer();
  Serial.print("> Zweite Zahl: ");
  Serial.println(num2);

  Serial.println("--------------------------------");

  // Berechnung
  Serial.print("Ergebnis: ");
  switch (op) {
    case '+':
      Serial.println(num1 + num2);
      break;
    case '-':
      Serial.println(num1 - num2);
      break;
    case '*':
      Serial.println(num1 * num2);
      break;
    case '/':
      if (num2 != 0) {
        Serial.println(num1 / num2);
      } else {
        Serial.println("Fehler: Division durch 0!");
      }
      break;
    default:
      Serial.println("Ungueltiger Operator!");
      break;
  }

  Serial.println("--------------------------------");
  Serial.println("");
  delay(1000);
}


void clearSerialBuffer() {
  delay(50);
  while (Serial.available() > 0) {
    Serial.read();
  }
}
