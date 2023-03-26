/*
 * main.cpp
 *
 *  Created on: May 24, 2022
 *      Author: David
 */
/*
 *Vtor kolok 2018 prv termin zadaca 1
  Да се дефинира класа за работа со козметички производи. За секој производ се чува името, цената во
денари, бројот на состојки и динамички алоцирана низа од состојките (име на состојка и маса во грамови).
Класата треба да ги содржи следните методи и преоптоварени оператори:
• Конструктори и деструктор;
• Оператор += за додавање на состојка на крајот на низата;
• Оператор -= за додавање на состојка на почетокот на низата;
• Оператор ++ за отстранување на последната состојка;
• Оператор -- за отстранување на првата состојка;
• Оператор << за печатење на сите информации за козметичкиот производ: име, цена, број на состојки и
листа од состојките.
 */

#include<iostream>
#include<cstring>

using namespace std;
struct Sostojka{
	string ime;
	int masa;
};

class Kozmetika{
private:
	string ime;
	int cena;
	int brS;
	Sostojka *sostojki;
public:
	Kozmetika(string imeF,int cenaF,int brSF,Sostojka *sostojkiF){
		ime = imeF;
		cena = cenaF;
		brS = brSF;
		sostojki = new Sostojka[brSF];
		for(int i = 0;i<brS;i++){
			sostojki[i] = sostojkiF[i];
		}
	}
	Kozmetika(const Kozmetika &k){
		ime = k.ime;
		cena = k.cena;
		brS = k.brS;
		sostojki = new Sostojka[brS];
		for(int i=0;i<brS;i++){
			sostojki[i] = k.sostojki[i];
		}
	}
	~Kozmetika(){
		delete [] sostojki;
	}
	Kozmetika &operator+=(Sostojka sostojka){
		Sostojka *novak = new Sostojka[brS+1];
		for(int i =0;i<brS;i++){
			novak[i] = sostojki[i];
		}
		delete[] sostojki;
		novak[brS++] = sostojka;
		sostojki = novak;
		return *this;
	}
	Kozmetika &operator-=(Sostojka sostojka){
		Sostojka *novak = new Sostojka[brS+1];
		novak[0] = sostojka;
		for(int i =0;i<brS;i++){
			novak[i+1] = sostojki[i];
		}
		delete[] sostojki;
		brS++;
		sostojki = novak;
		return *this;
		}
	Kozmetika &operator++(){
		Sostojka *novak = new Sostojka[brS-1];
		for(int i =0;i<brS-1;i++){
			novak[i] = sostojki[i];
		}
		brS--;
		delete[] sostojki;
		sostojki = novak;
		return *this;
	}
	Kozmetika operator++(int){ // post-fix
		Kozmetika z(*this);
		Sostojka *novak = new Sostojka[brS-1];
		for(int i =0;i<brS-1;i++){
			novak[i] = sostojki[i];
		}
		brS--;
		delete[] sostojki;

		sostojki = novak;
		return z;
		}
	Kozmetika &operator--(){
		Sostojka *novak = new Sostojka[brS-1];
		for(int i =1;i<brS;i++){
			for(int j =0;i<brS-1;i++){
				novak[j] = sostojki[i];
			}
		}
		delete[] sostojki;
		sostojki = novak;
		return *this;
	}
	friend ostream &operator<<(ostream &o,Kozmetika &k){
		o<<"Ime: "<<k.ime<<endl;
		o<<"Cena: "<<k.cena<<endl;
		o<<"Broj na sostojki: "<<k.brS<<endl;
		o<<"Sostojki i nivnata masa: "<<endl;
		for(int i = 0;i<k.brS;i++){
			o<<", Ime: "<<k.sostojki[i].ime<<" "<<", Masa: "<<k.sostojki[i].masa;
		}
		o<<endl;
		return o;
	}

};


int main(){
	Sostojka s[5];
	s[0].ime = "Sina boja";
	s[0].masa =50;
	s[1].ime = "Zelena boja";
	s[1].masa =25;
	s[2].ime = "Crvena boja";
	s[2].masa =10;
	s[3].ime = "Pudra";
	s[3].masa =5;
	s[4].ime = "Crna boja";
	s[4].masa =55;
	Kozmetika K1("Loreal",200,5,s);
	cout<<K1;
	K1.operator ++();
	cout<<K1;
	K1.operator +=(s[1]);
	cout<<K1;
	K1.operator -=(s[3]);
	cout<<K1;
	cout<<K1.operator ++();

	return 0;
}

