#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct _node{
	int data;
	struct _node *left;
	struct _node *right;
}node;

void printLeaf(node *root){
	node *temp= root;
	if(temp==NULL)return;
	printTreeInOrder(temp->left);
	printf("%d ",temp->data);
	printTreeInOrder(temp->right);
}

void printTreeInOrder(node *root){
	node *temp= root;
	if(temp==NULL)return;
	printTreeInOrder(temp->left);
	printf("%d ",temp->data);
	printTreeInOrder(temp->right);
}

void printTreePreOrder(node *root){
	node *temp= root;
	if(temp==NULL)return;
	printf("%d ",temp->data);
	printTreePreOrder(temp->left);
	printTreePreOrder(temp->right);
}

void printTreePostOrder(node *root){
	node *temp= root;
	if(temp==NULL)return;
	printTreePostOrder(temp->left);
	printTreePostOrder(temp->right);
	printf("%d ",temp->data);
}

void minValue(node *root){
	node*temp;
	temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	printf("%d\n",temp->data);
}

void maxValue(node *root){
	node*temp;
	temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	printf("%d\n",temp->data);
}

node* insertNode(node* root,node*new){
	node *temp;
	temp=root;
	while(1){
		if(new->data<temp->data){
			if(temp->left!=NULL){
				//printf("hi\n");
				temp=temp->left;
			}
			else{
				temp->left=new;
				break;
			}
		}else{
			if(temp->right!=NULL)temp=temp->right;
			else{
				temp->right=new;
				break;
			}
		}
	}
	//printf("%d ",new->data);
	return root;
}

node *createNode(int data){
	node *temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int main()
{
	int i,x,n;
	// scanf("%d",&n);
	n=100;
	srand (time(NULL));
	x=rand()%1000;
	node *root=createNode(x);
	for(i=0;i<n-1;i++){
		x=rand()%1000;
		node *temp=createNode(x);
		root=insertNode(root,temp);
	}
	// minValue(root);
	// maxValue(root);
	printTreeInOrder(root);
	printf("\n");
	// printTreePreOrder(root);
	// printf("\n");
	// printTreePostOrder(root);

	return 0;
}