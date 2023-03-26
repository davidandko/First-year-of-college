/*
 * main.c
 *
 *  Created on: Nov 15, 2021
 *      Author: David
 */
// zadaca 4 od rekurzii proizvolen broj od niza
#include<stdio.h>

	float rek2(int n){
		float rv1,rv2,vv;
		if(n==3){
			return (float)(n-1)/n*2+1.0/n*1;
		}
		if(n==2){
			return 2;
		}
		rv1=rek2(n-1);
		rv2=rek2(n-2);
				vv=(float)(n-1)/(n)*rv1+1.0/n*rv2;
		return vv;
	}

int main()
{
	printf("rezultatot e %f", rek2(5));

	return 0;
}


