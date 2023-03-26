/*
 * main.cpp
 *
 *  Created on: May 22, 2022
 *      Author: David
 */
#include<iostream>

#include<cstring>

using namespace std;

class UmetnickoDelo{
protected:
	char *avtor;
	float cena;
public:
	UmetnickoDelo(char *avtorF = "Nepoznat avtor",float cenaF = 0){
		avtor = new char[strlen(avtorF)+1];
		strcpy(avtor,avtorF);
		cena = cenaF;
	}
	virtual float cenaU(){
		return cena;
	}
	virtual void pechati(){
		cout<<"Ime: "<<avtor<<" Cena: "<<cena<<endl;
	}
	virtual ~UmetnickoDelo(){
		delete [] avtor;
	}
};
class MuzickoDelo: public UmetnickoDelo{
private:
	int godinaProizvodstvo;
public:
	MuzickoDelo(char *avtorF = "Nepoznat avtor",float cenaF = 0,int godina = 0): UmetnickoDelo(avtorF,cenaF){
		godinaProizvodstvo = godina;
	}
	float cenaU(){
		float vkupno = UmetnickoDelo::cenaU();
		if(godinaProizvodstvo>=1600 && godinaProizvodstvo<=1699){
		vkupno=UmetnickoDelo::cenaU() + UmetnickoDelo::cenaU()*(1/10);
		}
		return vkupno;
	}
	void pechati(){
	UmetnickoDelo::pechati();
	cout<<"Godina na proizvodstvo: "<<godinaProizvodstvo<<endl;
	}
};

class SlikarskoDelo : public UmetnickoDelo{
private:
	int procentOstetenost;
public:
	SlikarskoDelo(char *avtorF = "Nepoznat avtor",float cenaF = 0,int procent = 0): UmetnickoDelo(avtorF,cenaF){
		procentOstetenost = procent;
	}
	float cenaU(){
		float vkupno=UmetnickoDelo::cenaU() - UmetnickoDelo::cenaU()*(1/procentOstetenost);
		return vkupno;
	}
	void pechati(){
		UmetnickoDelo::pechati();
		cout<<"Procent na ostetenost: "<<endl;
	}

};
void funk(UmetnickoDelo **u,int broj){
	float max = 0;
	UmetnickoDelo *najskapo;
	for(int i = 0;i<broj;i++){
		if(max < u[i]->cenaU()){
			najskapo = u[i];
			max = najskapo->cenaU();
		}
	}
	cout<<"Najskapo e deloto: ";
			najskapo->pechati();
}
int main(){
UmetnickoDelo *udela[5];
MuzickoDelo m1("Bethoven",250,1655);
MuzickoDelo m2("Mozart",430,1725);
SlikarskoDelo s1("Picasso",12450,20);
SlikarskoDelo s2("Van Gogh",23124,50);
MuzickoDelo m3("Vivaldi",32141,1688);
udela[0] = &m1;
udela[1] = &m2;
udela[2] = &m3;
udela[3] = &s1;
udela[4] = &s2;
funk(udela,5);

	return 0;
}
