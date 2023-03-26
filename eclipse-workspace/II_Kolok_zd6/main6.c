/*
 * main6.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
// termin 2 grupa 1 zd 1
#include<stdio.h>
void simpleSort(int *a,int *n){
	int i,j,ela;
	ela=*n;
	if(*(a+ela-1)<*(a+ela-2)){
		ela--;
	}
	for(i=0;i<ela-1;i++){
		if(*(a+i)>*(a+i+1)){
			for(j=i+1;j<ela-1;j++){
				*(a+j)=*(a+j+1);
			}
			ela--;

		}
	}
	*n=ela;
}

int main(){
int i,a[100],n,brn;

printf("Vnesete dolzina na nizata\n");
fflush(stdout);
scanf("%d",&n);
brn=n;
printf("Vnesete elementi vo nizata\n");
fflush(stdout);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
simpleSort(a,&n);
for(i=0;i<n;i++){
	printf("%d ",a[i]);
}
printf("Bea izbrishani %d elementi\n",brn-n);
	return 0;
}

