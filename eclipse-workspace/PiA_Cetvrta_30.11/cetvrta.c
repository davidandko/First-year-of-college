/*
 * cetvrta.c
 *
 *  Created on: Nov 30, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
int a[100];
int i,poz,dol,pozg,dolg,n;


printf("Vnesete ja dolzinata na nizata\n");
fflush(stdout);
scanf("%d",&n);

printf("Vnesete gi elementite na nizata\n");
fflush(stdout);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
}
pozg = 0;
dolg = 1;

i = 0;

while(i<(n-1)){
	poz = i;
	dol = 1;

	while((a[i]<a[i+1]) && (i<(n-1))){
		dol++;
		i++;
	}
	if(dol>dolg){
		dolg = dol;
		pozg = poz;
	}
	i++;
}
printf("Najdolgata podniza pochnuva na pozicija %d i ima dolzina %d",pozg,dolg);



	return 0;
}

