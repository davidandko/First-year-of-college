/*
 * 21.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int n,cifra,prevrten;
	printf("Vnesi broj n: \n");
fflush(stdout);
scanf("%d",&n);
prevrten=0;
		while(n>0){
			cifra=n%10;
			prevrten=(prevrten*10)+cifra;
			n/=10;
		}
	printf("prevrten: %d",prevrten);
	return 0;

}

