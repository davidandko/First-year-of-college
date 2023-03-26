/*
 * main2.cpp
 *
 *  Created on: Apr 4, 2022
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
		head = NULL;
		tail = NULL;
	}
	void dodadiPrv(int x){
		jazol *nov = new jazol;

		nov->info = x;
 		nov->prev =NULL; // na pocetok koga stavame mora od leva strana da e NULL (vo dvojna povrzana lista)

		if(head == NULL){
			head = tail  = nov;
			nov->next = NULL;
			return;
		}
		nov->next = head;// toa sto bilo vo head e na nov next
		head->prev = nov;//ne ja zaboravaj ovaa vrska
		head = nov; // sega head e nov
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
	void brishiPrv(){
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
	void brishiPos(){\
		if(head == NULL){
			return;
		}
		if(head == tail){
			brishiPrv();
			return;
		}
		jazol *pom = tail;

		tail = tail->prev;
		tail->next = NULL;
		delete pom;
	}
	void brishiLista(){
		while(head != NULL){
			brishiPrv();
		}
	}
	void pechati(){
		jazol *dvizi = head;
		if(dvizi == NULL){
			return;
		}
		while(dvizi->next != NULL){
			cout<<"|"<<dvizi->info<<"|<->";
			dvizi = dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
};

int main(){
	DPLista L1;
	L1.init();
	L1.dodadiPrv(2);
	L1.dodadiPos(5);
	L1.dodadiPos(3);
	L1.dodadiPos(7);
	L1.dodadiPos(1);

	L1.pechati();

	L1.brishiPos();
	L1.pechati();
	L1.brishiPrv();
	L1.pechati();

	L1.brishiLista();
	return 0;
}
