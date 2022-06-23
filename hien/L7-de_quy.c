/*Tạo một mảng có 100 phần tử với giá trị lần lượt từ 1 tới 100
• Nhập vào một số từ bàn phím, thực hiện tìm kiếm nhị phân, “not found” nếu không tìm thấy
• In ra chỉ số của phần tử trung tâm hiện tại tại mỗi bước tìm kiếm. Cuối cùng, in ra số phép so sánh đã thực hiện trong trường hợp tìm thấy
*/
#include<stdio.h>
#include<stdlib.h>
int dem=0;
void binSearch2(int A[], int key, int lo, int hi)
{
	if(lo==hi)
	{
		if(key==A[lo])
		{	
			printf("i= %d\n", lo);
			return;
		}
		printf("NOT found!\n");
		return;
	}
	int mid=(lo+hi)/2;
	++dem;
	printf("mid= %d\n", mid);
	if(key==A[mid])
	{
		 printf("i= %d\n", mid);
		 return;
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
	int A[102];
	for(int i=0; i<100; ++i)
	{
		A[i]=i+1;
	}
	printf("NHap x = ");
	int x;
	scanf("%d", &x);
	binSearch2(A, x, 0, 100-1);
	printf("dem = %d", dem);
}
