/*Khai báo cấu trúc "Address" chứa ít nhất "name", "telephone number" và "e-mail address".
Viết chương trình sao chép danh bạ từ một tệp sang tệp khác sử dụng hàng đợi. 
Đầu tiên, đọc danh bạ từ một tệp vào hàng đợi sử dụng hàm enqueue(). 
Sau đó lấy các phần tử từ hàng đợi sử dụng hàm dequeue() và ghi vào tệp*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[30];
	int telephone; //telephone number
	char mail[50]; //e-mail address
} address;

typedef struct node
{
	address add;
	struct node* next;
} node;

typedef struct
{
	node* front;
	node* rear;
} Queue;

node* makeNode(char _name[], int _tel, char _mail[])
{
	node* new=malloc(sizeof(node));
	strcpy(new->add.name, _name);
	new->add.telephone = _tel;
	strcpy(new->add.mail, _mail);
	new->next=NULL;
	return new;
}

void initQ(Queue* Q)
{
	Q->front=NULL;
	Q->rear=NULL;
}

int isEmpty(Queue Q)
{
	return Q.rear==NULL && Q.front==NULL;
}

void enQ(Queue* Q, char _name[], int _tel, char _mail[])
{
	node* new=makeNode(_name, _tel, _mail);
	if(isEmpty(*Q))
	{
		Q->front=Q->rear=new;
		return;
	}
	Q->rear->next=new;
	Q->rear=new;
}

void deQ(Queue* Q)
{
	if(isEmpty(*Q))
	{
		printf("Q NULL -> ko xoa\n");
		return;
	}
	if(Q->rear==Q->front)
	{
		initQ(Q);
		return;
	}
	Q->front=Q->front->next;
}

void traversal(Queue Q)
{
	if(isEmpty(Q))
	{
		printf("Q NULL -> ko in\n");
		return;
	}
	node* tmp=malloc(sizeof(node));
	for(tmp=Q.front; tmp!=Q.rear; tmp=tmp->next)
	{
		printf("%s %i %s\n", tmp->add.name, tmp->add.telephone, tmp->add.mail);
	}
	printf("%s %i %s\n", (Q.rear)->add.name, (Q.rear)->add.telephone, (Q.rear)->add.mail);
}

int main()
{
	FILE *f1, *f2;
	char file_in[50]="team-btvn2-file";
	char file_out[50]="team-btvn-fileout";
	if((f1=fopen(file_in, "r"))==NULL)
	{
		printf("KO the mo file_in\n");
		return 0;
	}
	f2=fopen(file_out, "w");
	Queue Q;
	initQ(&Q);

	//đọc file va nhập vào hàng đợi
	while(!feof(f1))
	{
		char _name[30];
		int _tel;
		char _mail[50];
		fscanf(f1, "%s %d %s", _name, &_tel, _mail);
		if(Q.rear!=NULL)
		{
			//xóa lặp dòng cuối khi dùng feof
			if(strcmp(_name, (Q.rear)->add.name)==0 && _tel==(Q.rear)->add.telephone && strcmp(_mail, (Q.rear)->add.mail)==0)
			{
				continue;
			}
		}
		//enQ(Queue* Q, char _name[], int _tel, char _mail[])
		enQ(&Q, _name, _tel, _mail);
	}
	printf("traversal:\n");
	traversal(Q);
	
	//từ haàng đợi copy ra file_out
	while(Q.front!=Q.rear)
	{
		fprintf(f2, "%s %d %s\n", (Q.front)->add.name, (Q.front)->add.telephone, (Q.front)->add.mail);
		deQ(&Q);
	}
	fprintf(f2, "%s %d %s\n", (Q.front)->add.name, (Q.front)->add.telephone, (Q.front)->add.mail);
	deQ(&Q);
	
	fclose(f1);
	fclose(f2);
}
