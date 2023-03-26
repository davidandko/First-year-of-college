/*
 * main2.c
 *
 *  Created on: Dec 19, 2021
 *      Author: David
 */

#include<stdio.h>
#define MAX 100

void prevrti(int a[], int n){

	int pom;
    for (int lev = 0, desen = n - 1; lev < desen; lev++, desen--)
    {
        pom = *(a+lev);
        *(a+lev) = *(a+desen);
        *(a+desen) = pom;
    }
}

int main(){
	int i,n;
	int a[MAX];
	printf("Vnesete broj na elementi: \n");
	fflush(stdout);
	scanf("%d",&n);

	printf("Vnesete clenovi vo nizata: \n");
	fflush(stdout);

	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	prevrti(a,n);
	for(i=0;i<n;i++){
		printf("%d ",*(a+i));
	}

	return 0;
}
