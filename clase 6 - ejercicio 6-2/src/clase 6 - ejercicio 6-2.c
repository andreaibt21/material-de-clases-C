/******************************************************************************
Ejercicio 6-2:Realizar un programa que permita el ingreso de 10 números enteros
(positivos y negativos). Necesito generar un listado de los números positivos de
manera creciente y negativos de manera decreciente. (Como máximo 4 for)Ejemplo:
Listado 1 : 4, 5, 6, 10, 18, 29 Listado 2 : -1,-5,-9,-12
*******************************************************************************/
#include <stdio.h>

int llenarArry(int *array[], int index);
int main()
{
   int notas[5];
   llenarArry(&notas, 5);

    return 0;
};
int llenarArry(int *array[], int index){
    for(int i = 0; i < index; i++){
        *array[i]=0;
    };
     return 0;
};
