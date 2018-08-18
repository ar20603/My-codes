#include<bits/stdc++.h>

/* Aman Raj 170101006  */

struct node {
	int data;
	struct node* next;
};

struct node* createNode(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}

int deleteFirst(struct node** head){
	struct node *first;
	first=*head;
	*head=first->next;
	int x=first->data;
	free(first);
	return x;
}


struct node* insertAtStart(struct node* head, int x){
	struct node* temp=createNode();
	temp->next=head;
	temp->data=x;
	head=temp;
	return head;
}

struct node* push(struct node* head, int x){
	head=insertAtStart(head,x);
	return head;
}


struct node* insertAtEnd(struct node* head, int x){
	struct node* temp=createNode();
	temp->data=x;
	struct node* p;
	p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=temp;
	temp->next=NULL;
	return head;
}

int pop(struct node** head){
	if(head==NULL){
		printf("Empty stack error");
		return 0;
	}
	return deleteFirst(head);
}

void printList(struct node *list){      
    struct node* temp;
    temp=list;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
	int a;
	struct node* head;
	head=NULL;
	head=push(head,5);
	head=push(head,6);
	head=push(head,2);
	head=push(head,1);
	printList(head);
	a=pop(&head);
	printf("%d\n",a);
	printList(head);
	return 0;
}