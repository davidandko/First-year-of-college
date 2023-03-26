/*
 * main.c
 *
 *  Created on: Jan 11, 2022
 *      Author: David
 */
#include<stdio.h>
int main(){

int n=8,i,a[100]={1,2,1,1,1,6,7,8};
for(i=0;i<n;i++){
	printf("i pred %d\n:",i);
	while(a[i]==1){
		i++;
		printf("A vo while %d\n",i);
	}
}


return 0;
}
