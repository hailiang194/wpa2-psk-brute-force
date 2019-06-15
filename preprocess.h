#ifndef PREPROCESS_H
	#define PREPROCESS_H
#include <string.h>
#include <ctype.h>
#include <stdio.h>

//Convert ascii string to hex-string
//Note: (length of hexStr) >= 2 * (length of str) + 1
void strToHex(char *str, char *hexStr);

//return the first number appear in str
//if there is no number in st, this function will return 0
int firstNumInStr(char *str);

//remove all the leading and trailing white-spaces from a string
void strip(char *str);

#endif
