/*-Khai báo cấu trúc "Address" chứa ít nhất "name", "telephone number" và "e-mail address".
-Viết chương trình sao chép danh bạ từ một tệp sang tệp khác sử dụng ngăn xếp. 
Đầu tiên, đọc danh bạ từ một tệp vào ngăn xếp sử dụng hàm push(). 
Sau đó lấy các phần tử từ ngăn xếp sử dụng hàm pop() và ghi vào tệp.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[30];
	int tel; //telephone number
	char mail[50]; //e-mail address
} address;

typedef struct node
{
	address add;
	struct node* next;
} node;

typedef struct node* Stack;

node* makeNode(char _name[], int _tel, char _mail[])
{
	node* new=malloc(sizeof(node));
	strcpy(new->add.name, _name);
	new->add.tel = _tel;
	strcpy(new->add.mail, _mail);
	new->next=NULL;
	return new;
}

void push(Stack* Sptr, char _name[], int _tel, char _mail[])
{	
	node* new=makeNode(_name, _tel, _mail);
	new->next=*Sptr;
	*Sptr=new;
}

void pop(Stack* Sptr)
{
	if(*Sptr==NULL)
	{
		printf("Stack NULL -> ko pop\n");
		return;
	}
	node* next=(*Sptr)->next;
	
	node* topnode=*Sptr;
	topnode->next=NULL;	
	free(topnode);
	
	*Sptr=next;
}

void top(Stack S)
{
	if(S==NULL)
	{
		printf("Stack NULL -> ko top\n");
		return;
	}
	printf("Top: %s %d %s\n", S->add.name, S->add.tel, S->add.mail);
}

void traversal(Stack S)
{
	if(S==NULL)
	{
		printf("Stack NULL -> ko traversal\n");
		return;
	}
	node* tmp=S;
	while(tmp!=NULL)
	{
		printf("%s %d %s\n", tmp->add.name, tmp->add.tel, tmp->add.mail);
		tmp=tmp->next;
	}
}

int main()
{
	FILE *f1, *f2;
	char file_in[]="team-btvn2-file";
	char file_out[]="team-btvn-fileout-stack";
	if((f1=fopen(file_in, "r"))==NULL)
	{
		printf("KO the mo file_in\n");
		return 0;
	}
	f2=fopen(file_out, "w");
	Stack S=NULL;
	
	//đọc file va nhập vào ngăn xếp
	while(!feof(f1))
	{
		char _name[30];
		int _tel;
		char _mail[50];
		fscanf(f1, "%s %d %s", _name, &_tel, _mail);
		if(S!=NULL)
		{
			//xóa lặp dòng cuối khi dùng feof
			if(strcmp(_name, S->add.name)==0 && _tel==S->add.tel && strcmp(_mail, S->add.mail)==0)
			{
				continue;
			}
		}
		//push(Stack* Sptr, char _name[], int _tel, char _mail[])
		push(&S, _name, _tel, _mail);
	}
	
	printf("traversal:\n");
	traversal(S);
	
	//từ ngăn xếp copy ra file_out
	while(S!=NULL)
	{
		fprintf(f2, "%s %d %s\n", S->add.name, S->add.tel, S->add.mail);
		pop(&S);
	}
	
	fclose(f1);
	fclose(f2);
}
