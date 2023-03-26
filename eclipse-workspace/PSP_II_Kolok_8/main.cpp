/*За секој човек се знае името, годината на раѓање и адресата на живеење. Вредностите на овие
атрибути единствено може да се внесат со функцијата vnesi() и затоа предефинирано се поставени на нула
(за број) и прзен стринг (за стринг).
Дете е човек за кого дополнително се чуваат податоци за името на училиштето и одделението кое го
посетува (дозволени вредности се помеѓу 1 и 9). Вреднстите и за атрибутите и на детето се внесуваат од
тастатура со функција vnesi(), а предефинирано се поставени на нула (за број) и прзен стринг (за стринг).
Вработениот е човек за кого дополнително се чуваат податоци за фирмата во која работи и и бројот на
години стаж. Вреднстите и за атрибутите и на вработениот се внесуваат од тастатура со функција vnesi(), а
предефинирано се поставени на нула (за број) и прзен стринг (за стринг).

 Функцијата vnesi() треба за детето да бара информации за името, годината на раѓање, адресата,
училиштето и одделението, додека за вработениот треба да бара податоци за името, годината на раѓање,
адресата, фирмата и годините стаж.

 Да се напише функција pechati() која за детето ги печати информациите за името, годината на
раѓање, адресата, училиштето и одделението, додека за вработениот ги печати информациите за името,
годината на раѓање, адресата, фирмата и годините стаж.

 Во основната класа да се преоптовари операторот > кој треба да провери дали човекот кој ја
повикува функцијата(операторот) е постар од човекот кој се пренесува како аргумент.

Да се креира класа Semejstvo која е составена од низа од луѓе (и деца и вработени), а познат е и бројот на
членови во семејството. Во класата да се напише функција sortiraj() која ги сортира членовите во семејството
во растечки редослед според бројот на години и ја печати сортираната низа.
Главната програма е дадена на другата страна.*/

#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>

using namespace std;

class Covek{
protected:
	string ime;
	int godina;
	string adresa;
public:
	Covek(){
		ime="";
		godina=0;
		adresa="";
	}

	Covek(string imeF,int godinaF,string adresaF){
				ime=imeF;
				godina = godinaF;
				adresa = adresaF;
	}
	virtual void vnesi(string imev="",int godinav=0,string adresav="",string part4="",int part5=0){
		//Covek(imev,godinav,adresav);
		ime=imev;
		godina = godinav;
		adresa = adresav;
	}

	 virtual ~Covek(){}

	virtual void pechati(){
		cout<<"Ime: "<<ime<<endl;
		cout<<"Godina na ragjanje: "<<godina<<endl;
		cout<<"Adresa na ziveenje: "<<adresa<<endl;
	}

	bool operator>(Covek &C){
		return (this->godina < C.godina);
	}

	int getGodina(){
		return godina;
	}

	friend class Semejstvo;


};

class Dete:public Covek{
private:
	string uciliste;
	int odd;
public:
	void vnesi(string imev="",int godinav=0,string adresav="",string part4="",int part5=0){
		//Covek::vnesi(imev, godinav, adresav);
		ime=imev;
		godina=godinav;
		adresa=adresav;
		uciliste=part4;
		odd=part5;
	}

	void pechati(){

		Covek::pechati();
		cout<<"Uciliste: "<<uciliste<<endl;
		cout<<"Oddelenie: "<<odd<<endl;

	}

	friend class Semejstvo;
};

class Vraboten: public Covek{
private:
	string firma;
	int stazh;
public:
	void vnesi(string imev="",int godinav=0,string adresav="",string part4="",int part5=0){
		//Covek::vnesi(imev, godinav, adresav);
		ime=imev;
		godina=godinav;
		adresa=adresav;
		firma=part4;
		stazh=part5;
	}

	void pechati(){
		Covek::pechati();
		cout<<"Firma: "<<firma<<endl;
		cout<<"Godini stazh: "<<stazh<<endl;
	}

	friend class Semejstvo;

};

class Semejstvo{
private:
	int brClenovi;
	Covek **clenovi;
public:
	Semejstvo(Covek **clenoviv=NULL,int brClenoviv=0){
		brClenovi=brClenoviv;
		clenovi=new Covek*[brClenovi];
		for(int i=0;i<brClenovi;i++){
			Dete *pom=dynamic_cast<Dete *>(clenoviv[i]); // proveruva od koj tip e pokazuvacot,dokolku vrati 1 ili bilo koja vrednost osven 0 toj e od zadadeniot tip
			if(pom!=0){
				clenovi[i]=new Dete;
				clenovi[i]->vnesi(pom->ime, pom->godina, pom->adresa, pom->uciliste, pom->odd);
			}
			//clenovi[i]=*(clenoviv[i]);
			Vraboten *pom1=dynamic_cast<Vraboten *>(clenoviv[i]);
			if(pom1!=0){
				clenovi[i]=new Vraboten;
				clenovi[i]->vnesi(pom1->ime, pom1->godina, pom1->adresa, pom1->firma, pom1->stazh);
			}
			if(pom1==0 && pom==0){
				clenovi[i]=new Covek;
				clenovi[i]->vnesi(clenoviv[i]->ime, clenoviv[i]->godina, clenoviv[i]->adresa);
			}
		}
	}

	void sortiraj(){
		for(int i=0;i<brClenovi;i++){
			for(int j=i+1;j<brClenovi;j++){
				if(clenovi[i]->getGodina() < clenovi[j]->getGodina()){
					Covek *temp=clenovi[i];
					clenovi[i]=clenovi[j];
					clenovi[j]=temp;
				}
			}
		}
		for(int i=0;i<brClenovi;i++){
			clenovi[i]->pechati();
		}
	}
};

int main()
{
Covek *lugje[4];
lugje[0] = new Dete();
lugje[0]->vnesi("Toni", 2007, "Adresa 1", "Uchilishte 1", 3);
lugje[1] = new Vraboten();
lugje[1]->vnesi("Ana", 1980, "Adresa 1", "Firma 1", 10);
lugje[2] = new Dete();
lugje[2]->vnesi("Marija", 2005, "Adresa 1", "Uchilishte 1", 5);
lugje[3] = new Vraboten ();
lugje[3]->vnesi("Mitko", 1980, "Adresa 1", "Firma 2", 12);
Semejstvo s(lugje, 4);
s.sortiraj();

return 0;
}




