/*
 * programname: _public.h, header file of common function declaration
 * author: neko date:20201130
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare min function, get smaller integer of two integers
int min(const int ii1,const int ii2);


// declare max function, get bigger integer of two integers
int max(const int ii1,const int ii2);

// declare ctoi function, return int of char 
// return 0 if input is not a integer
int ctoi(const char chr);
