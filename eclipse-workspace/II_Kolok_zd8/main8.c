/*
 * main8.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
//termin 2 grupa 2 zd2
#include<stdio.h>
#define MAX 200
int main(){
	int i,j,k=0,n,m,a[MAX][MAX],br=0,flag;

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
		for (i = 0; i < n ; i++) {
		    flag=0;
		    for(j=0;j<m;j++){
		    	if(a[i][j]<0){
		    		flag=1;
		    		break;
		    	}
		    	else{
		    		flag=0;
		    	}
		    }

		   if(flag==0){
			   for(k=i;k<n;k++){
				   for(j=0;j<m;j++){
					   a[k][j]=a[k+1][j];
				   }
			   }
			   i--;n--;
			   br++;
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
		printf("\n Bea izbrishani: %d reda",br);
	return 0;
}
