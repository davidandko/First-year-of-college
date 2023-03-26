/*
 * main2.c
 *
 *  Created on: Jan 1, 2022
 *      Author: David
 */
// 2ra zadaca 2019
#include<stdio.h>
#define MAX 50
int main(){
	int i,j,k=0,max,n,m,a[MAX][MAX],b[MAX],flag;

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
		max = a[i][0];
			for(j=0;j<m;j++){
				if(max<a[i][j]){
					max = a[i][j];
				}
			}
			b[k] = max;
			k++;
		}
	for(i=0;i<k-1;i++){
		if(b[i]>b[i+1]){
			flag=1;
		}else{
			flag=0;
			printf("%d < %d\n",b[i],b[i+1]);
			break;
		}
	}
if(flag){
	printf("Uslovot e zadovolen\n");
}
if(!flag){
	printf("Uslovot ne e zadovolen\n");
}
	return 0;
}

