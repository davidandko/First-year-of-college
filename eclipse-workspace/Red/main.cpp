/*
 * main.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: David
 */
//red
#include<iostream>
using namespace std;
const int MAX = 50;


struct element{
	int info;
};
struct red{
	element S[MAX];
	int front,rear;

	void init(){
		front = 0;
		rear = -1;
	}
	bool empty(){
		return (rear<0);
	}
	bool full(){
		return (rear >= MAX-1);
	}
	void dodadi(int x){
		if(full()){
			cout<<"Redot e poln"<<endl;
		}
		S[++rear].info = x;
	}
	int izvadi(){
		if(empty()){
			cout<<"Redot e prazen"<<endl;
			return 0;
		}
		int pom = S[front].info;
		for(int i=0;i<rear;i++){
			S[i] = S[i+1];
		}
		rear--;
		return pom;
	}
	int peek(){
		if(empty()){
			cout<<"Redot e prazen, gospodine"<<endl;
		}
		return S[front].info;
	}
	void pechati(){
		for(int i=0;i<=rear;i++){
			cout<<S[i].info<<" ";
		}
	}
};

int main(){
	red r1;
	r1.init();
	int br;
	int el;
	cout<<"Kolku elementi?"<<endl;
	cin>>el;
	for(int i=0;i<el;i++){
		cin>>br;
		r1.dodadi(br);
	}

	r1.pechati();

	return 0;
}


