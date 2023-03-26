/*
 * main.cpp
 *
 *  Created on: May 18, 2022
 *      Author: David
 */
/*
Да се напише класа Prostor од која ќе бидат изведени класи StanbenProstor и
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
    float kvadrati;
    float cena;
public:
    Prostor(char *lokacijav= "",float kvadrativ = 0.0,float cenav = 0.0){
        lokacija = new char[strlen(lokacijav)+1];
        strcpy(lokacija,lokacijav);
        kvadrati = kvadrativ;
        cena = cenav;
    }
    Prostor(const Prostor &s){
        lokacija = new char[strlen(s.lokacija)+1];
        strcpy(lokacija,s.lokacija);
        cena = s.cena;
        kvadrati = s.kvadrati;
    }
   	Prostor &operator=(Prostor &s){
        if(this == &s){
            return *this;
        }
        else{
            delete [] lokacija;
            lokacija = new char[strlen(s.lokacija)+1];
            strcpy(lokacija,s.lokacija);
            cena = s.cena;
            kvadrati = s.kvadrati;
        }
        return *this;
    }
   	virtual void pechati(){
        cout<<"Ime na prostorot: "<<lokacija<<endl;
        cout<<"Cena po kvadrat: "<<cena<<endl;
        cout<<"Broj na kvadrati vo prostorot: "<<kvadrati<<endl;
    }
   	virtual float presmetaj_cena(){
   		return (cena*kvadrati);
   	}
   	virtual ~Prostor(){
   		delete [] lokacija;
   	}

};

class StanbenProstor : public Prostor{
private:
    int parking;
public:
    StanbenProstor(char *lokacijav ="",float kvadrativ=0.0,float cenav=0,int parkingv = 0) : Prostor(lokacijav,kvadrativ,cenav){
        parking = parkingv;
    }
    StanbenProstor &operator=(StanbenProstor &d){
    		if(this==&d){
    			return *this;
    		}else{
    			Prostor::operator=(d);
    			parking = d.parking;
    		}
    		return *this;
    	}


    void pechati(){
    	Prostor::pechati();
    	cout<<"Broj na parking mesta: "<<parking<<endl;
    }
    float presmetaj_cena(){
    	float vkupno = (cena*kvadrati)+parking*5000;
       	return vkupno;
    }
};


class MaloprodazenProstor : public Prostor{
private:
    int brendovi;
public:
    MaloprodazenProstor(char *lokacijav ="",float kvadrativ=0.0,float cenav=0,int brendoviv =0) : Prostor(lokacijav,kvadrativ,cenav){
        brendovi = brendoviv;
    }
    MaloprodazenProstor &operator=(MaloprodazenProstor &s){
        if(this == &s){
            return *this;
        }
        else{
        	Prostor::operator=(s);
        	brendovi = s.brendovi;
        }
        return *this;
    }
    float presmetaj_cena(){
    	float vkupno = (cena*kvadrati)-((1/100)*brendovi);
    	return vkupno;
    }

    void pechati(){
    	Prostor::pechati();
    	cout<<"Broj na brendovi vo prostorot: "<<brendovi<<endl;
    }
};
void najevtinProstor(Prostor *p[],int broj){
	int min = p[0]->presmetaj_cena();
	int poz = 0;
	for(int i=0;i<broj;i++){
		if(p[i]->presmetaj_cena()<min){
			min = p[i]->presmetaj_cena();
			poz = i;
		}
	}
	cout<<"Najevtin e prostorot so podatoci: "<<endl;
	p[poz]->pechati();
}

int main()
{
    Prostor *niza[20];
    StanbenProstor m1("Mida",100,1600,2),m2("Taftalidze 1",60,1400,1);
    MaloprodazenProstor p1("Tinex",200,1000,43),p2("Granap",150,950,25);
    niza[0]=&m1;
    niza[1]=&p1;
    niza[2]=&p2;
    //p2=p1; // go komentirav za da go probam presmetaj_cena
    p2.pechati();
    m1.pechati();
    m2.pechati();
    m2 = m1;
    m2.pechati();
    cout<<endl;
    cout<<endl;

    najevtinProstor(niza,3);

    cout<<endl;
    cout<<"Presmetana cena na stanbeniot prostor:"<<m1.presmetaj_cena()<<endl;
    cout<<"Presmetana cena na stanbeniot prostor:"<<m2.presmetaj_cena()<<endl;
    cout<<endl;
    cout<<"Presmetana cena na maloprodazen prostor: "<<p1.presmetaj_cena()<<endl;
    cout<<"Presmetana cena na maloprodazen prostor: "<<p2.presmetaj_cena()<<endl;;
    return 0;
}
