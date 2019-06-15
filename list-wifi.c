#include "list-wifi.h"

listWLAN_t get_list_visible_wifi(void)
{
	listWLAN_t list;

	system("netsh wlan show networks > networks.txt");

	FILE *WLANVisibleFile = fopen("networks.txt", "r");

	char *line = (char *)malloc(256 * sizeof(char));

	//empty header
	fgets(line, 256, WLANVisibleFile);
	//title
	fgets(line, 256, WLANVisibleFile);
	//number wifi visible
	fgets(line, 256, WLANVisibleFile);

	list.len = firstNumInStr(line);

	unsigned int index = 0;

	list.list = (ssidWLAN_t *)malloc(list.len * sizeof(ssidWLAN_t));

	while(fgets(line, 256, WLANVisibleFile) != NULL)
	{
		if(strstr(line, "SSID") == NULL)
			continue;


		//get ssid name
		char * ssidName = strchr(line, ':') + 1;

		strip(ssidName);

		list.list[index].name = (char *)malloc((strlen(ssidName) + 1) * sizeof(char));		

		strcpy(list.list[index].name, ssidName);

		//get Network type
		fgets(line, 256, WLANVisibleFile);		
		//get Authentication

		fgets(line, 256, WLANVisibleFile);

		if(strstr(line, "WPA2-Personal"))
			list.list[index].isWPA2_PSK = 1; //true
		else
			list.list[index].isWPA2_PSK = 0; //false

		index++;

	}

	fclose(WLANVisibleFile);

	remove("networks.txt");

	return list;
}

ssidWLAN_t *find_wifi(char * ssidName, listWLAN_t list)
{
	for(int i = 0; i < list.len; i++)
		if(strcmp(list.list[i].name, ssidName) == 0)
			return &(list.list[i]);

		return NULL;
}

short int is_visible_WPA2(char *ssidName, listWLAN_t list)
{
	ssidWLAN_t *wifiNeed = find_wifi(ssidName, list);

	if(wifiNeed == NULL)
		return 0; //false

	return (wifiNeed -> isWPA2_PSK);
}
