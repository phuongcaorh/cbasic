/* • Xây dựng danh bạ điện thoại
• Khai báo cấu trúc với name, phone number, và email
• Đọc 10 bản ghi từ tệp vào danh sách, sắp xếp theo thứ tự
tăng dần và ghi ra tệp
• Sử dụng sắp xếp chèn và sắp xếp lựa chọn
• (1) Sử dụng mảng các cấu trúc
• (2) Sử dụng danh sách liên kết đơn/đôi
• In ra số phép so sánh trong mỗi giải thuật */
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct address
{
    char name[20];
    char phone[11];
    char email[50];
}address;
void insertion_sort(address add[], int n)
{
 	int i, j;
	char tmp[50];
 	for (i=1; i<n; i++) {
 		strcpy(tmp,add[i].name);
 	for (j=i-1;j>=0 &&   (strcmp(tmp,add[j].name))<0;j--)
 		strcpy(add[j+1].name,add[j].name);
 		strcpy(add[j+1].name , tmp);
 	
 	}
}
void selection(address add[], int n)
{ 
 	int i, j, min;
 	char tmp[50];
	for (i = 0; i < n-1; i++){
		min = i;
	for (j = i+1; j <=n-1 ; j++)
		if ((strcmp(add[j].name,add[min].name))<0)
			min = j;
			strcpy(tmp,add[i].name);
			strcpy(add[i].name, add[min].name);
			strcpy(add[min].name,tmp);
			
	 }
 }
int main()
{
	address add[10];
	FILE *f1, *f2;
	f1=fopen("file.txt", "r");
	f2=fopen("file_out","w");
	for(int i=0;i<10;i++)
	{
		fscanf(f1,"%s %s %s",&add[i].name, &add[i].phone, &add[i].email);
		printf("%s %s %s\n",add[i].name,add[i].phone, add[i].email);

		//fprintf(f2,"%s %s %s\n",&add[i].name, &add[i].phone, &add[i].email);
	}
	//insertion_sort(add,10);
	selection(add,10);
	printf("==================");
	printf("sau khi sap xep\n");
	for(int i=0;i<10;i++)
	{
		fprintf(f2,"%s %s %s\n",&add[i].name, &add[i].phone, &add[i].email);
		printf("%s %s %s\n", add[i].name,add[i].phone, add[i].email);
	}
	
	fclose(f1);
	fclose(f2);
	return 0;
	

}