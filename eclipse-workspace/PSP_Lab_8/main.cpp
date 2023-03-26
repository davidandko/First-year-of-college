/*
 * main.cpp
 *
 *  Created on: May 4, 2022
 *      Author: David
 */
/*
Да се напише програма за обработка на текст. За таа намена, да се креира класа Rechenica во која
се чуваат податоци за нејзините елементи: зборовите и интерпункциските знаци во реченицата
(динамички алоцирана низа од стрингови) и број на елементи во реченицата. За класата Rechenica
да се напише:
- Default конструктор кој ќе креира реченица со два елементи “Zdravo” и “!”.
- Copy конструктор и конструктор со 2 аргументи.
- Деструктор
- Функција pechati() која ја печати реченицата
- метод dodadiElement(string m) кој ќе го додаде елемент (збор или интерпункциски знак) на крај
од реченицата.
- метод brishiElement(int poz) кој ќе го избрише елементот на позиција poz
Да се напише main во кој ќе се тестира задачата. Во main функцијата прво да се креира низа од
елементи на реченицата “Mnogu sakam da ucham PSP!” (одвојувањето на елементите може да се
направи рачно). Потоа со низата од елементи да се иницијализира објект од класа Rechenica и да се
испечати реченицата. Потоа на објектот да му се додадат елементите од следната подреченица “za
copy konstruktor.”. Потоа од реченицата да се избрише елементот на позиција 5 и да се испечати
реченицата.
*/

#include<iostream>
#include<cstring>

using namespace std;


class Rechenica{
private:
    string *rechenica;
    int broj;
public:
    Rechenica(){
        rechenica = new string[2];
        rechenica[0] = "Zdravo";
        rechenica[1] = "!";
        broj = 2;
    }
    Rechenica(string *rechenicaF, int brojF){
        rechenica = new string[brojF+1];
        for(int i = 0;i<brojF;i++){
        	rechenica[i] = rechenicaF[i];
        }
        broj = brojF;
    }
    Rechenica(const Rechenica &rec){
         rechenica = new string[rec.broj+1];
         for(int i = 0;i<rec.broj;i++){
        	 rechenica[i] = rec.rechenica[i];
         }
         this->broj = rec.broj;
    }
    void pechati(){
        for(int i = 0;i<broj;i++){
            cout<<rechenica[i];
        }
        cout<<endl;
    }
    ~Rechenica(){
    	delete [] rechenica;
    }
    void dodadiElement(string m){
		string *rech = new string[broj+1];
		for(int i=0;i<broj;i++){
			rech[i] = rechenica[i];
		}
		delete[] rechenica;
		rech[broj++] = m;
		rechenica = rech;
	}
    void brisiElement(int pozicija){

		string *rech = new string[broj-1];
		for(int i = 0;i<pozicija-1;i++){
			rech[i] = rechenica[i];
		}
        for(int i=pozicija-1;i<broj-1;i++){
            rech[i] = rechenica[i+1];
        }
		broj--;
		delete[] rechenica;
		rechenica = rech;
	}
};

int main(){
    string niza[5] = {"Mnogu ","sakam ","da ","ucham ","PSP!"};
    string podrec[3] = {" za ","copy ","konstruktor."};

    Rechenica r(niza,5);

    r.pechati();
    for(int i = 0;i<3;i++){
    	r.dodadiElement(podrec[i]);
    }
    r.pechati();
    r.brisiElement(5);
    r.pechati();

    return 0;
}



