
#include "i2cdetect.h"

//Constructor
i2cdetect::i2cdetect() {}

i2cdetect::i2cdetect(uint8_t sda, uint8_t scl) {
  pin_sda = sda;
  pin_scl = scl;
  Wire.begin(pin_sda, pin_scl);
  i2cScan(0x03, 0x77);  // default range
}

//Destructor
i2cdetect::~i2cdetect() { 
}

void i2cdetect::i2cScan(uint8_t first, uint8_t last) {
  uint8_t address, error, i2ccount;
  char buff[10];
 
  i2ccount=0;
  for (address = 0; address <= 119; address++) {
    if (address >= first && address <= last) {
      Wire.beginTransmission(address);
      error = Wire.endTransmission();
      if (error == 0) {
        // device found
        i2c_adresses[i2ccount]=address;
        i2ccount++;
      }
    }
  }
  i2c_maxCount = i2ccount;
}

void i2cdetect::i2cScan() {
  i2cScan(0x03, 0x77);
}

bool i2cdetect::i2cIsPresent(uint8_t adress) {
  for (uint8_t i=0; i<i2c_maxCount; i++) {
    if (i2c_adresses[i] == adress) {
      return true;
    } 
  }
  return false;
}

uint8_t* i2cdetect::i2cGetArray() {
  return i2c_adresses;
}

uint8_t i2cdetect::i2cGetCount() {
  return i2c_maxCount;
}

String i2cdetect::i2cGetPrintOut() {
  String ret="";
  char buff[10];

  for (uint8_t i=0; i<i2c_maxCount; i++) {
    sprintf(buff, "%02x", i2c_adresses[i]);
    ret += buff;
    if (i<i2c_maxCount-1) {
      ret += ", ";
    }
  }

  if (i2c_maxCount==0) {
    ret = "none i2c devices found";
  }
  return ret;
}

