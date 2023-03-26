/*
 * main.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: David
 */
// magacin
#include<iostream>

using namespace std;
const int MAX = 50;

struct element{
	int info;
};

struct magacin{
	element S[MAX];
	int vrv;

	void init(){
		vrv = -1;
	}
	bool empty(){
		return (vrv == -1);
	}
	bool full(){
		return (vrv ==MAX-1);
	}
	void vmetni(int x){
		if(full()){
			cout<<"Magacinot e poln "<<endl;
			return;
		}

		S[++vrv].info = x;
	}
	element izvadi(){
		if(empty()){
			cout<<"Magacinot e prazen "<<endl;
			return {};
		}
		return S[vrv];
		vrv--;
	}
	int peek(){
		if(empty()){
			cout<<"Nema sto da vidam, magacinot e prazen"<<endl;
		}
		return S[vrv].info;
	}
	void pechati(){
		if(empty()){
			cout<<"Nemam sto da pecatam"<<endl;
			return;
		}
		while(!empty()){
			cout<<S[vrv].info<<" ";
			vrv--;
		}
	}
};


int main(){

	magacin m1;
	m1.init();
	int br,el;
	cout<<"Kolku elementi?"<<endl;
	cin>>br;
	cout<<"Vnesi elementi "<<endl;
	for(int i=0;i<br;i++){
		cin>>el;
		m1.vmetni(el);
	}
	m1.pechati();
return 0;
}
