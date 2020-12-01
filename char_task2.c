/*
 * program name:char_task2.c
 * author:neko date:20201201
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "_public.h"

int ISALPHA(int ch);// if ch is alpha('A-Z','a-z'),return 1,else return 0
int ISALNUM(int ch);// if ch is alpha('A-Z','a-z') or num('0-9'),return 1,else return 0
int ISDIGIT(int ch);// if ch is num('0-9'),return 1,else return 0
int ISLOWER(int ch);// if ch is lower alpha('a-z'),return 1,else return 0
int ISUPPER(int ch);// if ch is upper alpha('A-Z'),return 1,else return 0
int TOLOWER(int ch);// if ch is upper alpha('A-Z'),return correspond lower alpha,else return 0
int TOUPPER(int ch);// if ch is lower alpha('a-z'),return correspond upper alpha,else return 0

int main()
{
		
	printf("%d\n",ISALPHA('A'));
	printf("%d\n",ISALNUM('A'));
	printf("%d\n",ISDIGIT('A'));
	printf("%d\n",ISLOWER('A'));
	printf("%d\n",ISUPPER('A'));
	printf("%c\n",TOLOWER('A'));
	printf("%c\n",TOUPPER('a'));
	
}

int ISALPHA(int ch)// if ch is alpha('A-Z','a-z'),return 1,else return 0
{
	if (
	   ((ch >= 65) && (ch <= 90 )) ||
	   ((ch >= 97) && (ch <= 122))
	   ) return 0;
	return -1;
}
int ISALNUM(int ch)// if ch is alpha('A-Z','a-z') or num('0-9'),return 1,else return 0
{
	if (
	   ((ch >= 65) && (ch <= 90 )) ||
	   ((ch >= 97) && (ch <= 122)) || 
	   ((ch >= 48) && (ch <= 57))
	   ) return 0; 
	return -1;
}
int ISDIGIT(int ch)// if ch is num('0-9'),return 1,else return 0
{
	if ((ch >= 48) && (ch <= 57)) return 0; 
	return -1;
}
int ISLOWER(int ch)// if ch is lower alpha('a-z'),return 1,else return 0
{
    if ((ch >= 97) && (ch <= 122)) return 1;
	return -1;
}
int ISUPPER(int ch)// if ch is upper alpha('A-Z'),return 1,else return 0
{
    if ((ch >= 48) && (ch <= 90)) return 1;
	return -1;
}
int TOLOWER(int ch)// if ch is upper alpha('A-Z'),return correspond lower alpha,else return 0
{
    if ((ch >= 48) && (ch <= 90)) return ch+32;
	return -1;
}
int TOUPPER(int ch)// if ch is lower alpha('a-z'),return correspond upper alpha,else return 0
{
    if ((ch >= 97) && (ch <= 122)) return ch-32;
	return -1;
}
