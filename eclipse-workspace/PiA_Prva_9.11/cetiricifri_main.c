/*
 * cetiricifri_main.c
 *
 *  Created on: Nov 9, 2021
 *      Author: David
 */
#include<stdio.h>
int zbir(int x){
	int prv, vtor,zbir;
	prv = x/100;
	vtor = x%100;
	zbir = prv + vtor;
}
int main(){
int i, br=0,rez;


	for(i=1000; i<=9999; i++)
		rez = zbir(i);
	if((i%rez)==0){
		//if(i%zbir(i)==0){
			printf("%d",i);
			br++;
		}
	printf("\nImalo %d takvi broevi.", br);
	return 0;
}

