/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */

// vtora od zbirkata
#include<stdio.h>
int main(){
	int i,pom,p,k,cifra,nocifra;

	printf("Vnesi pocetok i kraj na interval: ");
	fflush(stdout);

	scanf("%d%d",&p,&k);
for(i=p;i<k;i++){
	pom = i;
	while(pom>0){
	cifra=pom%10;
	pom/=10;
	}
	nocifra=i%10;;
if((cifra%2 == 0)&&(cifra>nocifra)){
	printf(" %d ",i);
	}
}
return 0;
}
