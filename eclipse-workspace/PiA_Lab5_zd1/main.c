/*
 * main.c
 *
 *  Created on: Nov 30, 2021
 *      Author: David
 */
#include<stdio.h>

int f(int n){
int cifra;
cifra=n%10;
if(cifra==9){
		cifra=0;
	}
if(cifra%2!=0){
	cifra++;
}
if(n<10){
	return cifra;
}
return f(n/10)*10+cifra;
}

int main(){
	int n;
	printf("Vnesete broj\n");
	fflush(stdout);
	scanf("%d",&n);

	printf("%d",f(n));
	return 0;
}

