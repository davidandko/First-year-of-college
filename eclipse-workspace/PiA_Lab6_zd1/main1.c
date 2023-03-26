/*
 * main1.c
 *
 *  Created on: Dec 8, 2021
 *      Author: David
 */
/*
 * lab1.c
 *
 *  Created on: Dec 8, 2021
 *      Author: David
 */
#include<stdio.h>
#include<math.h>
#define MAX 100

int main(){
	int i,a[MAX],b[MAX],n,maxbr=0;
	printf("Vnesete golemina na nizata\n");
	fflush(stdout);
	scanf("%d",&n);
	printf("Vnesuvajte elementi vo nizata\n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		if(a[i]>maxbr){ //if za naogjanje na najgolem clen na nizata
			maxbr=a[i];
		}
	}
printf("Najgolemiot broj vo nizata e %d\n",maxbr);
printf("Novata niza: \n");
for(i=0;i<n;i++){

	b[i]=maxbr-a[i]; //transformacijata se odviva tuka
	printf(" %d ",b[i]);
}
printf("\nNovata niza bez elementi so vrednost 0:\n");
for(i=0;i<n;i++){
	b[i]=maxbr-a[i];
if(b[i]!=0){ //go eliminira mestoto na elementot so maksimalna vrednost
	printf(" %d ",b[i]);
}
}

return 0;
}



