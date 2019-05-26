#ifndef WRITE_XML_H
	#define WRITE_XML_H

#include <stdio.h>
#include <string.h>
#include "preprocess.h"

void writeXML(char *path, char *ssidName, char *password);
void writeSSIDConfig(FILE *xmlFile, char *ssidName);
void writeConnectType(FILE *xmlFile);
void writeConnectMode(FILE *xmlFile);
void writeMSM(FILE *xmlFile, char *password);
void writeMacRandom(FILE *xmlFile);

#endif
