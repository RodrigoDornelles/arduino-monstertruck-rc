#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <rc-connect.h>

/*
 * Configuração do WIFI
 */
void RCwifi::Config() {
	RCwifi::Init();
	RCwifi::AttempConection();

	if(WiFi.status() != WL_CONNECTED)
		RCwifi::Host();

	RCwifi::ShowIP();
}
/*
 * Começar configuração wifi
 */
void RCwifi::Init(){
	Serial.print("Started");
	delay(1000);
	Serial.begin(115200);
}
/*
 * Buscar por pontos de wifi
 */
void RCwifi::AttempConection() {
	WiFi.mode(WIFI_STA);
	Serial.print("\nTrying to connect to a wifi network...");

	for(int i=0, j=MAX_ACESSPOINTS; i < j; i++)
		if(RCwifi::Connect(APssid[i],APpswd[i]))
			break;
}
/*
 * Ancorar AcessPoint
 */
void RCwifi::Host(){
	WiFi.mode(WIFI_AP);
	WiFi.softAP(HOSTssid, HOSTpassword);
	Serial.println("**WIFI ACESSPOINT HOST STARTED**\n");
	char string[60];
	sprintf(string, "SSID: %s \n Password: %s",HOSTssid, HOSTpassword);
	Serial.print(string);
	Serial.println("*******************************\n");
	WifiAPmode=true;
}
/*
 * Conectar a um Wifi
 */
int RCwifi::Connect(char ssid[20], char password[20]){
	WiFi.begin(ssid, password);
	
	char string[60];
	sprintf(string, "\n[%2d/%2d] Connecting to wifi %s ", i,j, APssid[i]);
	Serial.print(string);

	unsigned long attempt = millis();

	while (WiFi.status() != WL_CONNECTED && millis() <  (attempt + 800) ){
	  delay(260);
	  Serial.print(".");
	}

	if(WiFi.status() != WL_CONNECTED)
	{
		Serial.print("\n!!! SUCESS !!!");
		return !WifiAPmode=false;
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
