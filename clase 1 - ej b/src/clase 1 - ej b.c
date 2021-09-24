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
#include <ctype.h>

int utn_getCuil(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);

int main(void) {
	setbuf(stdout, NULL); //ESTO VA SIEMPRE

char cuil[11];

		utn_getCuil(cuil, "ingrese cuil", "mensaaje error", 3);

	return EXIT_SUCCESS;
}

int utn_getCuil(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferString[11];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%s", bufferString);

			if(strlen(bufferString) < 11){

				strcpy(auxiliar, bufferString);
				retorno = 0;
				break;

			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return retorno;
};

