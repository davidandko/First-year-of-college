/*
 * mainkristina.cpp
 *
 *  Created on: Apr 7, 2022
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
			nov->next = NULL;
			return;
		}
		nov->prev = tail;
		tail->next =nov;
		tail = nov;
	}
	void brisiPrv(){
		if(head == NULL){
			cout<<"Prazna lista"<<endl;
			return;
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
			cout<<"Prazna lista bro"<<endl;
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
		if(head == NULL){
			return;
		}
		jazol *dvizi = head;
		while(dvizi->next != NULL){
			cout<<"|"<<dvizi->info<<"|<->";
		}
		cout<<"|"<<dvizi->info<<"|";
	}
	void brisiLista(){
		while(head != NULL){

		}
	}
};
struct igrac{
	string ime;
	string prezime;
	int poeni;

	void pechati(){
		cout<<ime<<" "<<prezime<<" "<<poeni<<endl;
	}
	void igraIgrac(DPLista &l){
		char nasoka;
		int broj;
		jazol *dvizi = l.head;
		while(dvizi != NULL){
			cout<<"Vnesi cekori"<<endl;
			cin>>broj>>nasoka;
			if(nasoka == 'r'){
				for(int i=0;i<=broj;i++){
					dvizi = dvizi->next;
				}
				if(dvizi == NULL){
					break;
				}else{
					poeni += dvizi->info;
				}
			}
			if(nasoka == 'l'){
				for(int i = 0;i<=broj;i++){
					dvizi = dvizi->prev;
				}
				if(dvizi == NULL){
					break;
				}
				else{
				poeni += dvizi->info;
				}
			}
		}
	}
};

void igra(igrac &ig1,igrac &ig2,DPLista &lis){
	ig1.igraIgrac(lis);
	ig2.igraIgrac(lis);
}

int main()
{
	DPLista l1;
	l1.init();
	igrac i1;
	igrac i2;
	i1.ime = "Paul";
	i1.prezime = "Kalk";
	i1.poeni = 0;
	i2.ime = "Jamie";
	i2.prezime = "Jones";
	i2.poeni = 0;
	l1.dodadiPrv(6);
	l1.dodadiPos(5);
	l1.dodadiPos(2);
	l1.dodadiPos(10);
	l1.dodadiPos(3);
	l1.dodadiPos(0);
	l1.dodadiPos(7);
	l1.pechati();

	igra(i1, i2,l1);

	if (i1.poeni > i2.poeni)
	    cout << "Pobednik e "<<i1.ime<<" "<<i1.prezime<<" so "<<i1.poeni<<"poeni";
	if (i2.poeni > i1.poeni)
	    cout << "Pobednik e "<<i2.ime<<" "<<i2.prezime<<" so "<<i2.poeni<<"poeni";
	if (i1.poeni == i2.poeni)
	{
	    cout << "Dvajcata igraci imaat ist broj na poeni: "<<i1.ime<<" "<<i1.prezime<<" so "<<i1.poeni<<"poeni";
	    cout << " i "<<i2.ime<<" "<<i2.prezime<<" so "<<i2.poeni<<"poeni";
	}
	l1.brisiLista();
}




