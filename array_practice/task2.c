/*
 * programname:task1.c find the sum of 1 to 100
 * author:neko	date:20201129
 * problem:segmentation fault???? 
*/

#include<stdio.h>
#include<string.h>

int main()
{
	char string[100];
	memset(string,0,sizeof(string));

	strcpy(string, "abcdefg");

	int size=0;
	
	//printf("Please input a string: \n");
	//scanf("%s",string); this will rasie segmentation fault!

	//while (1)
	while (string[size] != 0)
	{
		//printf(" %s\n",string[size]);
		//printf(" The index is: %d\n",size);
		printf(" %c\n",string[size]);

		size += 1;
		
	}

}
