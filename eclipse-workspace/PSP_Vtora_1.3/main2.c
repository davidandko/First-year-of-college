/*
 * main2.c
 *
 *  Created on: Mar 1, 2022
 *      Author: David
 */
#include<stdio.h>
	enum sostojbi {stoi,nagore,nadolu};

	typedef struct ll{
		enum sostojbi sostojba;
		int sprat;
		int brPat;
	}lift;

	typedef struct pp{
		int odKade;
		int doKade;
	}patnik;

	void povikajLift(struct ll *l,patnik p){
		int i;
	if(l->sostojba != stoi){
		l->sostojba = stoi;
		printf("Liftot e zastanat\n");
	}
	if(l->sprat < p.odKade){
		l->sostojba = nagore;
		printf("Liftot trgna nagore\n");
		for(i=l->sprat;i<p.odKade;i++){
			printf("Liftot se naogja na %d sprat\n",i);
			l->sprat++;
		}
		printf("Liftot se naogja na %d sprat\n",i);

	}else if(l->sprat > p.odKade){
		l->sostojba = nadolu;
		printf("Liftot trgna nadolu\n");
		for(i=l->sprat;i<p.odKade;i--){
		printf("Liftot se naogja na %d sprat\n",i);
		l->sprat--;
	}
		l->sostojba = stoi;
		printf("Liftot zastana\n");

	}
	if(l->brPat>=5){
		printf("Nema mesto\n");
		return;
	}
	l->brPat++;
	printf("Brojot na patnici e %d\n",l->brPat);

	if(p.odKade>p.doKade){
		l->sostojba = nadolu;
		printf("Liftot trgna nadolu\n");

		for(i=p.odKade;i>p.doKade;i--){
			l->sprat--;
			printf("Liftot se naogja na %d sprat",l->sprat);
		}
		l->sostojba = stoi;
		printf("Liftot zastana\n");
	}else if(p.odKade<p.doKade){
		l->sostojba = nagore;
		printf("Liftot trgna nagore\n");
		for(i=p.odKade;i>p.doKade;i++){
		l->sprat--;
		printf("Liftot se naogja na %d sprat",l->sprat);
		}
	l->sostojba = stoi;
			printf("Liftot zastana\n");

	}
	l->brPat--;
	printf("Brojot na patnici %d \n",l->brPat);
	}
int main(){
	lift liftot = {stoi,3,0};
	patnik patnikot = {1,6};
	povikajLift(&liftot,patnikot);

	return 0;
}

