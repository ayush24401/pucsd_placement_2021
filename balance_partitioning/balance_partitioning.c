#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int sumleft(int arr[],int k){
	int sum=0;
	for(int i=k-1;i>=0;i--){
		sum=sum+arr[i];
	}
	return sum;
}

int sumright(int arr[],int k,int size){
	int sum=0;
	for(int i=k+1;i<size;i++){
		sum=sum+arr[i];
	}
	return sum;
}

int balance_partition(int arr[],int size,int N,int min,int diff){
	
	if(min<diff){
		return N+2;
	}	
	int suml=sumleft(arr,N);
	int sumr=sumright(arr,N,size);

	int difference=suml-sumr;
	diff=abs(difference);
	if(diff<min){
		min=diff;
	}
	return balance_partition(arr,size,N-1,min,diff);
}


void main(int argc, char *argv[]){
	int N = atoi(argv[1]);
	//creating the list
	int arr[1000];
	for(int i=0;i<N;i++){
		arr[i]=(2*i)+4;
		//printf(" %d",arr[i]);
	}
	
	int partition=balance_partition(arr,N,N-1,INT_MAX,0);
	printf("%d",partition);
}