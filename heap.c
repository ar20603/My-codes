#include<stdio.h>
#include<stdlib.h>

int parent(int x){
	return (x-1)/2;
}

int leftChild(int x){
	return 2*x+1;
}

int rightChild(int x){
	return 2*x+2;
}

int a[100];
int heapSize=-1;

void swap(int *a,int *b){
	// printf("%d %d\n",*a,*b);
	int t;
	t=*a;
	*a=*b;
	*b=t;
	// printf("%d %d\n",*a,*b);
}


void insertTopToBottom(int x){
	heapSize++;
	a[heapSize]=x;
	int i=heapSize;
	while(i>=1 && a[i]>a[parent(i)]){
		swap(&a[i],&a[parent(i)]);
		i=parent(i);
	}
	// printf("%d %d in",i,a[i]);
}

void print(){
	int i;
	for(i=0;i<=heapSize;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int max(int i,int l,int r){
	int largest=i;
	if(l<=heapSize && a[l]>a[i]){
		largest=l;
	}
	if(r<=heapSize && a[r]>a[largest]){
		largest=r;
	}
	return largest;
}

void maxHeapify(int i){
	int m=max(i,leftChild(i),rightChild(i));
	if(m!=i){
		swap(&a[i],&a[m]);
		maxHeapify(m);
	}
}

void heapSort(){
	while(heapSize>=1){
		swap(&a[0],&a[heapSize]);
		heapSize--;
		maxHeapify(0);
	}
}

int extractMax(){
	int x;
	if(heapSize<0)return -1;
	else if(heapSize==0)return a[heapSize--];
	else {
		x=a[0];
		a[0]=a[heapSize--];
		maxHeapify(0);
	}
	return x;
}

void delete(int i){
	a[i]=a[heapSize--];
	if(a[i]>a[parent(i)]){
		while(a[i]>a[parent(i)]){
			swap(&a[i],&a[parent(i)]);
			i=parent(i);
		}
	}else{
		maxHeapify(i);
	}
}

int main()
{
	int n,m,l,k,j,i;
	int b[10]={4,16,1,2,8,7,9,3,10,14};
	for(i=0;i<10;i++){
		// insertTopToBottom(b[i]);
		a[i]=b[i];
	}
	heapSize=9;
	// print();
	for(i=9;i>=0;i--){
		maxHeapify(i);
	}
	print();
	// heapSort();
	// print();
	// l=extractMax();
	// l=extractMax();
	// l=extractMax();
	// printf("%d \n",l )
	delete(3);
	print();
	return 0;
}