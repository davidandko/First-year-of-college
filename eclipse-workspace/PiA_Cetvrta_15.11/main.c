/*
 * main.c
 *
 *  Created on: Nov 15, 2021
 *      Author: David
 */
#include<Stdio.h>

int rek4a(int x,int kr){
int mr,vr;
if(x/10 == 0)
	return x+kr;
mr=x%10;
kr=kr+mr;

vr=rek4a(x/10,kr);

return vr;
}
int main(){

	printf("Zbir na cifri na 3567 e %d",rek4a(3567,0));
	return 0;
}
