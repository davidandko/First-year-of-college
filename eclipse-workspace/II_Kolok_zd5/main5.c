/*
 * main5.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
#include<stdio.h>
#define MAX 100

int main(){
	int i,j,k=0,min,n,m,a[MAX][MAX],b[MAX],flag,stop;

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

			min=a[0][j];
			for(i=0;i<n;i++){
			if(min>a[i][j]){
				min=a[i][j];
			}
		}
			b[k]=min; //0-1, 1-2
			k++;
		}
for(i=0;i<k-1;i++){
	if(b[i]<b[i+1]){
		flag=1;
	}
	else{
		stop=i;
		flag=0;
		printf("%d > %d",b[k],b[k+1]);
		break;
	}
}
if(flag){
	printf("Ispolnet e uslovot\n");
}
if(!flag){
printf("Uslovot ne e ispolnet vo %d\n",stop);
}
		return 0;
}

