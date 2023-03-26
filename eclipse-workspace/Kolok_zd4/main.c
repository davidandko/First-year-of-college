/*
 * main.c
 *
 *  Created on: Nov 17, 2021
 *      Author: David
 */

// zadaca 4 od dokument funkcii
#include<stdio.h>
#include<math.h>
int eprost(int n){
	int flag=0,i;

	for(i=2;i<sqrt(n);i++){
		if(n%i==0){
			flag++;
		}
	}
	if(flag!=0){
		return 0;
	}
	else
		return 1;
}
int main(){

	int j,brbr;

	for(j=1;j<=1000;j++){
		if(eprost(j)&&eprost(j+2)){
			printf(" %d ",j);
			brbr++;

		}

	}
	printf("\nBrojot na prosti broevi koi se razlikuvaat so 2 e: %d",brbr);
return 0;
}
