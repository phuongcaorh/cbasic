#include<stdio.h>
#include<string.h>
int main()
{
	int somay;
	char tencpu[5];
	char ram[5];
	 FILE *f1;
	/* f1=fopen("fileintest.txt","r");
	fscanf(f1,"%d \n", &somay);printf("%d \n",somay);
	for(int i=1;i<4;i++)
	{
		fscanf(f1,"%s %s \n", tencpu, ram);
		printf("%s %s \n", tencpu, ram);
	}
	fclose(f1);
	return 0; */
	char file_in1[100];
	printf("nhap vao ten file: \n");
	gets(file_in1);
	if((f1=fopen(file_in1,"r"))==NULL)
	{
		printf("khong mo duoc file \n");
		return;
	}
	fscanf(f1,"%d\n", &somay);printf("%d\n", somay);
	for(int i=1;i<4;i++)
	{

		fscanf(f1,"%s %s \n", tencpu, ram);
		printf("%s %s \n", tencpu, ram);
	}
	fclose(f1);
	return 0;
}
