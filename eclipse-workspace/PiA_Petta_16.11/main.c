/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: David
 */
#include<stdio.h>

void f(int n,char c){
if(c-n<'a'){
	printf("Losho vneseni vrednosti\n");
	return;
}
	if(c-n == 'a'){
		printf("%c",c-n);
		return;
	}
	printf("%c",c-n);
	f(n,c-1);


}
int main(){
	f(4,'n');
return 0;
}
