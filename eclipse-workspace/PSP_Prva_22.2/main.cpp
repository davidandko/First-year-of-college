#include<stdio.h>
#include<math.h>

struct Kompleksen{
	int real;
	int imag;
};
typedef struct Kompleksen Kompleksen;

Kompleksen soberi(Kompleksen,Kompleksen);
Kompleksen odzemi(Kompleksen*,Kompleksen*);
void mnozi(Kompleksen,Kompleksen,Kompleksen*);
void pecati(const Kompleksen*);

int main(){
	Kompleksen k[2],rez;
	int i;
	for(i=0;i<2;i++){
		printf("R: ");
		scanf("%d",&k[i].real);
		printf("I: ");
		scanf("%d",&k[i].imag);
	}
	for(i=0;i<2;i++){
		pecati(&k[i]);
	}
	rez = soberi(k[0],&k[1]);
	printf("Zbirot e ");
	pecati(&rez);

	rez = odzemi(&k[0],&k[1]);
		printf("Razlikata e ");
		pecati(&rez);

	mnozi(k[0],k[1],&rez);
	printf("Proizvodot e ");
	pecati(&rez);

	return 0;
}

Kompleksen soberi(Kompleksen a,Kompleksen b){
	Kompleksen c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}

Kompleksen odzemi(Kompleksen* a, Kompleksen* b){
	Kompleksen c;
	c.real = a->real - b->real;
	c.imag = a->imag - b->imag;
	return c;
}

void mnozi(Kompleksen a,Kompleksen b,Kompleksen* c){
	c.real = a.real * b.real + a.imag * b.imag;

	c.real = a.real * b.real - a.imag * b.imag;
	return c;
}
void pecati(const Kompleksen* c) {
	printf("R=%d I=%d \n", c->real, c->imag);
}




