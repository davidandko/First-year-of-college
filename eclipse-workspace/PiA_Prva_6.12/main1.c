/*
 * main1.c
 *
 *  Created on: Dec 6, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
	int prv,vtor,a[10][10],n,f = 1,i,j;
	printf("Vnesete broj na redici za kvadratnata matrica\n");
	fflush(stdout);
	scanf("%d",&n);
	printf("Vnesuvajte elementi vo nizata\n");
	fflush(stdout);
	//vnesuvanje
	for(i=0;i<n;i++){

		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//presmetka
	for(i=0;i<n;i++){
		prv = 1;
		vtor = 1;
		for(j=0;j<n;j++){
			prv = prv*a[i][j];
			vtor = vtor*a[j][i];
		}
		f = f*(prv+vtor);
	}

	printf("Baraniot rezultat e: %d",f);

	return 0;
}

