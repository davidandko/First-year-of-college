/*
 * main11.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
#include<stdio.h>
// otsranuvanje duplikat
void funkcija(int *a,int *n){
		int k;
		int ela=*n;
		for(int i=0;i<ela;i++){
				for(int j=i+1;j<ela;j++){
					if(*(a+i)==*(a+j)){
					for(k=j;k<ela-1;k++){
						*(a+k)=*(a+k+1);
					}
					ela--;
					j--;
				}
			}

		}
		*n=ela;
	}




int main(){
	int n=8,a[100]={1,2,3,2,5,2,3,2};
	funkcija(a,&n);  // a==&a[0]

	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}

	return 0;
}



