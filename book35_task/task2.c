/*
 * programname: task2	break loop practice
 * author:neko	date:20201129
*/

#include <stdio.h>

int main()
{
	int sum=5000;
	int input_num=0;

	for (input_num=0;(sum - input_num) >= 0;sum -= input_num)
	{
		printf("Current sum is: %d\n",sum)	;
		printf("Please input a number to sub: \n")	;
		scanf("%d",&input_num);

	}
}
