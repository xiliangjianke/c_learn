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
int strcmp1(const char* str1, const char* str2);
int strncmp1(const char* str1, const char* str2, size_t n);
char strchr1(const char* s, const int c);
char strrchr1(const char* s, const int c);

char *strstr(const char* str, const char* substr);
int main()
{
	// test strlen
	char str1[11];
	memset(str1,0,sizeof(str1));
	strcpy(str1, "llo");
	//printf("the length of str1:%s is %d\n",str1,strlen1(str1));

	/*
	// test strscp1
	char str2[11];
	memset(str2,0,sizeof(str2));
	strcpy1(str2, str1);
	//printf("str2 is %s\n",str2);
	
	// test strscp1
	size_t n=4;
	char str3[11];
	memset(str3,0,sizeof(str3));
	strncpy1(str3, str1, n);
	//printf("str3 is %s\n",str3);

	// test strcat1
	char str4[11];
	memset(str4,0,sizeof(str4));
	strcpy(str4, "he");
	strcat1(str4, str1);
	//printf("str4 contact str1 is %s\n",str4);
	char str5[11];
	size_t m=6;
	memset(str5,0,sizeof(str5));
	strcpy(str5, "he");
	strncat1(str5, str1, m);
	printf("str5 contact %d of  str1 is %s\n",m,str5);

	// test strcmp
	int result=10;
	char str6[11];
	memset(str6,0,sizeof(str6));
	strcpy(str6, "zel");
	result=strcmp1(str6, str1);
	printf("Compare result is %d\n",result);

	// test strncmp
	int result=10;
	size_t n=1;
	char str7[11];
	memset(str7,0,sizeof(str7));
	strcpy(str7, "zel");
	result=strncmp1(str7, str1, n);
	printf("Compare result is %d\n",result);
	
	// test strchr
	int result=strchr1(str1, 'o');
	printf("The index of l is %d\n",result);
	
	// test strrchr
	int result=strrchr1(str1, 'l');
	printf("The last index of l is %d\n",result);
	*/
	// test strstr
	char str8[11];
	memset(str8,0,sizeof(str8));
	strcpy(str8, "hello");
	//char *re=strstr(str8, str1);
	//printf("Index of substr in str is %s\n",re);
	printf("=%p=,=%s=\n",strstr(str8,str1),strstr(str8, str1));
//	printf("=%p=,=%s=\n",strstr("hello","llo"),strstr("hello", "llo"));
}

size_t strlen1(const char* str)
{
	int ii=0;

	while (str[ii]!='\0') ii++;

	return ii;
	/*
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
	}*/
}
char *strcpy1(char* dest, const char* src)
{
	int ii=0;

	while (src[ii]!='\0') { dest[ii]=src[ii]; ii++; }

	dest[ii]=0;

	return dest;
	/*
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
	return dest;*/
}
char *strncpy1(char* dest, const char* src, size_t n)
//如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。
//如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0

{
	int ilen=(strlen(src)>n)?n:strlen(src);

	size_t ii=0;

	for (ii=0;ii<ilen;ii++) { dest[ii]=src[ii]; }

	dest[ii]=0;

	return dest;

	
	/*
	printf("The length of src is %d \n",strlen(src));
	printf("The n is %d \n",n);
	int ii=0;
	for (ii=0;ii<=n-1;ii++)
	{
		if (strlen(src) >= n)
		{
		//	*(dest+ii) = *(src+ii);	
		//	ii++;	
			strcpy(dest,src);
		}
		else
		{
			 
			if (*(src+ii) != '\0')
			{
				
				*(dest+ii) = *(src+ii);	
			}
			else
			{
					
				*(dest+ii) = '0'; 
			}
		}
		// add '\0' at the end of string

		*(dest+ii+1) = '\0'; 

	}
	
	*(dest+ii+1) = 0; 
	return dest;*/
}
char *strcat1(char* dest, const char* src)
{
	int len_dest=strlen(dest);
	int len_src=strlen(src);
	
	int ii=0;
	for(ii=0;ii <= len_src;ii++)
	{
		*(dest+len_dest+ii) = *(src+ii);	
	}
	
	*(dest+len_dest+ii) = '0'; 
	return dest;
}

