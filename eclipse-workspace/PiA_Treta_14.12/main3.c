/*
 * main3.c
 *
 *  Created on: Dec 14, 2021
 *      Author: David
 */
#include<stdio.h>

int pomesti(int *a,int n){
	int i,pom;
	pom = *(a+n-1);
	if(pom>n-1){
		printf("Ne moze da se realizira pomestuvanjeto(izleguvame nadvor od nizata)\n ");
		return 0;
	}
	for(i=0;i<pom;i++){
		*(a+n-1-i) = *(a+n-1-i-1);
	}

	*(a+n-1-pom) = pom;

	if(n+1-pom == 0){
		printf("Nema lev sosed elementot i desniot sosed se: %d %d",*(a+n-1-pom),*(a+n-1-pom+1));
	}
	else if(pom == 0){
		printf("Nema desen sosed, leviot sosed i elementot se: %d %d",*(a+n-2),*(a+n-1));
	}
	else{
		printf("Leviot sosed, elementot i desniot sosed se: %d %d %d",*(a+n-1-pom-1),*(a+n-1-pom),*(a+n-1-pom+1));
	}
	return 0;
}
int main(){
int a[100],n,i;

printf("Vnesete dolzina na nizata: \n");
fflush(stdout);

scanf("%d",&n);

printf("Vnesete gi elementite vo nizata: \n ");
fflush(stdout);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
pomesti(a,n);

return 0;
}
