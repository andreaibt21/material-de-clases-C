/*
ANDREA BRICEÑO
 EJERCICIO
Realizar un programa que :
a)tenga 2 funciones una para calcular el minimo y otra para
calcular el maximo :
que retorne -1 si hubo errores y 0 si funcionó
que reciba dos número para comparar y un entero por referencia para devolver
el mínimo o máximo encontrado
b)Luego desarrollar una función que reciba por parámetro dos número enteros y
un puntero a función que ejecute la función recibida por parámetro y retorne el
resultado por retorno.  Puede recibir cualquiera de las dos funciones desarrolladas en
el punto a)
Crear un main donde se utilice la función del punto b) utilizando las 2 funciones
desarrolladas en el punto a)




 */

#include <stdio.h>
#include <stdlib.h>
int numeroMinimo(int numero1, int numero2, int* numeroMinimo);
int numeroMaximo(int numero1, int numero2, int* numeroMaximo);
int funcionMaxMin( int numero1, int numero2, int(*funcion)(int,int,int*) );
int main(void) {

	int numeroFinal;
    int (*funcion)(int,int,int*);
    funcion = numeroMinimo;
    numeroFinal= funcionMaxMin(1,4, funcion);

    printf("%d", numeroFinal);
	return EXIT_SUCCESS;
}

int numeroMinimo(int numero1, int numero2, int* numeroMinimo)
{ int retorno = -1;
   if(numero1<numero2){
	   *numeroMinimo = numero1;
	   retorno = 0;
   }else{
	   *numeroMinimo = numero2;
	   retorno = 0;
   }	return retorno;
};

int numeroMaximo(int numero1, int numero2, int* numeroMaximo)
{int retorno = -1;
   if(numero1>numero2){
	   *numeroMaximo = numero1;
   }else{
	   retorno = 0;
	   *numeroMaximo = numero2;
   }
return retorno;
}
int funcionMaxMin( int numero1, int numero2, int(*funcion)(int,int,int*) ){
    int auxResultado;

    funcion(numero1 , numero2 , &auxResultado);

    return auxResultado;
};
















