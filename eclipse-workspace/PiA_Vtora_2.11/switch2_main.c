/*
 * switch2_main.].c
 *
 *  Created on: Nov 2, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int broj, cifra1, cifra2;
	printf("Vnesete dvocifren broj \n");
	fflush(stdout);
	scanf("%d",&broj);

	cifra1= broj%10;
	cifra2= broj/10;

	switch(cifra2){
	case 0: break;
	case 1: printf("eden "); break;
	case 2: printf("dva "); break;
	case 3: printf("tri "); break;
	case 4: printf("cetiri "); break;
	case 5: printf("pet "); break;
	case 6: printf("sest "); break;
	case 7: printf("sedum "); break;
	case 8: printf("osum "); break;
	case 9: printf("devet "); break;
	}

	switch(cifra1){
	case 0: break;
		case 1: printf("eden "); break;
		case 2: printf("dva "); break;
		case 3: printf("tri "); break;
		case 4: printf("cetiri "); break;
		case 5: printf("pet "); break;
		case 6: printf("sest "); break;
		case 7: printf("sedum "); break;
		case 8: printf("osum "); break;
		case 9: printf("devet "); break;
	}

	return 0;
}

