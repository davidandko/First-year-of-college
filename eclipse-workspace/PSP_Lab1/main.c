/*
 * main.c
 *
 *  Created on: Mar 9, 2022
 *      Author: David
 */
/*
 На една компанија и е потребна програма за работа со ланци од аптеки. За таа цел треба да се
направат две структури: структура за ланец и структура за аптека. За секој ланец се знае името,
бројот на аптеки и низа од променливи од тип структура аптека (во низата има максимум 10
променливи). За секоја аптека се знае локацијата, бројот на вработени и податок дали работи во
недела.
Да се напише функција која ќе прима променлива од тип ланец како аргумент, а ќе ги испечати
локацијата на секоја аптека, во ланецот, која работи во недела.
Во главната програма да се овозможи внесување на информациите потребни за креирање на два
ланци и внесување на аптеките во секој ланец. Со употреба на веќе напишаната функција, да се
испечатат локациите на аптеките кои имаат помалку од 3 вработени, без разлика на ланецот во кој
се вклучени (функцијата да се повика за двата ланци).
 */

#include<stdio.h>

typedef struct Apteka{
    char lokacija[50];
    int brVraboteni;
    int daliRab;
}apteka;

typedef struct Lanec{
    char ime[50];
    int brApteki;
    apteka apteki[10];
}lanec;

void daliRab(lanec *lan){
    int i;
    for(i=0;i<lan->brApteki;i++){
        if(lan->apteki[i].daliRab == 1){
            printf("Lokacija na aptekata sto raboti vo NEDELA: %s\n",lan->apteki[i].lokacija);fflush(stdout);
        }
    }
}
void vrabotenost(lanec *lan){
    int i;
    for(i=0;i<lan->brApteki;i++){
        if(lan->apteki->brVraboteni<3){
            printf("Lokacija na aptekata sto ima povekje od 3 vraboteni: %s\n",lan->apteki[i].lokacija);fflush(stdout);
        }
    }
}


int main(){
int i,j;
lanec l[2];

for(i=0;i<2;i++){
    printf("Vnesi ime na lanec:");fflush(stdout);
    scanf("%s",l[i].ime);
    printf("Vnesi broj na apteki vo lanec: \n");fflush(stdout);
    scanf("%d",&l[i].brApteki);
    printf("Pocni da vnesuvas apteki: \n");
    for(j=0;j<l[i].brApteki;j++){
        printf("Vnesi lokacija na aptekata: \n");fflush(stdout);
        scanf("%s",l[i].apteki[j].lokacija);
        printf("Vnesi broj na vraboteni vo aptekata: \n");fflush(stdout);
        scanf("%d",&l[i].apteki[j].brVraboteni);
        printf("Vnesi dali aptekata raboti vo nedela 1 za DA ; 0 za NE: \n");fflush(stdout);
        scanf("%d",&l[i].apteki[j].daliRab);
    }

}
    daliRab(&l[0]);
    daliRab(&l[1]);
    vrabotenost(&l[0]);
    vrabotenost(&l[1]);

    return 0;
}


