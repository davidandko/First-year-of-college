/*
 * main2.c
 *
 *  Created on: Dec 7, 2021
 *      Author: David
 */

//6ta od auditoriski
#include<stdio.h>
 int main(){
	 int a[10][10],i,j,k,n,m,cont,cont1,brn = 0;

	 printf("Vnesete ja dimenzijata na matricata\n");
	 fflush(stdout);
	 scanf("%d%d",&m,&n);
	 printf("Vnesete gi elementite na matricata\n");
	 fflush(stdout);
	 for(i=0;i<m;i++){
		 for(j=0;j<n;j++){
			 scanf("%d",&a[i][j]);
		 }
	 }
	 for(k=0;k<n;k++){//a[0][k]
		 cont = 1;

		 for(i=1;i<m;i++){
			 cont1 = 0;
			 for(j=0;j<n;j++){
				 if(a[i][j]==a[0][k]){
					 cont1 = 1;
				 }

			 }
			 if(cont1 == 0){
				 cont = 0;
				 break;
			 }
		 }
		 if(cont == 1){
			 printf("Elementot %d go zadovoluva uslovot\n",a[0][k]);
			 brn++;
		 }

	 }
if(brn == 0){
	printf("Nieden element ne go zadovoluva praviloto\n");
	fflush(stdout);

}
return 0;
}
