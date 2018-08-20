#include<stdio.h>
#include <stdlib.h>

/* Aman Raj 170101006  */

typedef struct _node 
{
	struct _node *left;
	struct _node *right;
	// struct _node *parent;
	int data;

}node ;
int preIndex=0;

node *createNode(int x){
	node *p=(node*)malloc(sizeof(node));
	p->right=NULL;
	p->left=NULL;
	// p->parent=NULL;
	p->data=x;
	return p;
}

int search(int in[],int inStart,int inEnd,int x){
	int i;
	for(i=inStart;i<inEnd;i++){
		if(in[i]==x)return i;
	}
}

node *buildTree(int pre[],int in[],int inStart,int inEnd){
	if(inStart>inEnd)return NULL;

	node *newNode=createNode(pre[preIndex++]);
	int index=search(in,inStart,inEnd,newNode->data);

	if(inStart == inEnd)
    return newNode;

	newNode->left=buildTree(pre,in,inStart,index-1);
	newNode->right=buildTree(pre,in,index+1,inEnd);
	return newNode;
}

void print(node*p){
	if(p==NULL)return;
	print(p->left);
	printf("%d ",p->data);
	print(p->right);
}

int main()
{
	node *root;
	int pre[]={40,20,10,30,22,80,60,100};
	int in[]={10,20,22,30,40,60,80,100};

	root=buildTree(pre,in,0,7);
	print(root);
	printf("\n");
	return 0;
}