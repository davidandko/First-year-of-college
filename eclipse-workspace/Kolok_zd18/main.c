/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int zbdel(int n){
	int zbir=0,i;

	for(i=1;i<=n/2;i++){
	if(n%i==0){
		zbir+=i;
	}
	}
	return zbir;
}


int main(){
	int n,j,brbr;
printf("Vnesi broj: ");
fflush(stdout);
scanf("%d",&n);

for(j=1;j<=n;j++){
	if(zbdel(j)==j){
		printf("Sovrsen broj: %d\n",j);
		brbr++;

	}
}
printf("Postojat %d sovrsheni broevi vo intervalot pomali od %d",brbr,n);
return 0;
}

