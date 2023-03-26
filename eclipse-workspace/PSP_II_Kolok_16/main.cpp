/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
 * За секој одмор се знае името на дестинацијата (динамички алоцирана низа од знаци), колку дена трае
(цел број), основната цена на аранжманот (цел број), број на понудени факултативни посети, како и цена за секоја
понудена факултативна посета (динамички алоцирана низа од цели броеви). Одморот може да биде летен или
зимски. За летниот одмор дополнително се чува информација за типот на превоз (автомобил - 0, автобус - 1, авион
- 2), како и информација дали аранжманот е полупансион - 1 или цел пансион - 2. За зимскиот одмор дополнително
се чува информација дали е уплатена ски-карта, како и цена за ски-картата за еден ден.
 Да се напише функција presmetajCena() која ја пресметува вкупната цена која треба да се плати. Цената се
пресметува на тој начин што основната цена се собира со цената на сите факултативни посети. Доколку
станува збор за летен одмор, за полупансион се доплаќа 100, а за цел пансион се доплаќа 150. Ако превозот
е со авион се доплаќа уште 100. Доколку станува збор за зимски одмор, за уплатена ски карта се собира и
цената на ски картатата за секој ден од одморот.
 Да се преоптовари операторот > кој проверува дали првиот одмор (независно од типот) има поголема
вкупна цена од вториот одмор.
 Надвор од класите да се напише функција najdiSporedKategorija() која како аргументи прима низа од
одмори независни од типот, број на одмори во низата, број на денови и име на дестинација. Функцијата
треба да го најде и испечати најскапиот одмор во низата на дадената дестинација, кој не трае повеќе од
бројот на денови пренесени како аргумент.
Главната програма е дадена во продолжение.
Забелешка: Кодот сместете го во датотеката SsPZad3.cpp
int main()
{
Odmor *odmori[3];
odmori[0] = new Leten("Maldivi", 10, 1000, 4, {50, 30, 20, 60}, 2, 2);
odmori[1] = new Zimski("Kopaonik", 7, 500, 3, {20, 25, 20}, true, 40);
odmori[2] = new Leten("Santorini", 7, 700, 3, {10, 15, 30}, 2, 1);
najdiSporedkategorija(odmori, 3, "Maldivi", 8);
}
 */
#include<iostream>
#include<cstring>
using namespace std;

enum prevoz{avtomobil,avtobus,avion};
string prevozi[3] = {"Avtomobil","Avtobus","Avion"};
enum tip{polupansion=1,pansion=2};
string tipovi[2]= {"Polupansion","Pansion"};


class Odmor{
protected:
	char *destinacija;
	int traenje;
	int cena;
	int fakultativi;
	int *cenafak;
public:
	Odmor(char *destinacijaF = '\0',int traenjeF = 0, int cenaF = 0,int fakultativiF =0,int *cenafakF =0){
		destinacija = new char[strlen(destinacijaF)+1];
		strcpy(destinacija,destinacijaF);
		traenje = traenjeF;
		cena = cenaF;
		fakultativi = fakultativiF;
		cenafak = new int[fakultativi];
		for(int i = 0;i<fakultativi;i++){
			cenafak[i] = cenafakF[i];
		}
	}
	virtual int presmetajCena(){
		int vkupno = 0;
		for(int i =0;i<fakultativi;i++){
			vkupno+=cenafak[i];
		}
		return vkupno;
	}
	virtual ~Odmor(){
		delete [] destinacija;
		delete [] cenafak;
	}
	bool operator>(Odmor &od){
		return this->presmetajCena()>od.presmetajCena();
	}
	int getTraenje(){
		return traenje;
	}
	char *getDestinacija(){
		return destinacija;
	}
	virtual void pechati(){
		cout<<"Destinacija: "<<destinacija<<" Traenje: "<<traenje<<" Cena: "<<cena<<"Fakultativi: "<<fakultativi<<endl;
	}
};
class Leten : public Odmor{
private:
	prevoz prev;
	tip type;
public:
	Leten(char *destinacijaF = '\0',int traenjeF = 0, int cenaF = 0,int fakultativiF =0,int *cenafakF =0,prevoz prevF = avion,tip typeF = pansion):
		Odmor(destinacijaF,traenjeF,cenaF,fakultativiF,cenafakF){
		prev = prevF;
		type = typeF;
	}
	int presmetajCena(){
		int vkupno = Odmor::presmetajCena();
		if(type == polupansion ){
			vkupno+=100;
		}
		else if(type == pansion){
			vkupno+=150;
		}
		if(prev == avion){
			vkupno +=100;
		}
		return vkupno;
	}
	void pechati(){
		Odmor::pechati();
	}

};
class Zimski : public Odmor{
private:
	bool plateno;
	int cenakarta;
public:
	Zimski(char *destinacijaF = '\0',int traenjeF = 0, int cenaF = 0,int fakultativiF =0,int *cenafakF =0,bool platenoF = false,int cenakartaF= 0):
			Odmor(destinacijaF,traenjeF,cenaF,fakultativiF,cenafakF){
			plateno= platenoF;
			cenakarta = cenakartaF;
		}
	int presmetajCena(){
		int vkupno = Odmor::presmetajCena();
		if(plateno){
			vkupno+=cenakarta*traenje;
		}
		return vkupno;
	}
	void pechati(){
			Odmor::pechati();
		}

};



void najdiSporedKategorija(Odmor **niza,int broj,string ime,int denovi){
	int max = 0;
	int pozicija = 0;
	for(int i = 0;i<broj;i++){
	if((ime == niza[i]->getDestinacija()) && (niza[i]->getTraenje()<denovi) && (max<niza[i]->presmetajCena())){


				max = niza[i]->presmetajCena();
				pozicija = i;

		}
	}
	niza[pozicija]->pechati();

}

int main(){
	Odmor *odmori[3];
	int ceni1[4] = {50,30,20,60};
	int ceni2[3] = {20,25,20};
	int ceni3[3] = {10,15,30};
	odmori[0] = new Leten("Maldivi", 7, 1000, 4, ceni1 ,avtomobil, polupansion);
	odmori[1] = new Zimski("Kopaonik", 7, 500, 3, ceni2, true, 40);
	odmori[2] = new Leten("Santorini", 7, 700, 3, ceni3, avion, pansion);
	najdiSporedKategorija(odmori, 3, "Maldivi", 8);
	return 0;
	}

