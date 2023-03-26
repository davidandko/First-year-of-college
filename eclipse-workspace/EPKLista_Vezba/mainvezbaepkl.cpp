/*
 * mainvezbaepkl.cpp
 *
 *  Created on: Apr 6, 2022
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
		nov->link = head;
		tail->link = nov;
		head = nov;
	}
	void dodadiPos(int x){
		jazol *nov = new jazol;
		nov->info = x;
		if(head == tail){
			nov->link = nov;
			head = tail = nov;
			return;
		}
		nov->link = head;
		tail->link = nov;
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
		tail->link = head->link;
		head = head->link;
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
		jazol *dvizi = head;
		while(dvizi->link != tail){
			dvizi = dvizi->link;
		}
		jazol *pom = tail;
		dvizi->link = head;
		tail = dvizi;
		delete pom;
	}
	void brisiLista(){
		if(head == NULL){
			return;
		}
		while(head!=NULL){
			brisiPos();
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
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
};
int main(){
	return 0;
}


