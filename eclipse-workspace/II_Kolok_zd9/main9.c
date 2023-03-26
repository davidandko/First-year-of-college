/*
 * main9.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
// termin 2 grupa 2 zd 2
#define MAX 100
#include<stdio.h>

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
		for(j=0;j<m;j++){
			for(i=0;i<n;i++){
				if(a[i][j]>=0){
					local+=a[i][j];
					brloc++;
				}
			}
			p=(float)local/brloc;
				if(p<P){
					for(k=j;k<m;k++){
						for(i=0;i<n;i++){
							a[i][k]=a[i][k+1];
						}
					}
				m--;
				j--;
				}
				local=0;
				brloc=0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}

return 0;
}
