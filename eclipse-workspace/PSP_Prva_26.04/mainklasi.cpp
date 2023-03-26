/*
 * mainklasi.cpp
 *
 *  Created on: Apr 19, 2022
 *      Author: David
 */
#include <iostream>
#include<cstring>
using namespace std;

class proizvod{
private:
	char ime[20]; // ako bese dinamicka alokacija char *ime;
	int shifra;
	int zaliha;
	int prodadeno;
public:
	proizvod(){
		ime[0] = '\0';
		shifra = 0;
		zaliha = 0;
		prodadeno = 0;
	}
	proizvod(char *imev,int shifrav,int zalihav,int prodadenov){
		strcpy(ime,imev);
		shifra = shifrav;
		zaliha = zalihav;
		prodadeno = prodadenov;
	}
	proizvod(const proizvod &p){ // copy constructor
		// prostor za dinamicka alokacija
		strcpy(ime,p.ime);
		shifra = p.shifra;
		zaliha = p.zaliha;
		prodadeno = p.prodadeno;
	}
	void pechati(){
		cout<<ime<<": "<<shifra<<", prodadeno: "<<prodadeno<<" , a na zaliha: "<<zaliha<<endl;
	}
	const char *getIme(){
		return ime;
	}
	int getZaliha(){
		return zaliha;
	}
};

void sortirajPoImeRast(proizvod *nizaP,int n){
	for(int i = 0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(nizaP[i].getIme(),nizaP[j].getIme()) > 0){
				proizvod temp(nizaP[i]);
				nizaP[i] = nizaP[j];
				nizaP[j] = temp;
			}
		}
	}
}
void sortirajPoImeOpag(proizvod *nizaP,int n){
	for(int i = 0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(nizaP[i].getIme(),nizaP[j].getIme()) < 0){
				proizvod temp(nizaP[i]);
				nizaP[i] = nizaP[j];
				nizaP[j] = temp;
			}
		}
	}
}
void sortirajPoZalihaRast(proizvod *nizaP,int n){
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(nizaP[i].getZaliha() > nizaP[j].getZaliha()){
				proizvod temp(nizaP[i]);
				nizaP[i] = nizaP[j];
				nizaP[j] = temp;
			}
		}
	}
}
void sortirajPoZalihaOpag(proizvod *nizaP,int n){
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(nizaP[i].getZaliha() < nizaP[j].getZaliha()){
				proizvod temp(nizaP[i]);
				nizaP[i] = nizaP[j];
				nizaP[j] = temp;
			}
		}
	}
}

void sortirajNiza(proizvod *nizaP,int n,int kriterium = 2, bool pravec = 1){
if(kriterium == 0){
	if(pravec == 0){
		sortirajPoImeRast(nizaP,n);
	}
	else{
		sortirajPoImeOpag(nizaP,n);
	}
}
else if(kriterium == 2){
	if(pravec == false){
		sortirajPoZalihaRast(nizaP,n);
	}
	else{
	sortirajPoZalihaRast(nizaP,n);
	}
}
else{
	cout<<"Takov kriterium ne e implementiran"<<endl;
}

}

int main(){
int n;
proizvod nizaP[30],pom;

cout<<"Vnesete broj na proizvodi"<<endl;
cin>>n;
cout<<"Vnesete gi imeto, shifrata, zaliha i kolichinata na prodadeni edinici od proizvodot"<<endl;
for(int i =0;i<n;i++){
	char ime[20];
	int shifra;
	int zaliha;
	int prodadeno;

	cin>>ime>>shifra>>zaliha>>prodadeno;

	nizaP[i] = proizvod(ime,shifra,zaliha,prodadeno);
}
cout<<"Vnesete kriterium za sortiranje i pravec"<<endl;
int krit;
bool prav;
cin>>krit>>prav;

sortirajNiza(nizaP,n,krit,prav);

cout<<"Sortiranata niza e: "<<endl;
for(int i = 0;i<n;i++)
	nizaP[i].pechati();

return 0;
}


