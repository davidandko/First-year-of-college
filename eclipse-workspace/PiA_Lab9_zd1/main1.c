/*
 * main1.c
 *
 *  Created on: Dec 28, 2021
 *      Author: David
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50

int main(){
	int i=0;
	char c,a[MAX];

	while((i<MAX-1) && (c=getchar()) != '\n'){
		a[i]=c;
		i++;
	}
	a[i]=c;

	printf("%s\n",a);
	return 0;

}

