/*
 * 20.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int main()
{
   int n, pom=0;
   double suma=0.5, i;
   printf("vnesi broj");
   fflush(stdout);
   scanf("%d", &n);
   for(i=3; i<=n; i+=2)
   {
      if(pom==0){
       suma=i/(i+1);
       pom=1;
      }
      else if (pom==1){
      suma=(i+1)/i;
      pom=0;
      }
   }
   printf("sumata e %lf", suma);


    return 0;
}

