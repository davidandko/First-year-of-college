/*
 * main.cpp
 *
 *  Created on: Mar 17, 2022
 *      Author: David
 */

#include<iostream>
#include<string>

using namespace std;

struct apteka{
	string lokacija;
	int brVraboteni;
	bool daliRaboti;
	void init(string lokacijaF,int brVraboteniF,bool daliRabotiF){
		lokacija=lokacijaF;
		brVraboteni=brVraboteniF;
		daliRaboti=daliRabotiF;
	}
	void pechati(){
		cout<<"Lokacija na apteka: "<<lokacija<<endl;
		cout<<"Broj na vraboteni vo aptekata: "<<brVraboteni<<endl;
		if(daliRaboti == true){
			cout<<"Aptekata raboti vo nedela"<<endl
		}
		else{
			cout<<"Aptekata ne raboti vo nedela"<<endl;
		}
	}
};
struct lanec{
	string ime;
	int brApteki;
	apteka apteki[10];
	void init(string imeF,int brAptekiF,apteka aptekiF[]){
		ime=imeF;
		brApteki=brAptekiF;
		for(int i=0;i<brApteki;i++){
			apteki[i]=aptekiF[i];
		}
	}

};

