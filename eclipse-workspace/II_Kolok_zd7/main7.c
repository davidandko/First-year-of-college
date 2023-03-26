/*
 * main7.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
#include<stdio.h>
#define MAX 100
int main(){
	int zbir=0,brP=0,i,j,k,n,m,a[MAX][MAX],local=0,brloc=0;
	float P,p;
		printf("Vnesi broj na redovi: \n");
		fflush(stdout);
		scanf("%d",&n);
		printf("Vnesete broj na koloni \n");
		fflush(stdout);
		scanf("%d",&m);
		printf("Vnesete elementi vo matricata\n");
		fflush(stdout);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j]>=0){
					zbir+=a[i][j];
					brP++;
				}
			}
		}
		P=(float)zbir/brP;
		printf("Prosekot e: %.2f\n",P);
		fflush(stdout);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j]>=0){
					local+=a[i][j];
					brloc++;
						}
			}
			p=(float)local/brloc;
			printf("Local %.2f\n",p);
			if(p<P){
				for(k=i;k<n-1;k++){
					for(j=0;j<m;j++){
					a[k][j]=a[k+1][j];
					}
				}
				n--;
				i--;
			}
			local=0;
			brloc=0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf(" %d ",a[i][j]);
			}
			printf("\n");
		}
return 0;
}

