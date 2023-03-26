/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
 * Да се креира класа работа со ливче за спортско обложување. Во ливчето за спортско
обложување се чува динамички алоцирана низа од типувања и бројот на внесени типувања. Секое
типување се состои од две имиња за учесниците во мечот (реализирани како стрингови), тип (може
да биде 0, 1 или 2) и коефициент на добивка. Типувањето да се реализира како структура.
Да се обезбедат следниве методи за класата за работа со ливче за спортско обложување:
• Конструктор со default параметри кој добива низа од типувања и број на типувања
во ливче за спортско обложување. Доколку конструкторот се повика без аргументи се креира
ливче за спортско обложување со 0 типови.
• Деструктор кој ќе ја брише динамички алоцираната меморија.
Дополнително да се преоптоварат следниве оператори:
• Операторот >> за вчитување на сите податоци за ливче за спортско обложување.
• Операторот << за печатење на сите податоци за ливче за спортско обложување.
• Операторот = за доделување на ливче за спортско обложување.
• Операторот > за споредување на две ливче за спортско обложување (ако производот
на коефициентите на добивка на левиот аргумент е поголем од соодветниот
производ на десната страна операторот да врати true инаку да врати false).
• Операторот += кој го ќе додаде типување (кое се дава како десен операнд) на крај од
ливче за спортско обложување.
• Операторот -- кој овозможува бришење на типувањето на крај од низата.
Да се напише главна програма во која ќе се тестира работата на сите креирани методи и
преоптоварувања.
 */

#include<iostream>

using namespace std;
enum Tip{nula,kec,dvojka};
string tipce[3]={"Nula","Kec","Dvojka"};

struct Tipuvanje{
	string ime1;
	string ime2;
	Tip tip;
	float koef;
	void pechati(){
		cout<<"Ime na prviot ucesnik: "<<ime1<<endl;
		cout<<"Ime na vtoriot ucesnik: "<<ime2<<endl;
		cout<<"Tipot na oblozuvanje: "<<tipce[tip]<<endl;
		cout<<"Koeficient na dobivka: "<<koef<<endl;
		cout<<endl;
	}
};


class Livce{
private:
	Tipuvanje *tipovi;
	int brtipovi;
public:
	Livce(Tipuvanje *tipoviF = NULL,int brtipoviF=0){
		brtipovi = brtipoviF;
		tipovi = new Tipuvanje[brtipovi];
		for(int i = 0;i<brtipovi;i++){
			tipovi[i] = tipoviF[i];
		}
	}
	~Livce(){
		delete[] tipovi;
	}
	friend ostream &operator<<(ostream &output,Livce &L){
		output<<"Broj na tipovi: "<<L.brtipovi<<endl;
		for(int i = 0;i<L.brtipovi;i++){
			L.tipovi[i].pechati();
		}
		return output;
	}
	friend istream &operator>>(istream &input,Livce &L){
		cout<<"Vnesi broj na tipovi: "<<endl;
		input>>L.brtipovi;

		for(int i = 0;i<L.brtipovi;i++){
			cout<<"Vnesi ime na prv ucesnik: "<<endl;
			input>>L.tipovi[i].ime1;
			cout<<"Vnesi ime na vtor ucesnik: "<<endl;
			input>>L.tipovi[i].ime2;
			cout<<"Vnesi tip na oblozuvanje: "<<endl;
			////input>>L.tipovi[i].tip ///////////////// Greskata nastanuva tuka
			cout<<"Vnesi koeficient na oblozuvanje"<<endl;
			input>>L.tipovi[i].koef;
		}
		return input;
	}

	Livce &operator=(Livce &L){
		if(this == &L){
			return *this;
		}else{
			delete [] tipovi;
			brtipovi = L.brtipovi;
			tipovi = new Tipuvanje[brtipovi];
			for(int i = 0;i<brtipovi;i++){
				tipovi[i] = L.tipovi[i];
			}
			return *this;
		}
	}
	bool operator>(Livce &L){
		int lev=1,desen=1;
		for(int i = 0;i<brtipovi;i++){
			lev*=tipovi[i].koef;
		}
		for(int i = 0;i<L.brtipovi;i++){
			desen*=L.tipovi[i].koef;
		}
		return (lev>desen);
	}
	Livce &operator+=(Tipuvanje t){
		Tipuvanje *novo = new Tipuvanje[brtipovi+1];
		for(int i=0;i<brtipovi;i++){
			novo[i] = tipovi[i];
		}
		delete[] tipovi;
		novo[brtipovi++] = t;
		tipovi = novo;
		return *this;
	}
	Livce &operator--(){
		Tipuvanje *novo = new Tipuvanje[brtipovi-1];
		for(int i=0;i<brtipovi-1;i++){
			novo[i] = tipovi[i];
		}
		delete[] tipovi;
		brtipovi--;
		tipovi = novo;
		return *this;
	}
};
int main(){
	Tipuvanje pom;
	pom.ime1 = "Jovan";
	pom.ime2 = "Emilija";
	pom.koef = 2;
	pom.tip = nula;
	Tipuvanje t[2];
	t[0].ime1 = "David";
	t[0].ime2 = "Kristina";
	t[0].koef = 2.63;
	t[0].tip = kec;
	t[1].ime1 = "Naste";
	t[1].ime2 = "Micale";
	t[1].koef = 3;
	t[1].tip = dvojka;
	Livce l1(t,2);
	Livce l2;
	cout<<l1;
	cin>>l1;
	cout<<l1;
	cout<<endl;
	cout<<l2;
	l2 =l1;
	cout<<l2;
	l2.operator +=(pom);
	cout<<l2;
	--l2;
	cout<<l2;
	return 0;

}
