/*
 * main.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: David
 */
// edinecno povrzana lista
#include<iostream>

using namespace std;

struct jazol{	// info i link pole deka e edinecno povrzana
	int info;
	jazol *link;
};
struct EPLista{		// imame samo head bidejki e obicna edinecno povrzana
	jazol *head;

	void init(){
		head = NULL;
	}
	void kreirajPrv(int x){
		if(head != NULL){  // proverka dali ima nesto vo listata, ako ima ovaa funkcija nema da se izvrsi
			cout<<"Listata e vekje kreirana, koristete dodadiPrv() ili dodadiPos()";
			return;
		}
		jazol *nov = new jazol;	// ist kako dodadiPrv, pravime nov jazol, dodavame info, pa linkot na nov go povrzuvame so head i potoa head go azurirame na nov
		nov->info = x;
		nov->link = head;
		head = nov;
	}
	void dodadiPrv(int x){
		jazol *nov = new jazol;  // ^ ^^^^^^^^ ova sto go napisav gore
		nov->info = x;
		nov->link = head;
		head = nov;

	}
	void dodadiPos(int x){	// pravime nov jazol, dodavame info,nov->link go postavuvame na NULL!!!!!! proveruvame dali e prazna listata if(true)-> head = nov
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = NULL;
		if(head == NULL){
			head = nov;
			return;
		}
		jazol *dvizi = head; // pravime *dvizi za da dvizime do posleden jazol, postavuvame dvizi->link namesto NULL da bide nov
		while(dvizi->link != NULL){
			dvizi = dvizi->link;
		}
		dvizi->link = nov;
	}
	void pechati(){			// so dvizi se dvizime do posleden jazol i pecatime kako sto odime, otkako ke zavrsi while pecatime posleden (toj sto e vo dvizi)
		jazol *dvizi = head;
		while(dvizi->link != NULL){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi = dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
	void brisiPrv(){		// proveruvame granicni slucai, ako listata e prazna zavrsi ja programata, ako ne e prazna izolirame pa go brisime pom
		if(head == NULL){
			cout<<"Listata e prazna "<<endl;
			return;
		}
		jazol *pom = head;
		head = pom->link;
		delete pom;
	}
	void brisiPos(){		// proveruvame granicni slucai, prvo dali e prazna a potoa dali ima eden element
		if(head == NULL){
			cout<<"Listata e prazna"<<endl;
			return;
		}
		if(head->link==NULL){ // ako ima eden element go brisime head i go vrakjame na NULL
			delete head;
			head = NULL;
			return;
		}
		jazol *dvizi = head;	// dvizime do pretposleden element, izolirame posleden element, azurirame posledniot da pokazuva na NULL pa go brisime toa sto e vo pom
		while(dvizi->link->link != NULL){
			dvizi = dvizi->link;
		}
		 jazol *pomoshen=dvizi->link;
		dvizi->link=NULL;
		delete(pomoshen);

	}
	void brisiJazol(jazol *node){	// na vlez imame jazol, proveruvame dali head e toj jazol, ako da brisiPrv()
		if(node == head){
			brisiPrv();
			return;
		}
		else{
			jazol *dvizi = head;	// se dvizime se dodeka ne stigneme do clenot pred node, koga ke stigneme do toj clen azurirame negoviot sleden da bide linkot na node i go brisime node
			while(dvizi!=node){
				dvizi = dvizi->link;
			}
			dvizi->link = node->link;

			delete node;
		}
	}
	void brisiLista(){			// odime do kraj na lista i brisime elementi ili so brisi Prv ili so brisi Pos
		while(head!=NULL){
			brisiPos();
		}
	}
};


int main(){
	EPLista l1;
	l1.init();
	int br,el;
	cout<<"Vnesi broj na clenovi "<<endl;
	cin>>br;
	for(int i=0;i<br;i++){
		cin>>el;
		l1.dodadiPos(el);
	}
	cout<<endl;
	l1.pechati();


return 0;
}
