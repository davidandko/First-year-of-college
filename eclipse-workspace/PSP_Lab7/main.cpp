/*
 * main.cpp
 *
 *  Created on: Apr 27, 2022
 *      Author: David
 */
/*
 На универзитетот потребна му е програма со која ќе се води евиденција за основните податоци
на факултетите и студентите.
За секој студент се чуваат информации за име, презиме, индекс, број на положени предмети и
процент на совладаност. Бројот на положени предмети не смее да биде негативна вредност и
индексот треба да биде валиден (од облик: xxx/20xx, односно на петта позиција броејќи од крај да
има коса црта и да има број после цртата – барем на позиција шест). Бидејќи до крајот на
факултетот има вкупно 40 испити, за студентот да се напише функција за пресметка на процентот
на положените испити во однос на вкупниот број испити.
За факултетот се знае името, бројот на студенти и низата од студенти (има максимум 100
студенти).
Да се напишат класите student и fakultet. Притоа, доколку се внесат податоци кои не ги
задоволуваат наведените ограничувања, бројот на положени испити се поставува на 0, процентот
на 0, а името и презимето се празни.
Да се креира default конструктор, конструктор со параметри и функција за печатење (при
печатењето на податоците за факултетот, да се користи функцијата за печатење на податоците на
студентите).
Да се напише главна функција во која корисникот ќе внесе податоци за 5 студенти (процентот
на совладаност да се постави на 0) и име на факултетот. Потоа со тие податоци да се иницијализира
објект од класа fakultet. На крај да се испечатат податоците за факултетот.
Забелешка: Вредноста за процентот на совладаност не треба да се внесува. Таа се пресметува
според другите внесени вредности.
 */
#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
class student{
private:
	string ime;
	string prezime;
	char indeks[10];
	int brPol;
	float procent;
public:
	student(){
		ime = '\0';
		prezime = '\0';
		indeks[0] = '\0';
		brPol = 0;
		procent = 0;
	}
	student(string imeF,string prezimeF,char indeksF[],int brPolF){
		ime = imeF;
		prezime = prezimeF;
			if(indeksF[4] == '/'){
				if(isdigit(indeksF[5])){
						for(unsigned int i = 0;i<strlen(indeksF)-1;i++){
							indeks[i] = indeksF[i];
						}
				}
			}
		if(brPolF >= 0 && brPolF <=40){
			brPol = brPolF;
		}
		else{
			brPol = 0;
		}
		procent = float(brPol/40)*100
	}

	void setIme(string imeF){
			ime = imeF;
		}
	void setPrezime(string prezimeF){
			prezime = prezimeF;
		}
	void setIndeks(char *indeksF){
				strcpy(indeks,indeksF);
	}
	void setBrpol(int brPolF){
		brPol = brPolF;
	}
	void pechati(){

		cout<<"Ime: "<<ime<<"| Prezime: "<<prezime<<"| Indeks: ";
		for(unsigned int l = 0;l<strlen(indeks)-1;l++){
			cout<<indeks[l];
		}
		cout<<"| Broj na polozeni predmeti: "<<brPol<<"| Procent na polozeni:"<<procent<<"%"<<endl;
		cout<<endl;
		}

};
class fakultet{
private:
	string ime;
	int brStudenti;
	student studenti[100];
public:
	int i = 0;
	fakultet(){
		ime = '\0';
		brStudenti = 0;
	}

	fakultet(string imeF,int brStudentiF,student studentF[]){
		ime = imeF;
		if(brStudentiF >= 0){
			brStudenti = brStudentiF;
		}
		else{
			brStudenti = 0;
		}
		for(int j = 0;j<brStudenti;j++){
			studenti[j] = studentF[j];
		}
	}
	void setIme(string imeF){
		ime = imeF;
	}
	void setbrStud(int brStud){
		brStudenti = brStud;
	}
	void setStudent(student studentiF){
		studenti[i] = studentiF;
		i++;
	}
	void pechati(){
		cout<<"Ime na fakultet: "<<ime<<endl;
		cout<<"Podatoci na studenti: "<<endl;
		for(int i = 0;i<brStudenti;i++){
			studenti[i].pechati();
		}
	}
};
int main(){
	student studenti[5];
	string imeF;
	string imeStud,prezimeStud;
	fakultet fax;
	char indeks[10];
	int brPol;


	cout<<"Vnesete ime na fakultetot: "<<endl;
	cin>>imeF;
	for(int i = 0;i<5;i++){
		cout<<"Vnesi ime na student: "<<endl;
		cin>>imeStud;
		cout<<"Vnesi prezime na student: "<<endl;
		cin>>prezimeStud;
		cout<<"Vnesi indeks so format xxx/20xx: "<<endl;
		cin>>indeks;
		studenti[i].setIndeks(indeks);
		cout<<"Vnesi broj na polozeni predmeti: "<<endl;
		cin>>brPol;
		studenti[i] = student(imeStud, prezimeStud,indeks,brPol);

	}
	fax = fakultet(imeF,5,studenti);

	fax.pechati();
	return 0;
}