char *strncat1(char* dest, const char* src, size_t n)
{
	int ilen=(strlen(src)>n)?n:strlen(src);

	int idestlen=strlen(dest);

	int ii=0;

	for (ii=0;ii<ilen;ii++)
	{
		dest[idestlen+ii]=src[ii];	
	}

	dest[idestlen+ii]=0;
	/*
	printf("The length of src is %d \n",strlen(src));
	printf("The length of dest is %d \n",strlen(dest));
	printf("The n is %d \n",n);
	int len_dest=strlen(dest);
	int len_src=strlen(src);
	int ii=0;
	for (ii=0;ii<=n-1;ii++)
	{
		if (len_src >= n)
		{
		//	*(dest+ii) = *(src+ii);	
		//	ii++;	
			*(dest+len_dest+ii) = *(src+ii);	
		}
		else
		{
			if (ii < len_src)
			{
				
				*(dest+len_dest+ii) = *(src+ii);	
			}
			else
			{
					
				*(dest+len_dest+ii) = '0'; 
			}
		}
		// add '\0' at the end of string
	}
	
	*(dest+len_dest+ii+1) = '0'; 
	return dest;*/
}
int strcmp1(const char* str1, const char* str2)
{
	int ii=0;
	int min_len=(strlen(str1)>strlen(str2))?strlen(str2):strlen(str1);

	for (ii=0;ii<min_len;ii++)
	{
		if (str1[ii] == str2[ii])	continue;
		break;
	}
	
	if (strlen(str1) == strlen(str2) && (str1[ii] == str2[ii])) return 0;
	
	if (str1[ii] > str2[ii]) return 1;

	return -1;
	/*
	int len_str1=strlen(str1);	
	int len_str2=strlen(str2);	
	int max_len=max(len_str1, len_str2);
	int ii=0;
	for(ii=0;ii<max_len;ii++)
	{
		if (str1[ii] == str2[ii]) return 0;
		if (str1[ii] > str2[ii]) return 1;
		if (str1[ii] < str2[ii]) return -1;

	} */

}

int strncmp1(const char* str1, const char* str2, const size_t c)
{
	int ii=0;
	//int min_len=(strlen(str1)>strlen(str2))?strlen(str2):strlen(str1);

	for (ii=0;ii<c;ii++)
	{
		if (str1[ii] == str2[ii])	continue;
		break;
	}
	
	if (ii  == c ) return 0;
	
	if (str1[ii] > str2[ii]) return 1;

	return -1;
	/*
	int ii=0;
	for(ii=0;ii<c;ii++)
	{
		if (str1[ii] == str2[ii]) return 0;
		if (str1[ii] > str2[ii]) return 1;
		if (str1[ii] < str2[ii]) return -1;

	}*/

}
char strchr1(const char* s, const int c)
{
	int len_s=strlen(s);
	int ii=0;
	for(ii=0;ii<len_s;ii++)
	{
		if (s[ii] == c) return ii+1;

	}
	return -1;

}

char strrchr1(const char* s, const int c)
{
	int len_s=strlen(s);
	int ii=0;
	int temp=0;

	for(ii=0;ii<len_s;ii++)
	{
		if (s[ii] == c) temp=ii+1;

	}
	if (temp == 0) return -1;

	
}


char *strstr(const char* str, const char* substr)
{
	char* pos=(char *)str;
	char* pos1=0;

	while(1)
	{
		if (pos[0]=0) return 0;// str is empty string

		pos1 = strchr(pos,substr[0]);

		if (pos1 ==0 ) return 0;// substr not in str

		if (strncmp(pos1, substr, strlen(substr)) == 0) return pos1;

		pos++;
	}
	return 0;
}
