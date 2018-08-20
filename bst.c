#include<stdio.h>
#include <stdlib.h>

/* Aman Raj 170101006  */

typedef struct _node 
{
	struct _node *left;
	struct _node *right;
	struct _node *parent;
	int data;
}node ;

node *createNode(int x){
	node *p=(node*)malloc(sizeof(node));
	p->right=NULL;
	p->left=NULL;
	p->parent=NULL;
	p->data=x;
	return p;
}

node* insert(node * root, int data){
	//printf("%d\n",root->data );
	node *newNode=createNode(data);
	node *p=root;
	node *q=NULL;
	while(p!=NULL){
		q=p;
		if(p->data<data){
			p=p->right;
		}
		else if(p->data>data){
			p=p->left;
		}
	}
	if(q->data>data){
		q->left=newNode;
	}else q->right=newNode;
	newNode->parent=q;
	return root;
}

void print(node*p){
	if(p==NULL)return;
	print(p->left);
	printf("%d ",p->data);
	print(p->right);
}

node *mininum(node *p){
	while(p->left!=NULL){
		p=p->left;
	}
	return p;
}

node* successor(node *p){
	if(p->right!=NULL){
		// printf("%d\n",p->data );
		return mininum(p->right);
	}
	else {
		node* q=p->parent;
		if(q==NULL)printf("No successor\n");
		while(q->right==p){
			p=q;
			q=q->parent;
		}
		return q;
	}
}

node * search(node *root,int data)
{
	node *p=root;
	if(p==NULL){
		printf("No root\n");
	}
	while(p!=NULL){
		if(data>p->data){
			p=p->right;
		}
		else if(data<p->data){
			p=p->left;
		}
		else{
			return p;
		}
	}
}

node * deleteNode(node *root,int x)
{
	node * p=search(root,x);
	if(p->left==NULL && p->right==NULL){

		printf("hello\n");
		if(p->parent==NULL){
			root=NULL;return root;
		}

		if(p->data>p->parent->data){
			p->parent->right=NULL;
			free(p);
		}
		else{
			p->parent->left=NULL;
			free(p);
		}

	}

	else if(p->left==NULL || p->right==NULL){
		if(p->parent==NULL){
			root=NULL;return root;
		}

		node *child;

		if(p->left!=NULL){
			child=p->left;
		}
		else child=p->right;

		if(p->data>p->parent->data){
			printf("%d chu %d f %d\n",p->data ,child->data,p->parent->data);
			p->parent->right=child;
			free(p);
		}
		else{
			p->parent->left=child;
			free(p);
		}
	}

	else{
		node *suc=successor(p);
		int x=suc->data;
		// printf("%d hi %d\n",x ,p->data);
		root=deleteNode(root,suc->data);
		p->data=x;
		printf("%d \n",p->left->data );
		printf("%d \n",p->data );
		printf("%d \n",p->right->data );

	}

	return root;
}

int check(node *p1,node *p2){
	if(p1==NULL && p2==NULL)return 1;
	else if(p1==NULL || p2==NULL)return 0;
	if(p1->data!=p2->data)return 0;
	check(p1->left,p2->left);
	check(p2->right,p2->right);
	return 1;
}

int main()
{
	int a[15]={40,20,80,10,30,60,100,5,22,35,200,3,1,33,500};
	int i;
	node *root,*root2;
	for(i=0;i<15;i++){
		if(i==0){
			root=createNode(a[i]);
			root->parent=NULL;
		}
		else {
			root=insert(root,a[i]);
		}
	}

	// root=deleteNode(root,1);
	// // root=deleteNode(root,20);
	// root=deleteNode(root,80);
	// // print(root);

	// root=deleteNode(root,100);
	// // root=deleteNode(root,5);
	root=deleteNode(root,200);

	print(root);
	printf("\n");

	root=deleteNode(root,500);

	print(root);
	printf("\n");

	// for(i=14;i>=0;i--){
	// 	if(i==14){
	// 		root2=createNode(a[i]);
	// 		root2->parent=NULL;
	// 	}
	// 	else {
	// 		root2=insert(root2,a[i]);
	// 	}
	// }

	// print(root2);
	// printf("\n");

	// int y=check(root,root);

	// printf("%d\n",y );

}