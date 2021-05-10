/*
 ============================================================================
 Name        : Clase.c
 Author      : Andrea Briceño
 Version     :
 Copyright   : Your copyright notice
 Description :

 Desarrollar un programa que permita guardar los
 datos de 5 alumnos. Los datos a guardar para cada alumno:
 legajo, sexo, edad, nota1, nota2, promedio, apellido.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LARGO 3


void inicializarArrayInt( int array[], int tamano);
void inicializarArrayChar(char array[], int tamano);
void inicializarArrayString(char array[][10], int tamano);
void inicializarArrayFloat( float array[], int tamano);

int utn_getArrayInt(int numero[], char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
void ingresarArrayString(char array[], char *mensaje,  char *mensajeError);

void ingresarArrayFloat(float array[], int tamano);
void ingresarArrayChar(char array[], int tamano);

int main(void) {
	setbuf(stdout,NULL);
	int legajo[LARGO];
	char sexo[LARGO];
	int edad[LARGO];
	int nota1[LARGO];
	int nota2[LARGO];
	float promedio[LARGO];
	char apellido[LARGO][10];
	//char auxApellido[LARGO];

	//Inicializaciones pone todos los elementos en 0 o a

	inicializarArrayChar( sexo, LARGO);
	inicializarArrayInt( edad, LARGO);
	inicializarArrayInt( nota1, LARGO);
	inicializarArrayInt( nota2, LARGO);
	inicializarArrayFloat( promedio, LARGO);
	inicializarArrayString(apellido, LARGO);

	for(int i = 0; i < LARGO ; i++){

		utn_getArrayInt(&legajo[i], "Ingrese un legajo\n", "Error, intente nuevamente\n", 1 , 10000, 3);


	};

	for(int i = 0; i < LARGO ; i++){

				printf("%d legajo %d ",i ,legajo[i]);
				printf("  sexo %c " , sexo[i]);
				printf("  edad %d " ,edad[i]);
				printf("  nota1 %d " ,nota1[i]);
				printf("  nota2 %d " ,nota2[i]);
				printf("  promedio %.2f " ,promedio[i]);
				printf("  apellido %s \n" ,apellido[i]);

			};


	return EXIT_SUCCESS;
}

void inicializarArrayInt( int array[], int tamano){
	for(int i = 0; i < LARGO ; i++){
			array[i]= 0;
		};
}

void inicializarArrayFloat( float array[], int tamano){
	for(int i = 0; i < LARGO ; i++){
			array[i]= 0;
		};
}

void inicializarArrayChar(char array[], int tamano){
	for(int i = 0; i < tamano ; i++){
 		array[i] = 'a'; //comillas simples para caracteres
		};
}

void inicializarArrayString(char array[][10], int tamano){
	for(int i = 0; i < tamano ; i++){
		//destino, origen-- donde desde donde
 		strcpy(array[i], "a"); //comillas dobles para strings
		};
}


int utn_getArrayInt(int numero[], char *mensaje, char *mensajeError, int minimo, int maximo, int intentos){

	int bufferInt ; //variable auxiliar;

		if (numero != NULL  && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >=0 ){
				printf("%s \n", mensaje);
				scanf("%d", &bufferInt);
				if(bufferInt >= minimo && bufferInt <=maximo ){
					*numero = bufferInt;
				}else{

				printf("%s", mensajeError);
				intentos--;
			};
		}



	return 0;
};

void ingresarArrayFloat(float array[], int tamano){
	for (int i = 0; i < tamano; i++){
		printf("Ingrese un numero flotante");
		scanf("%f ", &array[i]);
	};
}
void ingresarArrayChar(char array[], int tamano){
	for (int i = 0; i < tamano; i++){
		printf("Ingrese un caracter");
		scanf("%c ", &array[i]);
	};
}
//ingresarArrayString(auxApellido, char mensaje,  char mensajeError);
// strcpy(apellido[i], auxApellido);//esttoy copiando lo del axiliar dentro del array de apellidos


void ingresarArrayString(char array[], char *mensaje,  char *mensajeError){

		printf(mensaje);  //variable aux scan
		fflush(stdin);
		gets(array);


		//gets()y luego strcpy (arraay, variableaux)
 		//strcpy(array[i], "a");

}


