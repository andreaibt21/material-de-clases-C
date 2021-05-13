/*
 * utn.c
 *
 *  Created on: May 12, 2021
 *      Author: andre
 */
#include <string.h>
#include <ctype.h>
#ifndef UTN_C_
#define UTN_C_



//INICIALIZACION




int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int auxiliar; //variable auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) { // si devuelve != 0 cuando si entra

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>=0);

	}
	return retorno;
};

int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	float auxiliar; //variable auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) { // si devuelve != 0 cuando si entra

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>=0);

	}
	return retorno;
};

int mostrarMenu(int *respuesta) {
	int auxRespuesta;
	printf(" \n          MENÚ ABM ");
	printf( "\n   1. ALTA  "
			"\n   2. MODIFICAR  "
			"\n   3. BAJA    "
			"\n   4. INFORMAR  "
			"\n   5. SALIR\n");

	utn_getNumero(&auxRespuesta, "\n\n  Ingrese una opcion    ","\nError, ingrese un numero del 1 al 6 \n\n", 1, 6,3);
	*respuesta = auxRespuesta;

	return 0;

};



#endif /* UTN_C_ */
