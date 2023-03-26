/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: David
 */
#include <stdio.h>
int rek (int a, int b) {
if ((a/10==0) || (b/10==0))
return ((a%10+b%10)>9);
else
return rek(a/10,b/10)*10+((a%10+b%10)>9);
}
int main (){
int izlez;
izlez=rek (6728,5678);
printf("%d",izlez);
return 0;
}

