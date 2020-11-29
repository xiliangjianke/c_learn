/*
 * programname:task7.c	
 * author:neko	date:20201129
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int result[4];
	memset(result,0,sizeof(result));
	
	int age=0;
	int hight=0;
	int figure=0;
	int appearance=0;

	while (result[3] < 2)
	{
		printf("Please input age, hight, figure, appearance: \n");
		scanf("%d %d %d %d",&age,&hight,&figure,&appearance);

		//big beauty
		if (((age >= 18   ) && (age <= 25)) &&
			((hight >= 165) && (hight <= 178)) &&
			(figure ==2   ) && (appearance ==1)
		   )
		{
			result[0] += 1;
			result[3] += 1;
		}
		//normal beauty
		if (((age >= 18   ) && (age <= 30   )) &&
			((hight >= 160) && (hight <= 165)) &&
			((figure ==2  ) || (figure ==1  )) &&
			(appearance == 0)
		   )
		{
			result[1] += 1;
			result[3] += 1;
		}
		//bad beauty
		if (((age >= 35   ) && (age <= 40)) &&
			((hight >= 155) && (hight <= 165)) &&
			((figure ==0  ) || (figure ==1  )) &&
			(appearance == 0)
		   )
		{
			result[2] += 1;
			result[3] += 1;
		}
	}
	printf("Big beauty is: %d; normal beauty is: %d; bad beauty is: %d\n",result[0], result[1], result[2]);
}
