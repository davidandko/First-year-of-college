/*
 * Kvantifikacija_Main.c
 *
 *  Created on: Oct 25, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int x,ab;

	printf("vensete vrednost za x\n");
	fflush(stdout);
	scanf("%d",&x);
	if(x<0)
		ab = -x;
		else
			ab = x;
	if(ab>=1000)
		printf("preterano ");
	else
		if(ab>=100)
			printf(" mnogu ");
	if(x>0)
		printf(" pozitiven");
		else
			if(x==0)
				printf("nula");
			else
				printf(" negativen");
	return 0;
}

