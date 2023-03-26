/*
 * ispiti.c
 *
 *  Created on: Nov 1, 2021
 *      Author: David
 */
// so znamence na scanf
#include<stdio.h>
int main(){
	int brpol = 0, brpad = 0, prosek = 0, ocenka;
	printf("Vnesuvajte ocenki, za prekin vnesete bilo sto razlicno od cel broj\n");
	fflush(stdout);

	while(scanf("%d",&ocenka)!=0){
		if(ocenka<=10 && ocenka>=6){
			brpol++;
			prosek += ocenka;
		}
		if(ocenka == 5)
			brpad++;
	}
	printf("Vkupno polozheni %d ispiti so prosek %.2f\n", brpol, (float)prosek/brpol);
	printf("Studentot padnal na %d ispiti",brpad);

	return 0;
}

