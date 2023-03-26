/*
 * main.cpp
 *
 *  Created on: May 18, 2022
 *      Author: David
 */
#include<iostream>

#include<cstring>

using namespace std;
enum type{nula=0,eden=1,dva=2} tipovi;


struct Tip{
	string ime1,ime2;
	type tipovi;
	float koef;
	void pechati(){
		cout<<"Ime br.1 => "<<ime1<<endl;
		cout<<"Ime br.2 => "<<ime2<<endl;
		cout<<"Tip na oblozuvanje =>"<<tipovi<<endl;
		cout<<"Koeficient na dobivka => "<<koef<<endl;
	}
};


class Livce{
private:
	Tip *tipuvanje;
	int broj;
public:
	Livce(const Livce &liv){
		tipuvanje = new Tip[liv.broj];
		for(int i =0;i<liv.broj;i++){
			tipuvanje[i] = liv.tipuvanje[i];
		}
		broj = liv.broj;
	}
	Livce(Tip *tipuvanjev=NULL,int brojv=0){
		tipuvanje = new Tip[brojv];
		for(int i = 0;i<brojv;i++){
			tipuvanje[i] = tipuvanjev[i];
		}
		broj = brojv;
	}
	~Livce(){
		delete[] tipuvanje;
	}
	/*friend istream &operator>>(istream &input,Livce &l){
		cout<<"Vnesi golemina na niza"<<endl;
		input>>l.broj;
		delete [] l.tipuvanje;
		l.tipuvanje = new Tip[l.broj];
		cout<<"Vnesi elementi vo nizata"<<endl;
		for(int i=0;i<l.broj;i++){
			input>>l.tipuvanje[i].;
		}
		return input;
	}*/
	friend ostream &operator<<(ostream &output,Livce &l){
		output<<"Broj na tipovi: "<<l.broj<<endl;
		output<<"Tipovi: "<<endl;
		for(int i =0;i<l.broj;i++){
			l.tipuvanje[i].pechati();
		}
		output<<endl;
		return output;
	}
	Livce &operator=(Livce &t){
		if(this == &t){
			return *this;
		}
		delete [] tipuvanje;
		tipuvanje = new Tip[t.broj];
		for(int i=0;i<t.broj;i++){
			tipuvanje[i]=t.tipuvanje[i];
		}
		broj = t.broj;
		return *this;
	}
	bool operator>(Livce &l){
			int proizvodlev=tipuvanje[0].koef,proizvoddesen=l.tipuvanje[0].koef;
			for(int i = 1;i<broj;i++){
				proizvodlev *= tipuvanje[i].koef;
				proizvoddesen*=l.tipuvanje[i].koef;
			}
			if(proizvodlev>proizvoddesen){
				return true;
			}
			else{
				return false;
			}
		}
	Livce &operator+=(const Tip &t){
		Livce ova(*this);
		Tip *novoLivce = new Tip[broj+1];
		for(int i = 0;i<broj;i++){
			novoLivce[i] = tipuvanje[i];
		}
		delete [] tipuvanje;
		novoLivce[broj++] = t;
		tipuvanje = novoLivce;
		return *this;
	}


};
int main(){
	return 0;
}



