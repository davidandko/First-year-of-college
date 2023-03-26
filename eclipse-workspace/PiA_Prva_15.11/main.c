/*
 * main.c
 *
 *  Created on: Nov 15, 2021
 *      Author: David
 */
//faktoriel so rekurzija
#include<stdio.h>

int rek1(int x){
	int rv,vv;

	if(x==1){
		return 1;
	}
	rv=rek1(x-1); // ja povikuva rek1
	vv=rv*x; // presmetuva faktoriel od n-1 i go mnozi so izdvoeniot broj x
	return vv;


}

int main(){

	int x;
	printf("Vnesete broj: ");
	fflush(stdout);
	scanf("%d",&x);
	printf ("%d",rek1(x));
	return 0;
}
