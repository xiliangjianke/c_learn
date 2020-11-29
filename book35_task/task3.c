/*
 * programname: task3.c output muitiplication table
 * author:neko	date:20201129
 * problem:3*3 and 3*4 are not aligned with the follow-up
*/

#include <stdio.h>

int main()
{
	int i=0;
	int j=0;
	int result=0;

	for (i=1;i<=9;i++)
	{
		printf("\n");
		for (j=1; j<=i; j++)	
		{
			printf("%d*%d=%d ",j,i,j*i)	;
		}
	}
	printf("\n");
}
