/*
 ============================================================================
 Name        : BIBLIOTECA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}



int utn_getSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos);
int utn_getSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin); // SIEMPRE VA AL TOMAR CHARs
			scanf("%c", &bufferChar);
			if(bufferChar == 'f' || bufferChar == 'm')
			{
				*variableChar = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos){
	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*variableChar = bufferChar;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
}


int mostrarUnEmpleados( datosPersonales unAlumno);
int mostrarUnEmpleados( datosPersonales unAlumno){
	printf("        %d      %s       %c         %d        %d     %.2f    \n", unAlumno.legajo, unAlumno.apellido, unAlumno.sexo, unAlumno.nota1, unAlumno.nota2, unAlumno.promedio);

	return 0;

};


int mostrarTodosLosContribuyentes(datosPersonales array[], int tamano);
int mostrarTodosLosContribuyentes(datosPersonales array[], int tamano){
	int retorno = -1;

		if(array != NULL && array > 0){
			printf(" ****************  DATOS PERSONALES DE ALUMNOS  ***************** \n ");
			printf("        LEGAJO    APELLIDO        SEXO     NOTA1   NOTA2   PROMEDIO \n");

			for(int i = 0; i < tamano ; i++){
				if(array[i].isEmpty == 0){
					printf(" %d", i);
				mostrarUnEmpleados( array[i]);
				}
			}
			retorno = 0;
		}

	return retorno;

};


int mostrarMenu(int *respuesta) {
	int auxRespuesta;
	printf(" \n          MENÚ ABM \n");
	printf("1. ALTA     \n2. LISTAR      \n3. BAJA       \n4. MODIFICAR  "
			" \n5. ORDENAR      \n6. SALIR\n");

	utn_getNumero(&auxRespuesta, "\n\n  Ingrese una opcion \n","\nError, ingrese un numero del 1 al 6 \n\n", 1, 6,3);
	*respuesta = auxRespuesta;

	return 0;

};


int inicializarEstructura(datosPersonales array[], int tamano);

int inicializarEstructura(datosPersonales array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1; // Pone cada campo isEmpty array en 1, es decir que está libre.
		}
		retorno = 0;
	}
	return retorno;
};
int mostrarSiCargoBien(datosPersonales array[], int tamano);
int mostrarSiCargoBien(datosPersonales array[], int tamano) {
	int retorno = -1;
	if (array != NULL) {
		printf("\nDatos cargados\n");

		for (int i = 0; i < tamano; i++) {
			printf("Legajo: %d\n", array[i].legajo);
			printf("sexo: %c\n", array[i].sexo);
			printf("edad: %d\n", array[i].edad);
			printf("nota1: %d\n", array[i].nota1);
			printf("nota2: %d\n", array[i].nota2);
			printf("promedio: %.2f\n", array[i].promedio);
			printf("Apellido: %s \n", array[i].apellido);
			printf("isEmpty: %d\n", array[i].isEmpty);
			retorno = 0;
		}
	}
	return retorno;
};


int buscarLibre(datosPersonales array[], int tamano);
int buscarLibre(datosPersonales array[], int tamanoDeArray) {
	int retorno = -1;

	if (array != NULL) {
		for (int i = 0; i < tamanoDeArray; i++) {
			if (array[i].isEmpty == 1) {
				retorno = i;
				break; //si encontré una posicion libre rompo el for
			};
		};
	};
	return retorno;
};



int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int auxiliar; //variable auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0) {
		do{

			printf("%s \n", mensaje);
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


int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);
int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferString[30];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%s", bufferString);

			if(strlen(bufferString) < 30)
			{
				strcpy(auxiliar, bufferString);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
};







//utn_getCuil( , "\nIngrese su cuil xx xxxxxxxx x", "Error ingrese nuevamente", 3);

int utn_getCuil(int *resultado, char *mensaje, char *mensajeError, int reintentos);
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
		}while(reintentos>=0);
	}
	return retorno;
};








