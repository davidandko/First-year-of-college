/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
 * Да се креира хиерархија на класи за водење евиденција за заработка од филмови за едно
студио. За секој филм е познат насловот, бројот на гледачи кои го гледале на кино и просечната
цена на картата. Почетната заработка за филмовите се добива кога бројот на гледачи ќе се помножи
по просечната цена на картата. Филмовите може да бидат акции или комедии.
За акциите се чува и податок за бројот на опасни сцени. Поради трошоците за изработка на
опасните сцени, заработката на акциите се намалува за 1% за секоја опасна сцена.
За комедиите се чува и податок за тоа дали главниот актер има ексклузивен договор за
комедијата. Доколку има таков договор, заработката на комедијата се намалува за 15%.
Во секоја од класите да се дефинираат конструктори со подразбрани (default) вредности и
деструктори. За секоја класа да се дефинира функција presmetajZarabotka() со чија помош се
пресметува заработката на соодветниот филм (при пресметката во изведените класи да се повика
функцијата presmetajZarabotka() за основната класа). Надвор од класите да се напише функција
najgolemaZarabotka() која прими два аргументи: низа од покажувачи кон филмови и нивниот
број. Функцијата najgolemaZarabotka() треба да го врати редниот број на филмот со најголема
заработка. Дополнително, надвор од класите да се напише и функција vkupnaZarabotka() која
прими два аргументи: низа од покажувачи кон филмови и нивниот број, а на излез ја враќа
вкупната заработка од сите филмови (независно од типот на филмовите).
Забелешка: Главната програма е дадена во продолжение.
 */
#include<iostream>

using namespace std;

class Film{
protected:
	string naslov;
	int br;
	float cena;
public:
	Film(string naslovF,int brF,float cenaF){
		naslov = naslovF;
		br = brF;
		cena = cenaF;
	}
	virtual ~Film(){};
	virtual float presmetajZarabotka(){
		return br*cena;
	}

};

class Akcija : public Film{
protected:
	int bropasni;
public:
	Akcija(string naslovF,int brF,float cenaF,int bropasniF):
		Film(naslovF,brF,cenaF){
		bropasni = bropasniF;
	}
	float presmetajZarabotka(){
		float vkupno = Film::presmetajZarabotka();
		return vkupno*=(1-bropasni/100);
	}
};
class Komedija : public Film{
protected:
	bool dogovor;
public:
	Komedija(string naslovF,int brF,float cenaF,bool dogovorF):
		Film(naslovF,brF,cenaF){
		dogovor = dogovorF;
	}
	float presmetajZarabotka(){
		float vkupno = Film::presmetajZarabotka();
		if(dogovor){
			vkupno*=0.85;
		}
		return vkupno;
	}
};
int najgolemaZarabotka(Film **f,int broj){
	float max = 0.0;
	int pozicija = 0;
	for(int i = 0;i<broj;i++){
		if(f[i]->presmetajZarabotka()>max){
			max = f[i]->presmetajZarabotka();
			pozicija =i;
		}
	}
	return pozicija;
}
float vkupnaZarabotka(Film **f,int broj){
	float vkupno = 0.0;
	for(int i = 0;i<broj;i++){
		vkupno+= f[i]->presmetajZarabotka();
	}
	return vkupno;
}


int main()
{
Film *E[4];
Komedija G1((char *)"Hangover", 100000, 5, false);
Komedija G2((char *)"Borat", 90000, 5, true);
Akcija K1((char *)"Mission impossible", 500000, 6, 20);
Akcija K2((char *)"Avengers", 3500000, 4, 30);
E[0] = &G1; E[1] = &G2; E[2] = &K1; E[3] = &K2;
cout<<"Najgolema zarabotka ima filmot so indeks "<<najgolemaZarabotka(E,4)<<endl;
cout<<"Vkupnata zarabotka na studioto iznesuva "<<vkupnaZarabotka(E,4)<<endl;
return 0;
}
