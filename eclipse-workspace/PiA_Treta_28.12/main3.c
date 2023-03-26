/*
 * main3.c
 *
 *  Created on: Dec 28, 2021
 *      Author: David
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
// so matricata
int main(){
	FILE *vlezna,*izlezna;
	float mat[10][10];
	int m,n,i,j;
	vlezna = fopen("dataV.txt","r");
	if(vlezna == NULL){
		printf("Datotekata e pogreshno otvorena\n");
		exit(-1);
	}
	izlezna = fopen("matrica2.txt","w");
	if(izlezna == NULL){
			printf("Datotekata e pogreshno otvorena\n");
			exit(-1);
	}
	fscanf(vlezna,"%d%d",&m,&n);

	for(i=0;i<m && !feof(vlezna);i++){
		for(j=0;j<n && !feof(vlezna);j++){
			fscanf(vlezna,"%f",&mat[i][j]);
		}
	}
	if(!(i==m && i==n)){
		printf("Imalo problem so otchituvanjeto\n");
		exit(-1);
	}
	fprintf(izlezna,"%d %d",n,m);

	for(j=0;j<n;j++){
		for(i=0;i<m;i++){
			fprintf(izlezna,"%f\n",mat[i][j]);
		}
	}
	fclose(vlezna);
	fclose(izlezna);
	return 0;
}

// ne raboti proveri
