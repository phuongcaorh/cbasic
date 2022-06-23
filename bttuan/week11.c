/*
• Khai báo mảng 2 triệu số nguyên
• Sử dụng hàm ngẫu nhiên để khởi tạo mảng
• Viết chương trình dạng menu
1. Tạo (lại) dữ liệu
2. Sắp xếp chèn
3. Sắp xếp lựa chọn
4. Sắp xếp vun đống 
• In ra thời gian thực hiện của mỗi giải thuật sắp xếp */
#include<stdio.h>
#include<stdlib.h>
void Random(int a[], int n)
{
   for(int i = 0; i < n; i++)
      a[i] = rand()%(n+1);
}
//2. xap xep chen
void insertion_sort(int a[], int n)
{
 	int i, j;
 	int next;
 	for (i=1; i<n; i++) {
 		next= a[i];
 	for (j=i-1;j>=0 && next<a[j];j--)
 	a[j+1] = a[j];
 	a[j+1] = next;
	}
}
//3. xap xep lua chon
 void selection(int a[], int n)
 { 
 	int i, j, min, tmp;
 	for (i = 0; i < n-1; i++){
 	min = i;
 	for (j = i+1; j <=n-1 ; j++)
 	if ( a[j] < a[min])
 		min = j;
 	tmp= a[i];
 	a[i]= a[min];
 	a[min] = tmp;
 	}
 }

//4 sap xep vun dong
 //in
void _print(int a[], int n)
{
	for(int i=0;i<n;i++)
		printf(" %d \n",a[i]);
}

void _printmenu()
{
	printf("=============================");
	printf("              MENU           ");
	printf("=============================");
	printf("1. Tạo (lại) dữ liệu");
	printf("2. Sắp xếp chèn");
	printf("3. Sắp xếp lựa chọn");
	printf("4. Sắp xếp vun đống ");
}
int main()
{
	int a[10];
	int n;

	printf("nhap vao so luong phan tu :\n");
	scanf("%d",&n);
	int choice;
	do
	{

		printf("nhap lua chon cua ban la(1-4) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			Random(a,n);
			_print(a,n);
			break;
			case 2:
				insertion_sort(a,n);
				_print(a,n);
				break;
			case 3:
				selection(a,n);
				_print(a,n);
				break;
			//case 4:
			//break;
			default:
				printf("khong hop le\n");
		}
		


	}
	while(choice>=1 && choice<=4);
	system("pause");
	return 0;
}