/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
 * а се креира класа работа со лото ливче. За лото ливчето се чува динамички алоцирана низа
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

using namespace std;

class Loto{
private:
	int *niza;
	int size;
public:
	Loto(){
		size = 1;
		niza = new int[size];
		niza[0] = 69;

	}
	Loto(int *nizaF,int sizeF){
		size = sizeF;
		niza = new int[size];
		for(int i=0;i<size;i++){
			niza[i] = nizaF[i];
		}
	}
	~Loto(){
		delete [] niza;
	}
	friend istream &operator>>(istream &input,Loto &L){
		cout<<"Vnesete golemina na niza: "<<endl;
		input>>L.size;
		delete [] L.niza;
		cout<<"Pocnete so vnesuvanje na broevi: "<<endl;
		L.niza = new int[L.size];
		for(int i =0;i<L.size;i++){
			input>>L.niza[i];
		}
		return input;
	}
	friend ostream &operator<<(ostream &output,Loto &L){
		output<<"Broj na livcinja: "<<L.size<<endl;
		output<<"Livcinjata:"<<endl;
		for(int i =0;i<L.size;i++){
			output<<L.niza[i]<<" ";
		}
		output<<endl;
		return output;
	}
	Loto &operator=(Loto &L){
		if(this == &L){
			return *this;
		}
		else{
			size = L.size;
			delete [] niza;
			niza = new int[size];
			for(int i = 0;i<size;i++){
				niza[i] = L.niza[i];
			}
			return *this;
		}
	}
	bool operator==(Loto &L){
		bool flag = 0;
		if(size == L.size){
			for(int i=0;i<size;i++){
				if(niza[i] == L.niza[i]){
					flag = 1;
				}
				else{
					flag = 0;
					break;
				}
			}
		}
		return flag;
	}
	int operator[](int pozicija){
		return niza[pozicija];
	}
	Loto &operator++(int novbr){
		int *novaniza = new int[size+1];
		for(int i = 0;i<size;i++){
			novaniza[i] = niza[i];
		}
		delete[] niza;
		novaniza[size++] = novbr;
		niza = novaniza;
		return *this;
	}
};
int main(){
	int niza[5] = {5,10,15,20,25};
	Loto l(niza,5);
	Loto l1;
	cout<<l;
	cin>>l;
	cout<<l;
	cout<<"l1"<<endl;
	cout<<l1;
	l1=l;
	cout<<l1;
	if(l1==l){
		cout<<"Tocno"<<endl;
	}
	else{
		cout<<"Gresno"<<endl;
	}
	cout<<l[2]<<endl;
	l.operator ++(15);
	cout<<l;
}


