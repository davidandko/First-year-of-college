/*
 * parni_sporedba_main.c
 *
 *  Created on: Nov 1, 2021
 *      Author: David
 */

#include<stdio.h>
int main(){
	int i, n, brnc, pom, cifra, brbr = 0;

	printf("vnesete ja granicata n\n");
	fflush(stdout);

	scanf("%d",&n);

	for(i=1; i<n; i++){
		brnc = 0;  // br na neparni cifri

		pom = i;

		while(pom>0){
			cifra = pom%10;
			pom =  pom/10;
			if(cifra%2==1){
				brnc++;
			}
		}
		if(brnc==0){
			printf("%d \n", i);
			brbr++;
		}


	}
	printf("Brojot na najdeni broevi e %d: \n", brbr);



	return 0;
}
