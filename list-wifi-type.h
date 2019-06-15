#ifndef LIST_WIFI_TYPE_H
	#define LIST_WIFI_TYPE_H

typedef struct SSID_WLAN
{
	char *name;
	unsigned int isWPA2_PSK : 1;
}ssidWLAN_t;

typedef struct LIST_WLAN
{
	ssidWLAN_t *list;
	unsigned int len;
}listWLAN_t;

#endif