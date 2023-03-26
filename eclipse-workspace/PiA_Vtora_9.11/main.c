/*
 * main.c
 *
 *  Created on: Nov 9, 2021
 *      Author: David
 */
#include<stdio.h>
#include<math.h>
int eprost(int x){
	int i;
	for(i=2;i<x;i++){
		if(x%i==0)
			return 0;

		return 1;
	}
}
int main(){
int n,i;

	printf("Vnesete broj\n");
	fflsuh(stdout);
	scanf("%d",&n);
	i=n+1;
	while(eprost(i)!=1){
		i++;
	}
	printf("\nRazlikata e %d ",i-n);
	return 0;
}

