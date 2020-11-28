/*
 * programname:book23.c, practice multi if
 * author:neko	date:2020.11.28
*/

#include <stdio.h>

int main()
{
	int a,b;

	printf("Please input two numbers:");
	scanf("%d %d",&a,&b);

	if (a == b)
	{
		printf("a(%d) equal b(%d)\n",a,b);
	}
	else
	{
		if (a > b)	
		{
			printf("a(%d) bigger than b(%d)\n",a,b);
		}
		else
		{
		printf("a(%d) less than b(%d)\n",a,b);
		}
	}
}
