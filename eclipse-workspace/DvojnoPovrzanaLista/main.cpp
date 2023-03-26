/*
 * main.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: David
 */
// Dvojno povrzana lista
#include<iostream>

using namespace std;

struct jazol{	// imame next i prev bidejki e dvojno povrzana, i funkcija init koja ni dozvoluva polesno da inicijalizirame jazli
	int info;
	jazol *next;
	jazol*prev;
	void init(int infoF, jazol *nextF,jazol *prevF){
		info = infoF;
		next = nextF;
		prev = prevF;
	}
};
struct DPLista{

	jazol *head;		// imame head i tail bidejki e dvojno povrzana lista
	jazol *tail;
	void init(){		// head i tail gi postavuvame na NULL standardno
		head = NULL;
		tail = NULL;
	}
	void vnesiPrv(int info){	// pravime nov jazol, go incijalizirame so funkcijata init vo jazol (mu zadavame info, nareden clen i prethoden clen)
		jazol *nov = new jazol;
		nov->init(info, head, NULL);
		if(tail == NULL){  		// tuka proveruvame dali ima nesto vo tail ako nema togas tamu go dodavame info;
			tail = nov;
		}
		else{
		head->prev = nov;		// tuka pazi mnogu so else, ako nemas else nisto nema da raboti kako so treba, prethodnikot na head e nov, koga ke izlezeme od forot go azurirame head = nov
		}
		head = nov;
	}
	void vnesiPosleden(int info){		// proveruvame dali ima nesto vo listata, ako nema povikuvame dodadi prv
		if(head == NULL){
			vnesiPrv(info);
		}					//pravime nov jazol, go inicijalizirame naredniot na tail da bide nov i tail go postavuvame na nov
		jazol *nov = new jazol;
		nov->init(info,NULL,tail);
		tail->next = nov;
		tail = nov;
	}
	void pecati(){						// isto kako sekade so dvizi odime do posledniot i potoa go pecatime i posledniot ko ke izlezime od while
		jazol *dvizi = head;
		while(dvizi->next != NULL){
			cout<<"|"<<dvizi->info<<"|<->";
			dvizi = dvizi->next;
		}
		cout<<"|"<<dvizi->info<<"|";
	}
	void izbrisiPrv(){
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
	void izbrishiPos(){
			if(head == NULL){
				return;
			}
			if(head == tail){
				izbrisiPrv();
				return;
			}
			jazol *pom = tail;

			tail = tail->prev;
			tail->next = NULL;
			delete pom;
		}
	void izbrisiJazol(jazol *node){		// proveruvame dali e node e head, ako da ke ja povikame izbrisi prv
		if(head == node){
			izbrisiPrv();
		}
		else{
			jazol *dvizi = head;
			while(dvizi->next != node){
				dvizi = dvizi ->next;  // koga ke izlezeme od while dvizi ke e pred node
			}
			dvizi->next = node->next; //sledbenikot na dvizi namesto node, go pravime da bide toj posle node
			(node->next)->prev = dvizi; //ne se buni, tuka na sledbenikot na node mu zadavame prethodnik da mu bide dvizi
			delete node; // node ne ni treba pa go brisime
			}
	}
};
int main(){
	DPLista dp1;
	dp1.init();


	dp1.vnesiPrv(2);
	dp1.vnesiPosleden(3);
	dp1.vnesiPosleden(4);
	dp1.pecati();
	cout<<endl;
	dp1.izbrishiPos();
	dp1.pecati();
	cout<<endl;
	dp1.izbrisiPrv();
	dp1.pecati();


	return 0;
}


