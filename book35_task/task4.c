/*
 * progranme:task4 
 * author:neko	date:20201129
*/

#include <stdio.h>

int main()
{
	int count=0;
	int sum=0;
	int input_num=0;

	while (1)
	{
		printf("Please input a number for sum: \n")	;
		scanf("%d",&input_num);

		//if num > 100
		if (input_num > 100) continue;

		if (input_num < 100)
		{
			if (input_num == 0) 
			{
				printf("The valid input number is: %d\n",count);
				printf("The sum is: %d\n",sum);
				break;
			}
			sum += input_num;
			count++;

		}
	}
}
