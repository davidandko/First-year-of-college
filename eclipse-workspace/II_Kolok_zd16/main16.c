/*
 * main16.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */

int main( int argc, char **argv){
	FILE *datoteka;
	char nizaRed[MAX];
	char c;
	int inword, words=0;;
	int line=0;
	int dol,i;

	if(argc!=0){
		printf("Upotreba na programata: %s ime_na_datoteka_za_citanje\n",argv[0]);
		return -1;
	}

	if((datoteka=fopen((argv[1]),"r"))==NULL){
		printf("Ne moze da se otvori datotekata za citanje.\n");
		return -1;
	}

	while((fgets(nizaRed,MAX,datoteka))!= NULL){
		// MI TREBA DOLZINATA NA NIZATA !!!
		dol=strlen(nizaRed);
		words=0;
		inword=0;
		for(i=0;i<dol;i++){ // KARAKTER PO KARAKTER.
			c=nizaRed[i]; // VO C KJE GO STAVIME MOMENTALNIOT ZNAk NA POZICIJA I
			if(isalpha(c)){
				if(!inword){
					inword=1;
					words++;

				}else if(inword){
					inword=0;
				}
			}
		}
		 if(words>10){
			 line++;
		 }
	}
	printf("Vo %d redovi ima povekje od 10 zborovi.\n",line);
	fclose(datoteka);

return 0;
}
