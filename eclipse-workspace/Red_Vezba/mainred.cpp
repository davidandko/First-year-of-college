/*
 * mainred.cpp
 *
 *  Created on: Apr 8, 2022
 *      Author: David
 */
#include<iostream>

using namespace std;
const int MAX= 50;
struct red{
	int front,rear;
	int S[MAX];
	void init(){
		front = 0;
		rear = -1;
	}
	bool empty(){
		return rear<0;
	}
	bool full(){
		return rear>=MAX-1;
	}
	int dodadi(int x){
		if(full()){
			cout<<"Redot e poln"<<endl;
			return 0;
		}
		return S[++rear] = x;
	}
	int izvadi(){
		if(empty()){
			cout<<"Redot e prazen"<<endl;
			return 0;
		}
		int pom = S[front];
		for(int i=0;i<rear;i++){
			S[i] = S[i+1];
		}
		rear--;
		return pom;
	}
	int peek(){
		if(empty()){
			cout<<"Redot e prazen"<<endl;
			return 0;
		}
		return S[front];
	}
	void pechati(){
		if(empty()){
			cout<<"Redot e prazen"<<endl;
			return;
		}
		for(int i = 0;i<=rear;i++){
			cout<<S[i]<<" ";
		}
	}
};



