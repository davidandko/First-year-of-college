/*
 * main.cpp
 *
 *  Created on: Mar 16, 2022
 *      Author: David
 */
/*
За организација на дополнителна ден сесија, на факултетот му е потребна програма за распределба
на студентите по просторија. За таа цел треба да се направаат две структури: структура за студентот
и структура за просторијата. За секој студент се знае името и презимето на студентот, број на индекс
и името на предметот што ќе го полага. За секоја просторија се знае име на просторијата (стринг),
бројот на работни места (максималниот број на работни места е 10) и студентите во училницата
(низа од променливи од тип структура студент). Во секоја од структурите да се декларираат (како
дел од структурите) и дефинираат функции за иницијализација на променливи и за печатење: init()
и pechati(). За структурата просторија да се преоптовари функцијата за печатење, така што кога ќе
и се проследува цел број x, тогаш да се испечатат само информациите за првите x студенти од
низата со студенти. Дополнително, да се дефинира функција najOptovarenaProstorija() која како
аргументи добива низа од простории и број на простории и ги печати податоците за просторијата
со најмногу студенти.
Да се напише главна програма во која ќе се иницијализираат 10 студенти и низа од две простории
(првата со 4, а втората со 6 студенти). Иницијализацијата на променливите да се реализира преку
функциите init(). Потоа за секоја од просториите да се повика функцијата за печатење (при
повикувањето за првата просторија, да се повика без аргументи, а за втората со аргумент 3).
Дополнително, да се повика najOptovarenaProstorija() кога на влез ја добива низата од простории.
Напомена: функцијата за печатење на просторија треба да ја повикува функцијата за печатење на
студент.
 */

#include<iostream>
#include<string>
using namespace std;

struct Student{
	string ime;
	string prezime;
	int brIndeks;
	string imePredmet;
	void init(string imeF,string prezimeF,int brIndeksF,string imePredmetF){
		ime=imeF;
		prezime=prezimeF;
		brIndeks=brIndeksF;
		imePredmet=imePredmetF;
	}
	void pechati(){
		cout<<"Ime na studentot: "<<ime<<endl;
		cout<<"Prezime na studentot: "<<prezime<<endl;
		cout<<"Broj na indeks na studentot: "<<brIndeks<<endl;
		cout<<"Ime na predmetot koj studentot go polaga: "<<imePredmet<<endl;
	}
};


struct Prostorija{
	string ime;
	int brRabotniMesta;
	Student studenti[10];
	void init(string imeF,int brRabotniMestaF, Student studentiF[]){
		ime=imeF;
		brRabotniMesta=brRabotniMestaF;
		for(int i=0;i<brRabotniMesta;i++){
			studenti[i]=studentiF[i];
		}
	}
	void pechati(){
		cout<<"Ime na prostorijata: "<<ime<<endl;
		cout<<"Broj na rabotni mesta vo prostorijata: "<<brRabotniMesta<<endl;
		for(int i=0;i<brRabotniMesta;i++){
			 studenti[i].pechati();
		}

	}
	void pechati(int x){ // preoptovarena funkcija
		for(int i=0;i<x;i++){
			studenti[i].pechati();
		}
	}
};

void najOptovarenaProstorija(Prostorija *prostorii,int brojProstorii){
	int pozicija,brstudenti,maxstudent=0;
	for(int i=0;i<brojProstorii;i++){
	brstudenti=prostorii[i].brRabotniMesta;
	if(brstudenti>maxstudent){
		maxstudent=brstudenti;
		pozicija=i;
	}
	}
	cout<<"Najoptovarena prostorija e prostorijata broj"<<pozicija<<" so "<<maxstudent<<" studenti."<<endl;
	prostorii[pozicija].pechati();
}

int main(){
	Prostorija prostor[2];
	Student student[10];
	string imeProstor,prezimeStud,imeStud,imePred;
	int brRab,brIn;
	for(int i=0;i<2;i++){
		cout<<"Vnesete ime na prostorijata: "<<endl;
		cin>>imeProstor;
		cout<<"Vnesete broj na rabotni mesta vo prostorija: "<<endl;
		cin>>brRab;
		for(int j=0;j<brRab;j++){
			cout<<"Vnesete ime na student: "<<endl;
			cin>>imeStud;
			cout<<"Vnesete prezime na student: "<<endl;
			cin>>prezimeStud;
			cout<<"Vnesete broj na indeks na student: "<<endl;
			cin>>brIn;
			cout<<"Vnesete ime na predmetot koj se polaga: "<<endl;
			cin>>imePred;
			student[j].init(imeStud, prezimeStud, brIn, imePred);

		}
		prostor[i].init(imeProstor, brRab,student);

	}
	prostor[0].pechati();
	prostor[1].pechati(3);
	najOptovarenaProstorija(prostor,2);

	return 0;
}
