/*
 * main2.cpp
 *
 *  Created on: Mar 16, 2022
 *      Author: David
 */
#include<iostream>
#include<string>

using namespace std;
const int maxG = 20;
struct element{
	char x;
};

struct magacin{
	int vrv;
	element S[maxG];

	void init(){
		vrv=-1;
	}
	int isEmpty(){
		return vrv<0;
	}
	bool isFull(){
		return vrv>=maxG-1;
	}
	void dodadiE(element e){
		if(isFull()){
			cout<<"Magacinot e poln"<<endl;
			return;
		}
		vrv++;
		S[vrv] = e;
	}
	element izvadi(){
		if(isEmpty()){
			cout<<"Nema sto da izneseme, magacinot e prazen"<<endl;
			return {};
		}
		element pom = S[vrv];
			vrv--;
			return pom;
	}
	element dzirni(){
		if(isEmpty()){
			cout<<"Nema elementi vo magacinot"<<endl;
			return {};
		}
		return S[vrv];
	}
};

bool daliEBalansiran(string izr,magacin &m){
	m.init();
	int dolzina = izr.length();

	for(int i=0;i<dolzina;i++){
		if(izr[i] == '(' || izr[i] == '[' || izr[i] == '{'){
			element pom;
			pom.x = izr [i];
			m.dodadiE(pom);

		}
		if(izr[i] == ')'){
			if(m.isEmpty()){
				return false;
			}
			if(m.izvadi().x != '('){
				return false;
			}
		}
		if(izr[i] == ']'){
			if(m.isEmpty()){
				return false;
			}
			if(m.izvadi().x != '['){
				return false;
			}
		}
		if(izr[i] == '}'){
			if(m.isEmpty()){
				return false;
			}
			if(m.izvadi().x != '{'){
				return false;
			}
		}

	}
	if(!m.isEmpty()){
		return false;
	}


	return true;
}

int main(){
	string niza;
	magacin m;
	cout<<"Vnesete go izrazot"<<endl;
	getline(cin,niza);
	bool rezultat = daliEBalansiran(niza,m);
	if(rezultat){
		cout<<"Izrazot e balansiran"<<endl;
	}
	else{
		cout<<"Izrazot ne e balansiran"<<endl;
	}
	return 0;
}



