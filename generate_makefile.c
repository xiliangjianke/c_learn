/*
 * program name:generate_makefile.c, generate makefile in input path
 * author:neko date:20201209
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

//#include "_public.h"
int main(int argc, char *argv[])
{
	if (argc != 2 )	{printf("Please input folder path!\n"); return -1;}

	char file_name[100][31]; // store c file name
	memset(file_name, 0, sizeof(file_name));

	DIR *dir; //folder pointer

	// open specified folder path
	if ((dir = opendir(argv[1])) == 0) return -1;

	// store file information
	struct dirent *stdinfo;

	// total number of file in path
	int file_count = 0;

	// get file name and put into file_name
	while (1)
	{
		// get file name and put into file_name
		
		if ((stdinfo = readdir(dir)) == 0) break; //open folder

		if ((stdinfo->d_type == 8) &&
			(strcmp(stdinfo->d_name+strlen(stdinfo->d_name)-2,".c") == 0) &&
			strncmp(stdinfo->d_name, "_", 1) != 0)
		{
			printf("name=%s, type=%d\n",stdinfo->d_name, stdinfo->d_type);	

			// save into file_name
			strncpy(file_name[file_count], stdinfo->d_name, strlen(stdinfo->d_name)-2);
			printf("filename[%d]=%s\n",file_count,file_name[file_count]);
			
			file_count++;
//			printf("file_count in loop is %d\n", file_count);
		}

	}

		closedir(dir); //close folder pointer
//	printf("file_count out loop is %d\n", file_count);
	// generate makefile
	
	FILE *fp = 0; // file pointer

	if ((fp = fopen("MakeFile", "w")) == 0)
	{
		printf ("fopen(MakeFile) failed!\n"); 
		return -1;
	} // open makefile
	
	int ii = 0;

	// write all:
	fprintf(fp, "all:");
	for (ii=0;ii<file_count;ii++) fprintf(fp,"%s ",file_name[ii]);
	fprintf(fp, "\n\n");

	// write compile command
	
	for (ii=0;ii<file_count;ii++)
	{
		fprintf(fp,"%s:%s.c\n", file_name[ii], file_name[ii]);	
		fprintf(fp,"\tgcc -o %s %s.c\n\n", file_name[ii], file_name[ii]);	
	}

	// write clean:
	fprintf(fp, "clean:\n\trm -rf ");
	for (ii=0;ii<file_count;ii++) fprintf(fp,"%s ",file_name[ii]);
	fprintf(fp, "\n\n");

	fclose(fp); // close file pointer
}
