// https://www.happybearsoftware.com/implementing-a-dynamic-array
// http://www.highscore.de/cpp/aufbau/klassen.html

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Wire.h"

class i2cdetect
{
  public:
    i2cdetect();
    i2cdetect(uint8_t sda, uint8_t scl);
    ~i2cdetect(); 

    void     i2cScan(uint8_t first, uint8_t last);
    void     i2cScan();

    String   i2cGetPrintOut();
    bool     i2cIsPresent(uint8_t adress);
    uint8_t  i2cGetCount();
    uint8_t* i2cGetArray();
    
  private:
    uint8_t  pin_sda = 4;
    uint8_t  pin_scl = 0;

    uint8_t  i2c_maxCount = 8;
    uint8_t  i2c_adresses[8] = {0};
};
