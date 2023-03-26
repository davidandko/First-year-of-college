/*
 * main.c
 *
 *  Created on: Nov 9, 2021
 *      Author: David
 */
#include<stdio.h>
int eprost(int x){
	int i;
	for(i=2;i<x;i++){
		if(x%i==0)
			return 0;

		return 1;
	}
}
int zbircifri(int x){
	int pom,cifra,zbir;
	zbir=0;

	pom = x;
	while(pom>0){
		cifra=pom%10;
		pom=pom/10;
		zbir=zbir+cifra;
	}
	return zbir;
}
int main(){
	int i,br=0;

	for(i=2;i<10000;i++){
		if(eprost(i)==1){
			int zbir = zbircifri(i);
		}
		if(eprost(zbir)==1){
			printf(%d,i);
		br++;
		}

	}

//ne e dovrsena

}
