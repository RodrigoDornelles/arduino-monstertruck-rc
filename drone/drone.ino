/*
 *  SETUPS:
 */

#define SerialClock         115200
/*
 *  MODULES:
 */

#include <rc-connect.h>
#include <rc-webserver.h>
#include <rc-display.h>
/*
 * BEGIN 
 */
void setup() {
  Serial.begin(SerialClock);

  RCdisplay ConfigDisplay();//display 4 arg 7 segs  
  RCwifi  ConfigWifi();     //Configuração WIFI
  RCweb   ConfigWeb();      //Configura Web Server
}

/*
 * PROCESS
 */

void loop() {
}
