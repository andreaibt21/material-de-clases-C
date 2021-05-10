/******************************************************************************
ANDREA BRICEÑO
Ejercicio 6-1:

Disponemos de dos variables numéricas (a y b).
Realizar un algoritmo que permita el intercambio de valores de dichas variables.

*******************************************************************************/
#include <stdio.h>
int intercambiarValores(int *a, int *b);
int main()
{

int a = 4;
int b = 3;

intercambiarValores(&a,&b);
    return 0;
}

int intercambiarValores(int *a, int *b){

 int aux;

 aux = *a; //valor de direccion de memoria
 *a = *b;
 *b = aux;

printf("a :%d \n", *a);
printf("b :%d \n", *b);
 return 0;
};


