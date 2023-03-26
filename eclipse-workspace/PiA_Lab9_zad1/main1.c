/*
 * main1.c
 *
 *  Created on: Dec 29, 2021
 *      Author: David
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
void isti(char s1[MAX],char s2[MAX]){
int i = 0;
	while((s1[i] != '\0') && (s2[i] != '\0')){
		if(isalpha(s1[i]) && isalpha(s2[i])){ //dvata elementi se bukvi
			if(s1[i]<s2[i]){ // s1 element e pomal od s2 element
				printf("Elementot %c e pomal od %c\n",toascii(s1[i]),toascii(s2[i]));
			}
			if(s1[i]>s2[i]){ // s2 element e pomal od s1 element
				printf("Elementot %c e pomal od %c\n",toascii(s2[i]),toascii(s1[i]));
			}
		}
		if(!(isalpha(s1[i])) && !(isalpha(s2[i]))){ //ni s1 ni s2 element ne e bukva
					if(s1[i]<s2[i]){
						printf("Elementot %c e pomal od %c\n",toascii(s1[i]),toascii(s2[i]));
					}
					if(s1[i]>s2[i]){
						printf("Elementot %c e pomal od %c\n",toascii(s2[i]),toascii(s1[i]));
					}
				}
		if((isalpha(s1[i])) && !(isalpha(s2[i]))){
			printf("Pecatam prazno mesto   fala mnogu\n");
		}
		if(!(isalpha(s1[i])) && isalpha(s2[i])){
					printf("Pecatam prazno mesto   fala mnogu\n");
				}
i++;
	}
}
int main(){
char s1[MAX],s2[MAX];
printf("Vnesi tekstualna niza vo s1: \n");
fflush(stdout);
fgets(s1,MAX,stdin);
printf("Vnesi tekstualna niza vo s2: \n");
fflush(stdout);
fgets(s2,MAX,stdin);

return 0;
}

