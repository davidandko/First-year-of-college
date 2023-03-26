/*
 * if_funkcija_pom.c
 *
 *  Created on: Nov 3, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){

	int a,b,pom;
	printf("Vnesete gi vrednostite za a i b soodvetno: \n");
	fflush(stdout);

	scanf("%d%d",&a,&b);

	pom = a;

	printf("Rezultat od celobrojno delenje na a i b PRED dobivanje na nova vrednost: %d\n",a/b);

	a=a*b;
	printf("Novata vrednost na a e: %d\n",a);

	if(pom>b){
		printf("Novata vrednost na b e: %d\n",b=pom-b); //b = a-b; kade sto a e istoto sto sme go vnesile preku tastatura
	}
	else
		printf("Brojot b ostana ist b= %d\n",b);

printf("Rezultat od celobrojno delenje na a i b POSLE dobivanje na nova vrednost: %d\n",a/b);

return 0;
}

