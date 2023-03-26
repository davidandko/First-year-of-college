/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
	int i,j,pom,broj,brcifri=0;
	printf("Vnesete broj: ");
	fflush(stdout);
	scanf("%d",&broj);
	pom=broj;
	while(pom!=0){
		pom/=10;
		brcifri++;
	}
	printf("Broj na cifri: %d\n",brcifri);
	if(brcifri==2){
		for(i=broj;i<=99;i++){
			if(i%3==0){
				printf("Dvocifreniot broj posle transformacija e: %d\n",i);
				break;
			}
		}
	}

	if(brcifri==3){
		for(j=broj;j>=100;j--){
			if(j%4==0){
				printf("Trocifreniot broj e: %d\n",j);
				break;
			}
		}
	}
	if((brcifri!=2)&&(brcifri!=3)){
		printf("Vnesovte broj sto ne e dvocifren/trocifren");
	}
	return 0;
}

