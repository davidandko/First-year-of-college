/*
 * Ocenka_Main.c
 *
 *  Created on: Oct 25, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int x,ost;
	char znak;
	printf("vnesete broj na poeni\n");
	fflush(stdout);
	scanf("%d",&x);
	ost = x%10;
	if(ost>=1 && ost<=3)
		znak = '-';
	if(ost>=4 && ost<=7)
		znak = ' ';
	if(ost>=8 || ost == 0)
		znak = '+';

	if(x<=50)
		printf("ocenka 5%c",znak);
	else
		if(x<=60)
			printf("ocenka 6%c",znak);
			else
				if(x<=70)
					printf("ocenka 7%c",znak);
					else
						if(x<=80)
							printf("ocenka 8%c",znak);
						else
							if(x<=90)
								printf("ocenka 9%c",znak);
								else
									printf("ocenka 10%c",znak);
	return 0;

}

