/*
 * maindpl.cpp
 *
 *  Created on: Apr 8, 2022
 *      Author: David
 */

#include<iostream>

using namespace std;

struct jazol{
	int info;
	jazol *next;
	jazol *prev;

};
struct DPLista{
	jazol *head;
	jazol *tail;
	void init(){
		head = tail = NULL;
	}
	void dodadiPrv(int x){
		jazol *nov = new jazol;
		nov->info = x;
		nov->prev = NULL;
		if(head == NULL){
			head = tail = nov;
			nov->next = NULL;
			return;
		}
		nov->next = head;
		head->prev = nov;
		head = nov;
	}
	void dodadiPos(int x){
		jazol *nov = new jazol;
		nov->info = x;
		nov->next = NULL;
		if(head == NULL){
			head = tail = nov;
			nov->prev = NULL;
			return;
		}
		nov->prev = tail;
		tail->next = nov;
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
		head = head->next;
		head->prev = NULL;
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
		tail = tail->prev;
		tail->next = NULL;
		delete pom;
	}
	void pechati(){
		jazol *dvizi = head;
		while(dvizi != tail){
			cout<<"|"<<dvizi->info<<"|<->";
		}
		cout<<"|"<<dvizi->info<<"|";
	}
	void brisiLista(){
		while(head != NULL){
			brisiPos();
		}
	}

};



