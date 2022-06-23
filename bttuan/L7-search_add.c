/*Xây dựng danh bạ điện thoại
• Khai báo cấu trúc có chứa name, telephone number và e-mail address.
• Khai báo mảng chứa tối đa 100 bản ghi
• Nhập 10 địa chỉ từ tệp vào mảng (đã sắp xếp theo thứ tự từ điển của name)
• Yêu cầu người dùng nhập name, in ra chỉ số đầu tiên có name khớp với name nhập vào; in ra 
“not found” nếu không tìm thấy*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[30];
	char phone[30]; 
	char email[30]; 
} Address;

int Search(Address Add[], char key[], int lo, int hi)
{
	if(lo==hi)
	{
		if(strcmp(key, Add[lo].name)==0)
		{	
			return lo;
		}
		return -1;
	}
	int mid=(lo+hi)/2;
	if(strcmp(key, Add[mid].name)==0)
	{
		 return mid;
	}else if(strcmp(key, Add[mid].name)<0)
	{
		Search(Add, key, lo, mid);
	}else
	{
		Search(Add, key, mid+1, hi);
	}
}

int main()
{
	Address Add[100];
	FILE *f1, *f2;
	char file_in[]="L8-file";
	if((f1=fopen(file_in, "r"))==NULL)
	{
		printf("KO the mo file_in\n");
		return 0;
	}
	for(int i=0; i<10; i++)
	{
		char _name[30];
		char _phone[30];
		char _email[50];
		fscanf(f1, "%s %s %s", _name, _phone, _email);
		printf("%s %s %s\n", _name, _phone, _email);
		strcpy(Add[i].name, _name);
		strcpy(Add[i].phone, _phone);
		strcpy(Add[i].email, _email);
	}
	printf("tim kiem nguoi co ten la: ");
	char _name[30];
	gets(_name);
	int kq=Search(Add, _name, 0, 10-1);
	if(kq!=-1)
	{
		printf("Tim thay tai i = %d\n", kq);
	}else
	{
		printf("Not Found!\n");
	}
}
