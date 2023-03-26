/*
 * mainmagacin.cpp
 *
 *  Created on: Apr 8, 2022
 *      Author: David
 */

#include<iostream>

using namespace std;
const int MAX = 30;
struct magacin{
	int info;
	int top;
	int S[MAX];

	void init(){
		top = -1;
	}
	bool empty(){
		return top == -1;
	}
	bool full(){
		return top>=MAX-1;
	}
	void dodadi(int x){
		if(full()){
			cout<<"Magacinot e poln"<<endl;
			return;
		}
		S[++top] = x;
	}
	int izvadi(){
		if(empty()){
			cout<<"Magacinot e prazen"<<endl;
			return 0;
		}
		return S[top--];
	}
	int peek(){
		if(empty()){
			cout<<"Prazen magacin"<<endl;
			return 0;
		}
		return S[top];
	}
	void pechati(){
		if(empty()){
			cout<<"Prazen magacin"<<endl;
			return;
		}
		while(!empty()){
			cout<<S[top]<<" ";
			top--;
		}
	}

};

int main(){
	return 0;
}
