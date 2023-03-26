/*
 * Kvadrant_Main.c
 *
 *  Created on: Oct 25, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
	float x,y;
	printf("Vnesete gi x i y\n");
	fflush(stdout);

	scanf("%f%f",&x,&y);

	if(x==0){
		if(y==0)
			printf("koordinaten pochetok");
		else
			printf("tockata lezi na y oska");
	}
	if(y==0)
	if(x!=0)
		printf("tochkata lezi na x oska");

	if(x>0){
		if(y>0)
			printf("I kvadrant");
		else
			if(y<0)
			printf("IV kvadrant");
	}

	else{
		if(x<0){
			if(y>0)
				printf("II kvadrant");
		}
		else{
			if(y<0)
				printf("III kvadrant");
		}
	}
	return 0;
}

