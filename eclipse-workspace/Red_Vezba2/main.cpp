/*
 * main.cpp
 *
 *  Created on: Apr 9, 2022
 *      Author: David
 */

#include<iostream>

using namespace std;
const int MAX = 50;
struct red{
	int S[MAX];
	int front,rear;
	void init(){
		front = 0;
		rear = -1;
	}
	bool empty(){
		return rear == -1;
	}
	bool full(){
		return rear >= MAX-1;
	}
	void dodadi(int x){
		if(full()){
			return;
		}
		rear++;
		S[rear] = x;
	}
	int otstrani(){
		if(empty()){
			return;
		}
		int pom = S[front];
		for(int i=0;i<rear;i++){
			S[i]=S[i+1];
		}
		rear--;
		return pom;
	}
	int peek(){
		if(empty()){
			return 0;
		}
		return S[front];
	}
	void pechati(){
		if(empty()){
			return;
		}
		for(int i =0;i<=rear;i++){
			cout<<S[i]<<" ";
		}
	}
};


