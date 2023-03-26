/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int i,cifra,pom,poc,kraj,sumacif=0;

	printf("Vnesi opseg (od-do):  \n");
	fflush(stdout);
	scanf("%d%d",&poc,&kraj);
	for(i=poc;i<=kraj;i++){
		pom=i; sumacif=0;
		while(pom>0){
			cifra=pom%10;
			if(cifra%2==0){
			sumacif=sumacif+cifra		;
		}

		pom/=10;
	}
		if((sumacif%3==0)&&(sumacif!=0)){
			printf("%d\n",i);
		}

}


return 0;
}

