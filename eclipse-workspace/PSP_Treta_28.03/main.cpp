/*
 * main.cpp
 *
 *  Created on: Mar 28, 2022
 *      Author: David
 */
#include<iostream>
#include<string>
using namespace std;

struct jazol{
	int info;
	jazol *link;
};

struct EPLista{
	jazol *head;

	void init(){
		head = NULL;
	}
	void kreirajEden(int x){
		if(head != NULL){
			cout<<"Listata e vekje kreirana, ako sakate da dodadete jazol koristete druga funkcija"<<endl;
			return;
		}
		jazol *pom;
		pom = new jazol;

		pom->info = x;
		pom->link =NULL;

		head = pom;
	}
	void dodadiPrv(int x){
		jazol *pom = new jazol;

		pom->info = x;

		head = pom;
	}
	void dodadiPos(int x){
		jazol *pom = new jazol;

		pom->info = x;
		pom->link = NULL;

		if(head == NULL){
			head = pom;
			return;
		}
		jazol *dvizi = head;

		while(dvizi->link != NULL){
			dvizi = dvizi->link;
		}
		dvizi->link = pom;
	}
	void brisiPrv(){
		if(head == NULL){
			cout<<"Prazna lista"<<endl;
			return;
		}
		jazol *pom = head;

		head = pom->link; // head = head->link;

		delete pom;
	}
	void brisiPos(){
		if(head == NULL){
			return;
		}
		if(head->link == NULL){
			delete head;
			head = NULL;
			return;
		}
		jazol *dvizi = head;
		while((dvizi->link)->link != NULL){
			dvizi = dvizi->link;
		}
		jazol *pom = dvizi->link;

		dvizi->link =NULL;

		delete pom;
	}
	void brisiLista(){
		while(head != NULL){
			brisiPrv();
		}
	}
	void pechati(){
		jazol *dvizi = head;

		while(dvizi != NULL){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi = dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}

};

void kreirajKombiniranaLista(EPLista &L1,EPLista &L2,EPLista &L3){
	jazol *dvizi1= L1.head;
	jazol *dvizi2 = L2.head;

	while((dvizi1!=NULL)&&(dvizi2!=NULL)){
		if(dvizi1->info<dvizi2->info){
			L3.dodadiPos(dvizi1->info);
			dvizi1 = dvizi1->link;
		}
		else{
			L3.dodadiPos(dvizi2->info);
			dvizi2 = dvizi2->link;
		}
	}
	while(dvizi1!=NULL){
		L3.dodadiPos(dvizi1->info);
		dvizi1 = dvizi1->link;
	}
	while(dvizi2!=NULL){
		L3.dodadiPos(dvizi2->info);
		dvizi2 = dvizi2->link;
	}

}


int main(){
	EPLista L1;
	EPLista L2;
	EPLista L3;
	L1.init();
	L2.init();
	L3.init();

	L1.dodadiPrv(1);

	L1.dodadiPos(3);

	L1.dodadiPrv(4);

	L1.dodadiPos(7);

	L1.dodadiPos(8);

	L2.dodadiPrv(2);
	L2.dodadiPos(5);
	L2.dodadiPos(6);

	kreirajKombiniranaLista(L1,L2,L3);
	L3.pechati();

	L1.brisiLista();
	L2.brisiLista();
	L3.brisiLista();

	return 0;
}




