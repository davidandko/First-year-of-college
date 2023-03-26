/*
 * 17.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int cifra,sumapar=0,sumanepar=0,pom,i,par=0,nep=0,brcifri=0;
	int start,end;
	printf("Vnesi pocetok i kraj: \n");
	fflush(stdout);
	scanf("%d%d",&start,&end);
	for(i=start;i<=end;i++){
		pom=i;
		while(pom>0){
			cifra=pom%10;
			if(cifra%2==0){
				sumapar+=cifra;
				par++;
			}
			else{
				sumanepar+=cifra;
				nep++;
			}
			brcifri++;
			pom/=10;
			if((brcifri==par)&&(brcifri==nep)){
						printf("Brojot ima samo parni ili samo neparni broevi");
						break;
					}
			if(sumanepar>sumapar){
			printf("%d\n",i);
			}
			break;
		}



	}
return 0;
}

