/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
// Programa za dellivost na broj so cetiricifren broj

#include<stdio.h>
int main(){
	int n,i;
	printf("Vnesi broj: ");
fflush(stdout);
	scanf("%d",&n);
	for(i=1000;i<=9999;i++){
		if(i%n == 0){
			printf(" %d ",i);
		}

	}
return 0;

}
