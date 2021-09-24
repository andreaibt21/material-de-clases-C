/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void funcion1(int array[], int tamanoDeArray);
void funcion2(int array[], int tamanoDeArray);
void funcion3(int *array, int tamanoDeArray);
void funcion4(int *array, int tamanoDeArray);
int main(void) {

	setbuf(stdout,NULL);

	int array[3]= {1,2,3};
	//char *puntero1;
	//puntero1 = NULL;
	//funcion1(array, 3);
	//funcion2(array, 3);
	//funcion3(array, 3);
	funcion4(array, 3);

	return EXIT_SUCCESS;
}

/*
 * Escribir 4 funciones que reciban un array de números int y su tamaño, e impriman los números por pantalla
 * 1era función: Recibe el array como vector y accede a los datos utilizando notación vectorial ([])
 */
void funcion1(int array[], int tamanoDeArray){

		for(int i = 0; i< tamanoDeArray;i ++){
			printf("i : %d \n", array[i]);
		}
};


// 2da función: Recibe el array como vector y accede a los datos utilizando aritmética de punteros

void funcion2(int array[], int tamanoDeArray){


		for(int i = 0; i< tamanoDeArray;i ++){

			printf("i : %d \n", *(array+i));
		}
};

// 3era función: Recibe el array como puntero y accede a los datos utilizando notación vectorial ([])


void funcion3(int *array, int tamanoDeArray){

		for(int i = 0; i< tamanoDeArray;i ++){

			printf("i : %d \n", array[i]);
		}
};

//4da función: Recibe el array como puntero y accede a los datos utilizando aritmética de punteros




void funcion4(int *array, int tamanoDeArray){

		for(int i = 0; i< tamanoDeArray;i ++){

			printf("i : %d \n", *(array+i));
		}
};


















