#include "i2cdetect.h"

i2cdetect* I2Cdetect = NULL;

void setup() {
  Serial.begin(115200);
  I2Cdetect = new i2cdetect(0,4);
  Serial.println("i2cdetect startup");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  String str = I2Cdetect->i2cGetAddresses();

  Serial.println(I2Cdetect->i2cGetAddresses());
}