#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// khoi tao kiem tra
typedef struct nodeType 
{
	char data[2];
	struct nodeType *left, *right;
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
 treeType leftChild(treeType n)
{
	if (n!=NULL) 
		return n->left;
	else 
		return NULL;
}
treeType rightChild(treeType n)
{
	if (n!=NULL) 
		return n->right;
	else 
		return NULL;
} 
// tao nut moi
nodeType *createNode(char _data[])
{
	nodeType *N;
	N=(nodeType*)malloc(sizeof(nodeType));
	if (N != NULL)
	{
		N->left = NULL;
		N->right = NULL;
		strcpy(N->data, _data);
	}
	return N;
	
}
// tinh de quy so nut
int nb_nodes(treeType T)
	{
	if(emptyTree(T)) 
		return 0;
	else 
		return 1+nb_nodes(leftChild(T))+nb_nodes(rightChild(T));
	} 
// tao cay tu hai cay con
treeType createfrom2(char _data[],treeType l, treeType r)
{
	treeType N;
	N=(nodeType*)malloc(sizeof(nodeType));
	strcpy(N->data,_data);
	N->left=l;
	N->right=r;
 	return N;
}
//them nut vao ben trai nhat
treeType Add_Left(treeType *Tree, char _data[])
{ 
	nodeType *NewNode = createNode(_data);
	if (NewNode == NULL) return (NewNode);
	if (*Tree == NULL)
	*Tree = NewNode;
	else{
	nodeType *Lnode = *Tree;
	while (Lnode->left != NULL)
	Lnode = Lnode->left;
	Lnode->left = NewNode;
	}
	return (NewNode);
}
// them nut vao ben phai nhat
 treeType Add_Right(treeType *Tree, char _data[])
{ 
	nodeType *NewNode = createNode(_data);
	if (NewNode == NULL) return (NewNode);
	if (*Tree == NULL)
		*Tree = NewNode;
	else{
	nodeType *Rnode = *Tree;
	while (Rnode->right != NULL)
	Rnode = Rnode->right;
	Rnode->right = NewNode;
} 
return (NewNode);
} 
// ham duyet cay nhi phan theo thu tu giua
void printInorder(treeType Tree)
{
	if(Tree != NULL)
	{
		printInorder(Tree->left);
		printf("%s", Tree->data);
		printInorder(Tree->right);
	}
}

int MAX(int a, int b)
{
	return a>b?a:b;
}
//tinh chieu cao cay=1+ chieu cao lon nhat cac nut tren cay// chieu cao=chieu sau
int height(treeType T)
{
	if(NULL == T) return 0;
	if(NULL ==leftChild(T) && NULL == rightChild(T)) return 1;
	if(NULL ==leftChild(T)) return height(rightChild(T))+1;
	if(NULL ==rightChild(T)) return height(leftChild(T))+1;
	
	return 1 + MAX(height(leftChild(T)),height(rightChild(T)) );
}
int countLeaves(treeType T)
{
    if (NULL == T)return 0;
    if(NULL ==leftChild(T)&&NULL==rightChild(T)) return 1;
    return countLeaves(leftChild(T))+countLeaves(rightChild(T));
}
int countnuttrong(treeType T)
{
	int a;
	a=nb_nodes(T)-countLeaves(T)-1;
	return a;
}
int countchidright(treeType T)
{
	if(NULL ==T)return 0;
	if(NULL ==rightChild(T)) return 1;
	return countchidright(rightChild(T));
}

int main()
{
	char data[2];
	treeType T1;
	makeNullTree(&T1);
	Add_Left(&T1,"!");
	Add_Left(&T1,"a");

	treeType T2;
	makeNullTree(&T2);
	Add_Left(&T2,"-");
	Add_Left(&T2,"b");
	Add_Right(&T2,"c");

	treeType T3;
	makeNullTree(&T3);
	Add_Right(&T3,"d");

	treeType T4;
	makeNullTree(&T4);
	T4 = createfrom2("/",T2,T3);
	treeType T;
	makeNullTree(&T);
	T= createfrom2("+",T1,T4);
	
	printInorder(T);
	printf("\nchieu cao cua cay la %d\n", height(T));
	printf("so nut cua cay la %d:\n",nb_nodes(T));
	printf("so nut la cua cay la %d\n",countLeaves(T));
	printf("so nut trong %d:\n",countnuttrong(T));
	printf("so con phai %d: \n", countchidright(T));
	return 0;
}
