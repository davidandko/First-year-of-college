/*
 * main.cpp
 *
 *  Created on: Apr 27, 2022
 *      Author: David
 */
/*
 На кошаркарски клуб му е потребна програма која ќе води евиденција за основните
податоци на екипата. За секој кошаркар се чуваат информации за името и основна плата. За
екипата се знае името, бројот на кошаркари, просекот на постигнати поени на екипата и низата од
кошаркари (има максимум 8 кошаркари). Просекот на постигнати поени по натпревар и бројот на
кошаркари во екипата не смеат да бидат негативни (во конструкторите и функциите за
поставување да се внимава ова да биде исполнето). Платата на еден кошаркар се пресметува така
што основната плата се зголемува за 50 денари за секој кош од просекот на постигнати поени по
натпревар за неговата екипа.
Да се напишат класите kosarkar и ekipa. Притоа, доколку се внесат податоци кои не ги
задоволуваат наведените ограничувања за пaросекот на постигнати кошеви по натпревар и бројот
на играчи, тие параметри да се постават на 0. За секоја од класите да се напишат default
конструкторот, конструктор со параметри и функција за печатење (при печатењето на податоците
за екипата, да се користи функцијата за печатење на податоците на играчот (освен за неговата
плата која мора да се печати од функцијата за печатење на класата екипа)). За класата kosarkar да
се напише и функција за пресметка на платата која на влез добива реален број кој служи за да го
содржи просекот на постигнати поени по натпревар за неговата екипа.
Да се напише main функција во која корисникот ќе внесе податоците за 5 играчи (основната
плата на секој кошаркар да се постави на 30000 денари), име на екипата и просечен број на поени
по наптревар кој треба да се постави на вредност 85. Потоа со тие податоци да се иницијализира
објект од класа ekipa. На крај да се испечатат податоците за екипата.
Забелешка: Вредноста за платата не треба да се внесува и чува како посебен параметар (основната
плата е тоа што се внесува и чува). Таа се пресметува според другите внесени вредности и се враќа
на излез од функцијата за пресметка на плата.
 */


#include<iostream>
#include<cstring>

using namespace std;

class kosarkar{
private:
	string ime;
	int plata;
public:
	kosarkar(){
		ime = '\0';
		plata = 0;
	}
	kosarkar(const string imeF,int plataF){
		ime = imeF;
		plata = plataF;
	}
	void pechati(){
		cout<<"Ime: "<<ime<<"|"<< "Plata: "<<plata<<endl;
	}
	int getPlata(int prosekPoeni){
		while(prosekPoeni){
			plata+=50;
			prosekPoeni-=1;
		}
		return plata;
	}
	void postaviIme(string const imeF){
		ime = imeF;
	}
	void postaviPlata(int plataF){
		plata = plataF;
	}

};
class ekipa{
private:
	string ime;
	int brojnakosarkari;
	float prosekpoeni;
	kosarkar niza[8];
public:
	int i=0;
	ekipa(){
		ime = '\0';
		brojnakosarkari = 0;
		prosekpoeni = 0;
	}
	ekipa(string imeF,int brojnakosarkariF,float prosekpoeniF,kosarkar &k){
		ime = imeF;
		if(brojnakosarkariF >= 0){
			brojnakosarkari = brojnakosarkariF;
		}
		else{
			brojnakosarkari = 0;
		}
		if(prosekpoeniF >= 0){
		prosekpoeni = prosekpoeniF;
		}
		else{
			prosekpoeni = 0;
		}
		for(int i=0;i<brojnakosarkari;i++){
			niza[i] = k;
		}
	}
	void pechati(){
		cout<<"Ime na ekipa: "<<ime<<endl;
		cout<<"Igraci: "<<endl;
		for(int i = 0;i<brojnakosarkari;i++){
			niza[i].pechati();
		}
	}
	void postaviIme(string const imeF){
		ime = imeF;
	}
	void postaviProsek(int prosekF){
		prosekpoeni = prosekF;
	}
	void postaviBr(int brF){
		brojnakosarkari = brF;
	}
	void postaviKos(kosarkar &k){
		niza[i] = k;
		i++;
	}
};

int main(){
	kosarkar kos[5];
	ekipa ek;
	string ime,imeEK;
	cout<<"Vnesi ime na ekipa: "<<endl;
	cin>>imeEK;
	for(int i = 0;i<5;i++){
		cout<<"Vnesi ime na kosarkar: "<<endl;
		cin>>ime;
		kos[i].postaviIme(ime);
		kos[i].postaviPlata(30000);
		kos[i].getPlata(85);
		ek.postaviIme(imeEK);
		ek.postaviBr(5);
		ek.postaviProsek(85);
		ek.postaviKos(kos[i]);

	}



	ek.pechati();

	return 0;
}
