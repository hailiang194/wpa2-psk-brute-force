#include "write-xml.h"

void writeXML(char *path, char *ssidName, char *password)
{
	FILE *xmlFile;
	xmlFile = fopen(path, "w");
	
	//header
	fprintf(xmlFile, "<?xml version=\"1.0\"?>\n");
	fprintf(xmlFile, "<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\">\n");
	
	//write <name>
	fprintf(xmlFile, "\t<name>%s</name>\n", ssidName);

	//write<SSIDConfig>
	writeSSIDConfig(xmlFile, ssidName);
	
	//write<ConnectionType>
	writeConnectType(xmlFile);

	//write<ConnectionMode>
	writeConnectMode(xmlFile);
	
	//write<MSM>
	writeMSM(xmlFile, password);

	//write<MacRandomization>
	writeMacRandom(xmlFile);

	//footer
	fprintf(xmlFile, "</WLANProfile>");


	fclose(xmlFile);
}

void writeSSIDConfig(FILE *xmlFile, char *ssidName)
{
	char hexName[2 * strlen(ssidName) + 1];

	strToHex(ssidName, hexName);
	
	//header
	fprintf(xmlFile,"\t<SSIDConfig>\n");
	
	//SSID header
	fprintf(xmlFile, "\t\t<SSID>\n");

	//write hex
	fprintf(xmlFile, "\t\t\t<hex>%s</hex>\n", hexName);	
	//write name
	fprintf(xmlFile, "\t\t\t<name>%s</name>\n", ssidName);

	//SSID footer
	fprintf(xmlFile, "\t\t</SSID>\n");

	//footer
	fprintf(xmlFile, "\t</SSIDConfig>\n");
}

void writeConnectType(FILE *xmlFile)
{
	fprintf(xmlFile, "\t<connectionType>ESS</connectionType>\n");
}

void writeConnectMode(FILE *xmlFile)
{
	fprintf(xmlFile, "\t<connectionMode>auto</connectionMode>\n");
}

void writeMSM(FILE *xmlFile, char *password)
{
	//header
	fprintf(xmlFile, "\t<MSM>\n");
	
	//write security header
	fprintf(xmlFile, "\t\t<security>\n");
	
	//write<authEncryption>
	fprintf(xmlFile, "\t\t\t<authEncryption>\n");
	fprintf(xmlFile, "\t\t\t\t<authentication>WPA2PSK</authentication>\n");
	fprintf(xmlFile, "\t\t\t\t<encryption>AES</encryption>\n");
	fprintf(xmlFile, "\t\t\t\t<useOneX>false</useOneX>\n");
	fprintf(xmlFile, "\t\t\t</authEncryption>\n");
	
	//write<sharedKey>
	fprintf(xmlFile, "\t\t\t<sharedKey>\n");
	fprintf(xmlFile, "\t\t\t\t<keyType>passPhrase</keyType>\n");
	fprintf(xmlFile, "\t\t\t\t<protected>false</protected>\n");
	fprintf(xmlFile, "\t\t\t\t<keyMaterial>%s</keyMaterial>\n", password);
	fprintf(xmlFile, "\t\t\t</sharedKey>\n");


	//write security footer
	fprintf(xmlFile, "\t\t</security>\n");
	
	//footer
	fprintf(xmlFile, "\t</MSM>\n");
}

void writeMacRandom(FILE *xmlFile)
{
	//header
	fprintf(xmlFile, "\t<MacRandomization xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v3\">\n");
	fprintf(xmlFile, "\t\t<enableRandomization>false</enableRandomization>\n");
	//footer
	fprintf(xmlFile, "\t</MacRandomization>\n");
}

