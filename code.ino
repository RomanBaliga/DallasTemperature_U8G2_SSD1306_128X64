#include <Arduino.h>
#include <U8g2lib.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include <Wire.h>


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

OneWire oneWireDS(2);

DallasTemperature DS(&oneWireDS);


void setup() {
    u8g2.begin();
    u8g2.setFont(u8g2_font_ncenB14_tr); // choose a suitable font
    DS.begin();
    Serial.begin(9600);
}

void loop(void) {
  
  DS.requestTemperatures();
  
  u8g2.clearBuffer();         

  u8g2.setCursor(5,20);
  u8g2.print("Inter:");
  u8g2.setCursor(70,20);
  //Serial.println(DS.getTempCByIndex(0));
  u8g2.print(DS.getTempCByIndex(0),1);
  //delay(1000);

  u8g2.setCursor(5,50);
  u8g2.print("Exter:");
  u8g2.setCursor(70,50);
  //Serial.println(DS.getTempCByIndex(1));
  u8g2.print(DS.getTempCByIndex(1),1); 
  

  u8g2.sendBuffer();       

  delay(1000); 
}
