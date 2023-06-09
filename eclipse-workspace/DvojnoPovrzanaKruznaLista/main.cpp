/*
 * main.cpp
 *
 *  Created on: Apr 5, 2022
 *      Author: David
 */
// Dvojno povrzana kruzna lista
#include<iostream>

using namespace std;

struct jazol{	// pravime  next i prev bidejki e dvojno povrzana i init za da dodavame prethodnik i sledbenik na jazolot vo nego
	int info;
	jazol *next;
	jazol *prev;
	void init(int infoF,jazol *nextF,jazol *prevF){
		info = infoF;
		next = nextF;
		prev = prevF;
	}
};
struct DPKLista{		// imame head i tail bidejki dvojno povrzana i kruzna, so init site na NULL
	jazol *head;
	jazol *tail;
	void init(){
		head = tail = NULL;
	}
	void dodadiPrv(int x){		// pravime nov jazol, potoa mu davame info
		jazol *nov = new jazol;
		nov->info = x;
		if(head == NULL){		// ako listata e przna nov go vrzuvame sam so sebe, pa potoa gi pravime i head i tail da pokazuvaat na nov
			nov->next = nov->prev = nov;
			head = tail = nov;
			return;
		}
		nov->next = head;		// go stavame sledniot na nov da bide head, a na head prethodnikot da bide nov
		head->prev = nov;
		head = nov;				// go azurirame head na nov i sledbenikot na tail go pravime da bide tail, pa potoa prethodnikot na head go pravime da bide tail
		tail->next = head;
		head->prev = tail;
	}
	void dodadiPos(int x){		// pravime nov jazol i mu dodavame info, ako nema nisto vo listata go dodavame kako prv
		jazol *nov = new jazol;
		nov->info = x;
		if(head == NULL){
			dodadiPrv(x);
			return;
		}
		tail->next = nov;	// pravime sledbenikot na tail da bide nov, pa prethodnikot na nov da bide tail, na kraj azurirame tail da bide nov
		nov->prev = tail;
		tail = nov;
		tail->next = head;	// sledbenikot na tail da bide head i prethodnikot na head da bide tail
		head->prev = tail;
	}
	void brisiPrv(){
		if(head->next == head){ // ako imame eden jazol, go brisime head i gi postavuvame i head i tail na NULL
			delete head;
			head = tail = NULL;
			return;
		}
		tail->next = head->next;	// sledbenikot na tail da bide sledbenikot na head
		head->next->prev = tail;	// na sledbenikot na head prethodnik da bide tail;
		delete head;				// go brisime head
		head = tail->next;			// head ke bide sledbenikot na tail
	}
	void brisiPosleden(){
		if(head->next == head){	// proveruvame dali ima samo eden element, ako da togas go brisime head i gi resetirame head i tail na NULL
			delete head;
			head = tail = NULL;
			return;
		}
		head->prev = tail->prev; // prethodnikot na head da bide prethodnikot na tail
		tail->prev->next = head;	// na prethodnikot na head sledbenik da bide head
		delete tail;				// go brisime tail
		tail = head->prev;			// tail go pravime da bide prethodnik na head
	}
	void pecati(){				// sekade e isto ne bidi glup
		jazol *dvizi = head;
		if(head == NULL){
			cout<<"Nemam sto da pecatam"<<endl;
			return;
		}
		if(head != NULL){
			do{
				cout<<"<->|"<<dvizi->info<<"|<->";
				dvizi = dvizi->next;
			}while(dvizi != head);
		}
	}
};

int main(){
	DPKLista dk1;
	dk1.init();
	dk1.dodadiPrv(24);
	dk1.dodadiPos(65);
	dk1.dodadiPos(1000);
	dk1.dodadiPos(69);
	dk1.pecati();
	cout<<endl;
	dk1.brisiPosleden();
	dk1.pecati();
	cout<<endl;
	dk1.brisiPrv();
	dk1.pecati();


	return 0;
}

