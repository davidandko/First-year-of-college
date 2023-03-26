/*
 * 22.c
 *
 *  Created on: Nov 20, 2021
 *      Author: David
 */

#include <stdio.h>
int main(){
int cifra,n=123,prevrten;
	while(n>0){
		cifra=n%10;
		prevrten=(prevrten*10)+cifra;
		n/=10;

	}

printf("%d",prevrten);

return 0;
}
