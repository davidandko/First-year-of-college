/*
 * main4.c
 *
 *  Created on: Jan 11, 2022
 *      Author: David
 */
#include<stdio.h>
void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(){
	int t[10],v[10],i,j,n;

	printf("Vnesete gi dolzinite na nizite\n");
	fflush(stdout);
	scanf("%d",&n);

	printf("Vnesuvajte gi nizite\n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d%d",&t[i],&v[i]);
	}

	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(v[i]>v[j]){
				swap(&v[i],&v[j]);
				swap(&t[i],&t[j]);
			}
		}
	}
	printf("Sortiranite nizi se: \n");
	for(i = 0;i,n;i++){
		printf("(%d, %d)",t[i],v[i]);
		printf("\n");
	}
	for(i=0;i<n-1;i++){
		if(v[i]>=v[i+1] || t[i]>=t[i+1]){
			printf("Nizite go ispolnuvaat uslovot\n");
		}
		else{
			printf("Nizite ne go ispolnuvaat uslovot\n");
		}
	}
	return 0;
}
