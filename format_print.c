/*
 * program name:book1.c
 * author:neko date:20201126
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "_public.h"

int get_str_from_XML(const char *xml, const char *filed_name, char *return_value);


int get_int_from_XML(const char *xml, const char *filed_name, int *return_value);

struct st_girl
{
	char name[51];
	int age;
	int height;
	double weight;
	char sc[31];
	char yz[31];
};

int main()
{
	struct st_girl *pst, queen, worker;
	memset(&queen, 0, sizeof(struct st_girl));
	memset(&worker, 0, sizeof(struct st_girl));

	char str[301];
	memset(str, 0, sizeof(str));

	pst=&queen;

	strcpy(pst->name, "xishi");
	pst->age = 18;
	pst->height = 168;
	pst->weight = 48.5;

	strcpy(pst->sc, "awsome");
	strcpy(pst->yz, "beauty");
	
	sprintf(str, "<name>%s</name><age>%d</age><height>%d</height>"\
				 "<weight>%f<weight><sc>%s</sc><yz>%s</yz>",pst->name,\
				  pst->age, pst->height, pst->weight, pst->sc, pst->yz);

	//printf("=%s=\n", str);

	get_str_from_XML(str, "name", worker.name);
	get_int_from_XML(str, "age", &worker.age);

	printf("name: %s, age: %d\n",worker.name, worker.age);

}

int get_str_from_XML(const char *xml, const char *filed_name, char *return_value)
{
	char start_label[51];	
	char end_label[51];	
	memset(start_label, 0, sizeof(start_label));
	memset(end_label, 0, sizeof(end_label));

	int len_fn = strlen(filed_name);
	int len_val = 0;

	char *start_index = 0;
	char *end_index = 0;
	//memset(start_index, 0, sizeof(start_index));
	//memset(end_index, 0, sizeof(end_index));

	sprintf(start_label, "<%s>", filed_name);
	sprintf(end_label, "</%s>", filed_name);

	//start_index = (char *)strstr(xml, start_label);
	start_index = (char *)strstr(xml, start_label);

	if (start_index == 0) return -1;
	//else end_index = (char *)strstr(start_index, end_label);
	else end_index = strstr(start_index, end_label);

	if (end_index == 0) return -1;
	else
	{
		len_val = end_index - start_index - len_fn - 2;
		strncpy(return_value, start_index + len_fn + 2, len_val);
	}
	return 0;

}


int get_int_from_XML(const char *xml, const char *filed_name, int *return_value)
{
	char result[51];
	memset(result, 0, sizeof(result));
	
	//int *return_code = 0;
	
	//return_code = get_str_from_XML(char *xml, char *filed_name, int *return_value);

	if (get_str_from_XML(xml, filed_name, result)!= 0) return -1;
	else (*return_value) = atoi(result);

	return 0;


}
