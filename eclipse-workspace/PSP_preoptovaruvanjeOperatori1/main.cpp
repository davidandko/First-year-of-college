/*
 * main.cpp
 *
 *  Created on: May 9, 2022
 *      Author: David
 */
#include<iostream>
#include<cstring>

using namespace std;
class Uchenik{
private:
	char *ime;
	float prosek;
	int godina;
public:
	Uchenik(char *imev = "",float prosekv = 0,int godinav = 0){
		ime = new char[strlen(imev)+1];
		strcpy(ime,imev);
		prosek = prosekv;
		godina = godinav;
	}
	~Uchenik(){
		delete[] ime;
	}
	Uchenik(const Uchenik &u){
		ime = new char[strlen(u.ime)+1];
		strcpy(ime,u.ime);
		prosek = u.prosek;
		godina = u.godina;
	}
	Uchenik &operator=(Uchenik &u){
		if(this  == &u){
			return *this;
		}
		delete[] ime;
		ime = new char[strlen(u.ime)+1];
		strcpy(ime,u.ime);
		prosek = u.prosek;
		godina = u.godina;

		return *this;
	}
	Uchenik &operator++(){
		godina++;
		return *this;
	}
	friend ostream &operator<<(ostream &os,Uchenik &u){
		os<<"Ime: "<<u.ime<<endl;
		os<<"Prosek: "<<u.prosek<<endl;
		os<<"Godina: "<<u.godina<<endl;

		return os;
	}

};
class Paralelka{
private:
		Uchenik *ucenici;
		int brU;
public:
		Paralelka(Uchenik *uceniciv = NULL,int brUv = 0){
			brU = brUv;
			ucenici = new Uchenik[brU];

			for(int i = 0;i<brU;i++){
				ucenici[i] = uceniciv[i];
			}
		}
		~Paralelka(){
			delete [] ucenici;
		}
		Paralelka(const Paralelka &P){
			brU = P.brU;
			ucenici = new Uchenik[brU];

			for(int i = 0;i<brU;i++){
				ucenici[i] = P.ucenici[i];
			}
		}
		Paralelka operator++(int){
			Paralelka temp(*this);
			for(int i = 0;i<brU;i++){
				++ucenici[i];
			}
			return temp;
		}
		Paralelka &operator+=(Uchenik &u){
			Uchenik *nova = new Uchenik[brU+1];
			for(int i = 0;i<brU;i++){
				nova[i] = ucenici[i];
			}
			nova[brU] = u;
			brU++;
			delete [] ucenici;
			ucenici = nova;
			return *this;
		}
		friend ostream &operator<<(ostream &os,Paralelka &P){
			os<<"Paralelkata ima: "<<P.brU<<" uchenici: "<<endl;
			for(int i =0;i<P.brU;i++){
				os<<i+1<<" "<<P.ucenici[i]<<endl;
			}
			return os;
		}
};

int main(){
Uchenik nizaU[3] = {{"Pero",5.0,3},{"Stojan",4.5,3},{"Ana",4.7,5}};
Uchenik U("Vera",4.3,3);

Paralelka P(nizaU,3);

cout<<P;

P+= U;
P++;

cout<<P;

	return 0;
}



