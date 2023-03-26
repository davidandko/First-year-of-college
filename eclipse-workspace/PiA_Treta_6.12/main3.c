/*
 * main3.c
 *
 *  Created on: Dec 6, 2021
 *      Author: David
 */
//ogledalo simetrija vo odnos na horizontala
#include<stdio.h>
 int main(){
	 //m broj na redici, n broj na koloni
	 int a[10][10],m,n,i,j,temp;
	 printf("Vnesete dimenzii na matricata\n");
	 fflush(stdout);
	 scanf("%d%d",&m,&n);

	 printf("Vnesete gi elementite vo matricata\n");
	 fflush(stdout);
	 for(i=0;i<m;i++){
		 for(j=0;j<n;j++){
			 scanf("%d",&a[i][j]);
		 }
	 }
	 for(i=0;i<m/2;i++){
		 for(j=0;j<n;j++){
			 temp=a[i][j];
			 a[i][j] = a[m-1-i][j];
			 a[m-1-i][j] = temp;
		 }
	 }
	 printf("Promenetata matrica: \n");
	 for(i=0;i<m;i++){
		 for(j=0;j<n;j++){
			 printf("&d ",a[i][j]);

		 }
		 printf("\n");
	 }
	 return 0;
 }

