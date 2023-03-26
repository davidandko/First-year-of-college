/*
 * main.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: David
 */
/*
Да се напише функција која како аргумент прима структура магацин во кој се сместени цифрите
на еден цел број. Во функцијата треба да формира нов број добиен како збир на цифрите од
почетокот и крајот на бројот (првата цифра се собира со последната, втората со претпоследната и
т.н.) и притоа доколку збирот на цифрите е поголем од 9, да се запише 9 на соодветната позиција.
На крај на екран да се испечати добиениот број.
Притоа, за решавање на задачата може да се користат само променливи од тип структура магацин,
односно функциите кои структурата ги има (init, push, peek, pop, isEmpty, isFull). Со тоа, за да се
провери бројот, најпрво треба магацинот да се празни елемент по елемент, а притоа да се полнат
два други помошни магацини со тие елементи. Откако сите елементи од оригиналниот магацин ќе
бидат поставени во двата помошни магацини, треба од едниот од помошните магацини да се
префрлат повторно во првиот оригинален магацин со цел да се добие бројот и превртен и во
оригинална форма. На крај, треба да се добие новиот број со празнење на елемент по елемент и од
двата сега полни магацини. Одговорот да се испечати на екран.
 */

#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

const int MAX = 20;

struct element{
	int podatok;
};

struct magacin{
	element elementi[MAX];
	int vrv;


	void init(){
		vrv = -1;
	}
	bool isEmpty(){
		return(vrv == -1);
	}
	bool isFull(){
		return(vrv == MAX-1);
	}
	void push(int el){
		if(isFull()){
			cout<<"Magacinot e poln"<<endl;
			return;
		}
		elementi[++vrv].podatok = el;

	}
	int pop(){
		if(isEmpty()){
			cout<<"Magacinot e prazen"<<endl;
			return {};
		}
		return elementi[vrv--].podatok;
	}
	int peek(){
				if(isEmpty()){
					cout<<"Nema sto da vidam, magacinot e prazen"<<endl;
				}
				return elementi[vrv].podatok;
			}

};

/*void func(magacin &m){
	magacin pomosen1,pomosen2;
	int zbir;
	int desen = m.vrv;
	int lev = 0;
	if(m.isEmpty()){
		cout<<"Magacinot e prazen"<<endl;
	}
	while(!m.isEmpty()){
		pomosen1.push(m.pop().podatok);
	}
		for(int i = 0;i<m.vrv;i++){
			zbir = pomosen1.elementi[lev].podatok+pomosen1.elementi[desen].podatok;
			pomosen2.vrv++;
				if(zbir>9){
					pomosen2.elementi[i].podatok = 9;
				}
				pomosen2.elementi[i].podatok = zbir;
				lev++;
				desen--;
		}
		while(!pomosen2.isEmpty()){
			m.push(pomosen2.pop().podatok);
	}
}
*/
void func(magacin &m){
	magacin pomosen1,pomosen2;
	int zbir;
	pomosen1.init();
	pomosen2.init();
	if(m.isEmpty()){
		cout<<"Magacinot e prazen"<<endl;
				return;
	}
	while(!m.isEmpty()){
		pomosen1.push(m.pop());
		pomosen2.push(pomosen1.peek());
	}
	while(!pomosen1.isEmpty()){
		m.push(pomosen1.pop());
	}
	while(!m.isEmpty() && !pomosen2.isEmpty()){
		zbir = m.pop()+pomosen2.pop();
		if(zbir>9){
			pomosen1.push(9);
		}else{
		pomosen1.push(zbir);
		}
	}
	while(!pomosen1.isEmpty()){
		m.push(pomosen1.pop());
	}

}


int main()
{
	magacin s;
	int no, element;
	s.init();
	cout << "Vnesete koj broj da se proveri:";
	cin >> no;
	while(no != 0){
		element = no%10;
		no /= 10;
		s.push(element);
	}
	func(s);

	while(!s.isEmpty()){
		cout<<s.pop();
	}
	return 0;
}

