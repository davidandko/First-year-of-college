/*
 * main2.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: David
 */
/*
Вп една кпндураџиска рабптилница рабптата е прганизирана сп ппмпш на ппдвижна лента.
Така, на излез пд машината за прпизвпдствп на ппдлпги за дпбиваат два типа ппдлпги
(десна и лева) кпи машината ги вади сп случаен расппред и ги става на ппчетпкпт на ппдвижната лента.
На крајпт пд лентата стпи еден рабптник кпј има задача да прави парпви (лева и десна ппдлпга)
 и истите да ги пакува. Притпа рабптникпт неспарените ппдлпги ги става една врз друга,
 па кпга ќе дпјде нпва ппдлпга ја гледа најгпрната неспарена ппдлпга и
 прпверува дали фпрмира пар сп нпвата ппдлпга
 (да се смета дека рабптникпт не мпже да земе прпизвплна ппдлпга, туку самп најгпрната).
 Акп фпрмираат пар, се земаат двете и се пакуваат.
 Акп не фпрмираат пар, нпвата ппдлпга се става најгпре вп купчетп сп неспарени ппдлпги.
 Да се напише прпграма кпја ќе гп симулира рабптеоетп вп рабптилницата и ќе
 птпечати пп кплку неспарени ппдлпги пстанале.
 Забелешка: Задачата да се решава самп сп редпви и магацини.
 Ппчетнипт кпд пд задачата се напда вп датптеката PSPZad1T1.cpp.
 Пример: Влез: |{”leva”}, {”desna”}, {”leva”}, {”desna”}, {”desna”}, {”desna”}, {”desna”}, {”leva”}, {”desna”}| Излез пд прпграмата: 3
 */
#include<iostream>
#include<string>

using namespace std;
const int maxG = 30;

struct chevli{
	bool leva;
};
struct red{
	int r;
	int f;
	chevli S[maxG];

	void init(){
		r =-1;
		f=0;
	}
	int isEmpty(){
		return r<0;
	}
	int isFull(){
		return r>=maxG-1;
	}
	void dodadi(chevli v){
		if(isFull()){
			cout<<"Nema mesto!"<<endl;
			return;
		}
		r++;
		S[r] = v;
	}
	chevli izvadi(){
		if(isEmpty()){
			cout<<"Prazen e redot!"<<endl;
			return {};
		}
		chevli pom = S[f];
		for(int i=0;i<r;i++){
			S[i]=S[i+1];
		}
		r--;
		return pom;
	}
	chevli peek(){
				if(isEmpty()){
					cout<<"Prazen red"<<endl;
					return {};
				}
				return S[f];
			}
};

struct magacin{
	int top;
	chevli M[maxG];

	void init(){
		top = -1;
	}
	int isEmpty(){
		return top<=-1;
	}
	int isFull(){
		return top>=maxG-1;
	}
	void dodadi(chevli e){
		if(isFull()){
			cout<<"Nema mesto vo magacinot!"<<endl;
			return;
		}
		top++;
		M[top] = e;
	}
	chevli izvadi(){
		if(isEmpty()){
			cout<<"Magacinot e prazen!"<<endl;
			return {};
		}
		chevli pom = M[top];
		top--;
		return pom;
	}
	chevli peek(){
		if(isEmpty()){
			return {};
		}
		return M[top];
				}
};
void funkcija(red &masina){
	magacin magac;
	magac.init();
	chevli pom;
	int br=0;
	while(!masina.isEmpty()){
		pom = masina.izvadi();
		if(magac.isEmpty()){
			magac.dodadi(pom);
		}else{
			if(pom.leva != magac.peek().leva){
				magac.izvadi();
				br++;
			}
			else{
			magac.dodadi(pom);
			}
		}


	}
	cout<<"Broj na parovi koi gi spariv bate David, poveli kralu moj: "<<br;
}

int main(){
	red redce;
	chevli pomosen;
		int i,brCev;
		redce.init();
		cout<<"Vnesete broj na cevli"<<endl;
		cin>>brCev;
		for(i=0;i<brCev;i++){
			cout<<"Vnesete dali e leva(1) ili desna(0) "<<endl;
			cin>>pomosen.leva;
			redce.dodadi(pomosen);
		}
		funkcija(redce);

}

