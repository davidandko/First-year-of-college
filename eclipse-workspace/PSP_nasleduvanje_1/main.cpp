/*
 * main.cpp
 *
 *  Created on: May 16, 2022
 *      Author: David
 */
#include<iostream>
#include<cstring>

using namespace std;

class Igrach{
protected:
	string ime;
	string prezime;
	bool liga;
public:
	Igrach(string ime = "",string prezime = "",bool liga = true){
		this->ime = ime;
		this->prezime = prezime;
		this->liga = liga;
	}
	friend ostream &operator<<(ostream &Os,Igrach &I){
		Os<<I.ime<<" "<<I.prezime<<(I.liga?" igra vo liga":" ne igra vo liga")<<endl;
		return  Os;
	}

};
class ATPIgrach : public Igrach{
private:
	int rang;
public:
	ATPIgrach(string ime = "",string prezime = "",bool liga = true,int rangv = 1): Igrach(ime,prezime,liga){
			rang=rangv;
		}
	friend ostream &operator<<(ostream &Os,ATPIgrach &A){
		Igrach I(A);
		Os<<I;
		Os<<"Igrachot e so ATP rang: "<<A.rang<<endl;

		return Os;
	}
};

int main(){
	Igrach I("Daniel","Medvedev",true);
	ATPIgrach A("Novak","Dzokovich",true,1);

	cout<<I;
	cout<<A;


	return 0;
}



