#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int arr[100];
	srand(time(NULL));
	for(int i=0;i<5;i++)
	{
		arr[i] = rand() % 100;

	}
	printf("in mang\n");
	for(int i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;


}