#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); // default pins for SDA and SCL
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scanning...");
  int found = 0;
  for (byte a = 1; a < 127; a++) {
    Wire.beginTransmission(a);
    if (Wire.endTransmission() == 0) {   // 0 = ACK
      Serial.print("Found 0x");
      if (a < 16) Serial.print("0");
      Serial.println(a, HEX);
      found++;
    }
  }
  if (found == 0) Serial.println("No I2C devices found");
  else { Serial.print("Done: "); Serial.print(found); Serial.println(" device(s)"); }
  delay(5000);
}
