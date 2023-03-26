/*
 * main.c
 *
 *  Created on: Mar 9, 2022
 *      Author: David
 */
/*#include<stdio.h>
#include<string.h>

typedef struct Apteka{
    char lokacija[20];
    int brVrab;
    int daliRab;
}apteka;

typedef struct Lanec{
	char ime[20];
	int brA;
	apteka ap[10];
}lanec;

void VoNedela (lanec *lan){
    int i;
    for(i=0;i<lan->brA;i++){
        if(lan->ap[i].daliRab==1){
        printf("Lokacijata na apteki koi rabotat vo nedela se: %s\n",lan->ap[i].lokacija);
    }
  }
}
void Vraboteni(lanec *l){
    int i;
    for(i=0;i<l->brA;i++){
        if(l->ap[i].brVrab < 3){
            printf("Onie koi imaat pomalku od 3 vraboteni se: %s\n",l->ap[i].lokacija);
        }
    }
}

int main(){

	int i,j;
	lanec lanci[2];
	apteka apteki[10];

		printf("Vnesi podatoci: \n");fflush(stdout);
		for(i=0;i<2;i++){
		    printf("Vnesi ime na %diot lanec:\n ",i+1);fflush(stdout);
		    scanf("%s",lanci[i].ime);
		    scanf("Broj na apteki: %d\n",&lanci[i].brA);
		    for(j=0;j<10;j++){
		        printf("Apteka broj %d\n",j+1);fflush(stdout);
		        printf("Vnesi lokacija, broj na vraboteni i dali raboti vo nedela(1 za DA;0 za NE");
		        scanf("%s",apteki[j].lokacija);
		        scanf("%d",&apteki[j].brVrab);
		        scanf("%d\n ",&apteki[j].daliRab);
		    }
		}
	VoNedela(&lanci[0]);
	VoNedela(&lanci[1]);
	Vraboteni(&lanci[0]);
	Vraboteni(&lanci[1]);
	return 0;

}

*/
#include<iostream>
#include<string>
using namespace std;
int const MAX=50;

struct element{
    int info;
};

struct Stack{
    element array[MAX];
    int top;
    void init(){
        top=-1;
    }
    bool isEmpty(){
        return (top==-1);
    }
    bool isFull(){
        return (top==MAX-1);
    }
    void push(int e)
    {
        if(isFull())
        {
            cout<<"Magacinot e poln\n";
            return;
        }
        array[++top].info=e;
    }
    element pop(){
        if(isEmpty())
        {
            cout<<"Magacinot e prazen\n";
            return{};
        }
        return array[top--];
    }
    element peek(){
        if(isEmpty())
        {
            cout<<"Magacinot e prazen\n";
            return{};
        }
        return array[top];
    }
};

void func(int br1,int br2,Stack &m)
{
    Stack pom1,pom2; pom1.init(); pom2.init();
    int t;
    while(!m.isEmpty())
    {
        t=m.pop().info;
        if(t>=br1&&t<=br2)
            pom1.push(t);
    }
    while(!pom1.isEmpty())
        pom2.push(pom1.pop().info);
    while(!pom2.isEmpty())
        m.push(pom2.pop().info);
}

int main()
{
    Stack s;
    int count,no1,no2,element;
    s.init();
    cout<<"Kolku elementi? ";
    cin>>count;
    for(int i=0;i<count;i++)
    {
        //cin.clear();
        cin>>element;
        s.push(element);
    }
    cout<<"Interval: ";
    cin>>no1>>no2;
    if(no1>no2)
    {
        int t=no1;
        no1=no2;
        no2=t;
    }
    func(no1,no2,s);
    while(!s.isEmpty())
        cout<<s.pop().info<<" ";
    return 0;
}
