/*
 * program name:char_str_task1.c
 * author:neko date:20201202
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "_public.h"

size_t strlen1(const char* str);
char *strcpy1(char* dest, const char* src);
char *strncpy1(char* dest, const char* src, size_t n);
char *strcat1(char* dest, const char* src);
char *strncat1(char* dest, const char* src, size_t n);
char *strchr1(const char* s, const int c);
char *strrchr1(const char* s, const int c);
int main()
{
	// test strlen
	char str1[11];
	memset(str1,0,sizeof(str1));
	strcpy(str1, "hello");
	printf("the length of str1:%s is %d\n",str1,strlen1(str1));

	// test strscp1
	char str2[11];
	memset(str2,0,sizeof(str2));
	strcpy1(str2, str1);
	printf("str2 is %s\n",str2);
}

size_t strlen1(const char* str)
{
	int ii=0;
	while (1)
	{
		if (*(str+ii) != '\0')
		{
			ii++;	
		}
		else
		{
			return ii;	
		}
	}
}
char *strcpy1(char* dest, const char* src)
{
	int ii=0;
	while (1)
	{
		if (*(src+ii) != '\0')
		{

			*(dest+ii) = *(src+ii);	
			ii++;	
		}
		else
		{
			*(dest+11)='\0';
			break;
		}
	}
}
//char *strncpy1(char* dest, const char* src, size_t n)
//如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。
//如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0

//char *strcat1(char* dest, const char* src)
//char *strncat1(char* dest, const char* src, size_t n)
//char *strchr1(const char* s, const int c)
//char *strrchr1(const char* s, const int c)
