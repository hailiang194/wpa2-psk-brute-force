#ifndef BRUTE_FORCE_WIFI_H
	#define BRUTE_FORCE_WIFI_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "write-xml.h"

void connectWifi(char *ssidName, char *password);
short isConnected(void);

void bruteForce(char *ssidName, char * dictPath);

#endif
