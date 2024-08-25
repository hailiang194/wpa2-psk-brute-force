#ifndef BRUTE_FORCE_WIFI_H
	#define BRUTE_FORCE_WIFI_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <io.h>
#define access _access

#else
#include <unistd.h>
#endif
#include "write-xml.h"

void connectWifi(char *ssidName, char *password);
short isConnected(void);

void bruteForce(char *ssidName, char * dictPath);

#endif
