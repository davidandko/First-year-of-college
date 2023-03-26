/*
 * main2.c
 *
 *  Created on: Dec 12, 2021
 *      Author: David
 */
#include<stdio.h>
#include<math.h>
#define MAX 100
int prost(int n){
	int i;
for(i=2;i<=sqrt(n);i++){
	if(n%i==0)
		return 0; // brojot e slozen
}
return 1;
}
int main(){

	int i,pom,a[MAX],b[MAX],n;
	printf("Vnesete golemina na nizata\n");
	fflush(stdout);

	scanf("%d",&n);

	printf("Vnesuvajte elementi vo nizata\n");
	fflush(stdout);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		if((prost(a[i]) == 1)&&(prost(a[i+1])== 1)){
			pom=a[i]; //promena na pozicija
			a[i]=a[i+1]; //promena na pozicija
			a[i+1]=pom; //promena na pozicija
			i++;	//za da se smenat poziciite samo ednas
		}
	}
for(i=0;i<n;i++){
	b[i]=a[i]; // tuka gi stavam elementite vo druga niza (uslov na zadacata)
	printf(" %d ",b[i]);
}

return 0;
}


