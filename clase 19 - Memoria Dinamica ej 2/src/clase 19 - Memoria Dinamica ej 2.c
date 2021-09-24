/*
ANDREA BRICEÑO

 */

#include <stdio.h>
#include <stdlib.h>


int funcionAgregarIntenXPosicion( int *array, int *tamano, int numero, int posicion );

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

	 funcionAgregarIntenXPosicion( arrayEnteros,  &tamanoArrayEnteros, 50,  3);


	  for (int i=0;i<tamanoArrayEnteros;i++)
			     {
			       printf( "\nNumeros del array nuevo  %d ", *(arrayEnteros+i));
			     }
	return EXIT_SUCCESS;
};

int funcionAgregarIntenXPosicion( int *array, int *tamano, int numero, int posicion ){

	int *punteroAuxiliar;
	int retorno = -1;
	(*(tamano))++;
	punteroAuxiliar = (int*)realloc( array, sizeof(int) * (*tamano) );
		//puntero de tamaño no es nulo	           //valor que contiene tamaño
	if (array!=NULL && tamano != NULL && posicion < *tamano) {

	     for ( int i= *tamano ; i != posicion; i--){

		    	 *(array + i ) = *(array + (i - 1)) ;
	     }

	     *(array + posicion) = numero;
		  if (punteroAuxiliar!=NULL){
			  array = punteroAuxiliar;
			  retorno = 0;
		  }
	}
	return retorno;
};








