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
#include <string.h>

typedef struct {
	int	idProducto;
	char marca[20];
	int	precio;
	int	isEmpty;
} estructuraProductos;


int compararMarca(estructuraProductos *producto1, estructuraProductos *producto2);
int compararPrecio(estructuraProductos *producto1, estructuraProductos *producto2);
int ordenador( estructuraProductos *producto, int tamanoArray, int(*funcion)( estructuraProductos*,estructuraProductos*) );

int main(void) {
	estructuraProductos productos[3] = {
	  {1001,"zadidas", 100},
	  {1002,"converse",122},
	  {1003,"rebook",121}
	};
    int (*funcion)(estructuraProductos* , estructuraProductos*);
    funcion = compararMarca;

    ordenador( productos, 3, funcion);


    for(int i = 0; i < 3; i++){
    	printf("\n  %d    %s     %d",   (*(productos+i)).idProducto, (*(productos+i)).marca, (*(productos+i)).precio);
    }



	return EXIT_SUCCESS;
}

int compararMarca(estructuraProductos *producto1, estructuraProductos *producto2){
	int retorno = -1;

	estructuraProductos estructuraAuxiliar;

	if( strcmp(  (*(producto1)).marca , (*(producto2)).marca )  > 0 ){ // aaa zzz
		estructuraAuxiliar = *producto1;
		*producto1 = *producto2;
		*producto2 = estructuraAuxiliar;

		retorno = 0;
	}

	return retorno;
};
int compararPrecio(estructuraProductos *producto1, estructuraProductos *producto2){
	int retorno = -1;

	estructuraProductos estructuraAuxiliar;

	if( ((*(producto1)).precio > (*(producto2)).precio) ){
		estructuraAuxiliar = *producto1;
		*producto1 = *producto2;
		*producto2 = estructuraAuxiliar;

		retorno = 0;
	}

	return retorno;
};
int ordenador( estructuraProductos *producto, int tamanoArray, int(*funcion)( estructuraProductos*,estructuraProductos*) ){
	int retorno;
	for(int i = 0; i<tamanoArray -1; i++){

		for(int j = i+1; j < tamanoArray; j++){


			if(funcion((producto + i), (producto + j)) == 0){
				retorno = 0;
				continue;
			}else{
				retorno = -1;
				break;}


		}

	}
	return retorno;
};



















