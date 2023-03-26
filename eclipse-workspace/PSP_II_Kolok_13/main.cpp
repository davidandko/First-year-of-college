/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
Да се креира класа Recenica која е составена од низа од зборови (динамички алоцирана), и бројот на
зборовите. Да се обезбедат следниве конструктори и методи за класата:
• Конструктор со default параметри кој како аргументи добива низа од зборови и должина на
низата, но ако се повика без аргименти прави низа од еден збор со содржина “default”
• Деструктор кој соодветно ќе ја избрише динамички алоцираната меморија.
Дополнително да се преоптоварат и следниве оператори за работа со низите:
• Операторот << за печатење на сите зборови во реченицата.
• Операторот = за доделување.
• Операторот > кој споредува две решеници и враќа true ако левиот објект има повеќе зборови
од десниот објект во однос на операторот.
• Операторот -= (string zbor) кој го додава зборот zbor на почеток на низата.
• Операторот ++ кој го отстранува последниот збор од низата а е реализиран како постфикс.
• Операторот [] кој го враќа зборот кој се наоѓа во реченицата на соодветната позиција и
дозволува истиот да биде променет.
Напомена: Класата треба да се грижи за мемориско оптимизирање на низата (преку грижа за
динамичката алокација при секоја операција)!
 */
#include<iostream>
#include<cstring>
using namespace std;

class Recenica{
private:
	string *zborovi;
	int broj;
public:
	Recenica(string *zboroviF = NULL,int brojF = 0){
		if(zboroviF == NULL){
			zborovi = new string[1];
			zborovi[0] = "Default";
			broj =1;
		}else{
			zborovi = new string[brojF];
			for(int i = 0;i< brojF;i++){
				zborovi[i] = zboroviF[i];
			}
			broj = brojF;
		}
	}
	~Recenica(){
		delete [] zborovi;
	}
	Recenica(const Recenica &r){
		broj = r.broj;
		for(int i = 0;i<broj;i++){
			zborovi[i] = r.zborovi[i];
		}
	}
	friend ostream &operator<<(ostream &output,Recenica &r){
		output<<"Broj na zborovi vo recenicata: "<<r.broj<<endl;
		for(int i=0;i<r.broj;i++){
			output<<r.zborovi[i]<<" ";
		}
		output<<endl;
		return output;
	}
	Recenica &operator=(Recenica &r){
		if(this==&r){
			return *this;
		}
		else{
			delete [] zborovi;
			zborovi = new string[r.broj];
			for(int i =0;i<r.broj;i++){
				zborovi[i] = r.zborovi[i];
			}
			zborovi = r.zborovi;
			return *this;
		}
	}
	bool operator>(Recenica &r){
		return broj>r.broj;
	}
	Recenica &operator-=(string zbor){
		string *nova = new string[broj+1];
		nova[0] = zbor;
		for(int i = 0 ;i<broj;i++){
			nova[i+1] = zborovi[i];
		}
		delete []  zborovi;
		broj++;
		zborovi = nova;
		return *this;
	}
	Recenica operator++(int){
		Recenica r(*this);
		string *nova = new string[broj-1];
		for(int i = 0;i<broj-1;i++){
			nova[i] = zborovi[i];
		}
		delete [] zborovi;
		broj--;
		zborovi = nova;

		return r;
	}
	string operator[](int poz){
		return zborovi[poz];
	}

};

int main()
{
string zborovi[6]={"sakam","da","polozam","psp","vo","juni"};
Recenica r1=Recenica();
Recenica r2=Recenica(zborovi,6);
Recenica r3;
r3=r2;
cout<<r2;
cout<<r3;
r2-="Jas";
cout<<r2;
r2-="David";
cout<<r2;
cout<< (r2>r1);
r1[0]="Nov";
cout<<r2[0];
return 0;
}

