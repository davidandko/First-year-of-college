/*
 * if_funkcija_ab.c
 *
 *  Created on: Oct 30, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int a,b;
	printf("Vnesete gi vrednostite za a i b soodvetno: \n");
	fflush(stdout);

	scanf("%d%d",&a,&b);

	printf("Rezultat od celobrojno delenje na a i b PRED dobivanje na nova vrednost: %d\n",a/b);

	a=a*b;
	printf("Novata vrednost na a e: %d\n",a);

	if(a>b){
		printf("Novata vrednost na b e: %d\n",b=a-b); //b = a-b; kade sto a e promeneto i ima nova vrednost a=a*b
	}
	else
		printf("Brojot b ostana ist b= %d\n",b);


printf("Rezultat od celobrojno delenje na a i b POSLE dobivanje na nova vrednost: %d\n",a/b);
return 0;
}
