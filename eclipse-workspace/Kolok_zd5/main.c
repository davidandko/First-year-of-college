/*
 * main.c
 *
 *  Created on: Nov 17, 2021
 *      Author: David
 */
//zadaca 5 od auditoriski za funkcii
#include<stdio.h>
#include<math.h>
float funkcija(int x, int n){
	float rez;
	if(x>=0){

		rez = x + (pow(x,n)/n)-(pow(x,(n+2))/n+2) ;

	}
	if(x<0){

		rez = -((pow(x,(n-1))/n-1)+(pow(x,(n+1))/n+1));
	}
	return rez;
}
int main(){
//int x,n;
printf("Vnesi dva broevi");
//scanf("%d%d",&x,&n);

printf("%f",funkcija(-2,3));

return 0;

}
