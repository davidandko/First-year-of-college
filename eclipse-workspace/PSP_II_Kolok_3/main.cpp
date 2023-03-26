/*
 * main.cpp
 *
 *  Created on: May 22, 2022
 *      Author: David
 */
#include<iostream>
#include<cstring>
using namespace std;

class Kadar{
protected:
	string ime;
	string prezime;
	int embg;
	char institut[7];
	int osnovnaPlata;
	string *nizaPredmeti;
	int brPredmeti;
public:
	Kadar(string imeF ="",string prezimeF = "",int embgF = 0,char *institutF =NULL,int osnovnaPlataF = 0,string *nizaPredmetiF = NULL,int brPredmetiF = 0){
		ime = imeF;
		prezime = prezimeF;
		embg = embgF;
		strcpy(institut,institutF);
		osnovnaPlata = osnovnaPlataF;
		nizaPredmeti = new string[brPredmeti];
		for(int i = 0;i<brPredmetiF;i++){
			nizaPredmeti[i] = nizaPredmetiF[i];
		}
		brPredmeti = brPredmetiF;
	}
	virtual int plata(){
		return osnovnaPlata;
	}
	virtual ~Kadar(){
		delete [] nizaPredmeti;
	}
	void pechati(){
		cout<<"Ime i prezime: "<<ime<<" "<<prezime<<endl;
		cout<<"EMBG: "<<embg<<endl;
		cout<<"Institut: "<<institut;
		cout<<"Plata: "<<plata()<<endl;
		for(int i=0;i<brPredmeti;i++){
			cout<<nizaPredmeti[i]<<", ";
		}
		cout<<endl;
	}
	bool predavaPredmet(string predmet){
		for(int i =0;i<brPredmeti;i++){
			if(nizaPredmeti[i] == predmet){
				return true;
			}
		}
		return false;
	}
	bool Institut(char *ins){
		if(strcmp(institut,ins)==0){
			return true;
		}
		return false;
	}
};
class Profesor : public Kadar{
private:
	int staz;
	int trudovi;
public:
	Profesor(string imeF ="",string prezimeF = "",int embgF = 0,char *institutF =NULL,int osnovnaPlataF = 0,string *nizaPredmetiF = NULL,int brPredmetiF = 0,int stazF = 0,int trudoviF = 0) :Kadar(imeF,prezimeF,embgF,institutF,osnovnaPlataF,nizaPredmetiF,brPredmetiF){
		staz = stazF;
		trudovi = trudoviF;
	}
	int plata(){
		int vkupno = Kadar::plata()+ (5/100)*staz*Kadar::plata() + (2/100)*trudovi*Kadar::plata();
		return vkupno;
	}
	void pechati(){
		Kadar::pechati();
		cout<<"Staz: "<<staz<<endl;
		cout<<"Broj na trudovi: "<<trudovi<<endl;
	}


};

class Asistent:public Kadar{
private:
	bool dr; // 0 ne , 1 da
public:
	Asistent(string imeF ="",string prezimeF = "",int embgF = 0,char *institutF =NULL,int osnovnaPlataF = 0,string *nizaPredmetiF = NULL,int brPredmetiF = 0,bool drF = 0) : Kadar(imeF,prezimeF,embgF,institutF,osnovnaPlataF,nizaPredmetiF,brPredmetiF){
		dr = drF;
	}
	int cena(){
		int vkupno = Kadar::plata();
		if(dr == true){
			vkupno+=1000;
		}
		return vkupno;
	}
	void pechati(){
		Kadar::pechati();
		cout<<"Doktorski studii: "<<(dr?"Da":"Ne")<<endl;
	}

};
void odgovoren(string predmet,Kadar **k,int broj){
	for(int i = 0;i<broj;i++){
		if(k[i]->predavaPredmet(predmet)){
			k[i]->pechati();
		}
	}
}
void najplatenNaInstitut(char *institut,Kadar **j,int broj){
	int maxPlata = 0;
	Kadar *pom;
	for(int i=0;i<broj;i++){
		if(j[i]->Institut(institut)){
			if(maxPlata<j[i]->plata()){
				maxPlata = j[i]->plata();
				pom = j[i];
			}
		}
	}
	cout<<"Najgolema plata: "<<maxPlata<<endl;
	pom->pechati();
}

int main(){
	Kadar *kadar[5];
	string p1[3] = {"SsP","MiA","Math"};
	kadar[0] =	new Profesor("Petko","Petkov",23131,"KTI",20000,p1,3,10,20);
	kadar[1] = new Asistent("Ana","Aneva",23131,"TK",15000,p1,3,false);
	kadar[2] = new Profesor("Goran","Mishevski",42142,"TK",20000,p1,3,15,10);
	kadar[3] = new Profesor("Marija","Kolevska",56565,"TK",20000,p1,3,5,30);
	kadar[4] = new Asistent("Zoran","Janev",78799,"KTI",20000,p1,3,true);
	odgovoren("MiA",kadar,5);
	najplatenNaInstitut("KTI",kadar,5);
	najplatenNaInstitut("TK",kadar,5);
	for(int i =0;i<5;i++){
		delete kadar[i];
	}
	return 0;
}

