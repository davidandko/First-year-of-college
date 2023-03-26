/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
 * Да се креира хиерархија на класи за водење евиденција за квалитет на медиуми преку
индексот за квалитет на месечно ниво. За секој медиум е познато името, бројот на вработени и
бројот на лажни вести кои се појавиле во медиумот во текот на месецот. Почетниот индекс за
квалитет за медиумот се добива кога бројот на вработени ќе се помножи со 5, и потоа се намалува
за 1 за секоја лажна вест во текот на месецот. Медиумите може да бидат телевизии или портали.
За телевизиите се чува и податок дали има профил на социјалните мрежи преку кој ги пласира
своите информации. За нив индексот на квалитет се зголемува за 20 доколку има профил на
социјалните мрежи.
За порталите се чува и податок за бројот на објавени постови во текот на тој месец. За секои
20 објавени поста, индексот за квалитет се зголемува за 5%.
Во секоја од класите да се дефинираат конструктори со подразбрани (default) вредности и
деструктори. Да се дефинираат и методи за печатење на сите информации за соодветните класи
(во изведените класи да се повика и искористи методот за печатење на основната класа). Исто така
за секоја класа да се дефинира функција presmetajIndeks() со чија помош се пресметува индексот
за квалитет за тој месец. Надвор од класите да се напише функција pomalIndeks() која на влез
добива два аргументи кои се покажувачи кон објекти од класа медиум и дава 1 на излез ако
објектот кон кој покажува првиот аргумент има помал индекс на квалитет и 0 обратно (функцијата
треба да работи за било која комбинација објекти од тип телевизија и/или портали). Дополнително,
надвор од класите да се напише функција najmalIndeks() која прими два аргументи: низа од
покажувачи кон медиуми и нивниот број. Функцијата najmalIndeks() треба да ја користи
функцијата pomalIndeks() и да го врати редниот број на медиумот со најмал индекс на квалитет.
 */

#include<iostream>
#include<cstring>

using namespace std;

class Medium{
protected:
	string ime;
	int vraboteni;
	int lazni;
public:
	Medium(string imeF = "",int vraboteniF= 0,int lazniF =0){
		ime = imeF;
		vraboteni = vraboteniF;
		lazni = lazniF;
	}
	virtual float presmetajIndeks(){
		return (5*vraboteni)-lazni;
	}
	virtual ~Medium(){};
	virtual void pechati(){
			cout<<" Ime: "<<ime<<" Broj na vraboteni: "<<vraboteni<<" Broj na lazni vesti: "<<lazni<<endl;
		}
};
class Televizija : public Medium{
private:
	bool profil;
public:
	Televizija(string imeF = "",int vraboteniF= 0,int lazniF =0,bool profilF = false):
	Medium(imeF,vraboteniF,lazniF){
		profil = profilF;
	}
	float presmetajIndeks(){
		float vkupno = Medium::presmetajIndeks();
			if(profil){
				vkupno+=20;
			}
			return vkupno;
		}
	void pechati(){
		Medium::pechati();
		cout<<"Profil: "<<(profil?"Ima":"Nema")<<endl;
	}

};
class Portal : public Medium{
private:
	int posts;
public:
	Portal(string imeF = "",int vraboteniF= 0,int lazniF =0,int postsF =0):
	Medium(imeF,vraboteniF,lazniF){
		posts = postsF;
	}
	float presmetajIndeks(){
		float vkupno = Medium::presmetajIndeks();
		for(int i=0;i<posts;i+=20)
			vkupno+=vkupno*(5/100);

		return vkupno;
		}
	void pechati(){
		Medium::pechati();
		cout<<"Posts: "<<posts<<endl;
		}
};

int pomalIndeks(Medium *prv,Medium *vtor){
	if(prv->presmetajIndeks()<vtor->presmetajIndeks()){
		return 1;
	}
	else{
		return 0;
	}

}
int najmalIndeks(Medium **m,int broj){
int pozicija = 0;
float min = 0.0;
	for(int i =0;i<broj;i++){
		if(pomalIndeks(m[i],m[i+1])){
			if(min>m[i]->presmetajIndeks()){
				pozicija = i;
				min = m[i]->presmetajIndeks();
			}
		}
	}
	return pozicija;
}


int main()
{
Medium *E[4];
Portal G1((char *)"Plusinfo", 8, 20, 150);
Portal G2((char *)"SDK", 10, 2, 100);
Televizija K1((char *)"Alfa", 22, 5, true);
E[0] = &G1; E[1] = &G2; E[2] = &K1;
E[najmalIndeks(E,3)]->pechati();
return 0;
}

