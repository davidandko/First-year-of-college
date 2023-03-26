/*
 * main.cpp
 *
 *  Created on: Apr 5, 2022
 *      Author: David
 */
// edinecno povrzana kruzna lista
#include<iostream>

using namespace std;
struct jazol{	// bidejki e edinecno povrzana pravime samo edno link pole
	int info;
	jazol *link;
};
struct EPKLista{	// bidejki e kruzna imame i head i tail i gi azurirame na null so init
	jazol *head;
	jazol *tail;
	void init(){
		head = NULL;
		tail = NULL;
	}
	void dodadiPrv(int x){		// tuka dodavame nov jazol, prvo na nov prenesi mu info
		jazol *nov = new jazol;
		nov->info = x;

		if(head == tail){	// tuka ako tail i head se istiot jazol togas nov go vrzuvame sam so sebe i na tail i head mu go davame nov
			nov->link = nov;
			head = tail = nov;
			return;
		}
		nov->link = head;		// dokolku imame elementi, pravime sledbenikot na nov da bide head, pa sledbenikot na tail da bide nov i go azurirame head na nov
		tail->link = nov;
		head = nov;
	}
	void dodadiPos(int x){		// standardno go dodavame i mu zadavame info
		jazol *nov = new jazol;
		nov->info = x;
		if(head == NULL){		// ako head nema nisto, go povrzuvame nov samiot so sebe i mu go zadavame na head i tail
			nov->link= nov;
			head = tail = nov;
			return;
		}
		nov->link = head;		// pravime sledbenikot na nov da bide head, a sledbenikot na tail da bide nov, pa tail stanuva nov
		tail->link = nov;
		tail = nov;
	}
	void brishiPrv(){			// proveruvame dali e prazna listata
		if(head == NULL){
			return;
		}
		if(head == tail){		// ako head i tail se na istiot jazol go brisime head i gi azurirame head i tail na NULL
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *pom = head; 		// pravime pomosen jazol so head, potoa sledbenikot tail go pravime da bide sledbenikot na tail, pa head da bide sledbenikot na head i na kraj go brisime pom
		tail->link = head->link;
		head = head -> link;
		delete pom;
	}
	void brishiPos(){
		if(head==NULL){	// proveruvame dali e prazna listata
			return;
		}
		if(head == tail){ // ako ima eden jazol go brisime head i gi postavuvame head i tail na NULL
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *dvizi = head;		// dvizi za da se dvizime do pretposledniot
		while(dvizi->link != tail){
			dvizi=dvizi->link;
		}
		jazol *pom = tail;	// izolirame
		dvizi->link = head;	// sledbenikot na dvizi(pretposledniot jazol) e head
		tail = dvizi;		// tail go azurirame na dvizi
		delete pom;			// go brisime pom(tail) toj sto bil posleden
	}
	void brishiLista(){		// gi izminuvame site elementi dodeka head ne stane NULL i gi brisime so edna od napisanite funkcii
		while(head!=NULL){
			brishiPrv();
		}
	}
	void pechati(){			//proveruvame dali listata e prazna
		if(head == NULL){
			cout<<"Listata e prazna "<<endl;
			return;
		}
		jazol *dvizi = head;	// so dvizi se dvizime, izleguvame od while i na kraj go pecatime posledniot jazol
		while(dvizi != tail){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi = dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|";
	}

};


int main(){
	EPKLista kl1;
	kl1.init();

	kl1.dodadiPrv(2);
	kl1.dodadiPos(3);
	kl1.dodadiPos(4);
	kl1.dodadiPos(5);
	kl1.pechati();
	cout<<endl;
	kl1.brishiPos();
	kl1.pechati();
	cout<<endl;
	kl1.brishiPrv();
	kl1.pechati();

	return 0;
}


