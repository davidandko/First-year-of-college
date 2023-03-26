/*
 * n_pozitivni_main.c
 *
 *  Created on: Nov 6, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int n,i=0,br,zbir=0,brneg=0,brpoz=0;

	printf("Vnesi broj na broevi n: \n");
	fflush(stdout);

	scanf("%d",&n);

while(i<n){

	printf("Vnesete broj: \n");
	fflush(stdout);
	scanf("%d",&br);

	if(br>0)
	{
	brpoz++;
	zbir=zbir+br;
	}

	if(br<0){
				brneg++;
				}
	i++;
				}

	printf("Sredna vrednost na pozitivnite broevi: %.2f \n",(float)zbir/brpoz);
	printf("Brojot na pozitivni broevi: %d\n",brpoz);
	printf("Brojot na negativni broevi: %d\n",brneg);


	return 0;
}

