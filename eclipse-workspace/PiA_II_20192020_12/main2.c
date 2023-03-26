/*
 * main2.c
 *
 *  Created on: Jan 11, 2022
 *      Author: David
 */
#include<stdio.h>

int main(){
	int A[50][50],B[50][50],i,j,na,nb,np,zbir;
	printf("Vnesete dimenzija za prvata matrica\n");
	fflush(stdout);
	scanf("%d",&na);
	printf("Vnesete gi elementite na matricata A\n");
	fflush(stdout);
	for(i=0;i<na;i++){
		for(j=0;j<na;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("Vnesete dimenzija za vtorata matrica\n");
	fflush(stdout);
	scanf("%d",&nb);
	for(i=0;i<nb;i++){
			for(j=0;j<nb;j++){
				scanf("%d",&B[i][j]);
			}
		}
	if(na<nb){
		np = na;
	}
	else{
		np = nb;
	}
	for(i=0;i<np;i++){
		if(A[i][i]==B[i][i]){
			zbir = 0;
			for(j=j+1;j<na;j++){
				zbir = zbir + A[i][j];
			}
			A[i][i] = zbir;

			zbir = 0;
			for(j=j+1;j<nb;j++){
							zbir = zbir + B[i][j];
						}
						B[i][i] = zbir;

		}
	}
	printf("Prvata matrica po transformacija e\n");
	for(i=0;i<na;i++){
			for(j=0;j<na;j++){
				printf("%d ",A[i][j]);

			}
			printf("\n");
		}
	printf("Vtorata matrica po transformacija e\n");
		for(i=0;i<nb;i++){
				for(j=0;j<nb;j++){
					printf("%d ",B[i][j]);

				}
				printf("\n");
			}
		return 0;
}
