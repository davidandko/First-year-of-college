/*
 * main.cpp
 *
 *  Created on: May 22, 2022
 *      Author: David
 */

/*
 Да се креира класа за опис на библиотека. За библиотеката се чува динамички алоцирана низа од
наслови на книги (насловот е стринг) и бројот на книги кој го има во библиотеката.
Да се обезбедат следниве методи за класата:
• Конструктор со default параметри кој добива низа од книги и број на книги во
библиотеката. Доколку конструкторот се повика без аргументи се креира библиотека со
една книга (со наслов по произволен избор).
• Деструктор кој ќе ја брише динамички алоцираната меморија.
Дополнително да се преоптоварат следниве оператори:
• Операторот < за споредба на две библиотеки (враќа true ако десниот операнд има повеќе
книги и fasle во спротивно)
• Операторот << за печатење на сите податоци за библиотеката.
• Операторот = за доделување библиотека.
• Операторот -= кој го наоѓа насловот кој е даден како десен операнд и го остранува од
низата со наслови (доколку не го најде, да не отстанува ништо).
• Операторот ++ кој овозможува додавање на нов наслов кој се добива како десен операнд
(додавањето да се направи на почеток од низата со наслови).
Да се напише главна програма во која ќе се тестира работата на сите креирани методи и
преоптоварувања.

 */

/*
class Biblioteka{
private:
    string *knigi;
    int brKnigi;
public:
    Biblioteka(string *knigiv=NULL,int brK=1)
    {
        if(knigiv==NULL)
        {
            knigi=new string[1];
            knigi[0]="1984";
            brKnigi=1;
            cout<<"Bibliotekata ima 1 kniga so naslov '"<<knigi[0]<<"'\n";
        }
        else{
        knigi=new string[brK+1];
        brKnigi=brK;
        for(int i=0;i<brKnigi;i++)
            knigi[i]=knigiv[i];
        }
    }
    ~Biblioteka(){ delete []knigi; }

    bool operator<(Biblioteka &b)
    {
        return brKnigi<b.brKnigi;
    }

    friend ostream &operator <<(ostream &out,Biblioteka &b){
        cout<<"Bibliotekata ima ";
        cout<<b.brKnigi<<" knigi\n";
        out<<"Naslovi na knigi:\n";
        for(int i=0;i<b.brKnigi;i++)
            out<<b.knigi[i]<<endl;
        out<<endl;
        return out;
    }

    Biblioteka &operator=(Biblioteka &b)
    {
        delete []knigi;
        brKnigi=b.brKnigi;
        knigi=new string[brKnigi];
        for(int i=0;i<brKnigi;i++)
            knigi[i]=b.knigi[i];
        return *this;
    }

    Biblioteka &operator-=(string naslov)
    {
        string *pom=new string[brKnigi];
        int ipom,flag=0;
        for(int i=0;i<brKnigi;i++)
        {
            if(knigi[i]==naslov)
            {
                ipom=i; flag=1; break;
            }
            else pom[i]=knigi[i];
        }
        if(flag==1)
        {
            for(int i=ipom;i<brKnigi;i++)
                pom[i]=knigi[i+1];
            delete []knigi;
            knigi=pom;
            brKnigi--;
        }
        return *this;
    }

    Biblioteka &operator+=(string naslov){
        brKnigi++;
        string *pom=new string[brKnigi];
        pom[0]=naslov;
        for(int i=1;i<brKnigi;i++)
            pom[i]=knigi[i-1];
        delete []knigi;
        knigi=pom;
        return *this;
    }

};

int main(){
    string naslovi[3]={"Sherlok","Odiseja2001","Vremeplov"};

    cout<<"Biblioteka 1"<<endl;
    Biblioteka b1=Biblioteka();

    Biblioteka b2=Biblioteka(naslovi,3);
    Biblioteka b3=b2;
    cout<<"\nRezultat od sporedba: ";
    cout<<(b1<b2);
    cout<<endl<<endl;
    cout<<b3;
    b2-=("Vremeplov");
    cout<<endl<<b2;
    b2+=("Astronomija");
    cout<<endl<<b2;
    return 0;
}
*/
#include<iostream>
#include<cstring>

using namespace std;

class Biblioteka{
private:
	string *knigi;
	int broj;
public:
	Biblioteka(string *knigiF = NULL,int brojF =1){
		if(knigiF == NULL){
			knigi = new string[brojF];
			knigi[0] = "Robinzon Kruso";
		}
		knigi = new string[brojF];
		for(int i=0;i<brojF;i++){
			knigi[i] = knigiF[i];
		}
		broj = brojF;
	}
	~Biblioteka(){
		delete [] knigi;
	}
	bool operator<(const Biblioteka &b){
		if(this->broj<b.broj){
			return true;
		}
		return false;
	}
	friend ostream &operator<<(ostream &o,Biblioteka &b){
		o<<"Broj na knigi: "<<b.broj<<endl;
		o<<"Knigi: "<<endl;
		for(int i=0;i<b.broj;i++){
			o<<b.knigi[i];
		}
		o<<endl;
		return o;
	}
	Biblioteka &operator=(const Biblioteka &b){
		if(this == &b){
			return *this;
		}
		delete[] knigi;
		knigi = new string[b.broj];
		for(int i = 0;i<b.broj;i++){
			knigi[i] = b.knigi[i];
		}
		broj = b.broj;
		return *this;
	}
	Biblioteka &operator-=(string naslov){
		string *nova = new string[broj-1];
		int j=0;
		for(int i =0;i<broj;i++){
			if(naslov!=knigi[i]){
				nova[j] = knigi[i];
				j++;
			}
		}
		delete [] knigi;
		broj--;
		knigi = nova;
		return *this;
	}
	Biblioteka &operator+=(string dodadi){
		string *nova = new string[broj+1];
		nova[0] = dodadi;
		for(int i = 0;i<broj;i++){
			nova[i+1] = knigi[i];
		}

		broj++;
		return *this;
	}
};

int main(){

	return 0;
}



