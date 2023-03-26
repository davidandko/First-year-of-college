/*
 * 23.c
 *
 *  Created on: Nov 20, 2021
 *      Author: David
 */
#include<stdio.h>
int proverka(int n){
int c1,c2;
	while(n!=0){
	c1=n%10;
	c2=(n/10)%10;
	if(c2<c1){
	return 0;
	break;
	}
	if(n==0){
	return 1;
	break;
	}
	n/=10;
	}
	return 0;
}
int main(){
int x;
printf("Vnesi broj: ");
fflush(stdout);
scanf("%d",&x);
if(proverka(x)==0){
	printf("Uslovot ne e ispolnet");
}
if(proverka(x)==1){
	printf("Uslovot e ispolnet");
}
	return 0;
}
