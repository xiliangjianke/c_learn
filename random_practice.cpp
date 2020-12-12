/*
 * program name:book201.cpp
 * author:neko date:20201210
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>

//#include "_public.h"


int main()
{
	srand(time(0));

	int result[52];
	memset(result, 0, sizeof(result));

	int ii = 0;
	int count = 0;

	while (1)
	{
		int tmp = rand()%52 + 1;

		for (ii=0;ii<count;ii++)
		{
			if (result[ii] == tmp) break;	
		}

		if (ii < count) continue;


		result[count++] = tmp;
		printf("%d ",tmp);
		if (count == 52) break;
	}

	int player[4][13];
	memset(player, 0, sizeof(player));
	for (ii=0;ii<13;ii++)
	{
		player[0][ii] = result[0 +4* ii];
		player[1][ii] = result[1 +4* ii];
		player[2][ii] = result[2 +4* ii];
		player[3][ii] = result[3 +4* ii];
	}

	for (ii=0;ii<13;ii++)
	{
		printf("Player1[%d]=%d\n",ii,player[1][ii]);	
	}
}

