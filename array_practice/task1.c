/*
 * programname:task1.c find the sum of 1 to 100
 * author:neko	date:20201129
 * problem: how to initial array for a vary sets of characters??
*/

#include<stdio.h>
#include<string.h>

int main()
{
	char string[100];
	memset(string,0,sizeof(string));

	int size=0;

	printf("Please input a string: \n");
	scanf("%s",string);
	//size=sizeof(string)/sizeof(string[0]);

	while (string[size] != '\0')
	{
		size += 1;
	}
	printf("The length of input string is: %d\n",size);

}
