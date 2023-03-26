/*
 * main.cpp
 *
 *  Created on: May 27, 2022
 *      Author: David
 */
/*
 *Да се напише класа Prostor од која ќе бидат изведени класи StanbenProstor и
MaloprodazenProstor. Во класата Prostor се чува локацијата (како динамичка низа од знаци),
квадратурата на просторот и основната цена по метар квадратен. За класата StanbenProstor се чува
информација за бројот на паркинг места кои сопственикот сака да ги купи. За класата
MaloprodazenProstor се чува информација за бројот на брендови кои ги носи групацијата што го
изнајмува просторот.
За секоја од класите да се напише функција presmetaj_cena() која ја пресметува цената за
соодветниот простор. Вкупната основна цена на простор се пресметува како производ од
квадратурата на просторот и основната цена по метар квадратен. Цената на станбен простор се
пресметува на тој начин што на вкупната основна цена се додаваат 5000 за секое купено паркинг
место. Цената на малопродажен простор се пресметува на тој начин што вкупната основната цена
се намалува за онолку проценти колку што групацијата има брендови.
Дополнително, за класите да се напише функција pechati() која ги печати податоците за објект
од соодветната класа, да се напишат конструктори со default параметри, copy конструктор и да се
преоптовари операторот = за доделување.
Надвор од класите да се напише функција која како аргументи прима два парамтери: низа од
покажувачи кон простори независни од типот на просторот и бројот на простори, а истата го наоѓа
најефтиниот простор и за него ги печати сите информации.
Да се состави и главна функција во која треба да се тестира работата на функцијата.
 */

#include<iostream>
#include<cstring>

using namespace std;


class Prostor{
protected:
	char *lokacija;
	int kvadrati;
	int cena;
public:
	Prostor(char*lokacijaF = '\0',int kvadratiF = 0,int cenaF = 0){
		lokacija = new char[strlen(lokacijaF)+1];
		strcpy(lokacija,lokacijaF);
		kvadrati = kvadratiF;
		cena = cenaF;
	}
	Prostor(const Prostor &p){
		lokacija = new char[strlen(p.lokacija)+1];
		strcpy(lokacija,p.lokacija);
		kvadrati = p.kvadrati;
		cena = p.cena;
	}
	Prostor &operator=(Prostor &p){
		if(this==&p){
			return *this;
		}
		else{
			delete [] lokacija;
			lokacija = new char[strlen(p.lokacija)+1];
			strcpy(lokacija,p.lokacija);
			kvadrati = p.kvadrati;
			cena = p.cena;
			return *this;
		}
	}
	virtual ~Prostor(){
		delete [] lokacija;
	}
	virtual int presmetaj_cena(){
		return kvadrati*cena;
	}
	virtual void pechati(){
		cout<<"Lokacija: "<<lokacija<<" Kvadrati: "<<kvadrati<<" Cena: "<<cena<<endl;
	}

};
class MaloprodazenProstor : public Prostor{
private:
	int brB;
public:
	MaloprodazenProstor(char*lokacijaF = '\0',int kvadratiF = 0,int cenaF = 0,int brBF = 0):
		Prostor(lokacijaF ,kvadratiF,cenaF){
		brB = brBF;
	}
	MaloprodazenProstor(const MaloprodazenProstor &s): Prostor(s){
			brB = s.brB;
		}
	int presmetaj_cena(){
		int vkupno = Prostor::presmetaj_cena();
		return vkupno*=(1-brB/100);
	}
	void pechati(){
			Prostor::pechati();
			cout<<"Broj na brendovi: "<<brB<<endl;
		}
	MaloprodazenProstor &operator=(MaloprodazenProstor &s){
			Prostor::operator =(s);
			brB = s.brB;
			return *this;
		}
};

class StanbenProstor : public Prostor{
private:
	int brP;
public:
	StanbenProstor(char*lokacijaF = '\0',int kvadratiF = 0,int cenaF = 0,int brPF = 0) :
	Prostor(lokacijaF,kvadratiF,cenaF){
		brP = brPF;
	}
	StanbenProstor(const StanbenProstor &s): Prostor(s){
		brP = s.brP;
	}
	StanbenProstor &operator=(StanbenProstor &s){
		Prostor::operator =(s);
		brP = s.brP;
		return *this;
	}

	void pechati(){
		Prostor::pechati();
		cout<<"Broj na parking mesta: "<<brP<<endl;
	}
	float presmetaj_cena(){
	    float vkupno = (cena*kvadrati)+brP*5000;
	    return vkupno;
	}
};
void najevtin(Prostor **niza,int broj){
	int min = niza[0]->presmetaj_cena();
	int pozicija=0;
	for(int i = 0;i<broj;i++){
		if(niza[i]->presmetaj_cena()<min){
			min = niza[i]->presmetaj_cena();
			pozicija = i;
		}
	}
	cout<<"Najevtin e prostorot: "<<endl;
	niza[pozicija]->pechati();
}

int main(){
	Prostor p1();
	Prostor **p;
	*p= new Prostor("Karposh",62,1200);
	*p = new Prostor("Centar",70,1300);
	*p = new Prostor("KV",90,1000);
	*p = new MaloprodazenProstor("David",21,100,4);
	*p = new StanbenProstor("Kristina",15,50,3);


	najevtin(p,5);

	return 0;
}
