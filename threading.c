#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _node{
	struct _node *left;
	struct _node *right;
	int data;
	bool rightTraversal;
}node;

node* createNode(int data){
	node *temp=(node*)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	temp->rightTraversal=false;

	return temp;
}

node *search(node *p,int x){
	node *q;
	if(p==NULL)return NULL;

	if(p->data==x)return p;
	q=search(p->left,x);
	if(q!=NULL){
		return q;
	}
	else{
		if(p->rightTraversal==false){
			q=search(p->right,x);
			return q;
		}
		else return NULL;
		
	}	
}




node* insert(node *root,int par,int data,char ch){

	node* newNode=createNode(data);
	if(par==-1){
		root=newNode;return root;
	}

	node *p=search(root,par);
	if(p==NULL){
		printf("parent not found\n");
	}
	if(ch=='L'){
		p->left=newNode;
		newNode->right=p;
		newNode->rightTraversal=true;
	}
	else{
		newNode->right=p->right;
		p->right=newNode;
		p->rightTraversal=false;
		newNode->rightTraversal=true;
	}
	return root;
}


void inOrder(node *root){
	node*p=root;
	if(p==NULL)return ;
	do{
		//printf("hi\n");
		while(p->left!=NULL){
			p=p->left;
		}
		printf("%d ",p->data );
		while(p->rightTraversal && p->right!=NULL){
			p=p->right;
			printf("%d ",p->data );
		}
		p=p->right;
	}while(p!=NULL);

}

void inorder(node *root){
	node *p;
	p=root;
	node *q;
	do{
		q=NULL;
		while(p!=NULL){
			q=p;
			p=p->left;
		}
		if(q!=NULL){
			printf("%d ",q->data);
			p=q;
			p=p->right;
			while(q->rightTraversal && p!=NULL){
				printf("%d ",p->data);
				q=p;
				p=p->right;
			}
		}	
	}while(q!=NULL);
}


int main(){
	// int a[15]={40,20,80,10,30,60,100,5,22,35,200,3,1,33,500};
	int i;
	node *root=NULL;
	char L='L';
	char R='R';
	root=insert(root,-1,18,L);
	root=insert(root,18,2,L);
	root=insert(root,2,8,L);
	root=insert(root,18,3,R);
	root=insert(root,3,10,L);
	root=insert(root,3,12,R);
	root=insert(root,10,7,L);
	root=insert(root,10,9,R);
	root=insert(root,7,81,R);
	root=insert(root,81,1,L);
	root=insert(root,1,20,R);

	inOrder(root);
}
