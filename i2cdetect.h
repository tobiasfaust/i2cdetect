// https://www.happybearsoftware.com/implementing-a-dynamic-array
// http://www.highscore.de/cpp/aufbau/klassen.html

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#ifndef I2CDETECT_H
#define I2CDETECT_H

#include "Wire.h"
#include <vector>

class i2cdetect
{
  public:
    i2cdetect();
    i2cdetect(uint8_t sda, uint8_t scl);
    ~i2cdetect(); 

    void     i2cScan(uint8_t first, uint8_t last);
    void     i2cScan();

    String   i2cGetAddresses();
    void     i2cGetAddresses(std::vector<uint8_t>* i2cAddresses);
    
    bool     i2cIsPresent(uint8_t adress);
    uint8_t  i2cGetCount();
    //void    i2cGetArray(std::vector<uint8_t>* i2cAddresses);
    
  private:
    uint8_t  pin_sda = 4;
    uint8_t  pin_scl = 0;

    uint8_t  i2c_maxCount = 8;
    uint8_t  i2c_adresses[8] = {0};
    // std::vector<uint8_t> i2cAddresses;
};
#endif
