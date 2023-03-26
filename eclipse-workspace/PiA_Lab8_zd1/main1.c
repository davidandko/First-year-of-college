/*
 * main1.c
 *
 *  Created on: Dec 19, 2021
 *      Author: David
 */
#include<stdio.h>
#define MAX 100
int minmax(int a[],int n,int *min, int *max){
	int i;
	*min=*max=*(a+0);
for(i=0;i<n;i++){
	if(*(a+i)>*max){
		*max=*(a+i);
	}
	if(*(a+i)<*min){
		*min=*(a+i);
	}
}
return 0;
}

int main(){
	int min,max,i,n;
	int a[MAX];
	printf("Vnesete broj na clenovi vo nizata\n");
	fflush(stdout);

	scanf("%d",&n);

	printf("Vnesuvajte clenovi vo nizata: \n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	minmax(a,n,&min,&max);
	printf("Minimum: %d ; Maksimum: %d",min,max);
return 0;
}
