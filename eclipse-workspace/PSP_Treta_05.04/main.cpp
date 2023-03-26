/*
 * main.cpp
 *
 *  Created on: Apr 5, 2022
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
		void init(){
			head = NULL;
		}
		void dodadiPrv(int x){
			jazol *nov = new jazol;
			nov->info = x;
			nov->prev = NULL;
			if(head == NULL){
				nov->next = NULL;
				head=nov;
				return;
			}
			head->prev = nov;
			nov->next = head;
			head = nov;
		}
		void dodadiPosleden(int x){
			jazol *nov = new jazol;
			nov->info = x;
			nov->next = NULL;
			if(head == NULL){
				nov->prev = NULL;
				head = nov;
				return;
			}
			jazol *dvizi = head;
			while(dvizi->next!=NULL){
				dvizi = dvizi->next;
			}
			dvizi->next = nov;
			nov->prev = dvizi;
		}
		void brisiPrv(){
			if(head == NULL){
				return;
			}
			if(head->next == NULL){
				delete head;
				head = NULL;
					return;
			}
			jazol *pom = head;
			head->next->prev = NULL;
			head = head->next;
			delete pom;
		}
		void brisiPos(){
			if(head == NULL){
				return;
			}
			if(head->next == NULL){
				delete head;
				head = NULL;
				return;
			}
			jazol *dvizi = head;
			while(dvizi->next->next != NULL){
				dvizi = dvizi->next;
			}
			jazol *pom = dvizi;
			dvizi->prev->next = NULL;

			delete pom;
		}
		void brishiLista(){
			while(head != NULL){
				brisiPrv();
			}
		}
		void pechati(){
			if(head == NULL)
				return;

			jazol *dvizi = head;
			while(dvizi->next!=NULL){
				cout<<"|"<<dvizi->info<<"|<->";
				dvizi = dvizi->next;
			}
			cout<<"|"<<dvizi->info<<"|"<<endl;
		}
};
	struct igrac{
		string ime;
		string prezime;
		int poeni;
		void igraIgrach(DPLista L1){
			int cekori;
			char pravec;
			int igraj = 1;
			jazol *dvizi = L1.head;

			while(igraj){
				cout<<"Vnesete cekori i pravec"<<endl;
				cin>>cekori;
				cin>>pravec;
				if(pravec == 'r'){
					while(cekori>0 && dvizi!=NULL){
						cekori--;
						dvizi= dvizi->next;
					}
					if(dvizi == NULL){
						igraj = 0;
					}
					else{
						 poeni += dvizi->info;
					}
				}else{
					while(cekori>0 && dvizi !=NULL){
						cekori--;
						dvizi = dvizi->prev;
					}
					if(dvizi == NULL){
						igraj = 0;
					}
					else{
						poeni += dvizi->info;
					}
				}
			}
		}
	};
void igra(igrac &i1,igrac &i2,DPLista &L1){
		i1.igraIgrach(L1);
		i1.igraIgrach(L1);
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
	l1.dodadiPosleden(5);
	l1.dodadiPosleden(2);
	l1.dodadiPosleden(10);
	l1.dodadiPosleden(3);
	l1.dodadiPosleden(0);
	l1.dodadiPosleden(7);
	l1.pechati();

	igra(i1, i2, l1);

	if (i1.poeni > i2.poeni)
	    cout << "Pobednik e "<<i1.ime<<" "<<i1.prezime<<" so "<<i1.poeni<<"poeni";
	if (i2.poeni > i1.poeni)
	    cout << "Pobednik e "<<i2.ime<<" "<<i2.prezime<<" so "<<i2.poeni<<"poeni";
	if (i1.poeni == i2.poeni)
	{
	    cout << "Dvajcata igraci imaat ist broj na poeni: "<<i1.ime<<" "<<i1.prezime<<" so "<<i1.poeni<<"poeni";
	    cout << " i "<<i2.ime<<" "<<i2.prezime<<" so "<<i2.poeni<<"poeni";
	}
	l1.brishiLista();
}
