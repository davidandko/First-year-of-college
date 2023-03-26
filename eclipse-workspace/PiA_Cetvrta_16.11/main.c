/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: David
 */
#include<stdio.h>

int eprost(int x){
	int i;
	for(i=2;i<x;i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main(){
	int poc,kraj,i,pom,cifra,prev,brbr=0,proizv;

	printf("Vnesete dolna i gorna granica na rasponot: \n");
	fflush(stdout);
	scanf("%d%d",&poc,&kraj);

	for(i=poc;i<=kraj;i++)
	pom=i;
	prev=0;
	proizv=1;
	while(pom>0){
		cifra=pom%10;
		pom=pom/10;

		prev = prev*10+cifra;
		proizv = proizv*cifra;
	}
	if(prev == i){
		if((proizv!=1)&&(proizv!=0)){
			int pr;
			pr= eprost(proizv);
			if(pr == 1){
				printf("%d",i);
				brbr++;
			}
		}
	}
	printf("\nBrojot na takvi broevi e %d",brbr);
	return 0;
}

