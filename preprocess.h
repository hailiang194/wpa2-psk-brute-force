#ifndef PREPROCESS_H
	#define PREPROCESS_H
#include <string.h>
#include <stdio.h>

//Convert ascii string to hex-string
//Note: (length of hexStr) >= 2 * (length of str) + 1
void strToHex(char *str, char *hexStr);

#endif
