#include<stdio.h>
#include<string.h>
int ham1(unsigned int n)
{
	int i,j,S=0,dem=0;
	for(i=0;i<n;i++)
		for(j=n;j>0;j/=2)
			{
				printf("i la %d\n",i);
				printf("j la %d\n",j);
				dem=dem+1;
			}
		

		return dem;
}
int ham5(int n)
{
	printf("%d\n",n);


	if(n==0) return 0;
	else return (2+ ham5(n/2));

}
int ham4(int a, int b)
{
	if(a>b)
		return ham4(a-b,b);
	else if (a<b) return ham4(a,b-a);
	else return a;
}
int main()
{
	int k;
	printf("\nham5 la \n");
	printf("\n %d\n", ham5(17));
	return 0;
}