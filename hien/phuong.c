/* doc  tep bang danh sach lien ket don roi in ra */

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _address
{
    char name[20];
    char phone[11];
    char email[50];
}Adress;
typedef struct Node {
   Adress data;
   struct Node *next;
}node;


//hien thi list
void printList(node *head) {

    node *ptr;
    ptr=head;

    printf("\n[head]: ");
   //bat dau tu phan dau cua list
   while(ptr != NULL) {
      printf("=> %s %s %s\n",ptr->data.name, ptr->data.phone, ptr->data.email);
      ptr = ptr->next;
   }
}

//chen link tai vi tri dau tien
//hàm insert làm thay đổi dslk nên phải truyền vào node head
void insert(node **head, char _name[], char _phone[], char _email[]) { 
   //tao mot link
   node *link = (node*)malloc(sizeof(node));

   //link->key = key;
   strcpy(link->data.name, _name);
   strcpy(link->data.phone, _phone);
   strcpy(link->data.email, _email);
   //tro link do toi first node cu
   link->next = *head;

   //tro first toi first node moi
   *head = link;
}
int main()
{
    node *head=NULL;
    FILE *f1;
    f1=fopen("tep.txt", "r");
    char _name[20];
    char _phone[11]; //ko nên để 10, nên để dư
    char _email[50];
    while(!feof(f1))
    {
        fscanf(f1,"%s %s %s", _name, _phone, _email);
        //điều kiện để bỏ lặp dòng cuối của eof: dữ liệu đọc vào ko giống đữ liệu đã được lưu vào head
        //và nó chỉ ktra khi head khác null
        if(head!=NULL)
        {
        	if(strcmp(_name, head->data.name)==0 && strcmp(_phone, head->data.phone)==0 && strcmp(_email, head->data.email)==0)
        	{
        		break;
        	}
        }
        printf("%s %s %s\n", _name, _phone, _email);
        insert(&head,_name, _phone, _email);// them vao dau

    }
    printList(head);
    fclose(f1);
}
