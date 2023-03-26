/*
 * maindplvezba.cpp
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
	void init(int infoF,jazol *nextF,jazol *prevF){
		info = infoF;
		next = nextF;
		prev = prevF;
	}
};
struct DPLista{
	jazol *head;
	jazol *tail;
	void init(){
		head = tail = NULL;
	}
	void dodadiPrv(int x){ // pazi
		jazol *nov = new jazol;
		nov->init(x,head,NULL);
		if(tail == NULL){
			tail = nov;
		}
		else{   // tuka
			head->prev = nov;
		}
		head = nov;
	}
	void dodadiPos(int x){
		if(head == NULL){
			dodadiPrv(x);
		}
		jazol *nov = new jazol;
		nov->init(x, NULL, tail);
		tail->next = nov;
		tail = nov;
	}
	void pecati(){
		jazol *dvizi = head;
		while(dvizi->next != NULL){
			cout<<"|"<<dvizi->info<<"|<->";
			dvizi = dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
	void brisiPrv(){
		if(head == NULL){
			cout<<"Listata e prazna"<<endl;
		}
		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *pom = head;
		head = head->next;
		head->prev =NULL;
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
	void brisiLista(){
		if(head==NULL){
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


