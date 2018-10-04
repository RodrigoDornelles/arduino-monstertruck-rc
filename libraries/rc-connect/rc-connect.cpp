#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <rc-connect.h>

void RCwifi::Init(){
	Serial.print("Started");
	delay(1000);
	Serial.begin(115200);
}
/*
 * Começar configuração wifi
 */
void RCwifi::Config() {
	RCwifi::Init();
	RCwifi::AttempConection();
	RCwifi::Host();
	RCwifi::ShowIP();
}
/*
 * Buscar por ponto de wifi
 */
void RCwifi::AttempConection() {
	WiFi.mode(WIFI_STA);
	Serial.print("\nTrying to connect to a wifi network...\n\n");

	for(int i=0, j=MAX_ACESSPOINTS; i < j; i++)
	{
		char string[60];
		sprintf(string, "\n[%2d/%2d] Connecting to wifi %s\n", i,j, APssid[i]);
		Serial.print(string);

		if(RCwifi::Connect(APssid[i],APpswd[i]))
			break;
	}
}
/*
 * Ancorar AcessPoint
 */
void RCwifi::Host(){
	if(WiFi.status() != WL_CONNECTED)
	{
		Serial.println("connection failed!");
		WiFi.mode(WIFI_AP);
		WiFi.softAP(HOSTssid, HOSTpassword);
		Serial.println("**WIFI ACESSPOINT HOST STARTED**\n");
		char string[16];
		sprintf(string, "SSID: %s \n Password: %s",HOSTssid, HOSTpassword);
		Serial.print(string);
		Serial.println("*******************************\n");
	}
}
/*
 * Conectar a um Wifi
 */
int RCwifi::Connect(char ssid[20], char password[20]){
	WiFi.begin(ssid, password);

	unsigned long attempt = millis();

	while (WiFi.status() != WL_CONNECTED && millis() <  (attempt + 5000) ){
	  delay(800);
	  Serial.print(".");
	}

	if(WiFi.status() != WL_CONNECTED)
	{
		Serial.print("\n!!! SUCESS !!!");
		return 1;
	}
	return 0;
}
/*
 * Mostrar IP WebServer
 */
void RCwifi::ShowIP(){
	Serial.println("\n**************************\nIP Adress:");
	Serial.print(WiFi.localIP());
	Serial.println("**************************");
}
/*
 * Modo Ancorado Ativo 
 */
bool RCwifi::IsHostedAP()
	return WifiAPmode;	