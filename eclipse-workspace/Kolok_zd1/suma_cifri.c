/*
 * suma_cifri.c
 *
 *  Created on: Nov 17, 2021
 *      Author: David
 */
// Od auditoriski za funkcii 1va zadaca
#include<stdio.h>

int zbir(int n){
	int cifri1,cifri2,suma;
	cifri1=n/100;
	cifri2=n%100;
	suma=cifri1+cifri2;
	return suma;
}

int main(){
	int brbr,i;


	for(i=1000;i<=9999;i++){

		if((i%zbir(i))==0){
			printf(" %d ",i);
			brbr++;
		}
	}
	printf("Brojot na broevi koj se dellivi so zbirot prvite dve cifri so poslednite dve cifri e: %d",brbr);

return 0;
}

//tochno reshena
