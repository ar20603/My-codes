#include<bits/stdc++.h>
using namespace std;
/* Aman Raj 170101006  */

struct node {
	double data;
	struct node* next;
};

struct node* createNode(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}

double deleteFirst(struct node** head){
	struct node *first;
	first=*head;
	*head=first->next;
	double x=first->data;
	free(first);
	return x;
}


struct node* insertAtStart(struct node* head, double x){
	struct node* temp=createNode();
	temp->next=head;
	temp->data=x;
	head=temp;
	return head;
}

struct node* push(struct node* head, double x){
	head=insertAtStart(head,x);
	return head;
}


struct node* insertAtEnd(struct node* head, double x){
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

double pop(struct node** head){
	if(*head==NULL){
		printf("Invalid Input");
		return -1;
	}
	return deleteFirst(head);
}

void printList(struct node *list){      
    struct node* temp;
    temp=list;
    while(temp!=NULL)
    {
        printf("%f ",temp->data);
        temp=temp->next;
    }
}

int isOperand(char c){
	int t=c-'0';
	if(t>=0 && t<=9)return t;
	else return -1;
}

int popAndCombine(struct node **stack,char c){
	double x,y,r;
	y=pop(stack);
	x=pop(stack);
	if(x==-1 || y==-1){return -1;}
	if(c=='+')r=(double)x+y;
	if(c=='-')r=(double)x-y;
	if(c=='/')r=(double)x/y;
	if(c=='*')r=(double)x*y;
	*stack=push(*stack,r);
	//cout<<r<<endl;
	return 0;
}

double postToInf(string s,int n){
	struct node* stack;
	stack=NULL;
	for(int i=0;i<n;i++){
		int x=isOperand(s[i]);
		if(x!=-1){
			stack=push(stack,(double)x);
		}
		else{
			int y=popAndCombine(&stack,s[i]);
			if(y==-1)return 0;
		}
	}
	double p=pop(&stack);
	return p;
}

int main(){
	//string a;
	// head=push(head,5);
	// head=push(head,6);
	// head=push(head,2);
	// head=push(head,1);
	// printList(head);
	// a=pop(&head);
	// printf("%d\n",a);
	// printList(head);
	string s;
	cin>>s;
	double x=postToInf(s,s.length());
	if(x!=0)cout<<x<<endl;
	return 0;
}