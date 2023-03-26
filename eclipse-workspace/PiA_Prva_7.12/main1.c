/*
 * main1.c
 *
 *  Created on: Dec 7, 2021
 *      Author: David
 */
//5ta od auditoriski
#include<stdio.h>
 int main(){
	 int a[100][100],i,j,n,zbir,cont=1;

	 printf("Vnesete ja dimenzijata na kvadratnata matrica\n");
	 fflush(stdout);
	 scanf("%d",&n);
	 printf("Vnesete gi elementite na matricata\n");
	 fflush(stdout);
	 for(i=0;i<n;i++){
		 for(j=0;j<n;j++){
			 scanf("%d",&a[i][j]);
		 }
	 }
	 for(i=0;i<n-1;i++){
		 zbir=0;
		 for(j=0;j<n-1-i;j++){
			 zbir = zbir+a[i][j];


		 }
		 if(zbir != a[i][n-1-i]){
			 cont = 0;
			 break;
		 }
	 }
	 if(cont == 1){
		 printf("Matricatata go zadovoluva uslovot\n");

	 }
	 else{
		 printf("Matricata ne go ispolnuva uslovot\n");
	 }
	 return 0;
 }
