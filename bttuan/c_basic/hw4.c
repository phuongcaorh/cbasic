/* viet chuong trinh quan li sinh vien voi cac chuc nang sau
- sinh vien duoc luu tru theo diem giam dan
- them vao sinh vien moi, khi them yeu cau giu nguyen thu tu cua diem
- tim sinh vien theo ID
- xoa sinh vien theo ID
Yeu cau dung danh sach lien ket don */
#include<stdio.h>
#include<stdlib.h>
typedef struct Student_t
{
	char id[10];
	char name[50];
	char grade[5];
	struct Student_t *next;
}Student;
void clear(void)
{
	int c;
	while((c=getchar())!='\n' &&c!=EOF);
}
// them vao dau danh sach

	Student *insert(Student *head)
	{
		Student  *pNew = (Student *)malloc(sizeof(Student));
		printf("Nhap vao thong tin moi: \n");
		printf("id: \n");
		gets(pNew->id);
		printf("name: \n");
		clear();
		gets(pNew->name);
		clear();
		printf("grade: \n");
		gets(pNew->grade);
		// gan phan tu vao dau danh sach
		pNew->next=head;
		head=pNew;
		return head;
	}


// in ra man hinh thong tin nhap duoc
void print1(Student *head)
{
	Student *p = head;
	printf("Noi dung danh sach: \n");
	while(NULL!=p)
	{
		printf("%s %s %s", p->id, p->name, p->grade);
		p = p->next;
	}
}
// tim sinh vien theo ID
void tim(Student *list, const char *mssv)
{
	printf("tim kiem thong thin sinh vien theo id: %s", mssv);
	int dem=0;
	Student *p=list;
	while(NULL!=p)
	{
		if(strstr((p->id),mssv)!=NULL)
		{
			printf("thong tin: %s %s %s",p->id,p->name,p->grade);
			dem=dem+1;
		}
		p=p->next;
	}


}
