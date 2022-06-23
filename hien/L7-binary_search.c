//binary search
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int binSearch(int A[], int key, int size)
{
	int mid, lo=0, hi=size-1;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(A[mid]==key)
		{
			return mid;
		}else if(key<A[mid])
		{
			hi=mid-1;
		}else
		{
			lo=mid+1;
		}
	}
	return -1;
}

int binSearch2(int A[], int key, int lo, int hi)
{
	if(lo==hi)
	{
		if(key==A[lo])
		{	
			return lo;
		}
		return -1;
	}
	int mid=(lo+hi)/2;
	if(key==A[mid])
	{
		 return mid;
	}else if(key<A[mid])
	{
		
		binSearch2(A, key, lo, mid);
	}else
	{
		binSearch2(A, key, mid+1, hi);
	}
}

int main()
{
	int A[1000];
	clock_t start, end;
	double cpu_time_used;
	for(int i=0; i<1000; i++)
	{
		A[i]=i+1;
	}
	int size=sizeof(A)/sizeof(A[0]);
	printf("Nhap x = ");
	int x;
	scanf("%d%*c", &x);	
	start = clock();
	printf("kqua i = %d\n", binSearch(A, x, size));
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time = %f\n", cpu_time_used);
	
	start = clock();
	printf("kqua i = %d\n", binSearch2(A, x, 0, size-1));
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time = %f\n", cpu_time_used);
}

//tao mang 100 ptu tu 1 den 100 tim ptu (in ra ptu A[mid])
 
