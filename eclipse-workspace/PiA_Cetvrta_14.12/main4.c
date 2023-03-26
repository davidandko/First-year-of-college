/*
 * main4.c
 *
 *  Created on: Dec 14, 2021
 *      Author: David
 */
#include<stdio.h>

int prodolzhi(int *a, int *b, int *pna, int *pnb){
	int *pod,*pok,*dk,*dd;
	int i;

	if(*pna>*pnb){
		pod = a; pok = b;
		dd = pna; dk = pnb;
	}
	else{
		pod = b; pok = a;
		dd = pnb; dk = pna;
	}
	for(i=0;i<*dd;i+=3){
		*(pok+*dk) = *(pod+i);
		(*dk)++;
	}
	return 0;
}
int main(){
	int a[100],i,na,b[100],nb;

	printf("Vnesete gi dolzinite na dvete nizi: \n");
	fflush(stdout);
	scanf("%d%d",&na,&nb);
	printf("Vnesete gi elementite vo prvata niza: \n");
	fflush(stdout);
	for(i=0;i<na;i++){
		scanf("%d",&a[i]);
	}
	printf("Vnesete gi elementite vo vtorata niza: \n");
	fflush(stdout);
	for(i=0;i<nb;i++){
		scanf("%d",&b[i]);
	}

	prodolzhi(a,b,&na,&nb);

printf("\nPrvata niza posle funkcijata e: \n");
for(i=0;i<na;i++){
	printf("%d ",a[i]);
}
printf("\nVtorata niza posle funkcijata e: \n");
for(i=0;i<nb;i++){
	printf("%d ",b[i]);
}

return 0;
}

