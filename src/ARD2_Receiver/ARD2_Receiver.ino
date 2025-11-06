// ARD2 - One-way receiver (Tinkercad)
void setup() {
  Serial.begin(9600);
  // print nothing on startup to avoid feedback if TX line is connected back by mistake
}
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.write(c);     // display in ARD2 Serial Monitor
  }
}
