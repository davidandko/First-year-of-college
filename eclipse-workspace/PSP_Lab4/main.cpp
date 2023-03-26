/*
 * main.cpp
 *
 *  Created on: Mar 30, 2022
 *      Author: David
 */
/*
Задача 1: Во една лабораторија во која се прават тестови за КОВИД-19 потребен е софтвер кој автоматски
ќе ги распредели во соодветни редови луѓето кои чекаат. За секој човек се знае името, ЕМБР, дали чека
резултат од направен тест и дали ќе прави серолошки тест и дали ќе прави PCR тест. Чекаат N луѓе во ист
ред, кои треба да се распределат во три реда: луѓе кои чекаат резултат и луѓе кои чекаат за серолошки тест
и луѓе кои чекаат за PCR тест. Ако некој сака да земе резултат и повторно да прави тест, прво чека во ред
за резултат, а потоа во ред за соодветното тестирање (откако ќе биде услужен во редот за резултати,
застанува на крај од редот за соодветното тестирање). Ако некој сака двете тестирања да ги направи, прво
застанува во редот за серолошко тестирање, а потоа (откако ќе биде опслужен) на крај од редот за PCR
тестирање.
Распределувањето и услужувањето на луѓето да се прави во посебна функција raspredeli&usluzi(). Во истата
функција да се распределуваат луѓето во редовите. Во функцијата и да се симулира дејството на
услужување со тоа што ќе се печатат името и ЕМБР на пациентот и порака за што биле услужени. Прво да
се опслужи редот за резултати, потоа редот за серолошко тестирање, а на крај редот за PCR тестирање.
Да се напише кодот за структурата Queue која ги вклучува и функциите за манипулација на елементите од
редот.

 */
#include<iostream>
#include<string>

using namespace std;

const int MAX = 50;
struct covek{
	string ime;
	int embr;
	bool rezultat;
	bool testiranjeSer;
	bool testiranjePCR;

	void pechati(){
		cout<<ime<<" "<<embr<<" "<<endl;
	}
};
struct Queue{
	covek niza[MAX];
	int front,rear;

	void init(){
		front=0;
		rear=-1;
	}
	bool isEmpty(){
		return rear<0;
	}
	bool isFull(){
		return rear >= MAX-1;
	}
	void vnesi(covek e){
		if(isFull()){
			cout<<"Nema mesto vo redot"<<endl;
		}
		niza[++rear] = e;
	}
	covek dequeue(){
		if(isEmpty()){
			cout<<"Redot e prazen"<<endl;
			return {};
		}
		covek pom = niza[front];
		for(int i = 0;i<rear;i++){
			niza[i] = niza[i+1];
		}
		rear--;
		return pom;
	}
	covek peek(){
		if(isEmpty()){
			cout<<"Nema nisto vo redot"<<endl;
		}
		return niza[front];
	}
};
	void raspredeliusluzi(Queue lugjeF,Queue za_testiranjeSerF,Queue za_testiranjePCRF,Queue za_rezultatiF){
		while(!lugjeF.isEmpty()){
			if(lugjeF.peek().rezultat && lugjeF.peek().testiranjeSer){
				za_rezultatiF.vnesi(lugjeF.dequeue());
				while(!za_rezultatiF.isEmpty()){
					za_rezultatiF.dequeue().pechati();
				}
				za_testiranjeSerF.vnesi(lugjeF.dequeue());
				while(!za_testiranjeSerF.isEmpty()){
					za_testiranjeSerF.dequeue().pechati();
				}

			}
			else if(lugjeF.peek().rezultat && lugjeF.peek().testiranjePCR){
				za_rezultatiF.vnesi(lugjeF.dequeue());
				while(!za_rezultatiF.isEmpty()){
					za_rezultatiF.dequeue().pechati();
				}
				za_testiranjePCRF.vnesi(lugjeF.dequeue());
				while(!za_testiranjePCRF.isEmpty()){
					za_testiranjeSerF.dequeue().pechati();
				}
			}
			else if(lugjeF.peek().rezultat){
				za_rezultatiF.vnesi(lugjeF.dequeue());
			}
			else if(lugjeF.peek().testiranjeSer){
				za_testiranjeSerF.vnesi(lugjeF.dequeue());
			}
			else if(lugjeF.peek().testiranjePCR){
				za_testiranjePCRF.vnesi(lugjeF.dequeue());
			}
		}

	}

	int main()
	{
	Queue lugje, za_testiranjeSer, za_testiranjePCR, za_rezultati;
	covek pomoshen;
	char c;
	int i=1;
	lugje.init();
	za_rezultati.init();
	za_testiranjeSer.init();
	za_testiranjePCR.init();
	while(1)
	{
		cout<<"Vnesete podatoci za covek "<<i<<endl;
		cin>>pomoshen.ime>>pomoshen.embr>>pomoshen.rezultat>>pomoshen.
		testiranjeSer>>pomoshen.testiranjePCR;
		lugje.vnesi(pomoshen);
		cout<<endl;
		cout<<"Vnesete . za kraj na vnesuvanjeto"<<endl;
		cin>>c;
		if(c == '.')
			break;
		i++;
	}
	raspredeliusluzi(lugje, za_rezultati, za_testiranjeSer, za_testiranjePCR);
	cout<<endl;
	return 0;
}
