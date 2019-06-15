#ifndef LIST_WIFI_H
	#define LIST_WIFI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list-wifi-type.h"
#include "preprocess.h"

//get list wifi that is visible 
listWLAN_t get_list_visible_wifi(void);

//return the location of the visible wifi has SSID Name is ssidName 
//if there is no wifi like this, it will return NULL
ssidWLAN_t *find_wifi(char * ssidName, listWLAN_t list);

//check if this ssidName is visible and it is a WPA2
short int is_visible_WPA2(char *ssidName, listWLAN_t list);

#endif