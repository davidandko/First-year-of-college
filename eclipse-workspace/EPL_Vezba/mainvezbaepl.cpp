/*
 * mainvezbaepl.cpp
 *
 *  Created on: Apr 5, 2022
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
	void kreirajPrv(int x){
		if(head!=NULL){
			cout<<"Ovaa funckija ne e za dodavanje elementi, taa go dodava samo prviot element"<<endl;
			return;
		}
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = head;
		head = nov;
	}
	void dodadiPrv(int x){
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = head;
		head = nov;
	}
	void dodadiPos(int x){
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = NULL;
		if(head == NULL){
			head = nov;
			return;
		}
		jazol *dvizi = head;
		while(dvizi->link!=NULL){
			dvizi = dvizi->link;
		}
		dvizi->link = nov;
	}
	void pechati(){
		jazol *dvizi = head;
		if(head == NULL){
			cout<<"Listata e prazna, nemam sto da pecatam";
			return;
		}
		while(dvizi->link != NULL){
			cout<<"|"<<dvizi->info<<"|->";

		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
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
		if(head->link == NULL){
			delete head;
			head = NULL;
			return;
		}
		jazol *dvizi = head;
		while(dvizi->link->link != NULL){
			dvizi= dvizi->link;
		}
		jazol *pom = dvizi->link;
		dvizi->link = NULL;
		delete pom;
	}
	void brisiJazol(jazol *node){
		if(head == node){
			brisiPrv();
			return;
		}
			jazol *dvizi = head;
			while(dvizi->link != node){
				dvizi = dvizi->link;
			}
			dvizi->link = node->link;
			delete node;
	}
	void brisiLista(){
		while(head!=NULL){
			brisiPrv();
		}
	}
};

