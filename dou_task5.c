/*
 * program name:book1.c
 * author:neko date:20201126
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "_public.h"

double FABS(const double x);
double ROUND(const double x);
double CEIL(const double x);
double FLOOR(const double x);
int main()
{
	
	printf("%lf\n",CEIL(1.9));
	printf("%lf\n",CEIL(-1.9));


	printf("%lf\n",FLOOR(1.9));
	printf("%lf\n",FLOOR(-1.9));
	
}

double FABS(const double x)
{
	if (x >= 0) return x;
	return 0-x;
}
double ROUND(const double x)
{
	if (x==0) return 0;
	if (x > 0)
	{
		long ll=x+0.5;return ll;
	}
	if (x < 0)
	{
		long ll=x-0.5;return ll;
	}
}
double CEIL(const double x)
{
	long ll=x;
	if (x==ll)	return x;
	if (x>0)
	{
		long ll=x+1;
		return ll;
	}
	else
	{
		long ll=x;
		return ll;
	}
}
double FLOOR(const double x)
{
	long ll=x;
	if (x==ll)	return x;
	if (x>0)
	{
		long ll=x;
		return ll;
	}
	else
	{
		long ll=x-1;
		return ll;
	}
}
