/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int brcifri(int n){
	int cifri;
	cifri=cifri+1;
	if(n/10==0){
		printf("%d",cifri);
	}
	else

		if(cifri%2==0){
			return 1;
		}
		else return 0;

return(n/10);
}

int main(){
	 printf("%d",brcifri(12));
}

