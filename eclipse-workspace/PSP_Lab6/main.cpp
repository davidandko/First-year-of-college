/*
 * main.cpp
 *
 *  Created on: Apr 20, 2022
 *      Author: David
 */
/*
 Да се напише функција за работа со двојно поврзана кружна листа, која на влез добива
една пополнета листа и цел број кој одговара на буџетот кој е на располагање. Секој јазол од
листата содржи инфо поле кое од тип структура infoS и во себе има информација за дестинација,
цена на посета на дестинацијата и број на посети. Функцијата треба да ја изминува листата според
предефиниран распоред даден во глобална низа cekoriNaRasp. Пред изминувањето на листа се
креира покажувач кој се поставува на почетниот елемент во листата. Потоа, при изминувањето се
чита вредност од cekoriNaRasp (при првата итерација тоа е почената вредност во cekoriNaRasp) и
покажувачот се поместува во десно во листата доколку отчитаниот број од cekoriNaRasp е
позитивен или во лево во листата ако отчитаниот број од cekoriNaRasp е негативен за онолку
елементи колку е прочитаната вредност. По застанувањето се проверува дали во буџетот има
доволно сретства за посета на таа дестинација. Ако има, бројот на посети на дестинацијата се
зголемува за 1, а буџетот се намалува за сумата потребна за посета на таа дестинација по што се
преминува кон ново читање на следната вредност од cekoriNaRasp и следното поместување на
покажувачот. Доколку нема доволно сретства во буџетот изминувањето на листата завршува.
Изминувањето на листата да се направи во глобална функција proshetaj.
Како дел од програмата да се напишат структури за имплементација на јазол и листа, и
функциите за поддршка на листата: функција за иницијализација, функции додавање и бришење
на елемент на почеток од листата, додавање и бришење на елемент на крај од листата, бришење
на цела листа, печатење на елементите од листата и додавање на јазол после даден јазол
(адресата на јазолот после кој треба да се направи додавањето се добива како прв аргумент на
влез од функцијата заедно со вредноста на инфо полето како втор аргумент).
 */

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int cekoriNaRasp[10] = {4,-3,2,5,-1,5,-2,3,-4,7};
struct infoS {
 string destinacija;
 int cena;
 int brPoseti;
 void init(string dest, int cenav, int brPosetiv){
	 destinacija = dest;
	 cena = cenav;
	 brPoseti = brPosetiv;
 }
};
struct jazol{
	jazol *next;
	jazol *prev;
	infoS info;
};
struct DPKLista{
	jazol *head;
	jazol *tail;
	void init(){
		head = tail = NULL;
	}
	void dodadiPrv(infoS x){
		jazol *nov = new jazol;
		nov->info =x;
		if(head == NULL){
			nov->next = nov->prev = nov;
			head = tail =nov;
			return;
		}
		nov->next = head;
		nov->prev = tail;
		head->prev = nov;
		tail->next = nov;
		head = nov;
	}
	void dodadiPos(infoS x){
		jazol *nov = new jazol;
		nov->info = x;
		if(head == NULL){
			nov->next = nov->prev = nov;
			head = tail = nov;
			return;
		}
		nov->prev = tail;
		nov->next = head;
		tail->next = nov;
		head->prev = nov;
		tail = nov;
	}
	void brisiPrv(){
		if(head == NULL){
			return;
		}
		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *pom = head;
		tail->next = head->next;
		head->next->prev = tail;
		head = head->next;
		delete pom;
	}
	void brisiPos(){
		if(head == NULL){
			return;
		}
		if(head == tail){
			delete head;
			head = tail = NULL;
			return;
		}
		jazol *pom = tail;
		tail->prev->next = head;
		head->prev = tail->prev;
		tail = tail->prev;
		delete pom;
	}
	void pechati(){
		if(head == NULL){
			return;
		}
		jazol *dvizi = head;
		while(dvizi != tail){
			cout<<"|"<<dvizi->info.destinacija<<", "<<dvizi->info.cena<<", "<<dvizi->info.brPoseti<<"|<->";
			dvizi =  dvizi -> next;
		}
		cout<<"|"<<dvizi->info.destinacija<<", "<<dvizi->info.cena<<", "<<dvizi->info.brPoseti<<"|";
	}
	void brisiLista(){
		while(head!=NULL){
			brisiPos();

		}
	}
	void dodadiPosleJazol(jazol *node,infoS info){
		jazol *nov = new jazol;
		nov->info = info;
		nov->next = node->next;
		nov->prev = node;
		node->next->prev = nov;
		node->next = nov;
	}

};

void proshetaj(DPKLista &l,int budzet){
	jazol *dvizi = l.head;
	for(int i = 0;i<10;i++){
		if(cekoriNaRasp[i] > 0){
			for(int j = 0; j<cekoriNaRasp[i];j++){
				dvizi = dvizi->next;
			}
			if(budzet > dvizi->info.cena){
				dvizi->info.brPoseti++;
				budzet -= dvizi->info.cena;
			}
			else{
				break;
			}
		}
		if(cekoriNaRasp[i] < 0){
			for(int j = 0;j<abs(cekoriNaRasp[i]);j++){
				dvizi = dvizi->prev;
			}
			if(budzet>dvizi->info.cena){
				dvizi->info.brPoseti++;
				budzet -= dvizi->info.cena;
			}
			else{
				break;
			}
		}
	}


}

int main(){
 DPKLista L1;
 string destinacii[6] = {"Paris", "Lisabon", "Praga", "Sank Peterzburg", "Rim", "Barcelona"};
 int ceni[6] = {10000, 30000, 9000, 25000, 12000, 15000};
 infoS x;
 L1.init();
 x.init(destinacii[0], ceni[0], 0);
 L1.dodadiPrv(x);
 for(int i = 1; i< 6;i++){
 x.init(destinacii[i], ceni[i], 0);
 L1.dodadiPos(x);
 }
 proshetaj(L1,100000);
 L1.pechati();
 L1.brisiLista();
 return 0;
}







