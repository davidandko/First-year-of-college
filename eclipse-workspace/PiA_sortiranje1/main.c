/*
 * main.c
 *
 *  Created on: Jan 10, 2022
 *      Author: David
 */
// binarno ako nizata e vo rastecki redosled
#include<stdio.h>
int linearno(int a[],int n, int key){
	int i;

	for(i=0;i<n;i++){
		if(a[i]==key){
			return i;
		}

	}
	return -1;
}
int binarno(int a[],int n,int key){
	int min = 0, max = n-1,srd;
	while(min<=max){
		srd = (min+max)/2;
		if(a[srd]==key){
			return srd;
		}
		else if(a[srd]>key){
			max = srd - 1;
		}
		else{
			min = srd + 1;
		}
	}
	return -1;
}
int main(){
int a[20],n,tip,ind,key;

printf("Vnesete ja dolzinata na nizata\n");
fflush(stdout);
scanf("%d",&n);
printf("Vnesete gi elementite na nizata\n");
fflush(stdout);
for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
}
printf("Vnesete element koj sakate da go najdete vo nizata\n");
fflush(stdout);
scanf("%d",&key);
printf("Vnesete kakvo prebaruvanje sakate da izvrsite: 0 - za linearno ; 1 - za binarno\n");
fflush(stdout);
scanf("%d",&tip);
if(tip == 0){
	ind = linearno(a,n,key);
	if(ind > -1){
		printf("Elementot e najden na pozicija %d\n",ind);
	}
	else{
		printf("Elementot ne e najden vo nizata\n");
	}
}
else if(tip == 1){
	ind = binarno(a,n,key);
	if(ind > -1){
		printf("Elementot e najden na pozicija %d",ind);
	}
	else{
		printf("Elementot ne e najden vo nizata\n");
	}

}else{
	printf("NE zaboravaj 0 ili 1\n");
}
return 0;
}
