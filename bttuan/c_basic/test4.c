#include<stdio.h>
#include<stdlib.h>
typedef struct thongtin
{
	char diadiem[100];
	char gio[10];
	char phut[10];
}diadiem;
struct node{
	diadiem data;
	struct node *next;
};
struct node *head=NULL;
struct node *cur = NULL;
// hien thi list
void printList()
{
	struct node *ptr = head;
	// bat dau tu phan tu dau tien cua List
	while(ptr != NULL)
	{
		printf("%50s %10s %10s \n ",ptr->data.diadiem, ptr->data.gio, ptr->data.phut);
		ptr = ptr ->next;
	}
}
// chen dslk tai vtd
void insert( struct node **head, char _diadiem[], char _gio[], char _phut[])
{
	// tao 1 dslk
	struct node *link=(struct node *) malloc(sizeof( struct node));
	//link->key=key
	//link->data= data;
	strcpy(link->data.diadiem, _diadiem );
	strcpy(link->data.gio, _gio );
	strcpy(link->data.phut, _phut );;
	
	// tro link do toi first node cu
	link->next= (*head);
	// tro first toi first node moi
	(*head) = link;
	
}
/*void timkiem(struct node *head, char key[])
{
	printf("nhap vao mot dia diem :\n");
	gets(key);
	struct node *cur;
	while(head!=NULL)
	{
		if(strcmp((cur->data.diadiem),key)) ==0)
		printf("%s %s %s", data.diadiem, data.gio, data.phut);
	}
}
*/

int main()
{
	diadiem data[10];
	FILE *f1;
	char _diadiem[100];
	char _gio[10];
	char _phut[10];
	f1=fopen("log.txt","r");
	/*for(int i=0;i<11;i++)
	{
		fscanf(f1,"%s %s %s\n", _diadiem, _gio, _phut);
		printf("%s %s %s\n", _diadiem, _gio, _phut);
		insert(&head, _diadiem, _gio, _phut);
	}
	printList();
	fclose(f1);
	return 0; */
	// tao menu thuc hien cac chuc nang
	int luachon;
    do
    {
    	printf("==========================\n");
    	printf("CHUONG TRINH TRUY VET COVID19\n");
    	printf("1. Nap file log lich su di chuyen\n");
    	printf("2. In ra lich su di chuyen\n");
    	printf("3. Tim kiem lich su theo dia diem\n");
    	printf("4. Tim kiem lich su theo thoi gian\n");
    	printf("5. Kiem tra truy vet moi nhat\n");
    	printf("6. Thoat\n");
    	printf("===========================\n\n");
    	printf("nhap lua chon: \n");
    	scanf("%d", &luachon);
    	if (luachon != 1 && luachon!=2 && luachon !=3 && luachon!=4 && luachon !=5 &&luachon !=6)
    		{
    			printf("ko hop le\n");
    		}
    	else if(luachon ==1)
    	{
    		printf(" Nap file log lich su di chuyen\n");
    		
    		for(int i=0;i<11;i++)
			{
				fscanf(f1,"%s %s %s\n", _diadiem, _gio, _phut);
				//printf("%s %s %s\n", _diadiem, _gio, _phut);
				insert(&head, _diadiem, _gio, _phut);
			}
    	}
    	else if(luachon == 2)
    	{
    		// in lich su di chuyen
    		printList();
    	}
    	else if(luachon == 3)
    	{
    		printf("tim kiem lich su theo dia diem");
    		//timkiem;
    	}
    	else if(luachon == 4)
    	{
    		printf("tim kiem lich su theo thoi gian");
    	}
    	else if(luachon == 5)
    	{
    		printf("kiem tra truy vet moi nhat");
    	}
    	
    	else 
    	{
    		break;
    	}
    }
    while(1);
    printf("ket thuc\n");
	//printInorder(T);
	return 0;

	fclose(f1);
}