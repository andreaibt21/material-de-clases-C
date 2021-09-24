/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Realizar una función que reciba como parámetro un array de enteros, su tamaño y
 un entero. La función se encargará de buscar el valor y borrará la primera ocurrencia del mismo.
 El array deberá reestructurarse dinámicamente.

 */

#include <stdio.h>
#include <stdlib.h>


int funcionBuscarYBorrar( int *array, int *tamano, int numero );

int main(void) {
	setbuf(stdout,NULL);
	int tamanoArrayEnteros = 5;
	int* arrayEnteros; //CREAR AMBAS VARIABLES DE TAMAÑO Y EL ARRAY !!!!!!!!!!!!!!!!!!!!!!!!!!

	 arrayEnteros= (int*)malloc(sizeof(int)*tamanoArrayEnteros);  //DECLARAR UN VECTOR DINAMICAMENTE

	 if (arrayEnteros!=NULL)
	 {
	     for (int i=0;i<tamanoArrayEnteros;i++)
	     {
	         *(arrayEnteros+i)=i;  //CARGA SECUENCIAL
	     }
	     for (int i=0;i<tamanoArrayEnteros;i++)
		     {
		       printf( "\nNumeros del array %d ", *(arrayEnteros+i));  //CARGA SECUENCIAL
		     }
	 }

	funcionBuscarYBorrar(arrayEnteros, &tamanoArrayEnteros, 3);

	  for (int i=0;i<tamanoArrayEnteros;i++)
			     {
			       printf( "\nNumeros del array %d ", *(arrayEnteros+i));
			     }
	return EXIT_SUCCESS;
};

int funcionBuscarYBorrar( int *array, int *tamano, int numero ){


	printf("\n numero a borrar: ");

	scanf("%d",&numero);
	int *punteroAuxiliar;
	int retorno = -1;
	if (array!=NULL && tamano != NULL) {

		if ( *(array + *tamano - 1) != numero){

			printf("\n iffffffff");

		     for ( int i=0; i < *tamano ; i++){

		    	 if(*(array+i) == numero){

					for ( int j = i; j < *tamano; j++){

		    		 *(array +j) = *(array + j+1);

					}

		    	 }
		     }

		}
		(*(tamano))--;
		punteroAuxiliar = (int*)realloc( array, sizeof(int) * (*tamano) );

		  if (punteroAuxiliar!=NULL){
			  array = punteroAuxiliar;
			  retorno = 0;
		  }
	}
	return retorno;
};
