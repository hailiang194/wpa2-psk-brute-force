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

int firstNumInStr(char *str)
{
	int num = 0;
	char *ref = str;
	const int len = strlen(str);
	
	//find first digit

	short findDigit = 0; //check if find first digit

	while(ref != str + (len - 1))
	{
		if(isdigit(*ref))
		{
			findDigit = 1;
			num *= 10;
			num += ((*ref) - '0');
		}

		if(!isdigit(*ref) && findDigit)
			break;

		ref++;
	}

	return num;
}

void strip(char *str)
{
	char *ref = str;

	//remove at the leading
	while(*ref != '\0')
	{
		if(!isspace(*ref))
		{
			strcpy(str, ref);
			break;
		}
		ref++;
	}

	//remove at the trailing
	ref = str + (strlen(str) - 1);

	while(ref >= str)
	{
		if(!isspace(*ref))
		{
			*(ref + 1) = '\0';
			break;
		}

		ref--;
	}

}