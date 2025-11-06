// ARD1 - One-way transmitter (Tinkercad)
void setup() {
  Serial.begin(9600);
  Serial.println("ARD1 ready. Type to send:");
}
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.write(c);     // goes out TX pin D1 to ARD2 RX
  }
}
