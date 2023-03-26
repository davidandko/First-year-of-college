/*
 * validnost_triagolnik.c
 *
 *  Created on: Oct 30, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int a,b,c;
	printf("Vnesete gi stranite a,b i c: \n");
	fflush(stdout);

	scanf("%d%d%d",&a,&b,&c);

	if((a+b)>c && (a+c)>b && (b+c)>a)
	printf("Triagolnikot e validen");

	else
		printf("Triagolnikot ne e validen");


	return 0;
}

