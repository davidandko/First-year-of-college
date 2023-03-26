/*
 * main.cpp
 *
 *  Created on: Mar 27, 2022
 *      Author: David
 */
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct student{
	string ime;
	int indeks;
	int poeni;
	void pechati(){
		cout<<ime<<" "<<poeni<<endl;
	}
};
void raspredeli(queue<student> *studentiF,queue<student> *polozeniF,queue<student> *nepolozeniF){
	while(!studentiF->empty()){
		if(studentiF->front().poeni>=50){
			polozeniF->push(studentiF->front());
			studentiF->pop();
		}
		else{
			nepolozeniF->push(studentiF->front());
			studentiF->pop();
		}
	}
}
int main(){
	queue<student> studenti,polozeni,nepolozeni;
	student pomoshen;
	char control;
	int i=1;
	while(1){
		cout<<"Vnesete podatoci za student: "<<i<<endl;
		cin>>pomoshen.ime>>pomoshen.indeks>>pomoshen.poeni;
		studenti.push(pomoshen);
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
	while(!polozeni.empty()){
		polozeni.front().pechati();
		polozeni.pop();
	}
	cout<<endl;
	cout<<"\t\tNepolozeni studenti: "<<endl;
	while(!nepolozeni.empty()){
		nepolozeni.front().pechati();
		nepolozeni.pop();
	}
	return 0;
}




