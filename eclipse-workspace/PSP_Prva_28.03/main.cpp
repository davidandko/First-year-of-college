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


int main(){
	EPLista L1;
	L1.init();
	cout<<"Prvo"<<endl;
	L1.dodadiPrv(7);
	cout<<"Vtor"<<endl;
	L1.dodadiPos(9);
	cout<<"Treto"<<endl;
	L1.dodadiPrv(1);

	L1.pechati();

	L1.brisiPrv();
	L1.pechati();
	L1.brisiPos();
	L1.pechati();

	L1.brisiLista();

	return 0;

}
