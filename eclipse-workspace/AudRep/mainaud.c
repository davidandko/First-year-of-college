/*
 * mainaud.c
 *
 *  Created on: Mar 2, 2022
 *      Author: David
 */
#include<stdio.h>

typedef struct Datum{
	int den;
	int mesec;
	int godina;
}datum;
typedef struct Prijatel{
	char ime[30];
	datum data;
	char poraka[200];
}prijatel;
typedef struct Profil{
	char ime[30];
	char grad[30];
	prijatel listaPrijatel[5000];
	int brPrijateli;
	datum data;
}profil;
void smeniIme(profil *prof){
	printf("Vnesete go novoto ime\n");fflush(stdout);
	gets(prof->ime);
	printf("Uspesno go smenavte imeto\n");fflush(stdout);
}
void smeniGrad(profil *prof){
	printf("Vnesete go imeto na noviot grad\n");fflush(stdout);
	gets(prof->grad);
	printf("Uspesno go smenavte gradot\n");fflush(stdout);
}
void smeniDatum(profil *prof){
	printf("Vnesete nov datum\n");fflush(stdout);
	scanf("%d%d%d",&(prof->data.den),&(prof->data.mesec),&(prof->data.godina));
	printf("Datumot e smenet\n");fflush(stdout);
}
void dodadiPrijatel(profil *prof,prijatel novprijatel){
	if((prof->brPrijateli)>=5000){
		printf("Ne mozete da imate povekje od 5000 prijateli\n");
		fflush(stdout);
	}
	else{
		prof->listaPrijatel[prof->brPrijateli] = novprijatel;
		(prof->brPrijateli)++;
		printf("Imate nov prijatel\n");
	}
}
void izbrisiPrijatel(profil *profil,char dushman){
	int i, j, najden = 0;
	for (i = 0; i < profil->brPrijateli; i++)
	 {
	 if (!strcmp(dushman, profil->listaPrijatel[i].ime))
	 {
	 for (j = i; j < profil->brPrijateli - 1; j++)
	 profil->listaPrijatel[j] = profil->listaPrijatel[j + 1];
	 (profil->brPrijateli)--;
	 najden = 1;
	 break;
	 }
	 }
	if (!najden) {
	 printf("Vo vashata lista na prijateli ne postoi prijatel so ime %s \n",
	dushman); fflush(stdout);
	 }
	else {
	 printf("Prijatelot so ime %s e izbrisan od vasata lista na prijateli\n",
	dushman); fflush(stdout);
	 }
	}



int main(){

}



