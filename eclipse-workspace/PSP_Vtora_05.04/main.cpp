/*
 * main.cpp
 *
 *  Created on: Apr 5, 2022
 *      Author: David
 */
#include<iostream>

using namespace std;
const int MAX = 50;

	struct stack{
	int S[MAX];
	int top;
	void init(){
		top = -1;
	}
	bool isEmpty(){
		return (top==-1);
	}
	bool isFull(){
		return (top >= MAX-1);
	}

	void push(int x){
		if(isFull()){
			cout<<"Listata e polna"<<endl;
		}
		top++;
		S[top] = x;
	}
	 int pop(){
		if(isEmpty()){
			cout<<"Listata e prazna"<<endl;
			return {};
		}
		return S[top];
		top--;
	 }
	 int peek(){
		 if(isEmpty()){
			 cout<<"Magacinot e prazen"<<endl;
			 return {};
		 }
		 return S[top];
	 }
	 void pechati(){
		 for(int i = 0;i<=top;i++){
			 cout<<"|"<<S[i]<<"|"<<endl;
		 }
	 }

	};

void promeni(stack &m){
	int cont = 0;
	int prev = 0;
	int mom, next;
	stack pom;
	pom.init();

	while(!m.isEmpty()){
		mom = m.pop();
		if(cont != 0){
			if(mom%prev == 0){
				pom.push(mom/prev);
			}
		}
		if(!m.isEmpty()){
			next = m.peek();
			if(mom%next == 0){
				pom.push(mom/next);
			}
		}
		cont++;
		prev = mom;
	}
	while(!pom.isEmpty()){
		m.push(pom.pop());
	}
}
int main() {
	stack m1;

	m1.init();

	m1.push(2);
	m1.push(10);
	m1.push(5);
	m1.push(2);
	m1.push(1);

	promeni(m1);

	while (!m1.isEmpty()) {
		cout << m1.pop() << endl;
	}

	return 0;
}
// imam greska nekade
