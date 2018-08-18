#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct _node{
	int data;
	struct _node *left;
	struct _node *right;
	bool rightthread;
}node;

node *createNode(int data){
	node *temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->rightthread=false;
	return temp;
}

