/*
 * delitel_cifri.c
 *
 *  Created on: Nov 14, 2021
 *      Author: David
 */
#include<stdio.h>
int proverka(int n){
	int cifra;
	cifra=(n%10);
	if((n/10) == 0){
		return 1;
	}
	if(((n%100)/10)%cifra){
		return 0;
	}
	return (proverka(n/10));

}
int main(){
	int n;
	printf("Vnesete broj: \n");
	fflush(stdout);
	scanf("%d",&n);
	if(proverka(n)>0){
		printf("Ispolnet e uslovot");
	}
	else
		printf("Uslovot ne e ispolnet");
}
