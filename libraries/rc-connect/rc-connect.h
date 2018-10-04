#include "Arduino.h"

#define MAX_ACESSPOINTS	1

class RCwifi {
  public:
  	void Config();										//Configura a Rede Wifi
  	bool IsHostedAP();
  private:
  	/*
	 * Variables 
  	*/
  	//Wifi mode:
  	bool WifiAPmode;									// 1 Host | 0 Client
  	//Host acess point:
	const char *HOSTssid = "MonsterRC";					//Nome Wifi Ancorado
	const char *HOSTpassword = "12345678";				//Senha Wifi Ancorado
	//connect to acesspoint:
	char APssid[MAX_ACESSPOINTS][20];					//AcessPoint Nomes
	char APpswd[MAX_ACESSPOINTS][20];					//AcessPoint Senhas
	/*	
	 * Functions
	 */
	void Init();										//Começar configuração wifi
	void AttempConection();								//Buscar por ponto de wifi
	void Host();										//Hostear AcessPoint
	int	 Connect(char ssid[20], char password[20]);		//Conectar a um Wifi
	void ShowIP();										//mostrar IP
};