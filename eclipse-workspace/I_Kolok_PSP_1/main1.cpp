/*
 * main1.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: David
 */
//Zadaca 2 16.4.2015 termin 1
/*
Во една продавница се организира акција за 8ми Март - со сметка над 500 денари купувачите од
женски пол добиваат подарок. За секој купувач се чува информација за неговото име,
пол и колкав промет направил во продавницата. Потребно е да се испечатат сите клиенти кои добиле подарок,
но во обратен редослед (последниот добитник ќе се испечати прв).
Ако некој машки клиент има направено промет над 1000 денари,
а позади него чека жена, тогаш и таа, без разлика на направениот промет, добива подарок.
Влез: Бројот на купувачи се внесува од тастатура, како и нивните податоци.
Излез: Името на клиентите кои добиле подарок.
Пример:
влез: (“Таnjа”, Z, 600), (“Pavel”, M, 550), (“Tea”, Z, 200), (“Goran”, M, 1050), (“Lena”, Z, 400), (“Dora”, Z, 350), (“Eva”, Z, 520)
излез: Eva, Lena, Tanja
Забелешка: Не е дозволено користење на низи!
Функциите за работа со редови и магацини се наоѓаат во датотеката Termin1Zad2.cpp
*/

#include<iostream>
#include<string>

using namespace std;
const int maxG = 30;

struct kupuvac{
	string ime;
	bool zena;
	int promet;

};
struct red{
	int r;
	int f;
	kupuvac S[maxG];

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
	void dodadi(kupuvac v){
		if(isFull()){
			cout<<"Nema mesto!"<<endl;
			return;
		}
		r++;
		S[r] = v;
	}
	kupuvac izvadi(){
		if(isEmpty()){
			cout<<"Prazen e redot!"<<endl;
			return {};
		}
		kupuvac pom = S[f];
		for(int i=0;i<r;i++){
			S[i]=S[i+1];
		}
		r--;
		return pom;
	}
	kupuvac peek(){
				if(isEmpty()){
					cout<<"Prazen red"<<endl;
					return {};
				}
				return S[f];
			}
};

struct magacin{
	int top;
	kupuvac M[maxG];

	void init(){
		top = -1;
	}
	int isEmpty(){
		return top<=-1;
	}
	int isFull(){
		return top>=maxG-1;
	}
	void dodadi(kupuvac e){
		if(isFull()){
			cout<<"Nema mesto vo magacinot!"<<endl;
			return;
		}
		top++;
		M[top] = e;
	}
	kupuvac izvadi(){
		if(isEmpty()){
			cout<<"Magacinot e prazen!"<<endl;
			return {};
		}
		kupuvac pom = M[top];
		top--;
		return pom;
	}
	kupuvac peek(){
		if(isEmpty()){
			return {};
		}
		return M[top];
				}
};
void funkcija(red &redule){
	magacin magacince;
	magacince.init();
	while(!redule.isEmpty()){
		kupuvac temp = redule.izvadi();
		if(temp.zena && temp.promet > 500){
			magacince.dodadi(temp);
		}
		if((redule.peek().zena) && (temp.promet > 1000)){
			magacince.dodadi(redule.izvadi());
		}
	}
	while(!magacince.isEmpty()){
		cout<<magacince.peek().ime<<", ";
		magacince.izvadi();
	}
}

int main(){
	red redce;
	kupuvac pomosen;
	int i,brKupuvaci;
	redce.init();
	cout<<"Vnesete broj na kupuvaci"<<endl;
	cin>>brKupuvaci;
	for(i=0;i<brKupuvaci;i++){
		cout<<"Vnesete info za kupuvach"<<endl;
		cin>>pomosen.ime>>pomosen.zena>>pomosen.promet;
		redce.dodadi(pomosen);
	}
	funkcija(redce);


}

