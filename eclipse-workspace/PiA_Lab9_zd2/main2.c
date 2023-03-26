/*
 * main2.c
 *
 *  Created on: Dec 29, 2021
 *      Author: David
 */
#include<stdio.h>
#include<string.h>

int main(int argc,char **argv){
	char s1[50];
	int i;
	for(i=1;i<argc;i++){
		strcat(s1,argv[i]);
	}
	printf("%s ",s1);
	return 0;
}
