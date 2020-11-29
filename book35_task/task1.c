/*
 * programname:task1.c find the sum of 1 to 100
 * author:neko	date:20201129
*/

#include<stdio.h>

int main()
{
	int count=1;
	int sum=0;

	while (count <= 100)
	{
		sum += count;
		count++;
	}

	printf("The sum of 1 to 100 is: %d\n",sum);
}
