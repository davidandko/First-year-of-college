/*
 * 19.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int simp;
	printf("Glavobolka= 1 Gradna Bolka = 2 Povrakjanje = 3 Vrtoglavica = 4 Bolka Vo Grb = 5 \n");
	printf("Vnesete simptomi: \n");
fflush(stdout);
	while(scanf("%d",&simp)){
		if(simp==1 || simp==4){
			printf("Oftamolog\n");
		}
		if(simp==2&& (simp==5 || simp==1)){
			printf("Kardiolog\n");
		}
		if((simp==3 && simp==4) || simp==1 ){
			printf("Ginekolog\n");
		}
		if((simp==1 && simp!=3) || simp==4){
			printf("Maticen lekar\n");
		}
	}
return 0;
}
