/*
 * programname:task1.c find the sum of 1 to 100
 * author:neko	date:20201129
 * problem:segmentation fault???? 
*/

#include<stdio.h>
#include<string.h>

int main()
{
	int scores[10];
	memset(scores,0,sizeof(scores));

	int i=0;
	int sum=0;
   //	int average=0;
	for (i=0;i<10;i++)	
	{
		printf("Please input socre: \n");
		scanf("%d",&scores[i]);
		sum += scores[i];
	}
	
	printf("Average socre: %d \n",sum/10);

}
