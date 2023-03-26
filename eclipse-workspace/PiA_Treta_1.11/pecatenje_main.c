/*
 * pecatenje_main.c
 *
 *  Created on: Nov 1, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int m, zbir, pom, cifra,i;

	printf("Vnesete m\n");
	fflush(stdout);

	scanf("%d",&m);

	if(m<=27){
		for(i=1; i<=1000; i++){
			zbir=0;
			pom = i;

			while(pom>0){
				cifra = pom%10; //najdesnata cifra od pom
				pom = pom/10; //otstranuvanje na najdesnata cifra od pom
				zbir = zbir+cifra;
			}
			if(m==zbir){
				printf("%d\n",i); //tuka moze i so prazno mesto za da gi dobieme broevite eden do drug
			}

		}

	}


	return 0;
}

