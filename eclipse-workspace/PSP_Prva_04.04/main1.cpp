/*
 * main1.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: David
 */

#include<iostream>

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
	void dodadiPrv(int x){
		jazol *pom = new jazol;

		pom->info = x;
		pom->link = head;

		head = pom;

	}
	void brisiLista(){
		while(head != NULL){
			jazol *pom = head;
			head = head->link;
			delete pom;
		}
	}
	void pechati(){
		jazol *dvizi = head;
		if(dvizi == NULL){
			return;
		}
		while(dvizi->link != NULL){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi = dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|->";

	}

};

void prevrtiLista(EPLista &L1){
	jazol *head = L1.head;
	jazol *novaHead = NULL;
	jazol *pom = head;
	while(head != NULL){
		head = head->link;
		pom->link = novaHead;
		novaHead = pom;
		pom  = head;
	}
L1.head = novaHead;
}

int main(){
	EPLista L;
	L.init();
	L.dodadiPrv(1);
	L.dodadiPrv(7);
	L.dodadiPrv(3);
	L.dodadiPrv(5);
	L.dodadiPrv(2);

	L.pechati();
	prevrtiLista(L);
	cout<<endl;
	L.pechati();
	L.brisiLista();

	return 0;
}
