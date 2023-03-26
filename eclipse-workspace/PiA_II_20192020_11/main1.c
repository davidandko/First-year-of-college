/*
 * main1.c
 *
 *  Created on: Jan 11, 2022
 *      Author: David
 */
#include<stdio.h>

int funkcija(int a[],int *n){
	int pd,b[100],i,j,k=0,brP;
	for(i=0;i<*n;i++){
		brP=0;
		for(j=0;j<*n;j++){
			if(a[i] == a[j]){
				brP++;
			}
		if(brP==1){
			b[k] = a[i];
			k++;
		}
		}


	}
pd = *n;
for(i=0;i<k;i++){
	a[i] = b[i];

}
*n = k;
return pd-k;
}
int main(){
	int a[100],n,i;

	printf("Vnesete ja dolzinata na nizata\n");
	fflush(stdout);
	scanf("%d",&n);

	printf("Vnesete elementi vo nizata\n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Brojot na ispushteni elementi e %d\n",funkcija(a,&n));
	printf("ELementite na transformiranata niza se\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
// ima greska,vidi ja snimkata od predavanje
