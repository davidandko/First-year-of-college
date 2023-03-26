/*
 * Proverka_vrednosti_main.c
 *
 *  Created on: Oct 26, 2021
 *      Author: David
 */

#include<stdio.h>
int main(){
	int a,b,c,d;

printf("Vnesete cetiri celobrojni vrednosti\n");

fflush(stdout);

scanf("%d%d%d%d",&a,&b,&c,&d);

printf("%d\n",a+b/(c-d));

return 0;
}
