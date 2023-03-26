/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>


int main(){
int i,c3,c2,c1,brbr;
	for(i=100;i<=999;i++){
		c3 = i/100;
		c2 = (i/10)%10;
		c1 = i%10;
		if(i == ((c2*c2)+c1+((c3*c3)*c3))){
			printf("%d ",i);
			brbr++;
		}
	}
printf("Broj na broevi %d",brbr);

return 0;
}


