/*
 * n_poz.c
 *
 *  Created on: Nov 6, 2021
 *      Author: David
 */

#include<stdio.h>
int main(){
	int n,j,i=0,br=0,zbir=0,brneg=0,brpoz=0;
	printf("Vnesi broj na broevi n, potoa pocni da vnesuvas proizvolni celi broevi: \n");
	fflush(stdout);
	scanf("%d",&n);
for(j=0; j<n; j++)
	{
		printf("Vnesi broj: \n");


	}
	while(i<n){
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
	printf("Brojot na negativni broevi: %d\n",brneg);
	return 0;
}

