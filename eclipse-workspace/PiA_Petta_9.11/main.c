/*
 * main.c
 *
 *  Created on: Nov 9, 2021
 *      Author: David
 */

//Programa za rekurzija za faktoriel
#include<stdio.h>
int fact(int n){
if(n==1)
	return 1;
else
	return n*fact(n-1);
}
int main(){
	int rez;
	rez = fact(5);

	printf("%d",rez);

	return 0;
}
