/*
 * programname:task5.c	
 * author:neko	date:20201129
*/

#include <stdio.h>

int main()
{
	int count=0;

	while (count <= 100)
	{
		if (count%2 == 0)	
		{
			printf("%d \n",count);
		}
		count++;
	}
}
