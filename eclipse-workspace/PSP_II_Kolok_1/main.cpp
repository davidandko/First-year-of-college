/*
 * main.cpp
 *
 *  Created on: May 22, 2022
 *      Author: David
 */
#include<iostream>
#include<cstring>
enum rod{maski,zenski,sreden};
enum broj{ednina,mnozina};
enum vreme{minato,segasnost,idnina};
using namespace std;

class Zbor{
protected:
	string zbor;
	int redbr;
public:
	Zbor(string zborF = "",int redbrF = 0){
		zbor = zborF;
		redbr = redbrF;
	}
	virtual int presmetajDolzhina(){
		int len = zbor.length();
		return len;
	}
	virtual void pechatiZbor(){
		cout<<zbor<<" ";
	}
	bool operator<(Zbor &z){
		if(this->zbor.length()<z.zbor.length()){
			return true;
		}
		else{
			return false;
		}
	}
	virtual ~Zbor(){}
};
class Imenki : public Zbor{
private:
	rod rodc;
	broj brojc;
public:
	Imenki(string zborF= "",int redbrF=0,rod rodcF = maski,broj brojcF=ednina):Zbor(zborF,redbrF){
		rodc = rodcF;
		brojc = brojcF;
	}
	int presmetajDolzhina(){
		int poslednapoz = zbor.length();
		string pom;
		int dolzina;
		if(brojc == mnozina){
			for(int i = poslednapoz-4;i<=poslednapoz-1;i++){
				for(int j = 0;j<=3;j++){
					zbor[i] = pom[j];
				}
			}
			if(pom == "nje" || pom == "nja"){
				dolzina = poslednapoz-3;
			}
		else if((zbor[poslednapoz-1] == 'i' ||	zbor[poslednapoz-1] == 'e' || zbor[poslednapoz-1] == 'a' )){
				dolzina = poslednapoz-1;
			}
		}
		return dolzina;
	}
	void pechatiZbor(){
		cout<<"Zborot ";
		Zbor::pechatiZbor();
		cout<<" e imenka i ima";
		Imenki::presmetajDolzhina();
		cout<<" bukvi"<<endl;
	}
};

class Glagol : public Zbor{
private:
	vreme time;
public:
	Glagol(string zborF = "",int redbrF = 0,vreme timeF = minato): Zbor(zborF,redbrF){
		time = timeF;
	}
	int presmetajDolzhina(){
		int poslednapoz = zbor.length();
				string pom;
				int dolzina;
		if(time == minato){
			for(int i = poslednapoz-4;i<=poslednapoz-1;i++){
				for(int j = 0;j<=3;j++){
					pom[j] = zbor[i];
				}
			}
			if(pom == "vme" || pom == "nja"){
				dolzina = poslednapoz-3;
			}
			else if((zbor[poslednapoz-1] == 'v' )){
				dolzina = poslednapoz-1;
			}
		}
		else if(time == idnina){
			for(int i = 0;i<=3;i++){
				pom[i] = zbor[i];
			}
			if(pom == "kje"){
				dolzina= poslednapoz-4;
			}
		}
		return dolzina;
	}
	void pechati(){
		cout<<"Zborot ";
		Zbor::pechatiZbor();
		cout<<" e glagol i ima dolzina ";
		Glagol::presmetajDolzhina();
		cout<<" bukvi"<<endl;
	}
};


class Rechenica{
private:
	Zbor *zborovi;
	int brzbr;
public:
	Rechenica(Zbor *zboroviF,int brzbrF){
		for(int i=0;i<brzbrF;i++){
			zborovi[i] = zboroviF[i];
		}
		brzbr = brzbrF;
	}
	void sortiraj()
	{
		for(int i = 0;i<brzbr;i++){
			for(int j = i+1;j<=brzbr;j++){
				if(zborovi[i]<zborovi[j]){
					Zbor pom = zborovi[j];
					zborovi[j] = zborovi[i];
					zborovi[i] = pom;
				}

			}

		}
		for(int i =0;i<brzbr;i++){
			zborovi[i].pechatiZbor();
		}
	}

};


int main(){
	// se skrenav



}
