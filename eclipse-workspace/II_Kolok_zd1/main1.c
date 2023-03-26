/*
 * main1.c
 *
 *  Created on: Jan 1, 2022
 *      Author: David
 */
// 1va zad 2019
#include<stdio.h>
#define MAX 50
void podrediparnepar(int *a,int n){
int i,b[MAX],lev=0,desen=n-1;
for(i=0;i<n;i++){
	*(b+i) = *(a+i);
}
for(i=0;i<n;i++){
	if(*(a+i) % 2 == 0){
	*(b+lev)=*(a+i);
		lev++;
	}
	if(*(a+i) % 2 == 1){
	*(b+desen)=*(a+i);
		desen--;
		}
	}
for(i=0;i<n;i++){
	*(a+i)=*(b+i);
}
}
int main(){
	int a[MAX],n,i;
	printf("Vnesete broj na elementi vo nizata\n");
	fflush(stdout);
	scanf("%d",&n);
	printf("Zapocnete so vnesuvanje na elementi vo nizata\n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	podrediparnepar(a,n);
	printf("Transformiranata niza: \n");
	for(i=0;i<n;i++){
		printf("%d ",*(a+i));
	}


	return 0;
}

