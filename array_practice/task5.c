/*
 * programname:task1.c find the sum of 1 to 100
 * author:neko	date:20201129
 * problem:segmentation fault???? 
*/

#include<stdio.h>
#include<string.h>

int main()
{
	int scores[2][2];
	memset(scores,0,sizeof(scores));

	int class_sum[2];
	memset(class_sum,0,sizeof(class_sum));

	int i=0;
	int j=0;
	int grade_sum=0;
   //	int average=0;
	for (i=0;i<2;i++)	
	{
		
		for (j=0;j<2;j++)	
		{
				
			printf("Please input socre of person in serail %d class %d: \n",i,j);
			scanf("%d",&scores[i][j]);
			grade_sum += scores[i][j];
			class_sum[i] += scores[i][j];
		}
	}
	
  	printf("Total socre of class 1 is: %d \n",class_sum[0]);
  	printf("Total socre of class 2 is: %d \n",class_sum[1]);

  	printf("Average socre of class 1 is: %d \n",class_sum[0]/2);
  	printf("Average socre of class 2 is: %d \n",class_sum[1]/2);
  	printf("Average socre of grade is: %d \n",grade_sum/4);

}
