/*
 * main1.c
 *
 *  Created on: Dec 14, 2021
 *      Author: David
 */
#include<stdio.h>
int funk(int *a,int n){
	int b[100];
	int i;

	for(i=0;i<n;i++){
		//b[i]=a[i]+a[n-1-i];
		*(b+i)=*(a+i)+*(a+n-1-i);
	}
	for(i=0;i<n;i++){
		//a[i]=b[i]; //b[i]==*(b+i)
		*(a+i) = *(b+i);
	}

	return 0;
}

int main(){
int a[100],n,i;

printf("Vnesete dolzina na nizata: \n");
fflush(stdout);

scanf("%d",&n);

printf("Vnesete gi elementite vo nizata: \n ");

for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}

funk(a,n);

printf("\nIzleznata niza e: \n");
for(i=0;i<n;i++){
	printf(" %d ",a[i]);
}


	return 0;
}

