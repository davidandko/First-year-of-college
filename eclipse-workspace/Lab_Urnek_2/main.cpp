/*
 * main.cpp
 *
 *  Created on: Mar 12, 2022
 *      Author: David
 */

#include<iostream>
#include<string>

using namespace std;

struct Restoran{
	string ime;
	string lokacija;
	int promet;
	int brVraboteni;
	void init(string imeF,string lokacijaF,int prometF,int brVraboteniF){
		ime=imeF;
		lokacija=lokacijaF;
		promet=prometF;
		brVraboteni=brVraboteniF;
	}
	void pechati(){
		cout<<"Ime na restoranot: "<<ime<<endl;
		cout<<"Lokacija na restoranot: "<<lokacija<<endl;
		cout<<"Promet na restoranot: "<<promet<<endl;
		cout<<"Broj na vraboteni vo restoranot: "<<brVraboteni<<endl;
	}
};

struct Lanec{
	string imeLanec;
	int brRestorani;
	Restoran restorani[10];
	void init(string imeLanecF,int brRestoraniF,Restoran restoraniF){
		imeLanec=imeLanecF;
		brRestorani=brRestoraniF;
		for(int i=0;i<brRestorani;i++){
			restorani[i]=restoraniF;
		}
	}
	void pechatiL(){
		cout<<"Ime na lanecot: "<<imeLanec<<endl;
		cout<<"Broj na restorani vo lanecot: "<<brRestorani<<endl;
		for(int i=0;i<brRestorani;i++){
			restorani[i].pechati();
		}
	}
	void pechatiL(string imePreoptovari){ //preoptovaruvanje tuka
		for(int i=0;i<brRestorani;i++){
			if(restorani[i].ime == imePreoptovari){
				restorani[i].pechati();
			}
		}
	}
};


void najkorisenRestoran(Lanec *lan){
	float profit=0,prometN;
	int pozicija,brVrab;
	for(int i = 0;i<lan->brRestorani;i++){
		prometN=lan->restorani[i].promet;
		brVrab=lan->restorani[i].brVraboteni;
		if((prometN/3)-(5/100)*brVrab>profit){
			profit = (prometN/3)-(5/100)*brVrab;
			pozicija = i;
		}
	}
	cout<<"Najkorisen restoran e restoranot "<<lan->restorani[pozicija].ime<<" so profit od "<<profit<<" denari "<<endl;
}



int main(){
	Lanec lance[2];
	Restoran restorani[6];
	string imeL,imeR,lokacija;
	int brVrab,brRes,promet;
	for(int i=0;i<2;i++){
		cout<<"Vnesete ime na lanecot: "<<endl;;
		cin>>imeL;
		cout<<"Vnesete broj na restorani vo lanecot: "<<endl;
		cin>>brRes;

		for(int j=0;j<brRes;j++){
			cout<<"Vnesete ime na restoran: "<<endl;
			cin>>imeR;
			cout<<"Vnesete lokacija na restoranot: "<<endl;
			cin>>lokacija;
			cout<<"Vnesete promet na restoranot: "<<endl;
			cin>>promet;
			cout<<"Vnesete broj na vraboteni vo restoranot: "<<endl;
			cin>>brVrab;
			restorani[j].init(imeR,lokacija,promet, brVrab);
		}
		lance[i].init(imeL, brRes, restorani[i]);
	}
	lance[0].pechatiL();
	lance[1].pechatiL(lance[1].restorani[3].ime);
	najkorisenRestoran(&lance[0]);
	najkorisenRestoran(&lance[1]);

	return 0;
}
