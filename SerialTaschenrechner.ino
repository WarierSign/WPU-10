void setup() {
  Serial.begin(9600);
  while (!Serial) { ; } // Warten auf serielle Verbindung
  Serial.println("--- Arduino Taschenrechner ---");
}

void loop() {
  // 1. Erste Zahl einlesen
  Serial.println("Gib die erste Zahl ein:");
  while (Serial.available() == 0) {}
  float num1 = Serial.parseFloat();
  clearSerialBuffer();
  Serial.print("> Erste Zahl: ");
  Serial.println(num1);

  // 2. Operator einlesen
  Serial.println("Gib den Operator ein (+, -, *, /):");
  while (Serial.available() == 0) {}
  char op = Serial.read();
  clearSerialBuffer();
  Serial.print("> Operator: ");
  Serial.println(op);

  // 3. Zweite Zahl einlesen
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

  Serial.println("--------------------------------\n");
  delay(1000);
}

// Hilfsfunktion zum Leeren des Speichers (entfernt verbleibende Enter-Tasten/Zeilenumbrüche)
void clearSerialBuffer() {
  delay(50);
  while (Serial.available() > 0) {
    Serial.read();
  }
}
