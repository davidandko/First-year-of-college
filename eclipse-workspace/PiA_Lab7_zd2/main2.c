/*
 * main2.c
 *
 *  Created on: Dec 12, 2021
 *      Author: David
 */
#include<stdio.h>
#define MAX 100
int main(){
	int a[MAX][MAX],b[MAX][MAX];
	int n,m,i,j;
	int istelement,brel=0;
	//istelement e za brojnata vrednost na elementot koj e pronajden vo dvete matrici na ista pozicija
	//brel e broj na pronajdeni isti elementi

	printf("Vnesete broj na redovi: \n");
	fflush(stdout);
	scanf("%d",&n);

	printf("Vnesete broj na koloni: \n");
	fflush(stdout);
	scanf("%d",&m);

	printf("Vnesete elementi vo prvata matricata: \n");
	fflush(stdout);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}

	printf("Vnesete elementi vo vtorata matrica: \n");
	fflush(stdout);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]==b[i][j]){ // tuka e proverkata na dvete matrici
				istelement=a[i][j];
				printf("Ist element e pronajden na pozicija [%d][%d], toa e brojot: %d \n",i,j,istelement);
				brel++;
			}
		}
	}
	printf("Pronajdeni se %d elementi koj na ista pozicija vo matricata imaat ista vrednost\n",brel);
	return 0;
}

