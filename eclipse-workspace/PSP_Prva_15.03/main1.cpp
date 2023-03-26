/*
 * main1.cpp
 *
 *  Created on: Mar 16, 2022
 *      Author: David
 */

#include<iostream>
#include<string>
using namespace std;

	struct covek{
	string ime;
	string prezime;
	bool rl,rp,rv;
};

	const int MaxG =20;

	struct red{
		int f;
		int r;

		covek Q[MaxG];

		void init(){
			f=0;
			r=-1;
		}
		int isEmpty(){
			return r<=-1;
		}
		int isFull(){
			return r>=MaxG-1;
		}
		void dodadi(covek x){
			if(isFull()){
				cout<<"Prepoln e redot"<<endl;
				return;
			}
			r++;
			Q[r]=x;
		}
		covek izvadi(){
			covek pom;
			if(isEmpty()){
				cout<<"Redot e prazen"<<endl;
				return {};
			}
			pom = Q[f];
					for(int i=0;i<r;i++){
						Q[i]=Q[i+1];

					}
					r--;
			return pom;
		}
		covek dzirni(){
			if(isEmpty()){
				cout<<"Prazen red"<<endl;
				return {};
			}
			return Q[f];
		}

	};
int main(){
	covek pom;
	red lk,pa,vd;

	lk.init();
	pa.init();
	vd.init();

	int n;
	cout<<"Vnesete kolku korisnici ke vnesuvate "<<endl;
	cin>>n;
	cout<<"Vnesete gi podatocite za korisnicite: ime,prezime,rl,rp,rv"<<endl;
	for(int i=0;i<n;i++){
		cin>>pom.ime>>pom.prezime>>pom.rl>>pom.rp>>pom.rv;
		if(pom.rl != 0){
			lk.dodadi(pom);
		}
		else if(pom.rp != 0){
			pa.dodadi(pom);
		}
		else if(pom.rv != 0){
			vd.dodadi(pom);
		}
	}
	while(!lk.isEmpty()){
		covek pom1 = lk.izvadi();
		cout<<"Opsluzen za licna karta: "<<pom1.ime<<" "<<pom1.prezime<<endl;
		pom1.rl = false;
		if(pom1.rp != 0){
			pa.dodadi(pom1);
		}
		else{
			if(pom1.rv != 0){
				vd.dodadi(pom1);
			}
		}
	}
	while(!pa.isEmpty()){
		covek pom1 = pa.izvadi();
		cout<<"Opsluzen za pasosh: "<<pom1.ime<<" "<<pom1.prezime<<endl;
		pom1.rp = false;
		if(pom1.rv!=0){
			vd.dodadi(pom1);
		}
	}
	while(!vd.isEmpty()){
			covek pom1 = vd.izvadi();
			cout<<"Opsluzen za vozachka dozvola: "<<pom1.ime<<" "<<pom1.prezime<<endl;
			pom1.rv = false;
			if(pom1.rv!=0){
				vd.dodadi(pom1);
			}
		}
return 0;
}
