#include <math.h>
#define ntcPin 33

extern float tempRead(float ntcRead);

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("temp: ");
  Serial.println(tempRead(analogRead(ntcPin)),2);
  delay(1000);
}
