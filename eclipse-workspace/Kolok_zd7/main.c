/*
 * main.c
 *
 *  Created on: Nov 17, 2021
 *      Author: David
 */
#include<stdio.h>
#include<math.h>
int transformacija(int broj){
if(broj==0){
	return 0;
}

int cifra = broj%10;

if(cifra%2==0){
	cifra = 0;
}
else{
	cifra--;
}
return transformacija(broj/10)*10+cifra;
}
int main(){

	int n;
	printf("Vnesi broj: ");
	fflush(stdout);
	scanf("%d",&n);
	printf("\nBrojot posle transformacija e: %d",transformacija(n));

	return 0;
}

