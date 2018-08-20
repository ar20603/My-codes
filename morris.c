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

node *createNode(int x){
	node *p=(node*)malloc(sizeof(node));
	p->right=NULL;
	p->left=NULL;
	// p->parent=NULL;
	p->data=x;
	return p;
}

// void print(node*p){
// 	if(p==NULL)return;
// 	print(p->left);
// 	printf("%d ",p->data);
// 	print(p->right);
// }

node* insert(node *root, int data)
{
	node *tmp=createNode(data);
	node *p=root;
	node*q=NULL;
	while(p!=NULL){
		q=p;
		if(p->data>data){
			p=p->left;
		}else{
			p=p->right;
		}
	}

	if(q->data>data){
		q->left=tmp;
	}
	else{
		q->right=tmp;
	}
	return root;
}

void morrisTraversal(node *root)
{
	node *p=root;
	node*q=NULL;
	if(root==NULL)return;
	while(p!=NULL){
		if(p->left==NULL){
			printf("%d ",p->data );
			p=p->right;
		}
		else{
			q=p->left;
			
			while(q->right!=NULL && q->right!=p){
				q=q->right;
			}
			if(q->right==NULL){
				q->right=p;
				p=p->left;
			}
			else{
				p=p->right;
				printf("%d ",p->data );
				q->right=NULL;
			}
		}
		
	}
}

int main()
{
	node *root;
	int a[15]={40,20,80,10,30,60,100,5,22,35,200,3,1,33,500};
	int i;
	for(i=0;i<15;i++){
		if(i==0){
			root=createNode(a[i]);
			// root->parent=NULL;
		}
		else {
			root=insert(root,a[i]);
		}
	}

	morrisTraversal(root);
}
