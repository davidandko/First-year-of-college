/*
 * mainepl.cpp
 *
 *  Created on: Apr 8, 2022
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
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = head;
		head = nov;
	}
	void dodadiPos(int x){
		jazol *nov = new jazol;
		nov->link = NULL;
		nov->info =x;
		if(head == NULL){
			head = nov;
			return;
		}
		jazol *dvizi = head;
		while(dvizi->link != NULL){
			dvizi = dvizi->link;
		}
		dvizi->link = nov;
	}
	void brisiPrv(){
		if(head == NULL){
			return;
		}
		jazol *pom = head;
		head = pom->link;
		delete pom;
	}
	void brisiPos(){
		if(head == NULL){
			return;
		}
		if(head ->link == NULL){
			delete head;
			head = NULL;
			return;
		}
		jazol *dvizi = head;
		while(dvizi->link->link == NULL){
			dvizi = dvizi->link;
		}
		jazol *pom = dvizi->link;
		dvizi->link = NULL;
		delete pom;
	}
	void pecati(){
		if(head == NULL){
			return;
		}
		jazol *dvizi = head;
		while(dvizi->link != NULL){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi = dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
	void brisiLista(){
		while(head != NULL){
			brisiPos();
		}
	}
};
int main(){
	return 0 ;
}


