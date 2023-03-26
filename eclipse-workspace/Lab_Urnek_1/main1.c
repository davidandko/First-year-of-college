/*
 * main1.c
 *
 *  Created on: Mar 5, 2022
 *      Author: David
 */
#include<stdio.h>
#include<string.h>
typedef struct Restoran{
char ime[30];
char lokacija[50];
int brVraboteni;
}restoran;

typedef struct Lanec{
	char ime[30];
	int brRest;
	restoran rest[10];
}lanec;

void pechati(lanec *lan,int brVraboteni){
	int i;
	for(i=0;i<lan->brRest;i++){
		if(lan->rest[i].brVraboteni<brVraboteni){
			printf("Ime na restoran: %s\n",lan->rest[i].ime); fflush(stdout);
			printf("Lokacija: %s\n",lan->rest[i].lokacija); fflush(stdout);
			printf("\n\n"); fflush(stdout);
		}
	}

}



int main(){
	int i,j;
	lanec l1,l2;

		printf("Vnesi ime na lanec: \n"); fflush(stdout);
		scanf("%s",l1.ime);
		printf("Vnesi broj na restorani: \n"); fflush(stdout);
		scanf("%d",&l1.brRest);
		printf("Pocni da vnesuvas restorani:\n"); fflush(stdout);
		for(j=0;j<l1.brRest;j++){
			printf("Ime: \n"); fflush(stdout);
			scanf("%s",l1.rest[j].ime);
			printf("Broj na vraboteni: \n"); fflush(stdout);
			scanf("%d",&l1.rest[j].brVraboteni); fflush(stdout);
			printf("Lokacija: \n"); fflush(stdout);
			scanf("%s",l1.rest[j].lokacija);
		}

		printf("Vnesi ime na lanec: \n"); fflush(stdout);
				scanf("%s",l2.ime);
				printf("Vnesi broj na restorani: \n"); fflush(stdout);
				scanf("%d",&l2.brRest);
				printf("Pocni da vnesuvas restorani:\n"); fflush(stdout);
				for(i=0;i<l2.brRest;i++){
					printf("Ime: \n"); fflush(stdout);
					scanf("%s",l2.rest[i].ime);
					printf("Broj na vraboteni: \n"); fflush(stdout);
					scanf("%d",&l2.rest[i].brVraboteni); fflush(stdout);
					printf("Lokacija: \n"); fflush(stdout);
					scanf("%s",l2.rest[i].lokacija);
				}
		pechati(&l1,3);
		pechati(&l2,3);

	return 0;
}



