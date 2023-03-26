/*
 * main.cpp
 *
 *  Created on: Mar 26, 2022
 *      Author: David
 */
#include<iostream>
#include<string>
using namespace std;

const int MAX = 50;
struct student{
	string ime,prezime;
	int indeks;
	int poeni;
	void pechati(){
		cout<<ime<<" "<<prezime<<" "<<poeni<<endl;
	}
};
struct element{
	student info;
};


struct red{
	element niza[MAX];
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
	void enqueue(element e){
		if(isFull()){
			cout<<"Nema mesto vo redot"<<endl;
			return;
		}
		niza[++rear] = e;
	}
	element dequeue(){
		if(isEmpty()){
			cout<<"Redot e prazen"<<endl;
			return {};
		}
		element pom = niza[front];
		for(int i = 0;i<rear;i++){
			niza[i] = niza[i+1];
		}
		rear--;
		return pom;
	}
	element peek(){
		if(isEmpty()){
			cout<<"Nema nisto vo redot"<<endl;
		}
		return niza[front];
	}
};
	void raspredeli(red *studentiF,red *polozeniF,red *nepolozeniF){
		element pom;
		while(!studentiF->isEmpty()){
			 pom = studentiF->dequeue();
		if(pom.info.poeni>=0 && pom.info.poeni<=100){
			 if(pom.info.poeni>=50)
			            polozeniF->enqueue(pom);
			        else
			            nepolozeniF->enqueue(pom);
			 }
		}
	}

int main(){
	red studenti,polozeni,nepolozeni;
	element pomoshen;
	char control;
	int i=1;
	studenti.init();
	polozeni.init();
	nepolozeni.init();

	while(1){
		cout<<"Vnesete podatoci za student: "<<i<<endl;
		cin>>pomoshen.info.ime>>pomoshen.info.prezime>>pomoshen.info.indeks>>pomoshen.info.poeni;
		studenti.enqueue(pomoshen);
		cout<<endl;
		cout<<"Vnesete '.' za kraj na vnesuvanjeto"<<endl;
		cin>>control;
		if(control == '.'){
			break;
		}
		i++;
	}
	raspredeli(&studenti,&polozeni,&nepolozeni);
	cout<<endl;
	cout<<"\t\tPolozeni studenti: "<<endl;
	while(!polozeni.isEmpty()){
		polozeni.dequeue().info.pechati();
	}
	cout<<endl;
	cout<<"\t\tNepolozeni studenti: "<<endl;
	while(!nepolozeni.isEmpty()){
		nepolozeni.dequeue().info.pechati();
	}
	return 0;
}

