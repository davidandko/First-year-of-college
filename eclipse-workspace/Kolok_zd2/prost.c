/*
 * prost.c
 *
 *  Created on: Nov 17, 2021
 *      Author: David
 */
//Zadaca 2 od auditoriski za funkcii

#include<stdio.h>
#include<math.h>

int eprost(int n){
int i;
for(i=2;i<sqrt(n);i++){

	if((n%i)==0){
		return 0;
	}
	else
		return 1;

}

}
int pogolem(int n){

do
	n++;

while(!eprost(n));

return n;
}
int main(){

	int x,razlika;
printf("Vnesi broj: ");
fflush(stdout);
scanf("%d",&x);
if(eprost(x) != 0){
razlika=(pogolem(x))-(eprost(x));
printf("%d",razlika);
}
else
	printf("Brojot ne e prost");

return 0;
}
