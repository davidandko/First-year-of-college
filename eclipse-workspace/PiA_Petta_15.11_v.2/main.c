/*
 * main.c
 *
 *  Created on: Nov 15, 2021
 *      Author: David
 */

#include<stdio.h>

int rek5a(int x, int kr){
	int vr,mr;
	if(x/10 == 0){
		if(kr>x){
			return kr;
		}
		else
			return x;
	}
	mr = x%10;
	if(kr<mr){
		kr=mr;
	}
vr =  rek5a(x/10,kr);
return vr;
}
int main(){

	printf("Najgolemata cifra pd 35672 e %d",rek5a(35672,0));
	return 0;
}
