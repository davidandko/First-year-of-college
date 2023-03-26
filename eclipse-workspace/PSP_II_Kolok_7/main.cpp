/*
 * main.cpp
 *
 *  Created on: May 24, 2022
 *      Author: David
 */
/* Vtor kolok 2018 zadaca 2
Да се креира хиерархија на класи за водење на евиденција за кујнски елементи во еден салон за кујни. За
секој кујнски елемент е познато името на компанијата која го произведува, материјалот од кој е изработен
(медијапан или иверка), месечниот трошок за чување на производот и бројот на месеци од кога кујнскиот
елемент e во салонот. Почетната цена на кујнскиот елемент е 4000 денари ако е од медијапан и 2000 денари
ако е од иверка, а се зголемува за месечниот трошок за чување за секој месец поминат во салонот. Кујнските
елементи може да бидат кујнски маси или висечки елементи.
За кујнските маси дополнително се чува податок за површината (во квадратни метри), бројот на фиоки
(максимум 10) и низа со зафатнината на секоја од фиоките (во метри кубни). Цената на кујнските маси се
одредува со тоа што цената на кујнски елемент се зголемува за 25% за секој квадратен метар површина и за
20% за секој кубен метар зафатнина на фиоките.
За висечките елементи дополнително се чува информација за бројот на вратички и за бројот на полици.
Цената на висечкиот елемент се добива со тоа што цената на кујнски елемент се зголемува за 500 денари за
секоја вратичка и 2000 денари за секоја полица.
Во секоја од класите да се дефинираат потребните конструктори и деструктори. Да се дефинираат и методи
за печатење на сите информации за соодветните класи. Надвор од класите да се напише функција najevtin()
која ќе прими низа од покажувачи кон кујнски елементи и нивниот број и ќе ги испечати податоците за
најевтиниот (независно дали е кујнска маса и висечки елемент) заедно со неговата цена. Да се напише и
уште една глобална функција vkcena() која ќе прими низа од покажувачи кон кујнски елементи и нивниот
број, а ќе ја врати вкупната вредност на сите кујнски елементи
 */

#include<iostream>
#include<cstring>
#include<stdlib.h>
enum materijal{iverka,medijapan};

using namespace std;


string imeMat[2]={"Iverka","Medijapan"};


class KE{
protected:
	string ime;
	materijal m;
	int trosok;
	int meseci;
public:
	KE(string imeF = "",materijal mF = iverka,int trosokF = 0,int meseciF=0){
		ime = imeF;
		m = mF;
		trosok = trosokF;
		meseci = meseciF;
	}
	virtual ~KE(){
	}
	virtual int cena(){
		int cena;
		if(m == medijapan){
			cena = 4000;
		}
		else{
			cena = 2000;
		}
		return cena+(trosok*meseci);
	}
	virtual void pechati(){
		cout<<"Ime: "<<ime<<" Materijal: "<<imeMat[m]<<" Trosok: "<<trosok<<" Meseci: "<<meseci<<endl;
	}
};
class KM : public KE{
private:
	int povrsina;
	int *zafatnina;
	int fioki;
public:

	KM(string imeF = "",materijal mF = iverka,int trosokF = 0,int meseciF=0,int povrsinaF = 0,int *zafatninaF = 0,int fiokiF = 0):
		KE(imeF,mF,trosokF,meseciF){
		povrsina = povrsinaF;
		if(fioki<=10){
			fioki = fiokiF;
		}else{
			fioki = 0;
		}
		zafatnina = new int[fioki];
		for(int i = 0;i<fioki;i++){
			zafatnina[i] = zafatninaF[i];
		}
	}
	int cena(){
		int vkupno = KE::cena();
		for(int i = 0;i<fioki;i++){
			vkupno+=KE::cena()*(zafatnina[i]/5);
		}
		vkupno +=KE::cena()*(povrsina/4);
		return vkupno;
	}
	void pechati(){
		KE::pechati();
		cout<<"Povrsina: "<<povrsina<<" Broj na fioki: "<<fioki<<" Zafatnina na fiokite"<<endl;
		for(int i =0;i<fioki;i++){
			cout<<zafatnina[i]<<" ";
		}
		cout<<endl;
	}
};
class VE : public KE{
private:
	int vrati;
	int polici;
public:
	VE(string imeF = "",materijal mF = iverka,int trosokF = 0,int meseciF=0,int vratiF = 0,int policiF =0):
			KE(imeF,mF,trosokF,meseciF){
		vrati = vratiF;
		polici = policiF;
	}
	int cena(){
		int vkupno = KE::cena();
		vkupno += (500*vrati)+(2000*polici);
		return vkupno;
	}
	void pechati(){
		KE::pechati();
		cout<<"Vrati: "<<vrati<<" "<<" Polici: "<<polici<<endl;
	}
};
void najevtin(KE **e,int br){
	int min=e[0]->cena();
	int j=0;
	for(int i = 1;i<br;i++){
		if(min>e[i]->cena()){
			min = e[i]->cena();
			j = i;
		}
	}
	cout<<"Najevtin: "<<endl;
	e[j]->pechati();
}
int vkcena(KE **e,int br){
		int vk=0;
		for(int i = 0;i<br;i++){
		vk+=e[i]->cena();
	}
		return vk;
}
int main(){

	int zaf[3] = {15,20,25};
	KE k1("David",iverka,10000,3);
	KE k2("Krsitina",medijapan,20000,4);
	k2.pechati();
	KE *k3[3];
	k3[0] = &k1;
	k3[1] = &k2;
	KM k("Zlatan",medijapan,2000000,2,10,zaf,3);
	k3[2] = &k;
	k.pechati();
	najevtin(k3,3);
	cout<<"Vkupna cena: "<<vkcena(k3,2);


	return 0;
}
