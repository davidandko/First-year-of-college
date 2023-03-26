/*
 * main.c
 *
 *  Created on: Nov 15, 2021
 *      Author: David
 */
#include<stdio.h>

int rek5(int x){
	int vr,mr,vv;
	if(x/10 == 0)
		return x;
	mr = x%10;
	vr = rek5(x/10);
	if(mr>vr)
		vv = mr;
	else
		vv=vr;
	return vv;
}

int main(){
	printf("Najgolemata cifra na brojot 35672 e %d",rek5(35672));
	return 0;
}
