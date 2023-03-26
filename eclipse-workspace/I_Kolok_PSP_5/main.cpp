/*
 * main.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: David
 */
/*
 Дадени се две двојно поврзани листи чии јазли содржат парен број цели броеви (бројот на
елементи во двете листи мора да е еднаков, доколку не е еднаков, се отфрлаат вишокот на
елементи од подолгата листа). Да се напише функција која како аргумент прима три двојно
поврзани листи, од кои две веќе пополнети и една празна која ја враќа пополнета на следниов
начин: се земаат по два броеви од двете листи наизменично (еден број од почеток и еден од крајот
на првата, па на ист начин два броја од втората, во следната итерација вториот број од почетокот и
претпоследниот на првата листа, истото и од втората, инт.) и се проверува дали апсолутната
вредност од разликата на првите два броеви е иста со апсолутната вредност од разликата на
броевите од втората листа. Доколку овој услов е исполнет, во новата двојно поврзана листа се
сместува 1, доколку пак условот не е исполнет во новата листа да се смести 0.
Како дел од програмата да се напишат структури за имплементација на јазол и двојно поврзана
листа заедно со функциите за поддршка на листата: функции за иницијализација, додавање и
бришење на елемент на почеток од листата, додавање и бришење на елемент на крај од листата,
бришење на цела листа и печатење на елементите од листата.
Како дел од програмата да се напише главна функција во која ќе се дефинираат и
иницијализираат сите листи, и првите две листи ќе се пополнат со елементи кои корисникот ќе ги
внесува преку тастатура. Во main функцијата потоа да се повика функциите за печатење на
првите две листи, по што ќе се повика бараната функција (која треба да се имплементира) и на
крај ќе се испечати новата листа после модификацијата. Програмата да се напише во C++.
Пример:
L1: 2 ↔ 5 ↔ 10 ↔ 7 ↔ 1 ↔ 4 ↔ 12 ↔ 6
L2: 3 ↔ 21 ↔ 0 ↔ 12 ↔ 6 ↔ 6 ↔ 14 ↔ 7
Резултантна листа: 1 ↔ 1 ↔ 1 ↔ 1
 */
#include<iostream>
#include<cmath>
using namespace std;

struct Jazol{
	int info;
	Jazol *next;
	Jazol *prev;

	void init(int infoF,Jazol *nextF,Jazol *prevF){
		info = infoF;
		next = nextF;
		prev = prevF;
	}
};
struct DList{
	Jazol *head;
	Jazol *tail;

	void init(){
		head = NULL;
		tail = NULL;
	}
	void insertFirst(int info){
		Jazol *nov = new Jazol;
		nov->init(info, head, NULL);
		if(tail == NULL){
			tail = nov;
		}
		else{
			head->prev = nov;
		}
		head = nov;
	}
	void insertLast(int info){
		if(head == NULL){
			insertFirst(info);
		}
		else{
			Jazol *nov = new Jazol;
			nov->init(info, NULL, tail);
			tail->next = nov;
			tail = nov;
		}
	}
	void pecati(){
		Jazol *dvizi = head;
		while(dvizi->next!= NULL){
			cout<<dvizi->info<<" ";
			dvizi = dvizi->next;
		}
		cout<<dvizi->info<<" ";
	}
	void deleteFirst(){
		Jazol *dvizi = head;
		if(dvizi != NULL){
			head = head->next;
			head->prev = NULL;
		}
		if(head == NULL){
			tail = NULL;
		}
		delete dvizi;
	}
	void deleteJazol(Jazol *node){
		if(node == head){
			deleteFirst();
		}
		else{
			Jazol *prethodnik = node->prev;
			Jazol *sledbenik = node->next;
			prethodnik->next = sledbenik;
			sledbenik->prev = prethodnik;
			delete node;
		}

	}
};
void function(DList &l1,DList &l2,DList &l3){
	Jazol *poc1 = l1.head;
	Jazol *kraj1 = l1.tail;
	Jazol *poc2 = l2.head;
	Jazol *kraj2 = l2.tail;
	while(poc1 != NULL && poc2 != NULL){
		int brp1=poc1->info,brk1=kraj1->info,brp2=poc2->info,brk2=poc2->info;
		if(abs(brp1-brk1)==abs(brp2-brk2)){
			l3.insertLast(1);
		}
		else{
			l3.insertLast(0);
		}
		poc1 = poc1->next;
		kraj1 = kraj1->prev;
		poc2 = poc2->next;
		kraj2 = kraj2->prev;
	}

}

int main(){
	DList L1,L2,L3;
	int br1,br2,pom;
	L1.init();
	L2.init();
	L3.init();
	cout<<"Vnesete broj na promenlivi vo L1 i L2 soodvetno"<<endl;
	cin>>br1>>br2;
	cout<<"Vnesi elementi vo L1"<<endl;
	for(int i=0;i<br1;i++){
		cin>>pom;
		L1.insertLast(pom);
	}
	cout<<"Vnesi elementi vo L2"<<endl;
		for(int i=0;i<br2;i++){
			cin>>pom;
			L2.insertLast(pom);
		}
	/*if(br1>br2){
		odzemi = br1-br2;
		Jazol *dvizi = L2.tail;
		while(odzemi != 0){
			L2.deleteJazol(dvizi);
			odzemi--;
		}
	}else{
		odzemi = br2-br1;
		Jazol *dvizi = L1.tail;
		while(odzemi!=0){
			L1.deleteJazol(dvizi);
			odzemi--;
		}
	}
	*/

cout<<endl;
	L1.pecati();
cout<<endl;
	L2.pecati();
cout<<endl;
function(L1,L2,L3);

L3.pecati();

	return 0;
}
// tuka sum nekade ama ne mi pecati tocno
