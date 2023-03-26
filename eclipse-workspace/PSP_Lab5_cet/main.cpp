/*
 * main.cpp
 *
 *  Created on: Apr 7, 2022
 *      Author: David
 */

#include<iostream>
using namespace std;

struct jazol{
    int info;
    jazol *link;
};

struct EPLista{
    jazol *head;

    void init(){
        head=NULL;
    }

    void kreirajLista(int el){
        head=new jazol;
        head->info=el;
        head->link=NULL;
    }

    void dodadiPrv(int el){
        jazol *pom=new jazol;
        pom->info=el;
        pom->link=head;
        head=pom;
    }

    void dodadiPos(int el){
        jazol *pom=new jazol,*dvizi=head;
        pom->info=el;
        if(head==NULL)
            head=pom;
        else{
            while(dvizi->link!=NULL)
                dvizi=dvizi->link;
            dvizi->link=pom;
        }
        pom->link=NULL;
    }
    void brishiPrv()
    {
        if(head!=NULL)
        {
            if(head->link==NULL){
                delete head;
                head=NULL;
            }
            else{
                jazol *pom=head;
                head=head->link;
                delete pom;
            }
        }
    }
    void brishiPos(){
        if(head!=NULL)
        {
            if(head->link==NULL)
            {
                delete head;
                head=NULL;
            }
            else{
            jazol *pom=head,*brisi;
            while(pom->link->link!=NULL)
                pom=pom->link;

            brisi=pom->link;
            pom->link=NULL;
            delete brisi;
            }
        }
    }

    void brishiLista(){
        while(head!=NULL)
            brishiPos();
    }

    void pechatiLista()
    {
        cout<<"List = ";
        for(jazol *pom=head; pom!=NULL; pom=pom->link)
            cout<<"|"<<pom->info<<"|->";
        cout<<"NULL"<<endl;
    }
};

void modificiraj(EPLista &L1){

	jazol *prev;
	jazol *pom=L1.head;
	jazol *pom2;
	jazol *pom3;

	while(pom!=NULL && pom->link !=NULL){

		if(pom==L1.head){
			pom2=pom->link;
			pom3=pom2->link;
			L1.head=pom2;
			pom2->link=pom;
			prev=pom;
			pom->link=pom3;
			pom=pom3;
		}
		else{
		pom2=pom->link;
		pom3=pom2->link;
		pom2->link=pom;
		prev->link=pom2;
		pom->link = pom3;
		prev=pom;
		pom=pom3;
		}

	}

}

int main()
{
    EPLista l1;
    l1.init();
    int n;
    cout<<"Vnesete ja listata (0 za kraj)\n";
    cin>>n;
    l1.dodadiPrv(n);
    while(n!=0)
    {
        cin>>n;
        l1.dodadiPos(n);
    }
    l1.brishiPos();
    l1.pechatiLista();
    modificiraj(l1);
    l1.pechatiLista();
    l1.brishiLista();
    return 0;
}

