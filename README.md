# I2c-Detect
 a simple Arduino i2c Detection Library for my projects because i didn´t find any simple solution which fits my requirements

## use the library

initialize the library with your selected I2C pins<br>
<code>i2cdetect(uint8_t sda, uint8_t scl);</code>
<pre>
i2cdetect* t = NULL;

setup() {
 t = new i2cdetect(4,5);
}
</pre>

make a scan, this step is necessary as first step before you are able to use the next functions<br>
<code>void     i2cScan();</code>
<pre>
t->i2cScan();
</pre>

get all detected ic2 devices with their addresscode back as comma separated string<br>
<code>String   i2cGetAddresses();</code>
<pre>
String s = t->i2cGetAddresses();
Serial.println(s);
</pre>

get all detected ic2 devices with their addresscode back as byte vector<br>
<code>void     i2cGetAddresses(std::vector<uint8_t>* i2cAddresses);</code>
<pre>
i2cdetect* t = NULL;
std::vector<uint8_t>* addr = NULL;

setup() {
  addr = new std::vector<uint8_t>{};
  t = new i2cdetect(4,5);
  t->i2cScan();
  t->i2cGetAddresses(addr);
  
  for (uint8_t i = 0; i < addr->size(); i++) {
    char c[5];
    snprintf(c, sizeof(c), "0x%02X", addr->at(i));
    Serial.println(c);
  }
}
</pre>

Check if an i2c Adresscode was detect<br>
<code>bool     i2cIsPresent(uint8_t adress);</code>
<pre>
bool b = i2cIsPresent(0x3C);
if(b) { Serial.println("Device exists"); }
else  { Serial.println("Device exists"); }
</pre>

Get the number of detected devices<br>
<code>uint8_t  i2cGetCount();</code>
<pre>
uint8_t a = i2cGetCount();
Serial.print("Devices found: "); Serial.println(a);
</pre>
