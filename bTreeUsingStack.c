#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	int data;
	struct _node *left;
	struct _node *right;
}node;

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



node *stack[1000];
int top=-1;

void push(node *x){
	top++;
	stack[top]=x;
}

node *pop(){
	top--;
	return stack[top+1];
}

int empty(){

	if(top>=0)return 0;
	else return 1;
}

void inOrder(node *root){
	node* p;
	p=root;
	do{
		while(p!=NULL){
			push(p);
			p=p->left;
		}
		if(!empty()){
			p=pop();
			//printf("hi\n");
			printf("%d ",p->data);
			p=p->right;
		}
	}while(!empty() || p!=NULL);
}

void preOrder(node *root){
	node* p;
	p=root;
	do{
		while(p!=NULL){
			push(p->right);
			printf("%d ",p->data);
			p=p->left;
		}
		if(!empty()){
			p=pop();
			//printf("hi\n");
			// p=p->right;
		}
	}while(!empty() || p!=NULL);
}

int main()
{
	int i,x,n;
	// scanf("%d",&n);
	n=9;
	int a[9]={8,3,10,1,6,4,7,14,13};
	// srand (time(NULL));
	// x=rand()%1000;
	node *root=createNode(a[0]);
	
	for(i=1;i<n;i++){
		//x=rand()%1000;
		node *temp=createNode(a[i]);
		root=insertNode(root,temp);
	}

	//inOrder(root);
	preOrder(root);

}
