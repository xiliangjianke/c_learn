/*
 * program name:book50.c
 * author:neko date:20201126
*/
#include <stdio.h>

int main()
{
	int ii=10;
	
	int *pii=0;

	pii=&ii;

	*pii=20;

	printf("The value of pii is: %p!\n",pii);
	printf("The value of *pii is: %d!\n",*pii);
	printf("The value of ii is: %d!\n",ii);
	
	return 0;
}
