/*
 * program name:book50.c
 * author:neko date:20201126
*/
#include <stdio.h>

int main()
{
	int ii=10;
	char cc='A';
	double dd=100.56;


	int *pii=0;
	char *pcc=0;
	double *pdd=0;

	pii=&ii;
	pcc=&cc;
	pdd=&dd;
	printf("The value of pii is: %p!\n",pii);
	printf("The value of pcc is: %p!\n",pcc);
	printf("The value of pdd is: %p!\n",pdd);
	
	return 0;
}
