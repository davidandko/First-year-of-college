/*
 * main.cpp
 *
 *  Created on: May 4, 2022
 *      Author: David
 */
/*
 Да се напише програма за следење на телесна тежина. За таа намена, да се креира класа Korisnik во
која се чуваат податоци за името на корисникот (динамички алоцирана низа од карактери), низа од
реални вредности за измерените тежини во килограми (динамички алоцирана низа од float елементи)
и број на мерења. За класата Korisnik да се напише:
- Default конструктор кој ќе креира корисник со празно име и едно мерење кое има вредност 60.
- Copy конструктор и конструктор со 3 аргументи.
- Деструктор
- Функција pechati() која ги печати податоците за корисникот
- метод dodadiMerenje(float m) кој ќе го додаде мерењето во низата од мерења на крајна позиција.
- метод brishiMerenje() кој ќе го избрише првото мерење во низата со измерени тежини
Да се напише main во кој ќе се тестира задачата. Во main функцијата прво да се креира низа од 4
мерења. Потоа со низата од мерења да се иницијализира објект од класа Korisnik и да се испечатат сите
податоци за овој објект. Потоа на објектот да му се додаде дополнителнo мерење со методата
dodadiMerenje(69.3) и да му се избрише мерење со методата brishiMerenje() по што треба повторно да
се испечатат сите информации за објектот.
 */
#include<iostream>
#include<cstring>

using namespace std;

class Korisnik{
private:
	char *ime;
	float *merenja;
	int broj;
public:
	Korisnik(){//default
		ime = new char[1];
		strcpy(ime,"");
		merenja = new float[1];
		broj = 1;
		merenja[0] = float(60);
	}
	Korisnik(char *imeF,float *merenjaF,int broj){//argumenten
		this->broj = broj;
		ime = new char[strlen(imeF)+1];
		strcpy(ime,imeF);

		merenja = new float[broj];
		for(int i = 0;i<broj;i++){
			merenja[i] = merenjaF[i];
		}
	}
	Korisnik(const Korisnik &kor){//copy constructor
		broj = kor.broj;
		ime = new char[strlen(kor.ime)+1];
		strcpy(ime,kor.ime);
		merenja = new float[broj];
		for(int i = 0;i<broj;i++){
			merenja[i] = kor.merenja[i];
		}
	}
	~Korisnik(){
		delete[] ime;
		delete[] merenja;
	}
	void pechati(){
		cout<<"Ime na korisnik: "<<ime<<endl;
		cout<<"Broj na merenja: "<<broj<<endl;
		cout<<"Merenja: "<<endl;
		for(int i = 0;i<broj;i++){
			cout<<merenja[i]<<" kg"<<endl;
		}
	}
	void dodadiMerenje(float m){
		float *merenjeF = new float[broj+1];
		for(int i=0;i<broj;i++){
			merenjeF[i] = merenja[i];
		}
		delete[] merenja;
		broj++;
		merenjeF[broj] = m;
		merenja = merenjeF;
	}
	void brisiMerenje(){
		float *merenjeF = new float[broj-1];
		for(int i=0;i<broj-1;i++){
			merenjeF[i] = merenja[i+1];
		}
		broj--;
		delete[] merenja;
		merenja = merenjeF;
	}
};

int main(){
	char ime[6]="David";
	float niza[4] = {50,69,30,56};
	Korisnik kor;

	Korisnik David(ime,niza,4);
	David.pechati();
	David.dodadiMerenje(69.3);
	David.pechati();
	David.brisiMerenje();
	David.pechati();

	kor = Korisnik(David); // probav i so copy constructor da vidam so ke pechati
	kor.pechati();

	return 0;
}



