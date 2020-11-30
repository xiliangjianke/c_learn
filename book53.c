/*
 * program name:book50.c
 * author:neko date:20201126
*/
#include <stdio.h>

void funcld(int *p);

int main()
{
	int a=10;


	printf("First place: a is a variable, address is %p, value is %d!\n",&a,a);
	funcld(&a);
	printf("Second place: a is a variable, address is %p, value is %d!\n",&a,a);
}

void funcld(int *p)
{
		
	printf("Third place: a is a variable, address is %p, value is %d!\n",p,*p);
	*p=20;
	printf("Fourth place: a is a variable, address is %p, value is %d!\n",p,*p);
}
