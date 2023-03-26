/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
 * Да се креира класа за опис на библиотека. За библиотеката се чува динамички алоцирана низа од
наслови на книги (насловот е стринг) и бројот на книги кој го има во библиотеката.
Да се обезбедат следниве методи за класата:
• Конструктор со default параметри кој добива низа од книги и број на книги во
библиотеката. Доколку конструкторот се повика без аргументи се креира библиотека со
една книга (со наслов по произволен избор).
• Деструктор кој ќе ја брише динамички алоцираната меморија.
Дополнително да се преоптоварат следниве оператори:
• Операторот < за споредба на две библиотеки (враќа true ако десниот операнд има повеќе
книги и fasle во спротивно)
• Операторот << за печатење на сите податоци за библиотеката.
• Операторот = за доделување библиотека.
• Операторот -= кој го наоѓа насловот кој е даден како десен операнд и го остранува од
низата со наслови (доколку не го најде, да не отстанува ништо).
• Операторот ++ кој овозможува додавање на нов наслов кој се добива како десен операнд
(додавањето да се направи на почеток од низата со наслови).
Да се напише главна програма во која ќе се тестира работата на сите креирани методи и
преоптоварувања.
 */

#include<iostream>

using namespace std;

class Biblioteka{
private:
	string *naslovi;
	int broj;
public:

	Biblioteka(string *nasloviF = NULL ,int brojF=1){
		if(nasloviF == NULL){
			naslovi = new string[1];
			broj = 1;
			naslovi[0] = "1984";
		}else{

			broj = brojF;
			naslovi = new string[broj];
			for(int i = 0;i<broj;i++){
				naslovi[i] = nasloviF[i];
			}
		}
	}
	~Biblioteka(){
		delete [] naslovi;

	}

	bool operator<(Biblioteka &b){
		return (this->broj<b.broj);
	}
	friend ostream &operator<<(ostream &output,Biblioteka &b){
		output<<"Broj na knigi: "<<b.broj<<endl;
		output<<"Knigite: "<<endl;
		for(int i = 0;i<b.broj;i++){
			output<<b.naslovi[i]<<" ";
		}
		return output;
	}
	Biblioteka &operator=(Biblioteka &b){
		if(this==&b){
			return *this;
		}
		delete [] naslovi;
		naslovi = new string[b.broj];
		for(int i =0;i<b.broj;i++){
			naslovi[i] = b.naslovi[i];
		}
		broj = b.broj;
		return *this;
	}
	Biblioteka &operator-=(string naslov){
		int pozicija = -1;
		for(int i = 0;i<broj;i++){
			if(naslovi[i] == naslov){
				pozicija = i;
			}
		}
		if(pozicija >= 0){
			int j = 0;
			string *nova = new string[broj -1];
			for(int i = 0;i<broj;i++){
				if(naslovi[i]!= naslov){
					nova[j] = naslovi[i];
					j++;
				}
			}
			broj--;
			delete[] naslovi;
			naslovi = nova;
			return *this;
		}
		return *this;

	}
	Biblioteka &operator+=(string naslov){
		string *nova = new string[broj+1];
		nova[0] = naslov;
		for(int i =0;i<broj;i++){
			nova[i+1] = naslovi[i];
		}
		delete [] naslovi;
		broj++;
		naslovi = nova;
		return *this;
	}

};
int main(){
	Biblioteka b1;
	string niza[3] = {"Lolita","Robinzon Kruso","1984"};
	Biblioteka b2(niza,3);
	cout<<b1<<endl;
	cout<<b2<<endl;
	b1 = b2;
	cout<<b1<<endl;
	b2.operator -=("1984");
	cout<<b2;
	b1.operator +=("David");
	cout<<b1;
}
