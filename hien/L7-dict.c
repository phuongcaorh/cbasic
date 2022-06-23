/*Một từ điển được lưu trữ theo đúng thứ tự tại /usr/share/dict/words
1.Viết chương trình đọc từ điển vào mảng
2.Yêu cầu người dùng nhập vào một từ, tìm chỉ số của từ đó trong mảng,
  Nếu ko tìm thấy thì trả về -1 sử dụng tìm kiếm nhị phân 
  ko đệ quy int string_binary_search(char* dict[], char* key) ;
  hoặc đệ quy int string_binary(char* dict[], char* key, int low, int high);
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char word[30];
}dictt;

int string_binary(dictt dict[], char* key, int lo, int hi)
{
	if(lo==hi)
	{
		if(strcmp(key, dict[lo].word)==0)
		{	
			return lo;
		}
		return -1;
	}
	int mid=(lo+hi)/2;
	if(strcmp(key, dict[mid].word)==0)
	{
		 return mid;
	}else if(strcmp(key, dict[mid].word)<0)
	{
		string_binary(dict, key, lo, mid);
	}else
	{
		string_binary(dict, key, mid+1, hi);
	}
}

int main()
{
	dictt dict[30];
	FILE *f1;
	char file_in[]="/usr/share/dict/words";
	if((f1=fopen(file_in, "r"))==NULL)
	{
		printf("KO the mo file_in\n");
		return 0;
	}
	//while(!feof(f1))
	for(int i=0; i<30; i++)
	{
		char word[30];
		fgets(word, sizeof(word), f1);
		word[strlen(word)-1]=0;
		strcpy(dict[i].word, word);
		printf(" -> %s\n", dict[i].word);
	}
	printf("tim kiem: ");
	char word[30];
	gets(word);
	int size=sizeof(dict)/sizeof(dict[0]);
	int kq=string_binary(dict, word, 0, size-1);
	if(kq!=-1)
	{
		printf("Tim thay tai i = %d\n", kq);
	}else
	{
		printf("Not Found!\n");
	}
}
