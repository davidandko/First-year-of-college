/*
 * main4.c
 *
 *  Created on: Jan 16, 2022
 *      Author: David
 */
// prva zadaca 2019 grupa 2
#include<stdio.h>
#include<stdlib.h>
/*void valueIs(int *a,int n){
	int i;
	int poz=0,neg=n-1;
	for(i=0;i<n;i++){
		if(*(a+i)>=0){
			*(a+poz)=*(a+i);
			poz++;
		}
		if(*(a+i)<0){
			*(a+neg)=*(a+i);
			neg--;
		}
	}
}
*/
void valueIs(int *a,int n){
int i,j;
	for(i=0;i<n;i++){
		if(*(a+i)>=0){
			for(j=i;j>=0;j--){
				*(a+j-1)=*(a+j);
			}
		}
	}
}

int main(){

	int a[100],n;
	printf("Vnesi dolzina na nizata\n");
	fflush(stdout);
	scanf("%d",&n);

	printf("Vnesi elementi vo nizata\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	/*printf("Nizata pred transformacija glasi:\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}
	*/
	valueIs(a,n);
	printf("\nNizata posle transformacija glasi:\n");
	fflush(stdout);
	for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}

	return 0;
}
