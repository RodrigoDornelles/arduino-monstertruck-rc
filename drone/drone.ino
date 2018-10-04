/*
 *  LIBARY:
 */

#include <ESP8266WebServer.h>

/*
 *  MODULES:
 */

#include <rc-connect.h>

/*
 *  SETUPS:
 */
ESP8266WebServer server(80);

void setup() {
  RCwifi  Config();   //Configuração WIFI
  server.begin();
}

void loop() {

}
