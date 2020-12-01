/*
 * programname: _public.h, function file of common function declaration
 * author: neko date:20201130
*/

#include "_public.h" 

// get smaller integer of two integers
int min(const int ii1,const int ii2)
{
	if (ii1 < ii2) return ii1;

	return ii2;
}

// get bigger integer of two integers
int max(const int ii1,const int ii2)
{
	if (ii1 > ii2) return ii1;

	return ii2;
}

// return int of char
int ctoi(const char chr)
{
	switch (chr)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return -1;
	}
}
