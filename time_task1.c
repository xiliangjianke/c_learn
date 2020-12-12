/*
 * program name:book1.c
 * author:neko date:20201126
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int time_to_str(const time_t ti, char *strtime);

//#include "_public.h"
int main(int argc, char *argv[])
{
	time_t tnow;
	char time_str[301];
	memset(time_str, 0, sizeof(time_str));

	time(&tnow);

	time_to_str(tnow, time_str);
//	printf("'0' is %d\n",ctoi('0'));
	
}

int time_to_str(const time_t ti, char *strtime)
{
	struct tm *sttm;
	sttm = localtime(&ti);

	printf("%04u-%02u-%02u %02u:%02u:%02u\n", sttm->tm_year+1900,\
			sttm->tm_mon+1, sttm->tm_mday,sttm->tm_hour,sttm->tm_min,\
			sttm->tm_sec);
}
