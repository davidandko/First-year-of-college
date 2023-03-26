/*
 * main1.c
 *
 *  Created on: Dec 12, 2021
 *      Author: David
 */
#include<stdio.h>
#define MAX 100
int main(){
	int a[MAX][MAX];
	int i, j, n, m;
	int srvr=0,brclenovi,brelementi=0;
	//brelementi e za brojot na elementi koi se pogolemi od srednata vrednost
	//brclenovi e za brojot na clenovi na matricata


	printf("Vnesi broj na redovi: ");
	fflush(stdout);
	scanf("%d",&n);

	printf("Vnesi broj na koloni: ");
	fflush(stdout);
	scanf("%d",&m);

	brclenovi = n*m;

	for (i=0; i<n; i++){
		for (j=0; j<m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++){
				srvr+=a[i][j]; // gi sobira elementite na matricata
			}
		}
	srvr/=brclenovi; // tuka srvr se inicijalizira da bide sredna vrednost so delenje na brclenovi i zbirot od elementite na matricata
	for (i=0; i<n; i++) {
			for (j=0; j<m; j++){
					if(a[i][j]>srvr){
						printf("Clen pogolem od srednata vrednost: %d \n", a[i][j]);
						brelementi++;
					}
				}
			}
printf("Brojot na clenovi koi se pogolemi od srednata vrednost e: %d",brelementi);

	return 0;
}
