/*
 * main1.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: David
 */
#include<iostream>
#include<string>

using namespace std;
const int maxG = 30;

struct element{
	char x;
};
struct red{
	int r;
	int f;
	element S[maxG];

	void init(){
		r =-1;
		f=0;
	}
	int isEmpty(){
		return r<0;
	}
	int isFull(){
		return r>=maxG-1;
	}
	void dodadi(element v){
		if(isFull()){
			cout<<"Nema mesto!"<<endl;
			return;
		}
		r++;
		S[r] = v;
	}
	element izvadi(){
		if(isEmpty()){
			cout<<"Prazen e redot!"<<endl;
			return {};
		}
		element pom = S[f];
		for(int i=0;i<r;i++){
			S[i]=S[i+1];
		}
		r--;
		return pom;
	}
};

struct magacin{
	int top;
	element M[maxG];

	void init(){
		top = -1;
	}
	int isEmpty(){
		return top<=-1;
	}
	int isFull(){
		return top>=maxG-1;
	}
	void dodadi(element e){
		if(isFull()){
			cout<<"Nema mesto vo magacinot!"<<endl;
			return;
		}
		top++;
		M[top] = e;
	}
	element izvadi(){
		if(isEmpty()){
			cout<<"Magacinot e prazen!"<<endl;
			return {};
		}
		element pom = M[top];
		top--;
		return pom;
	}
};

int main(){
	red izlezen;
	magacin pomoshen;
	int Xpoj = 0;
	char odT;
	izlezen.init();
	pomoshen.init();

	cout<<"Vnesuvajte gi bukvite, za kraj vnesete znak za ."<<endl;

	while(1){
		cin>>odT;
		if(odT == '.'){
			break;
		}
		element e;
		e.x =odT;
		izlezen.dodadi(e);
		if(odT == 'X' && Xpoj<=1){
			if(Xpoj != 0){
			pomoshen.dodadi(e);
			}
			Xpoj++;

			if(Xpoj == 2){
				while(!pomoshen.isEmpty()){
					element ep = pomoshen.izvadi();
					izlezen.dodadi(ep); // izlezen.dodadi(pomoshen.izvadi());
				}
			}
		}
		if(Xpoj>0 && Xpoj<2){
			pomoshen.dodadi(e);
		}
	}

cout<< endl;

while(!izlezen.isEmpty()){
	cout<<izlezen.izvadi().x;
}
cout<<endl;
	return 0;
}




