/*
 * main1.cpp
 *
 *  Created on: Mar 16, 2022
 *      Author: David
 */
//magacin

#include<iostream>
#include<string>

using namespace std;

const int golemina = 20;

struct element{
	int x;
};
struct magacin{
	int vrv;
	element S[golemina];
	void init(){
		vrv=-1;
	}

	int isEmpty(){
		return vrv<0;
	}
	int isFull(){
		return vrv>=golemina-1;
	}
	void dodadiE(element x){
		if(isFull()){
			cout<<"Magacinot e poln"<<endl;
			return;
		}
		vrv++;
		S[vrv] = x;
	}
	element izvadiE(){
		if(isEmpty()){
			cout<<"Magacinot e prazen"<<endl;
			return {};
		}
		element x = S[vrv];
		vrv--;
		return x;
	}
	void ispecatiBezVadenje(){
		for(int i=0;i<vrv;i++){
			cout<<S[i].x<<" ";
			cout<<endl;
		}
	}
};

void pechatiBinarno(int x,magacin &m){
	int pom = x;
	m.init();
	while(pom){
		int ost = pom%2;
		element pomoshen;
		pomoshen.x = ost;
		m.dodadiE(pomoshen);
		pom = pom/2;
	}
	cout<<"Binarnata pretstava na "<<x<<" e ";
	while(!m.isEmpty()){
		//element pomoshen = m.izvadiE();
		//cout<<pomoshen.x;
		cout<<m.izvadiE().x;
	}
	cout<<endl;
}

int main(){
	cout<<"Vnesete cel broj"<<endl;
	int x;
	cin>>x;
	magacin m;

	pechatiBinarno(x,m);

	return 0;
}

