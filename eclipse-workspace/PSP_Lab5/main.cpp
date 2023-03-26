/*
 * main.cpp
 *
 *  Created on: Apr 6, 2022
 *      Author: David
 */
/*
Да се имплементира функција која како аргументи добива две единечно поврзани листи и
два броја. Првата влезна листа е полна а втората празна. Задача на функцијата е сите јазли чие
инфо поле има вредност која се наоѓа во распонот на влезните броеви (вклучувајќи ги и самите
броеви) да бидат префрлени во втората листа (притоа да не се креираат нови јазли туку да се
реискористат постојните).
Како дел од програмата да се напишат структури за имплементација на јазол и листа заедно
со функциите за поддршка на листата: функции за иницијализација, додавање и бришење на
елемент на почеток од листата, додавање и бришење на елемент на крај од листата, бришење на
цела листа и печатење на елементите од листата. Како дел од програмата да се напише main
функција во која ќе се дефинираат и иницијализираат двете листи, и првата листа ќе се пополни
со елементи кои се внесуваат преку тастатура. Исто така во main функцијата треба од тастатура да
се внесат вредностите на броевите кои го одредуваат распонот на вредности кои ќе се префрлат
во втората листа со помош на функцијата. Во main функцијата потоа да се повика функцијата за
печатење на првата листа, по што ќе се повика бараната функција (која треба да се имплементира)
и на крај ќе се испечатат двете листи после модификацијата. Програмата да се напише во C++.
 */
#include<iostream>

using namespace std;

struct jazol{
	int info;
	jazol *link;
};
struct EPLista{
	jazol *head;

	void init(){
		head = NULL;
	}
	void kreirajPrv(int x){
		if(head != NULL){
			cout<<"Listata e vekje kreirana, koristete dodadiPrv() ili dodadiPos()";
			return;
		}
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = head;
		head = nov;
	}
	void dodadiPrv(int x){
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = head;
		head = nov;

	}
	void dodadiPos(int x){
		jazol *nov = new jazol;
		nov->info = x;
		nov->link = NULL;
		if(head == NULL){
			head = nov;
			return;
		}
		jazol *dvizi = head;
		while(dvizi->link != NULL){
			dvizi = dvizi->link;
		}
		dvizi->link = nov;
	}
	void pechati(){
		jazol *dvizi = head;
		while(dvizi->link != NULL){
			cout<<"|"<<dvizi->info<<"|->";
			dvizi = dvizi->link;
		}
		cout<<"|"<<dvizi->info<<"|"<<endl;
	}
	void brisiPrv(){
		if(head == NULL){
			cout<<"Listata e prazna "<<endl;
			return;
		}
		jazol *pom = head;
		head = pom->link;
		delete pom;
	}
	void brisiPos(){
		if(head == NULL){
			cout<<"Listata e prazna"<<endl;
			return;
		}
		if(head->link==NULL){
			delete head;
			head = NULL;
			return;
		}
		jazol *dvizi = head;
		while(dvizi->link->link != NULL){
			dvizi = dvizi->link;
		}
		 jazol *pomoshen=dvizi->link;
		dvizi->link=NULL;
		delete(pomoshen);

	}
	void brisiLista(){
			while(head!=NULL){
				brisiPos();
			}
		}
	void brisiJazol(jazol *node){
		if(node == head){
			brisiPrv();
			return;
		}
		else{
			jazol *dvizi = head;
			while(dvizi!=node){
				dvizi = dvizi->link;
			}
			dvizi->link = node->link;
		}
	}

};
void func(EPLista &L1,EPLista &L2,int fir,int sec){
	jazol *dvizi = L1.head;
	while(dvizi->link!=NULL){
		if(dvizi->info >= fir && dvizi->info <=sec){
			if(L2.head == NULL){
				L2.head = dvizi;
			}
			else{
				jazol *pom = L2.head->link;
				pom = dvizi;
				pom = pom->link;
			}
		}
		dvizi = dvizi->link;
		}
	}
int main(){
	EPLista l1,l2;
	int broj,el,prv,vtor,pom;
	l1.init();
	l2.init();

	cout<<"Vnesete broj na elementi vo listata"<<endl;
	cin>>broj;
	cout<<"Pocni da vnesuvas broevi"<<endl;
	for(int i=0;i<broj;i++){
		cin>>el;
		l1.dodadiPos(el);
	}

	cout<<"Vnesi interval na broevi"<<endl;
	cin>>prv>>vtor;
	if(prv>vtor){
		pom = prv;
		prv = vtor;
		vtor = pom;
	}
	cout<<"Prvicnata lista: "<<endl;
	l1.pechati();
	func(l1,l2,prv,vtor);
	cout<<"Listite posle prerabotka vo funkcija: "<<endl;
	l1.pechati();
	cout<<endl;
	l2.pechati();
	return 0;
}


