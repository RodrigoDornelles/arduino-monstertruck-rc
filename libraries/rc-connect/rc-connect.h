#include "Arduino.h"


//Connect AP:
#define MAX_ACESSPOINTS     1             
//Host AP:
#define AcessPointSSID      "rc-wifi"
#define AcessPointPassword  "12345678"

class RCwifi {
  public:
  	void ConfigWifi();									//Configura a Rede Wifi
  	bool IsHostedAP();									//Modo Ancorado Ativo
  private:
  	/*
	 * Variables 
  	*/
  	//Wifi mode:
  	bool WifiAPmode=false;								// 1 Host | 0 Client
  	//Host acess point:
	const char *HOSTssid = AcessPointSSID;				//Nome Wifi Ancorado
	const char *HOSTpassword = AcessPointPassword;		//Senha Wifi Ancorado
	//connect to acesspoint:
	char APssid[MAX_ACESSPOINTS][20];					//AcessPoint Nomes
	char APpswd[MAX_ACESSPOINTS][20];					//AcessPoint Senhas
	/*	
	 * Functions
	 */
	void Init();										//Começar configuração wifi
	void AttempConection();								//Buscar por ponto de wifi
	void Host();										//Ancorar AcessPoint
	int	 Connect(char ssid[20], char password[20]);		//Conectar a um Wifi
	void ShowIP();										//Mostrar IP WebServer
};