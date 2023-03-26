/*
 * main.cpp
 *
 *  Created on: Apr 5, 2022
 *      Author: David
 */
#include <iostream>
using namespace std;

struct jazol {
	int info;
	jazol *next;
	jazol *prev;
};

struct DPKLista {
	jazol *head;
	jazol *tail;

	void init(){
		head = tail = NULL;
	}

	void dodadiPrv(int x){
		jazol *nov = new jazol;
		nov->info = x;

		if(head==NULL){
			nov->next = nov;
			nov->prev = nov;

			head = tail = nov;
			return;
		}

		nov->next = head;
		nov->prev = tail;
		head->prev = nov;
		tail->next = nov;

		head = nov;
	}

	void dodadiPos(int x){
		jazol *nov = new jazol;
		nov->info = x;

		if(head == NULL){
			nov->next = nov;
			nov->prev = nov;
			head = tail = nov;
			return;
		}

		nov->next = head;
		nov->prev = tail;
		tail->next = nov;
		head->prev = nov;

		tail = nov;
	}

	void brisiPrv(){
		if(head == NULL){
			return;
		}

		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}

		jazol *pom = head;

		tail->next = head->next;
		head->next->prev = tail;

		head = head->next;

		delete pom;
	}

	void brisiPos(){
		if(head == NULL)
			return;

		if(head == tail){
			delete head;
			tail = head = NULL;
			return;
		}

		jazol *pom = tail;

		tail->prev->next = head;
		head->prev = tail->prev;

		tail = tail->prev;

		delete pom;
	}

	void brisiLista(){
		while(head!=NULL)
			brisiPos();
	}

	void pechati(){
		jazol *dvizi = head;

		if(head == NULL)
			return;

		while(dvizi!=tail){
			cout<<"|"<<dvizi->info<<"|<->";
			dvizi=dvizi->next;
		}

		cout<<"|"<<dvizi->info<<"|"<<endl;
	}

};

int main(){
	DPKLista L1;

	L1.init();

	L1.dodadiPrv(2);
	L1.dodadiPos(5);
	L1.dodadiPos(3);
	L1.dodadiPos(7);
	L1.dodadiPos(1);

	L1.pechati();

	L1.brisiPrv();
	L1.pechati();
	L1.brisiPos();
	L1.pechati();

	L1.brisiLista();

	return 0;
}






