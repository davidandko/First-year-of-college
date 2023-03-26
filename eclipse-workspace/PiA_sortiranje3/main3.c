/*
 * main3.c
 *
 *  Created on: Jan 11, 2022
 *      Author: David
 */
#include<stdio.h>

int main(){
	int maxE,A[10][10],m,n,a[10],i,j,k,temp;

	printf("Vnesete dimenzii na matricata\n");
	fflush(stdout);
	scanf("%d%d",&m,&n);

	printf("Vnesete elementi vo matricata\n");
	fflush(stdout);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}
	for(j=0;j<m;j++){
		maxE = A[0][j];

		for(i=1;i<m;i++){
			if(maxE<A[i][j]){
				maxE = A[i][j];
			}
		}
		a[j] = maxE;
	}
	for(i = 0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;

				for(k=0;k<n;k++){
					temp = A[k][i];
					A[k][i] = A[k][j];
					A[k][j] = temp;
				}
			}
		}
	}
	printf("Promenetata matrica e: \n");
	fflush(stdout);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

