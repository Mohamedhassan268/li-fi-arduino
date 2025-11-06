// ARD2 - Optical receiver (hardware) using LDR on A0
const int SENSE = A0;
const unsigned long BIT_US = 1000; // must match TX
int threshold, hyster = 20;

bool lightOn() {
  static bool state = true;            // idle = light present
  int v = analogRead(SENSE);
  if (!state && v > threshold + hyster) state = true;
  else if (state && v < threshold - hyster) state = false;
  return state;                         // true=1, false=0
}
void setup() {
  Serial.begin(9600);
  long sum=0; for(int i=0;i<200;i++){ sum+=analogRead(SENSE); delay(5); }
  threshold = sum/200;
}
void loop() {
  while (lightOn()) {}                 // wait for start (light off)
  while (!lightOn()) {}                // edge confirm
  delayMicroseconds(BIT_US + BIT_US/2);
  byte b=0;
  for(int i=0;i<8;i++){ if(lightOn()) b|=(1<<i); delayMicroseconds(BIT_US); }
  delayMicroseconds(BIT_US);           // stop
  Serial.write(b);
}
