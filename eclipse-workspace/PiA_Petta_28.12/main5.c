/*
 * main5.c
 *
 *  Created on: Dec 28, 2021
 *      Author: David
 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc, char **argv){
	FILE *vlezna;
	char zbor[21],c;
	int brZb=0,k=0,iw=0,i,j,brp;

	if(argc != 2){
		printf("Losho povikana programa\n");
		exit(-1);
	}

	vlezna = fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("Problem so otvoranje na datotekATA\n");
		exit(-1);
	}
	while((c = fgetc(vlezna)) != EOF){
		if(isalpha(c)){
			if(iw==0){
				iw = 1;
			}
			zbor[k] = c;
			k++;
		}
		else{
			if(iw==1){
				zbor[k] = '\0';

				for(i=0;i<k;i++){
					brp = 1;
					for(j=i+1;j<k;j++){
						if(tolower(zbor[i])==tolower(zbor[j])){
							brp++;
						}
					}
					if(brp>2){
						brZb++;
						break;
					}
					k=0;
					iw=0;
				}
			}
		}

	}
	if(k !=0){
		zbor[k] = '\0';
		for(i=0;i<k;i++){
				brp = 1;
				for(j=i+1;j<k;j++){
					if(tolower(zbor[i])==tolower(zbor[j])){
						brp++;
					}
				}
				if(brp>2){
					brZb++;
					break;
				}
		k=0;
		iw=0;
		}
	}
	fclose(vlezna);
	printf("Vo datotekata imalo %d takvi zborovi\n",brZb);
return 0;
}

