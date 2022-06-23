#include "binarytree.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

// tao ra cay moi co goc la data 
TN* makeTree(char data)
{
	TN *pNew = (TN*)malloc(sizeof(TN));
	pNew->data = data;
	pNew->left = NULL;
	pNew->right = NULL;
	pNew->parent = NULL;
	return pNew;
}
// them nut moi cao cay khac rong
// nut moi them vao vi tri da xac dinh truoc 
// lan luot theo muc, tu trai sang phai
// neu isLeftChild=1 la con trai, nguoc lai la con phai
void addNode(char data, TN *parent, int isLeftChild)
{
	TN *pNew = (TN*)malloc(sizeof(TN));
	pNew->data = data;
	pNew->left = NULL;
	pNew->right = NULL;
	pNew->parent = parent;
	if(isLeftChild==1) parent->left = pNew;
	else parent->right = pNew;
}
// thu tu truoc
void preOrderTraversal(const TN *root)
{
	if(NULL==root) return;
	printf("%c ", root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
// thu tu giua
void inOrderTraversal(const TN *root)
{
	if(NULL==root) return;	
	inOrderTraversal(root->left);
	printf("%c ", root->data);
	inOrderTraversal(root->right);	
}

// thu tu sau
void postOrderTraversal(const TN *root)
{
	if(NULL==root) return;	
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%c ", root->data);
}

int MAX(int a, int b)
{
	return a>b?a:b;
}
int height(const TN *root)
{
	if(NULL == root) return -1;
	if(NULL ==root->left && NULL ==root->right) return 0;
	return 1+ MAX(height(root->left), height(root->right));
}
int countNodes(const TN *root)
{
	if(NULL == root) return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}
int countLeaves(const TN *root)
{
	if(NULL == root) return 0;
	if(NULL ==root->left && NULL ==root->right) return 1;
	return countLeaves(root->left) + countLeaves(root->right);
}
// tu lam
int countInternalNodes(const TN *root)
{
	
	return -1;
}

void levelOrderTraversal(const TN *root)
{
	initQueue();
	enqueue(root);
	while(!isEmpty())
	{
		TN* node = dequeue();
		printf("%c ", node->data);
		if(NULL!=node->left) enqueue(node->left);
		if(NULL!=node->right) enqueue(node->right);
	}
}
TN * depestLeaf(const TN *root)
{
	initQueue();
	enqueue(root);
	//TN *lastLeaf = NULL;
	TN* node;
	while(!isEmpty())
	{
		node = dequeue();
		//printf("%c ", node->data);
		//if(node->left==NULL && node->right==NULL) lastLeaf = node;
		if(NULL!=node->left) enqueue(node->left);
		if(NULL!=node->right) enqueue(node->right);
	}
	//return lastLeaf;
	return node;
}
TN * shallowestLeaf(const TN *root)
{
	// TODO
}
