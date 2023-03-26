/*
 * main.cpp
 *
 *  Created on: May 11, 2022
 *      Author: David
 */
/*
 Да се креира класа работа со лото ливче. За лото ливчето се чува динамички алоцирана низа
од цели броеви и бројот на внесени броеви во ливчето.
Да се обезбедат следниве методи за класата:
• Конструктор со default параметри кој добива низа од цели броеви и број на цели
броеви во лото ливчето. Доколку конструкторот се повика без аргументи се креира лото
ливче со 1 број (со произволна вредност).
• Деструктор кој ќе ја брише динамички алоцираната меморија.
Дополнително да се преоптоварат следниве оператори:
• Операторот >> за вчитување на сите податоци за лото ливчето.
• Операторот << за печатење на сите податоци за лото ливчето.
• Операторот = за доделување на лото ливче.
• Операторот == за споредување на две лото ливчиња (ако имаат ист број на внесени
броеви и исти вредности за внесените броеви да врати true инаку да врати false).
• Операторот [] кој го враќа бројот од соодветната позиција.
• Операторот ++ кој овозможува додавање на нов број на крај од низата.
Да се напише главна програма во која ќе се тестира работата на сите креирани методи и
преоптоварувања.
 */
#include<iostream>
#include<cstring>

using namespace std;

class Loto{
private:
	int *broevi;
	int size;
public:
	Loto(){
		broevi = new int[1];
		size = 1;
		broevi[0] = 124;
	}
	Loto(int *broeviF,int sizeF){
		broevi = new int[sizeF+1];
		for(int i=0;i<sizeF;i++){
			broevi[i] = broeviF[i];
		}
		size = sizeF;
	}
	~Loto(){
		delete[] broevi;

	}
	friend istream &operator>>(istream &input,Loto &l){
		cout<<"Vnesi golemina na niza "<<endl;
		input>>l.size;
		delete [] l.broevi;
		l.broevi = new int[l.size];
		cout<<"Vnesuvaj elementi vo nizata: "<<endl;
		for(int i=0;i<l.size;i++){
			input>>l.broevi[i];
		}
		return input;
	}
	friend ostream &operator<<(ostream &output,Loto &l){
		for(int i = 0;i<l.size;i++){
			output << l.broevi[i]<<" ";
		}
		output<<endl;
		return output;
		}
	Loto &operator=(const Loto &l){
		if(this==&l){
	       return *this;
		}
		else{
	    delete [] broevi;
	    size = l.size;
	    broevi = new int[size];
	    for(int i = 0;i <size; i++)
	        broevi[i] = l.broevi[i];

	    return *this;
	        }
	    }
	bool operator==(Loto &l){
		int x = 0;
		if(size == l.size){
			for(int i = 0;i<l.size;i++){
				if(broevi[i] == l.broevi[i]){
					x++;
				}
				else{
					return false;
					break;
				}
			}
		}else{
			return false;
		}
		return (x==size);
	}
	int &operator[](int pozicija){
		return this->broevi[pozicija];
	}
	Loto &operator++(int broj){

		int *broi = new int[size+1];
		for(int i = 0;i<size;i++){
			broi[i] = broevi[i];
		}
		delete [] broevi;
		broi[size++] = broj;
		broevi = broi;
		return *this;
		}
};
int main(){
	int niza[6] = {37,26,3,7,2,1};
	Loto l1();
	Loto l2(niza,6);
	Loto l3;
	cout<<l2;
	l3=l2;
	cout<<l3;
	if(l2 == l3){
		cout<<"l2 i l3 se isti"<<endl;
	}
	else{
		cout<<"l2 i l3 ne se isti"<<endl;
	}
	cout<<"Brojot na 4ta pozicija vo l2 nizata"<<endl;
	cout<<l2[4]<<endl;
	l2.operator ++(5);
	cout<<l2;
	return 0;

}


