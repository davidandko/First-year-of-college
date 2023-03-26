/*
 * pogolem_od.c
 *
 *  Created on: Nov 16, 2021
 *      Author: David
 */
#include<stdio.h>
int proverka(int n){

	if(n/100 == 0){
	if((n%10)<(n%100)/10){
		return 0;
	}
	return 1;
	}
	if((n%10)<(n%100)/10){
			return 0;
		}

	return (proverka(n/10));

}
int main(){
	printf("%d",proverka(23457));
	return 0;
}
