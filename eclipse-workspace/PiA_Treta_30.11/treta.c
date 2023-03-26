/*
 * treta.c
 *
 *  Created on: Nov 30, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
	int a[100],i,raz,maxRaz=0,n;

	printf("Vnesete broj na elementi\n");
	fflush(stdout);

	scanf("%d",&n);
	printf("Vnesuvajte gi elementite na vektorot\n");
	fflush(stdout);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		for(i=0;i<(n-1);i++){
			raz=a[i]-a[i+1];
			if(raz<0){
				raz=-raz;
			}
			if(maxRaz<raz){
				maxRaz = raz;
			}
		}
printf("Maksimalnata vrednost pomegju dva sosedni elementi\n");
printf("na vektorot iznesuva %d",maxRaz);
return 0;
}

