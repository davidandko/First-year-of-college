/*
 * main.cpp
 *
 *  Created on: Apr 3, 2022
 *      Author: David
 */
/*
Дадени се двојно поврзани листи чии јазли кои содржат парен број цели броеви
и бројот на елементи е еднаков.
Да се напише функција која како аргументи прима три листи,
од кои две се веќе пополнети и една празна која ја враќа пополнета на следниов начин:
се земаат по два броја од почетокот на првата листа и два броја од крајот од втората листа
и се проверува дали сумата на првите два броеви од првата листа е делива со разликата на
броевите од втората листа. Доколку условот е исполнет, во новата листа се сместува 1,
доколку пак условот не е исполнет во новата листа се сместува 0.
Како дел од програмата да се напишат структури за имплементација на јазол и
двојно поврзана листа заедно со функциите за поддршка на листата:
функции за иницијализација, додавање и бришење на елемент на почеток од листата,
додавање и бришење на елемент на крај од листата, бришење на цела листа и
печатење на елементите од листата.
Како дел од програмата да се напише главна функција во која ќе се дефинираат и
иницијализираат сите листи, и првите две листи ќе се пополнат со елементи кои
корисникот ќе ги внесува преку тастатура.
Во main функцијата потоа да се повика функциите за печатење на првите две листи,
по што ќе се повика бараната функција (која треба да се имплементира) и
на крај ќе се испечати новата листа после модификацијата.
Програмата да се напише во C++.
Пример:
L1: 2 ↔ 8 ↔ 10 ↔ 7 ↔ 11 ↔ 10↔ 15 ↔ 6
L2: 2 ↔ 5 ↔4 ↔ 7 ↔ 5 ↔ 12↔ 4 ↔ 6
Резултантна листа: 1 ↔ 0 ↔ 1 ↔ 1
 */
#include<iostream>

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
		while(dvizi != NULL){
			cout<<dvizi->info<<" ";
			dvizi = dvizi->next;
		}
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
	Jazol *kraj2 = l2.tail;
	while((poc1 != NULL)){
	int br11=poc1->info,  br12=poc1->next->info,  br21=kraj2->info,  br22=kraj2->prev->info;
		if((br11+br12)%(br21-br22)==0){
			l3.insertLast(1);
		}
		else{
			l3.insertLast(0);
		}
		poc1 = poc1->next->next;
		kraj2 = kraj2->prev->prev;
	}

}


/*void function(DList &l1,DList &l2,DList &l3){
	Jazol *poc1 = l1.head;
	Jazol *poc2 = l1.head->next;
	Jazol *kraj1 = l2.tail;
	Jazol *kraj2 = l2.tail->prev;
	while((poc1 != NULL)){
	int br11=poc1->info,  br12=poc2->info,  br21=kraj1->info,  br22=kraj2->info;
		if((br11+br12)%(br21-br22)==0){
			l3.insertLast(1);
		}
		else{
			l3.insertLast(0);
		}
		poc1 = poc1->next->next;
		poc2 = poc2->next->next;
		kraj1 = kraj1->prev->prev;
		kraj2 = kraj2->prev->prev;
	}

} gresna
*/
int main(){
	DList L1,L2,L3;
	L1.init();
	L2.init();
	L3.init();
	int brbr,broj;
	cout<<"Vnesi broj na elementi: "<<endl;
	cin>>brbr;
	cout<<"Pocni da vnesuvas vo prvata lista"<<endl;
	for(int i=0;i<brbr;i++){
		cin>>broj;
		L1.insertLast(broj);
	}
	cout<<"Pocni da vnesuvas vo vtorata lista"<<endl;
	for(int i=0;i<brbr;i++){
		cin>>broj;
		L2.insertLast(broj);
	}
	cout<<endl;
	L1.pecati();
	cout<<endl;
	L2.pecati();
	cout<<endl;
	function(L1,L2,L3);

	L3.pecati();
	return 0;
}


