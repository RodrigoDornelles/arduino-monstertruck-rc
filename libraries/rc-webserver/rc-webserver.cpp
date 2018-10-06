#include <Arduino.h>
#include <ESP8266WebServer.h>

#include <rc-webserver.h>

ESP8266WebServer server(80);

/*
 * Start web server
 */
void RCweb::ConfigWeb() {
	Serial.print("starting web server...");
	server.begin();
}