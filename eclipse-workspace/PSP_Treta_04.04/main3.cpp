/*
 * main3.cpp
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

struct EPKLista{
	jazol *head;
	jazol *tail;
	void init(){
		head = tail = NULL;
	}
	void dodadiPrv(int x){
		jazol *nov = new jazol;

		nov->info = x;
		if(head == tail){
			nov->link = nov;
			head = tail = nov;
			return;
		}
		nov->link= head;
		tail->link = nov;
		head = nov;
	}
	void dodadiPos(int x){
		jazol *nov = new jazol;
		nov->info = x;

		if(head == NULL){
			nov->link = nov;
			tail->link = nov;
			return;
		}
		nov->link = head;
		tail->link = nov;
		tail = nov;
	}
	void brishiPrv(){
		if(head == NULL){
			return;
		}
		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *pom = head; // izolacija

		tail->link = head->link;
		head = head->link;

		delete pom;
	}
	void brishiPos(){
		if(head == NULL){
			return;
		}
		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *pom = tail;
		jazol *dvizi = head;
		while(dvizi->link != tail){ // ova se dvizi se do posledniot jazol kade zastanuva
			dvizi = dvizi->link;
		}
		dvizi->link = head;
		tail = dvizi;
		delete pom;
	}
	void brishiLista(){
		while(head != NULL){
			brishiPrv();
		}
	}
	void pechati(){
		if(head == NULL){
			return;
		}
		jazol *dvizi = head;

		while(dvizi != tail){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi = dvizi->link;
		}
		cout<<"|"<<tail->info<<"|"<<endl;
	}
};

int main(){
	EPKLista L1;

	L1.init();

	L1.dodadiPrv(1);
	L1.dodadiPos(4);
	L1.dodadiPos(6);
	L1.dodadiPos(5);
	L1.dodadiPos(3);


	L1.pechati();

	L1.brishiPrv();
	L1.pechati();
	L1.brishiPos();
	L1.pechati();

	L1.brishiLista();


	return 0;
}
