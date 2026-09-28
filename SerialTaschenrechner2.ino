void setup() {
  Serial.begin(9600);
  while (!Serial) { ; } // Warten auf serielle Verbindung
  Serial.println("--- Arduino Taschenrechner ---");
  Serial.println("Gib eine Rechnung ein");
}

void loop() {
  // Warten, bis Zeichen im seriellen Puffer ankommen
  if (Serial.available() > 0) {
    // Liest die erste Zahl (stoppt automatisch beim Operator)
    float num1 = Serial.parseFloat();
    
    // Liest das nächste Zeichen (den Operator)
    char op = Serial.read();
    
    // Liest die zweite Zahl
    float num2 = Serial.parseFloat();

    // Zeigt die eingelesene Rechnung an
    Serial.print("Eingabe: ");
    Serial.print(num1);
    Serial.print(" ");
    Serial.print(op);
    Serial.print(" ");
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

    // Puffer leeren (Entfernt verbleibende Zeilenumbrüche/Enter)
    clearSerialBuffer();
    Serial.println("--------------------------------");
    Serial.println("Naechste Rechnung eingeben:");
  }
}

void clearSerialBuffer() {
  delay(50);
  while (Serial.available() > 0) {
    Serial.read();
  }
}
