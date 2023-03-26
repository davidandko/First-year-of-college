/*
 * main.c
 *
 *  Created on: Nov 9, 2021
 *      Author: David
 */
#include<stdio.h>
#include<math.h>

int eprost(int x){
	int i,kor;
	kor=(int)sqrt(x)+1;
	for(i=2;i<kor;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main(){
	int i;

	for(i=0;i<1000;i++)
		if(eprost(i)&&eprost(i+2))
			printf("%d %d\n",i,i+2);

	return 0;
}
