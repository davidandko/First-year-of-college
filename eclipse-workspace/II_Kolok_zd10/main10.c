/*
 * main10.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
// termin 3 grupa 2 zd 2
#define MAX 100
#include<stdio.h>
int main(){
	int i,j,k,n,m,a[MAX][MAX],flag,br=0;
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
		for(j=0;j<m;j++){
			flag=1;
			for(i=0;i<m;i++){
				if(a[i][j]<0){
					flag=1;
					break;
				}
				else{
					flag=0;
				}
			}
			if(flag==1){
				for(k=j;k<m;k++){
					for(i=0;i<n;i++){
						a[i][k]=a[i][k+1];
					}
				}
				br++;
				m--;
				j--;

			}
			if(br==3){
				break;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		return 0;
}

