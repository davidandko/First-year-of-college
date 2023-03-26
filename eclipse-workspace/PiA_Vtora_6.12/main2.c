/*
 * main2.c
 *
 *  Created on: Dec 6, 2021
 *      Author: David
 */
//zadaca so simetricna dijag
#include<stdio.h>

int main(){
	int a[10][10],i,j,cont = 1,n;
	printf("Vnesete ja dimenzijata na matricata\n");
	fflush(stdout);
	 scanf("%d",&n);

	 printf("Vnesete gi elementite na matricata\n");
	 fflush(stdout);
	 for(i=0;i<n-1;i++){
		 for(j=0;j<n-1;j++){
			 scanf("%d",&a[i][j]);
		 }
	 }
	 for(i=0;i<n;i++){
		 for(j=0;j<1;j++){
			 if(a[i][j]!=a[j][i]){
				 cont = 0;
			 }
		 }
	 }
	 if(cont==1){
		 printf("Matricata e simetricna\n");
	 }
	 else{
		 printf("Matricata ne e simetricna\n");
	 }
	return 0;
}
