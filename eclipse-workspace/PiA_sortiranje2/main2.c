/*
 * main2.c
 *
 *  Created on: Jan 11, 2022
 *      Author: David
 */

#include<stdio.h>
void swap(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void simpleSort(int a[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}

}
void bubbleSort(int a[],int n){
	int i,j;
	for(i=0;i<n-1;i++){ // n-1-i posledna pozicija
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

int main(){
	int a[100],n,tip,i;

	printf("Vnesete dolzina na nizata\n");
	fflush(stdout);
	scanf("%d",&n);
	printf("Vnesete elementi vo nizata: \n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Vnesete tip na sortiranje: 0 - simple ; 1 - bubble\n");
	fflush(stdout);
	scanf("%d",&tip);
	if(tip == 0){
		simpleSort(a,n);
	}
	else if(tip == 1){
		bubbleSort(a,n);
	}
	else{
		printf("Takvo sortiranje se ushte nemame implementirano\n");
		return 0;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

