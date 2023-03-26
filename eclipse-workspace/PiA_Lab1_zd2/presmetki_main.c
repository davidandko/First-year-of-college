/*
 * presmetki_main.c
 *
 *  Created on: Oct 26, 2021
 *      Author: David
 */

#include<stdio.h>
int main(){
	int a,b;

	printf("Vnesete dva celi broevi a i b\n");
	fflush(stdout);
	scanf("%d%d",&a,&b);
	printf("Zbirot na broevite a+b= %d\n",a+b);
	printf("Razlikata na broevite a-b= %d\n", a-b);
	printf("Proizvodot na broevite a*b= %d\n", a*b);

	if(a>b){
		printf("Brojot a e pogolem od brojot b\n");
	}
	if(a<b){
			printf("Brojot b e pogolem od brojot a\n");
	}
	if(a==b){
		printf("Broevite se isti\n");
	}
	return 0;
}
