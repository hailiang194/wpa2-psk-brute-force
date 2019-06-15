#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list-wifi.h"
#include "brute-force-wifi.h"

int main(int argc, char *argv[])
{
	//bruteForce("Mi A2", "dict.txt");
	
	char ssidName[1000];
	char dictPath[1000];
	
	printf("+-----------------------------------------------+\n");
	printf("|               BRUTE FORCE WPA WIFI            |\n");
	printf("+-----------------------------------------------+\n\n");


	if(argc >= 3)
	{
		strcpy(ssidName, argv[1]);
		strcpy(dictPath, argv[2]);
	}
	else
	{
		if(argc == 1)
		{
			printf("SSID NAME = ");
			gets(ssidName);

			printf("DICTIONARY\'S PATH = ");
			gets(dictPath);
		}

		if(argc == 2)
		{

			printf("DICTIONARY\'S PATH = ");
			gets(dictPath);
		}
	}

	printf("-------------------------------------------------\n\n");

	listWLAN_t listNet = get_list_visible_wifi();

	if(!is_visible_WPA2(ssidName, listNet))
	{
		printf("YOUR WIFI IS NOT WPA2-PERSONAL OR IT\'S NOT VISIBLE.PLEASE TRY AGAIN!\n");
		printf("VISIBLE WPA2-PERSONAL WIFI:\n");

		for(int i = 0; i < listNet.len; i++)
			printf("\tNAME = %s\n", listNet.list[i].name);

		return 0;
	}

	bruteForce(ssidName, dictPath);
	return 0;
}
