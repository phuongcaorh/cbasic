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
// ham duyet cay nhi phan theo thu tu truoc
void printPreorder(treeType Tree)
{
	if(Tree != NULL)
	{
		printf("%s", Tree->data);
		printPreorder(Tree->left);
		printPreorder(Tree->right);
	}
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
//ham duyet cay nhi phan theo thu tu sau
void printPostorder(treeType Tree)
{
	if(Tree != NULL)
	{
		printPostorder(Tree->left);
		printPostorder(Tree->right);
		printf("%s",Tree->data);
	}
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
	//printPreorder(T);
	printInorder(T);
	//printPostorder(T);

	return 0;
}
