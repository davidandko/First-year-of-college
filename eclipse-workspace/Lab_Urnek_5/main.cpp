/*
 * main.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: David
 */
/*
 *Задача 1:
Да се имплементира функција која како аргументи добива единечно поврзана листа и
природен број, а чија задача е да ги избрише од листата сите елементи чие инфо поле е исто со
дадениот природен број.
Како дел од програмата да се напишат структури за имплементација на јазол и листа заедно
со функциите за поддршка на листата: функции за иницијализација, додавање и бришење на
елемент на почеток од листата, додавање и бришење на елемент на крај од листата, бришење на
цела листа и печатење на елементите од листата. Како дел од програмата да се напише main
функција во која ќе се дефинира и иницијализира листата, и ќе се пополни со елементи кои се
внесуваат преку тастатура. Исто така во main функцијата треба од тастатура да се внесе вредноста
на бројот за кој ќе се изврши бришењето. Во main функцијата потоа да се повика функцијата за
печатење на листата, по што ќе се повика бараната функција (која треба да се имплементира) и на
крај ќе се испечати листата после модификацијата. Програмата да се напише во C++.
Пример:
list = |12|->|7|->|5|->|13|->|5|->|9|->|2|->NULL
broj = 5
Решение:
list = |12|->|7|->|13|->|9|->|2|->NUL
 */
#include<iostream>
using namespace std;
struct jazol{
	int info;
	jazol *link;
};
struct EPlista{
	jazol *head;

	void init(){
		head=NULL;
	}

	void kreirajEden(int _info){
		if(head!=NULL){
			cout<<"Listata e vekje kreirana,koristete druga f-ja."<<endl;
			return;
		}
		jazol *nov=new jazol;
		nov->info=_info;
		nov->link=NULL;
		head=nov;
	}

	void dodadiPrv(int _info){
		jazol *nov=new jazol;
		nov->info=_info;
		nov->link=head;
		head=nov;
	}

	void dodadiPosleden(int _info){
		jazol *nov=new jazol;
		nov->info=_info;
		nov->link=NULL;

		if(head==NULL){
			head=nov;
			return;
		}
		jazol *dvizi=head;
		while(dvizi!=NULL){
			dvizi=dvizi->link;
		}
		dvizi->link=nov;
	}

	void pechatiLista(){
		jazol *dvizi=head;
		while(dvizi != NULL){
			cout<<"|"<<dvizi->info<<"|";
			dvizi=dvizi->link;
		}
		cout<<dvizi->info<<"|"<<endl;
	}

	void brisiPrv(){
		if(head==NULL){
			cout<<"Prazna lista."<<endl;
			return;
	}
		jazol *pom=head;
		head=pom->link;
		delete(pom);
	}

	void brisiPosleden(){
		if(head==NULL){
			return;
		}
		if(head->link==NULL){
			delete head;
			head=NULL;
			return;
		}
		jazol *dvizi=head;
		while((dvizi->link)->link!=NULL){
			dvizi=dvizi->link;
		}
		jazol *pomoshen=dvizi->link;
		dvizi->link=NULL;
		delete(pomoshen);
	}

	void deleteJazol(jazol *node){
		if(node==head){
			brisiPrv();
		}else{
			jazol *dvizi=head;
			while(dvizi!=node){
				dvizi=dvizi->link;
			}
			dvizi->link=node->link;
			delete(node);
		}
	}

	void brisiLista(){
		jazol *dvizi=head;
		while(dvizi!=NULL){
			brisiPrv();
		}
	}
};
void func(EPlista &l,int k){
	jazol *dvizi = l.head;
	while(dvizi != NULL){
		if(dvizi->info == k){
			l.deleteJazol(dvizi);
			dvizi = dvizi->link;
		}
		dvizi = dvizi->link;
	}
}



int main(){
	EPlista L;
	L.init();
	int n,br,pom;
	cout<<"Vnesete kolku elementi ke ima vo listata"<<endl;
	cin>>br;
	cout<<"Vnesi priroden broj"<<endl;
	cin>>n;
	cout<<"Vnesete elementi vo listata"<<endl;
	for(int i=0;i<br;i++){
		cin>>pom;
		L.dodadiPosleden(pom);
	}
	cout<<endl;
	cout<<"Listata pred funckijata: "<<endl;
	L.pechatiLista();
	cout<<endl;
	func(L,n);
	cout<<endl;
	cout<<"Listata posle funkcijata: "<<endl;
	L.pechatiLista();
	return 0;
}





