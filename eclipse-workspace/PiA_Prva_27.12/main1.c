/*
 * main1.c
 *
 *  Created on: Dec 27, 2021
 *      Author: David
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char **argv){
	int brsog=0,brsam=0;
	char c;
	FILE *vlez;

	if(argc != 2){
		printf("Brojot na argumenti treba da e dva\n");
		exit(-1);
	}
printf("%s\n",argv[1]);
	vlez = fopen(argv[1],"r");
	if(vlez == NULL){
		printf("Datotekata loso se otvori\n");
		exit(-1);
	}
	while((c=fgetc(vlez)) != EOF){
		if(isalpha(c)){
			c = tolower(c);
			if(c== 'a' || c=='e'||c=='i'||c=='o'||c=='u'){
				brsam++;
			}
			else{
				brsog++;
			}
		}
	}
	fclose(vlez);

	printf("Odnosot na samoglaski/soglaski vo datotekata e %f\n",(float)brsam/brsog);

return 0;
}



