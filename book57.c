/*
 * program name:book50.c
 * author:neko date:20201126
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char name[51];
	strcpy(name, "c practice");



	printf("%p!\n",name);
	printf("%p!\n",&name);
	printf("%p!\n",&name[0]);
	
	printf("%s!\n",name);
	printf("%s!\n",&name);
	printf("%s!\n",&name[0]);
}
