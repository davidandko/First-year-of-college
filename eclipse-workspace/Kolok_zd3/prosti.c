/*
 * prosti.c
 *
 *  Created on: Nov 17, 2021
 *      Author: David
 */
#include<stdio.h>
#include<math.h>

int eprost(int n){
	int i,flag=0;
	for(i=2;i<sqrt(n);i++){
		if(n%i==0){
			flag++;
		}
	}
	if(flag!=0){
				return 0;
			}
			else
				return 1;
}
int zbircif(int n){

	int cifra,zbir=0;
	cifra=n%10;
	while(n>0){
		zbir+=cifra;
		n=n/10;
	}
	return zbir;
}

int main(){
int j;
	for(j=2;j<10000;j++)
	{
		if(eprost(j)&&eprost(zbircif(j)))
		{
			printf(" %d ",j);
		}
	}
	return 0;

}
