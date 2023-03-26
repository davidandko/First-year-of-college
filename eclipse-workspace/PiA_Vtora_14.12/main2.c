/*
 * main2.c
 *
 *  Created on: Dec 14, 2021
 *      Author: David
 */
#include<stdio.h>
int funk1(int *a,int *pn){
	int i,j,k,cont;
	j=0; // brojot na zadrzani elementi i pozicija na koja treba da go zapisheme sledniot zadrzhan element
	for(i=0;i < *pn;i++){
		cont = 0;
		for(k=0;k<j;k++){
			if(*(a+i)==*(a+k)){
				cont = 1;
			}
		}
		if(cont == 0){
			*(a+j) = *(a+i);
			j++;
		}
	}
*pn=j;
}

int main(){
int a[100],n,i;

printf("Vnesete dolzina na nizata: \n");
fflush(stdout);

scanf("%d",&n);

printf("Vnesete gi elementite vo nizata: \n ");
fflush(stdout);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
funk1(&a[0],&n);

printf("Modificiranata niza ima dolzina: %d i elementi\n",n);
for(i=0;i<n;i++){
	printf("%d ",a[i]);
}

	return 0;
}

