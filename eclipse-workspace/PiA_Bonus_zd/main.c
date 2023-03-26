/*
 * main.c
 *
 *  Created on: Dec 30, 2021
 *      Author: David
 */
#include<stdio.h>
#define MAX 100
void transform(int *a,int *b,int *n,int *m){
	int i,j,ela,elb;
	ela = *n;
	elb = *m;
	for(i=0;i<ela;i++){
		if(*(a+i) % 2 != 0){
			*(b+i)=*(a+i);
			for(j=i;j<ela-1;j++){
				*(a+j) = *(a+j+1);
			}
			ela--;
			elb++;
		}
	}
*n=ela;
*m=elb;
}

int main(){
	int a[MAX],b[MAX],n,m=0,i; //m dolzina na vtora niza, spored uslovot na zadacata na pocetok e 0
	printf("Vnesete dolzina na nizata a: \n");
	fflush(stdout);
	scanf("%d",&n);
	printf("Pocni so vnesuvanje na elementi vo nizata: \n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	transform(a,b,&n,&m);
	printf("\nTransformiranata niza a ima %d elementi",n);
	fflush(stdout);
	printf("\nTransformiranata niza a glasi: \n");
	fflush(stdout);
	for(i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\nTransformiranata niza b ima %d elementi",m);
	fflush(stdout);
	printf("\nTransformiranata niza b glasi: \n");
	fflush(stdout);
	for(i=0;i<m;i++){
		printf("%d ",*(b+i));
	}
	return 0;
}

