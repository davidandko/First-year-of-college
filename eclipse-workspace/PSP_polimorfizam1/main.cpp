/*
 * main.cpp
 *
 *  Created on: May 23, 2022
 *      Author: David
 */
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Registracija{
protected:
	string ime;
	int brSh;
	int zaf;
	int osCena;
	char **zemji;
	int brZ;
public:
	Registracija(string imev="",int brShv=0,int zafv=0,int osCenav = 0,char *zemjiv[] = NULL,int brZv=0){
		ime = imev;
		brSh = brShv;
		zaf = zafv;
		osCena = osCenav;
		brZ = brZv;
		zemji = new char*[brZ];
		for(int i =0;i<brZ;i++){
			zemji[i] = new char[strlen(zemjiv[i]+1)];
			strcpy(zemji[i],zemjiv[i]);
		}
	}
	Registracija(const Registracija &R){
		ime = R.ime;
		brSh = R.brSh;
		zaf = R.zaf;
		osCena = R.osCena;
		brZ = R.brZ;
		zemji = new char*[brZ];
		for(int i =0;i<brZ;i++){
			zemji[i] = new char[strlen(R.zemji[i]+1)];
			strcpy(zemji[i],R.zemji[i]);
		}
	}
	Registracija &operator=(const Registracija &R){
		if(this == &R){
			return *this;
		}else{
			for(int i =0;i<brZ;i++){
				delete [] zemji[i];
			}
			delete [] zemji;
			ime = R.ime;
			brSh = R.brSh;
			zaf = R.zaf;
			osCena = R.osCena;
			brZ = R.brZ;
			zemji = new char*[brZ];
			for(int i =0;i<brZ;i++){
				zemji[i] = new char[strlen(R.zemji[i]+1)];
				strcpy(zemji[i],R.zemji[i]);
			}
		}
		return *this;
	}
	virtual int vkCena(){
		return osCena;
	}

	virtual ~Registracija(){
		for(int i =0;i<brZ;i++){
			delete [] zemji[i];
		}
		delete [] zemji;
	}
	virtual void pechati(){
		cout<<ime<<" , "<<brSh<<" , "<<zaf<<" , "<<osCena<<" , "<<brZ<<endl;
		cout<<"vazhi vo: "<<brZ<<"zemji"<<endl;
		cout<<"Zemji"<<endl;
		for(int i =0;i<brZ;i++){
			cout<<zemji[i]<<endl;
		}
	}

};

class Reg_avto : public Registracija{
protected:
	bool uchestvo;
public:
	Reg_avto(string imev="",int brShv=0,int zafv=0,int osCenav = 0,char *zemjiv[] = NULL,int brZv=0,bool uchestvov = false):
		Registracija(imev,brShv,zafv,osCenav,zemjiv,brZv){
		uchestvo = uchestvov;
	}
	Reg_avto(const Reg_avto &R): Registracija(R){
		uchestvo = R.uchestvo;
	}
	Reg_avto &operator=(Reg_avto &D){
		Registracija::operator =(D);
		uchestvo = D.uchestvo;

		return *this;
	}
	virtual int vkCena(){
		int vk = Registracija::vkCena();
		if(zaf > 2000){
			vk = 1.1*vk;
		}
		if(uchestvo == false){
			vk = 0.95*vk;
		}
		return vk;
	}
	void pechati(){
		Registracija::pechati();
		cout<<"Vkupna cena: "<<vkCena();	}
};
class Reg_kamion :public Registracija{
private:
	int brm;
public:
	Reg_kamion(string imev="",int brShv=0,int zafv=0,int osCenav = 0,char *zemjiv[] = NULL,int brZv=0,int brmv=0):
		Registracija(imev,brShv,zafv,osCenav,zemjiv,brZv){
		brm = brmv;
	}
	virtual int vkCena(){
		int vk = Registracija::vkCena();

		vk = vk*(1+(brm/72)*4/100);
		return vk;
	}
	void pechati(){
		cout<<"Klasa Reg_Kamion"<<endl;
		Registracija::pechati();
				cout<<"Vkupna cena: "<<vkCena();
		}
};

bool sporedi(Registracija *l,Registracija *d){
	if(l->vkCena() > d->vkCena()){
		return true;
	}
	return false;
}
void platilNajmalku(Registracija **niza,int brReg){
	int j=0;
	for(int i = 1;i<brReg;i++){
		if(sporedi(niza[j],niza[i])){
			j=i;
		}
	}
	cout<<"Podatocite na toj sto platil najmalku se: "<<endl;
	niza[j]->pechati();
}
int main(){
	char *zemji1[3] = {"Makedonija","Albanija","Srbija"};
	char *zemji2[3] = {"Kosovo","Crna Gora","BiH"};
	char *zemji3[4] = {"Grcija","Bugarija","Hrvatska","Slovenija"};

	Registracija *niza[3];
	Reg_avto a1("Ljubinka Pilicheva",2,2500,12000,zemji1,3,false);
	Reg_avto a2("Maja Petrova",3,1700,10000,zemji2,3,false);
	Reg_kamion k1("Naum Stankovski",4,3000,15000,zemji3,4,90);

	niza[0]=&a1;
	niza[1]=&k1;
	niza[2]=&a2;

	platilNajmalku(niza,3);

	return 0;
}
