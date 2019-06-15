#include <stdio.h>
#include <stdlib.h>
#include "preprocess.h"


/*
 * THIS FILE IS USED TO TEST
*/

int main(int argc, char const *argv[])
{
	char test[] = "\t";

	strip(test);

	printf("\'%s\'\n", test);
	return 0;
}