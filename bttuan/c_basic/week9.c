/*
• Xây dựng danh bạ điện thoại
• Khai báo cấu trúc có chứa các trường "name", "telephone
number", "e-mail address.”.
• Đọc 10 bản ghi từ tệp vào BST theo thứ tự tăng dần của email
• (1) Tìm một địa chỉ email
• (2) In ra thông tin các bản ghi từ BST theo thứ tự tăng dần của
email
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct address
{
	char name[50];
	char phone[11];
	char email[50];

}address;
typedef struct Node 
{
	address data;
	struct Node *left;
	struct Node *right;
}Node;
typedef struct Node* TreeType;

// them nut vao cay nhi phan tim kiem
void InsertNode(char _name[],char _phone[],char _email[],TreeType *Root ){
if ((*Root )== NULL){
/* Create a new node for key x */
	(*Root)=(Node*)malloc(sizeof(Node));
	//(*Root)->key = x;
	strcmp((*Root)->data.name, _name);
	strcmp((*Root)->data.phone, _phone);
	strcmp((*Root)->data.email, _email);
	(*Root)->left = NULL;
	(*Root)->right = NULL;
}
else if (strcmp(_email,(*Root)->data.email)<0) 
	InsertNode(_name,_phone,_email, &(*Root)->left);
else (strcmp(_email,(*Root)->data.email)>0)
	InsertNode(_name,_phone,_email, &(*Root)->right);
} 
void printtree(TreeType root)
{
	if(root!=NULL)
	{
		printf("%d\n",root-> data);
		root->left;
		root->right;

	}
}
int main()
{
	FILE*f1;
	address data;
	f1=fopen("file_in.txt","r");
	TreeType T=NULL;
	char _name[50];
	char _phone[11];
	char _email[50];
	while(!feof(f1))
	{
		fscanf(f1,"%s %s %s", _name, _phone, _email);
		// dieu kien bo lap dong cuoi cung
		if(T!=NULL)
        {
        	if(strcmp(_name, T->data.name)==0 && strcmp(_phone, T->data.phone)==0 && strcmp(_email, T->data.email)==0)
        	{
        		break;
        	}
        }
        printf("%s %s %s\n", _name, _phone, _email);
        InsertNode(_name,_phone,_email,&T);

	}
	printtree(T);
	fclose(f1);
}