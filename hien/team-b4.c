/*Cho cấu trúc danh bạ điện thoại và danh sách liên kết đơn:

typedef struct _address {
  char name[30];
  char phone[30];
  char email[30];
}Address;

typedef struct _node {
  Address data;
  struct _node *next;
}node;

Hãy viết các hàm tìm kiếm một phần tử trong danh sách theo name sử dụng các thuật toán linear_search,
sentinel_search và transpose, hàm trả về địa chỉ của các phần tử nếu tìm được (trong trường hợp transpose thì
trả về địa chỉ sau khi đổi chỗ). Nếu không tìm được trả về NULL. Cho biết nguyên mẫu của các hàm:
Node* linear_search(Node *head, char key[30]);
Node* sentinel_search(Node *head, char key[30]);
Node* transpose(Node *head, char key[30]); */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[30];
	char phone[30]; 
	char email[30]; 
} Address;

typedef struct _node {
  Address data;
  struct _node *next;
}node;

node* makeNode(char _name[], char _phone[], char _email[])
{
	node* new=malloc(sizeof(node));
	strcpy(new->data.name, _name);
	strcpy(new->data.phone, _phone);
	strcpy(new->data.email, _email);
	new->next=NULL;
	return new;
}

void add(node** headptr, char _name[], char _phone[], char _email[])
{
	node* new=makeNode(_name, _phone, _email);
	if(*headptr==NULL)
	{
		*headptr=new;
		return;
	}
	node* tmp=*headptr;
	while(tmp!=NULL)
	{
		if(tmp->next==NULL)
		{
			tmp->next=new;
			return;
		}
		tmp=tmp->next;
	}
}

void traversal(node* head)
{
	if(head==NULL)
	{
		printf("Rong");
		return;
	}
	node* tmp=head;
	while(tmp!=NULL)
	{
		printf("->%s %s %s\n", tmp->data.name, tmp->data.phone, tmp->data.email);
		tmp=tmp->next;
	}
}

node* linearSearch(node *head, char key[])
{
	node* tmp=head;
	while(tmp!=NULL && (strcmp(tmp->data.name, key)!=0))
		tmp=tmp->next;
	return tmp;
}

node* sentinelSearch(node *head, char key[])
{
	add(&head, key,"","");
	node* tmp=head;
	while((strcmp(tmp->data.name, key)!=0))
		tmp=tmp->next;
	if(tmp->next==NULL)
		return NULL;
	return tmp;
}

node* transpose(node **head, char key[])
{
	if((strcmp((*head)->data.name, key)==0))
		return *head;
	node* tmp=malloc(sizeof(node));
	for(tmp=*head; tmp->next!=NULL && (strcmp((tmp->next)->data.name, key)!=0); tmp=tmp->next);
	if(tmp->next==NULL)
		return NULL;
	if((strcmp((tmp->next)->data.name, key)==0))
	{
		node* change1=malloc(sizeof(node));
		strcpy(change1->data.name, tmp->data.name);
		strcpy(change1->data.phone, tmp->data.phone);
		strcpy(change1->data.email, tmp->data.email);
		
		strcpy(tmp->data.name, (tmp->next)->data.name);
		strcpy(tmp->data.phone, (tmp->next)->data.phone);
		strcpy(tmp->data.email, (tmp->next)->data.email);
		
		strcpy((tmp->next)->data.name, change1->data.name);
		strcpy((tmp->next)->data.phone, change1->data.phone);
		strcpy((tmp->next)->data.email, change1->data.email);
		
		traversal(*head);
		return tmp;
	}
}

int main()
{
	FILE *f1, *f2;
	char file_in[]="team-btvn2-file";
	if((f1=fopen(file_in, "r"))==NULL)
	{
		printf("KO the mo file_in\n");
		return 0;
	}
	
	node* head=NULL;
	for(int i=0; i<10; i++)
	{
		char _name[30];
		char _phone[30];
		char _email[50];
		fscanf(f1, "%s %s %s", _name, _phone, _email);
		printf("%s %s %s\n", _name, _phone, _email);
		add(&head, _name, _phone, _email);
	}
	do
	{
	printf("tim kiem nguoi co ten la: ");
	char _name[30];
	gets(_name);
//	node* a=linearSearch(head, _name);
//	node* a=sentinelSearch(head, _name);
	node* a=transpose(&head, _name);
	if(a==NULL)
	{
		printf("\nko tim thay thong tin cua nguoi co ten la '%s'\n", _name);
	}else
	{
		printf("\n--> Address: %s %s %s\n",a->data.name, a->data.phone, a->data.email);
	}
	printf("lua chon(chon 2 de thoat) =");
		int choose;
		scanf("%d%*c", &choose);
		if(choose==2)
			break;
	}
	while(1);
}
