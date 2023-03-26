/*
 * main.c
 *
 *  Created on: Nov 15, 2021
 *      Author: David
 */
#include<stdio.h>
int rek3(int x){
	int vr,vv;
	if((x/10)==0){
		return 1;
	}
	vr=rek3(x/10);

	vv=vr +1;
	return vv;


}

int main(){
printf("3567 ima %d cifri", rek3(3567));

return 0;

}
