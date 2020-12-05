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
	if ((chr >= '0') || (chr <= '9')) return chr-'0';
	return -1;
	/*switch (chr)
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
	}*/
}


// safe strcpy function: copy src to dest
char *STRCPY(char* dest,const size_t dest_size, const char* src)
{
	if (dest == 0) return 0; // if dest if empty string,return 0
	memset(dest,0,sizeof(dest)); // initialize dest

	if (src == 0) return dest; // special case: src is empty string
	
	// if len(src) > dest_size?strncpy:srcpy
	if (strlen(src) > dest_size - 1) { strncpy(dest, src, dest_size - 1); }
	else strcpy(dest, src);

	return dest;
}


// safe strcpy function: copy src to dest
char *STRNCPY(char* dest,const size_t dest_size, const char* src, size_t n)
{
	if (dest == 0) return 0; // if dest if empty string,return 0
	memset(dest,0,sizeof(dest)); // initialize dest

	if (src == 0) return dest; // special case: src is empty string
	
	// if len(src) > dest_size?strncpy:srcpy
	if (n > dest_size - 1) { strncpy(dest, src, dest_size - 1); }
	else strncpy(dest, src, n);

	return dest;
	
}


// safe strcat function
char *STRCAT(char* dest,const size_t dest_size, const char* src)
{
	if (dest == 0) return 0;	
	if (src == 0) return dest;	

	unsigned int free_len = dest_size - strlen(dest) - 1;

	if (free_len > strlen(src)) strcat(dest, src);
	else { strncat(dest, src, free_len); dest[dest_size - 1] = 0; } 

	return dest;
}

// safe strcat function
char *STRNCAT(char* dest,const size_t dest_size, const char* src, const size_t n)
{
	if (dest == 0) return 0;	
	if (src == 0) return dest;	

	unsigned int free_len = dest_size - strlen(dest) - 1;

	if (free_len > n) strncat(dest, src, n);
	else { strncat(dest, src, free_len); dest[dest_size - 1] = 0; } 

	return dest;
}


// delete string to the right of specified char
void DeleteRChar(char *str,const char chr)
{
	if (str == 0) return;	
	if (strlen(str) == 0) return;	

	int str_len = strlen(str);

	while (str_len > 0)
	{
		if (str[str_len - 1] == chr) break;
		str[str_len - 1]=0;
		str_len--;
	}
}

// delete string to the left of specified char
void DeleteLChar(char *str,const char chr)
{
	if (str == 0) return;
	if (strlen(str) == 0) return;

	char temp_str[strlen(str) + 1];
	memset(temp_str, 0, sizeof(temp_str));
	strcpy(temp_str, str);

	int temp_index = 0;

	while (temp_str[temp_index] != chr) temp_index++;

	memset(str, 0, sizeof(str));
	strcpy(str, temp_str + temp_index);
	
}

// delete string to the left and right of specified char
void DeleteLRChar(char *str,const char chr)
{
	DeleteLChar(str, chr);	
	DeleteRChar(str, chr);	
}

// convert lowercase to uppercase,ignore non alphabetic type
void ToUpper(char *str)
{
	if (str == 0) return;
	if (strlen(str) == 0) return;

	int len_str = strlen(str);
	int ii = 0;

	for (ii=0;ii<len_str;ii++)
	{
		if ((str[ii] >= 'a') && (str[ii] <= 'z')) str[ii] -= 32;	
	}
}
//void ToUpper(string &str)

// convert uppercase to lowercase,ignore non alphabetic type
void ToLower(char *str)
{
	if (str == 0) return;
	if (strlen(str) == 0) return;

	int len_str = strlen(str);
	int ii = 0;

	for (ii=0;ii<len_str;ii++)
	{
		if ((str[ii] >= 'A') && (str[ii] <= 'Z')) str[ii] += 32;	
	}
}

//void ToLower(string &str)
