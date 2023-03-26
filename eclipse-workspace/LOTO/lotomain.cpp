/*
 * lotomain.cpp
 *
 *  Created on: Aug 8, 2022
 *      Author: David
 */
#include<iostream>

using namespace std;



int main(){
	int l1[3][7]={{4,5,7,9,16,20,24},{2,5,15,19,31,33,37},{6,3,2,5,24,15,33}};

	int eden=0,dva=0,tri=0,cetiri=0,pet=0,sest=0,sedum=0,osum=0,devet=0,deset=0,edinaeset=0,dvanaeset=0,trinaeset=0,cetirinaeset=0,petnaeset=0,sestnaeset=0,sedumnaeset=0,osumnaeset=0,devetnaeset=0
		,dvaeset=0,dvaesetieden=0,dvaesetidva=0,dvaesetitri=0,dvaeseticetiri=0,dvaesetipet=0,dvaesetisest=0,dvaesetisedum=0,dvaesetiosum=0,dvaesetidevet=0,trieset=0,triesetieden=0,triesetidva=0,triesetitri=0,
		trieseticetiri=0,triesetipet=0, triesetisest=0,triesetisedum=0;


	for(int i=0;i<3;i++){
		for(int j=0;j<7;j++){
			switch(l1[i][j])
			{
			case 1: eden++;
			cout<<"1 vo "<<i+1<<" kolo"<<endl;
			break;
			case 2: dva++;
			cout<<"2 vo "<<i+1<<" kolo"<<endl;
			break;
			case 3: tri++;
			cout<<"3 vo "<<i+1<<" kolo"<<endl;
			break;
			case 4: cetiri++;
			cout<<"4 vo "<<i+1<<" kolo"<<endl;
			break;
			case 5: pet++;
			cout<<"5 vo "<<i+1<<" kolo"<<endl;
			break;
			case 6: sest++;
			cout<<"6 vo "<<i+1<<" kolo"<<endl;
			break;
			case 7: sedum++;
			cout<<"7 vo "<<i+1<<" kolo"<<endl;
			break;
			case 8: osum++;
			cout<<"8 vo "<<i+1<<" kolo"<<endl;
			break;
			case 9: devet++;
			cout<<"9 vo "<<i+1<<" kolo"<<endl;
			break;
			case 10: deset++;
			cout<<"10 vo "<<i+1<<" kolo"<<endl;
			break;
			case 11: edinaeset++;
			cout<<"11 vo "<<i+1<<" kolo"<<endl;
			break;
			case 12: dvanaeset++;
			cout<<"12 vo "<<i+1<<" kolo"<<endl;
			break;
			case 13: trinaeset++;
			cout<<"13 vo "<<i+1<<" kolo"<<endl;
			break;
			case 14: cetirinaeset++;
			cout<<"14 vo "<<i+1<<" kolo"<<endl;
			break;
			case 15: petnaeset++;
			cout<<"15 vo "<<i+1<<" kolo"<<endl;
			break;
			case 16: sestnaeset++;
			cout<<"16 vo "<<i+1<<" kolo"<<endl;
			break;
			case 17: sedumnaeset++;
			cout<<"17 vo "<<i+1<<" kolo"<<endl;
			break;
			case 18: osumnaeset++;
			cout<<"18 vo "<<i+1<<" kolo"<<endl;
			break;
			case 19: devetnaeset++;
			cout<<"19 vo "<<i+1<<" kolo"<<endl;
			break;
			case 20: dvaeset++;
			cout<<"20 vo "<<i+1<<" kolo"<<endl;
			break;
			case 21: dvaesetieden++;
			cout<<"21 vo "<<i+1<<" kolo"<<endl;
			break;
			case 22: dvaesetidva++;
			cout<<"22 vo "<<i+1<<" kolo"<<endl;
			break;
			case 23: dvaesetitri++;
			cout<<"23 vo "<<i+1<<" kolo"<<endl;
			break;
			case 24: dvaeseticetiri++;
			cout<<"24 vo "<<i+1<<" kolo"<<endl;
			break;
			case 25: dvaesetipet++;
			cout<<"25 vo "<<i+1<<" kolo"<<endl;
			break;
			case 26: dvaesetisest++;
			cout<<"26 vo "<<i+1<<" kolo"<<endl;
			break;
			case 27: dvaesetisedum++;
			cout<<"27 vo "<<i+1<<" kolo"<<endl;
			break;
			case 28: dvaesetiosum++;
			cout<<"28 vo "<<i+1<<" kolo"<<endl;
			break;
			case 29: dvaesetidevet++;
			cout<<"29 vo "<<i+1<<" kolo"<<endl;
			break;
			case 30: trieset++;
			cout<<"30 vo "<<i+1<<" kolo"<<endl;
			break;
			case 31: triesetieden++;
			cout<<"31 vo "<<i+1<<" kolo"<<endl;
			break;
			case 32: triesetidva++;
			cout<<"32 vo "<<i+1<<" kolo"<<endl;
			break;
			case 33: triesetitri++;
			cout<<"33 vo "<<i+1<<" kolo"<<endl;
			break;
			case 34: trieseticetiri++;
			cout<<"34 vo "<<i+1<<" kolo"<<endl;
			break;
			case 35: triesetipet++;
			cout<<"35 vo "<<i+1<<" kolo"<<endl;
			break;
			case 36: triesetisest++;
			cout<<"36 vo "<<i+1<<" kolo"<<endl;
			break;
			case 37: triesetisedum++;
			cout<<"37 vo "<<i+1<<" kolo"<<endl;
			break;
			default: break;
			}
		}

	}
	cout<<"Pojava na ista pozicija na broevite: "<<endl;
	cout<<"Eden: "<<eden<<endl;
	cout<<"Dva: "<<dva<<endl;
	cout<<"Tri: "<<tri<<endl;
	cout<<"Cetiri: "<<cetiri<<endl;
	cout<<"Pet: "<<pet<<endl;
	cout<<"Sest: "<<sest<<endl;
	cout<<"Sedum: "<<sedum<<endl;
	cout<<"Osum: "<<osum<<endl;
	cout<<"Devet: "<<devet<<endl;
	cout<<"Deset: "<<deset<<endl;
	cout<<"Edinaeset: "<<edinaeset<<endl;
	cout<<"Dvanaeset: "<<dvanaeset<<endl;
	cout<<"Trinaeset: "<<trinaeset<<endl;
	cout<<"Cetrinaeset:  "<<cetirinaeset<<endl;
	cout<<"Petnaeset: "<<petnaeset<<endl;
	cout<<"Sestnaeset: "<<sestnaeset<<endl;
	cout<<"Sedumnaeset: "<<sedumnaeset<<endl;
	cout<<"Osumnaeset: "<<osumnaeset<<endl;
	cout<<"Devetnaeset: "<<devetnaeset<<endl;
	cout<<"Dvaeset: "<<dvaeset<<endl;
	cout<<"Dvaeset i eden: "<<dvaesetieden<<endl;
	cout<<"Dvaset i dva: "<<dvaesetidva<<endl;
	cout<<"Dvaeset i tri: "<<dvaesetitri<<endl;
	cout<<"Dvaeset i cetiri: "<<dvaeseticetiri<<endl;
	cout<<"Dvaeset i pet: "<<dvaesetipet<<endl;
	cout<<"Dvaeset i sest: "<<dvaesetisest<<endl;
	cout<<"Dvaeset i sedum: "<<dvaesetisedum<<endl;
	cout<<"Dvaeset i osum: "<<dvaesetiosum<<endl;
	cout<<"Dvaeset i devet: "<<dvaesetidevet<<endl;
	cout<<"Trieset: "<<trieset<<endl;
	cout<<"Trieset i eden: "<<triesetieden<<endl;
	cout<<"Trieset i dva: "<<triesetidva<<endl;
	cout<<"Trieset i tri: "<<triesetitri<<endl;
	cout<<"Trieset i cetiri: "<<trieseticetiri<<endl;
	cout<<"Trieset i pet: "<<triesetipet<<endl;
	cout<<"Trieset i sest: "<<triesetisest<<endl;
	cout<<"Trieset i sedum: "<<triesetisedum<<endl;


	return 0;
}



