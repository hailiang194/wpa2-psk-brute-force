#include "preprocess.h"

void strToHex(char *str, char *hexStr)
{
	int loop;
	int i; 
    
	i=0;
	loop=0;
    
	while(str[loop] != '\0')
	{
		sprintf((char*)(hexStr+i),"%02X", str[loop]);
		loop+=1;
		i+=2;
	}
	//insert NULL at the end of the output string
	hexStr[i++] = '\0';
}
