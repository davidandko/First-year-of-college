/*
 * bukva.c
 *
 *  Created on: Nov 16, 2021
 *      Author: David
 */
#include<stdio.h>

void rekp1(int x, char c){
	int mr;
	if(x/10 == 0){
		printf("%c",x+c);
				return;
	}
	rek(x/10,c);
	printf("%c",x%10+c);

}
int main(){
	rek(1234,'A');
	return 0;
}

