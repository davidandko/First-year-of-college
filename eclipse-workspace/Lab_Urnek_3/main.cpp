/*
 * main.cpp
 *
 *  Created on: Mar 20, 2022
 *      Author: David
 */
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

const int MAX = 20;

struct element{
	int podatok;
};

struct magacin{
	element elementi[MAX];
	int vrv;


	void init(){
		vrv = -1;
	}
	bool prazen(){
		return(vrv == -1);
	}
	bool poln(){
		return(vrv == MAX-1);
	}
	void vmetni(int el){
		if(poln()){
			cout<<"Magacinot e poln"<<endl;
			return;
		}
		elementi[++vrv].podatok = el;

	}
	element izvadi(){
		if(prazen()){
			cout<<"Magacinot e prazen"<<endl;
			return {};
		}
		return elementi[vrv--];
	}
	int pogledni(){
			if(prazen()){
				cout<<"Nema sto da vidam, magacinot e prazen"<<endl;
			}
			return elementi[vrv].podatok;
		}
};
void swap(int *prv,int *vtor){
	int temp;
		temp=*prv;
		*prv=*vtor;
		*vtor=temp;
}

void func(int br1,int br2,magacin &m){
	magacin pm;
	pm.init();
	int pod;
	if(m.poln()){
		cout<<"Nema nisto vo magacinot"<<endl;
		exit(-1);
	}
	while(!m.prazen()){
		pod = m.izvadi().podatok;
		if( pod >= br1 && pod <= br2){
			pm.vmetni(pod);
		}
	}
	while(!pm.prazen()){
		m.vmetni(pm.izvadi().podatok);
	}
}

void inverter(int *elementi,int k){
	int pomos[MAX],j=0;
	for(int i = k ;i>=0;i--){
		pomos[j]=elementi[i];
		j++;
	}
	for(int i=0;i<j;i++){
		elementi[i]=pomos[i];
	}
}


int main(){
	magacin mag;
	int brEl,broj1,broj2,elmnt,k=0,niza[MAX];
	mag.init();
	cout<<"Vnesete broj na elementi vo magacin (max 20)"<<endl;
	cin>>brEl;
	cout<<"Pocnete so vnesuvanje elementi: "<<endl;
	for(int i=0;i<brEl;i++){
		cin>>elmnt;
		mag.vmetni(elmnt);
	}
	cout<<"Vnesete interval(dva broja): "<<endl;
	cin>>broj1>>broj2;
	if(broj1 == broj2){
				cout<<"Ne vnesovte interval"<<endl;
				exit(-1);
			}
	if(broj1>broj2){
			swap(&broj1,&broj2);
		}
	func(broj1,broj2,mag);

	while(!mag.prazen()){
		niza[k] =  mag.izvadi().podatok;
		k++;
	}
	inverter(niza,k-1);
	for(int i=0;i<=k-1;i++){
		cout<<niza[i]<<" ";
	}
	return 0;
}


