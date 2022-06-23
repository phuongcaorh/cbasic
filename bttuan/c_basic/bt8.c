#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int setup_namelist(char *namelist[], FILE* file)
{	
	int count=1;
	count++;
	if(count<=10)
	{
		fscanf(file,"%s",&namelist);
		printf("%s",namelist);
		setup_namelist(&namelist,file);
	}
}
int main()
{	char *name[20];
	FILE *f1;
	f1=fopen("file_8.txt","r");
	setup_namelist(&name,f1);
	fclose(f1);
	return 0;
}