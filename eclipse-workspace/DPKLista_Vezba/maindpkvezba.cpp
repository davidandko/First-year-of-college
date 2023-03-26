/*
 * maindpkvezba.cpp
 *
 *  Created on: Apr 6, 2022
 *      Author: David
 */

#include<iostream>

using namespace std;

struct jazol{
	int info;
	jazol *next;
	jazol *prev;
};

struct DPKLista{
	jazol *head;
	jazol *tail;
	void init(){
		head = tail = NULL;
	}
	void dodadiPrv(int x){
		jazol *nov = new jazol;
		nov->info = x;
		if(head == NULL){
			nov->next = nov->prev = nov;
			head = tail = nov;
			return;
		}
		nov->next = head;
		nov->prev = tail;
		head = nov;
		tail->next = head;
		head->prev = tail;

	}
	void dodadiPos(int x){
		jazol *nov = new jazol;
		if(head==NULL){
			nov->next = nov->prev = nov;
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
		if(head == NULL){
			return;
		}
		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *pom = tail;
		tail->prev->next = head;
		head->prev = tail->prev;
		tail = tail->prev;

		delete pom;
	}
	void pecati(){
		if(head == NULL){
			return;
		}
		jazol *dvizi = head;
		while(dvizi!=tail){
			cout<<"|"<<dvizi->info<<"|<->";
			dvizi = dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
	void brisiLista(){
		if(head == NULL){
			return;
		}
		while(head!=NULL){
			brisiPos();
		}
	}
};
int main(){
	return 0;
}

