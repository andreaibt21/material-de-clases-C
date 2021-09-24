/*
ANDREA BRICEÑO
 */

#include <stdio.h>
#include <stdlib.h>

int multiplicacion(int numero1, int numero2);
int calculador( int numero1, int(*funcion)(int,int), int numero2, int *resultado );

int main(void) {

	int numeroFinal;

    int (*funcion)(int, int); //declaro puntero a funcion que voy a llamar dentro de otra funcion
    funcion = multiplicacion;

    calculador( 3, funcion, 4, &numeroFinal);

    printf("%d", numeroFinal);
	return EXIT_SUCCESS;
}

int multiplicacion(int numero1, int numero2){
	int resultado;

	resultado = numero1 * numero2;

	return resultado;
};

int calculador( int numero1, int(*funcion)(int,int), int numero2, int *resultado ){


	 *resultado =  funcion (numero1 , numero2 );

    return *resultado;
};

