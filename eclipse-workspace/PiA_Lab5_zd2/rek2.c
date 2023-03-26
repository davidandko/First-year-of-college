/*
 * rek2.c
 *
 *  Created on: Nov 30, 2021
 *      Author: David
 */
#include<stdio.h>
int f(int n){

if(n>10){
	if(((n%10)+1)%((n/10)%10)==0){
		return f(n/10);
        }
        else
        	return 0;
    }
    return 1;
}
int main()
{
    int n;
    printf("Vnesi broj\n");
    fflush(stdout);
    scanf("%d", &n);
if(f(n)==0){
	printf("Uslovot ne e ispolnet");
}
if(f(n)==1){
	printf("Uslovot e ispolnet");
}
    return 0;
}

