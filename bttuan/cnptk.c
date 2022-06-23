/* doc ghi tep su dung cay nhi phan tim kiem 
• Sử dụng cây nhị phân tìm kiếm để
lưu danh bạ điện thoại với email tăng
dần
• Hiển thị danh bạ theo thứ tự tăng
dần của email*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct address
{
	char name[50];
	char phone[11];
	char email[50];
}address;
typedef struct nodeType
{
	address data;
	struct node *left, *right;
}nodeType;
typedef struct nodeType *treeType;
void makeNullTree(treeType *T)
{
	(*T)=NULL;
}
int emptyTree(treeType T)
{
	return T==NULL;
}
// truy cap con trai, phai
 treeType leftChild(treeType T)
{
	if (T!=NULL) 
		return T->left;
	else 
		return NULL;
}
treeType rightChild(treeType T)
{
	if (T!=NULL) 
		return T->right;
	else 
		return NULL;
}

// tao nut moi
nodeType *createNode(char _name[], char _phone[], char _email[])
{
	nodeType *N;
	N=(nodeType*)malloc(sizeof(nodeType));
	if(N == NULL)
	{
		printf("error: out of memory\n");
		exit(1);
	}
	else
	{
		strcpy(N->data.name,_name);
		strcpy(N->data.phone,_phone);
		strcpy(N->data.email,_email);
		N->left=NULL;
		N->right=NULL;
	}
	return N;
	
}
// chen (insert)

void InsertNode(char _name[], char _phone[], char _email[],treeType *Root )
{
	if (*Root == NULL){

	(*Root)=(nodeType*)malloc(sizeof(nodeType));
	strcpy((*Root)->data.name,_name);
	strcpy((*Root)->data.phone,_phone);
	strcpy((*Root)->data.email,_email);
	(*Root)->left = NULL;
	(*Root)->right = NULL;
}
else if (_email < (*Root)->data.email) InsertNode(_name, _phone, _email,&(*Root)->left);
else if (_email > (*Root)->data.email) InsertNode(_name, _phone, _email, &(*Root)->right);
} 
//chen ver2
/*

treeType InsertNode(char _name[], char _phone[], char _email[],treeType Root ){
	if (Root == NULL){
	
	Root=(NodeType*)malloc(sizeof(NodeType));
	strcpy(Root->data.name,_name);
	strcpy(Root->data.phone,_phone);
	strcpy(Root->data.email,_email);
	Root->left = NULL;
	Root->right = NULL;
	Return Root;
}
else if (_email < Root->data.email) return InsertNode(_name, _phone, _email, Root->left);
else if (_email> Root->data.email) return InsertNode(_name, _phone, _email, Root->right);
} 
*/

// ham duyet cay nhi phan theo thu tu giua
void printInorder(treeType Tree)
{
	if(Tree != NULL)
	{
		printInorder(Tree->left);
		
		printInorder(Tree->right);
		printf("%s %s %s\n", Tree->data.name, Tree->data.phone, Tree->data.email);
		

	}
}

int main()
{	
	
	treeType T;
	address data[11];
	makeNullTree(&T);
	FILE *f1;
	f1=fopen("file_in.txt","r");
	char _name[50];
	char _phone[11];
	char _email[50];
	for(int i=0;i<10;i++)
	{
		// doc file va ghi vao cay nhi phan
		fscanf(f1,"%s %s %s",_name, _phone, _email);

		printf("%s %s %s \n",_name, _phone, _email);
		InsertNode(_name, _phone, _email, &T);
		
    }
    printf("???\n");
	printInorder(T);
	return 0;

	fclose(f1);

}