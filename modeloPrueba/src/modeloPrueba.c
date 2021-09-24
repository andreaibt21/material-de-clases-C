/*
 ============================================================================
 Name        : modeloPrueba.c
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
#include "utn.h"
#include "pantalla.h"

	typedef struct {
		int altura;
		char calle[50];
		char barrio[50];
		int isEmpty;
	} estructuraDireccion;

	typedef struct {
		int idPantalla;
		char nombre[50];
	    estructuraDireccion direccion;
		int tipoDePantalla;
		float precioPorDia;
		int isEmpty;
	}pantallas;

	typedef struct {
		int idPublicidad;
		int idPantalla;
		int cuitDeCliente;
		int diasPublicados;
		char archivo[50];
		int isEmpty;
	}publicidad;



#define  CANTIDADCONTRIBUYENTES 3
#define LARGODESTRING 51

//almunos.h en el punto c incluyo el .h para que las funciones me sirven


int inicializarEstructuraContribuyente(pantallas array[], int tamano);
int buscarLibre(pantallas array[], int tamano);
int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);
int mostrarUnaPantalla( pantallas unaPantalla);
int mostrarTodosLosContribuyentes(pantallas array[], int tamano);
int agregarUnContribuyente( pantallas   array[], int tamanoDeArray, int *contadorDeLegajo );
int modificarAlumno( pantallas   array[], int tamanoDeArray, int posicion);
int buscarLegajo(pantallas array[], int tamanoDeArray);
int borrarElEmpleado(pantallas array[], int tamano);

//int mostrarSiCargoBien(estructuraEmpleados array[], int tamano);
//int utn_getCharSexo(char *variableChar, char *mensaje, char *mensajeError, int reintentos);
//void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
//int promediarNotas(float *promedio, int nota1, int nota2);

/// ----------------------------------          MAIN          -----------------------------------------
int main(void) {
	setbuf(stdout, NULL); //ESTO VA SIEMPRE

	pantallas empleado[CANTIDADCONTRIBUYENTES];

	inicializarEstructuraContribuyente(empleado, CANTIDADCONTRIBUYENTES);


	int respuesta = 0;

    int contadorDeLegajo = 1000;
    int seIngresoUnEmpleado= -1;
		do {
		mostrarMenu(&respuesta);

		switch (respuesta) {

		case 1: //AGREGAR UN EMPLEADO

			agregarUnContribuyente( empleado, CANTIDADCONTRIBUYENTES, &contadorDeLegajo );

			break;
		case 2:  // MODIFICAR UN EMPLEADO

			seIngresoUnEmpleado = buscarLibre(empleado, CANTIDADCONTRIBUYENTES);
			if (seIngresoUnEmpleado > 0){
				//modificarAlumno(alumno, CANTIDADALUMNOS );

				printf("\n // MODIFICAR UN ALUMNO");
			} else{

				printf("\n Error, debe de ingresar al menos un empleado");
			}

			break;
		case 3: // ELIMINAR UN EMPLEADO

			seIngresoUnEmpleado = buscarLibre(empleado, CANTIDADCONTRIBUYENTES);
			if (seIngresoUnEmpleado > 0){

			borrarElEmpleado(empleado, CANTIDADCONTRIBUYENTES);

			} else{

				printf("\n Error, debe de ingresar al menos un empleado");
			}

			break;

		case 4: // MOSTRAR ALUMNOS

			seIngresoUnEmpleado = buscarLibre(empleado, CANTIDADCONTRIBUYENTES);
			if (seIngresoUnEmpleado > 0){
			mostrarTodosLosContribuyentes(empleado, CANTIDADCONTRIBUYENTES);

			} else{

				printf("\n Error, debe de ingresar al menos un empleado");
			}
			break;

		case 5: // SALIR
			break;


		}

	} while (respuesta != 5);

	return EXIT_SUCCESS;
};




int inicializarEstructuraContribuyente(pantallas array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1; // Pone cada campo isEmpty array en 1, es decir que está libre.
		}
		retorno = 0;
	}
	return retorno;
};

/*
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
};*/

int buscarLibre(pantallas array[], int tamanoDeArray) {
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


// INGRESO - ALTA


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

/*
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
*/

/*
int utn_getCharSexo(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
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
 * */


//3-Listar

/*	typedef struct {
		int idPantalla;
		char nombre[50];
	    char direccion;
		int tipoDePantalla;
		float precioPorDia;
		int isEmpty;
	}pantallas;



 * */

int mostrarUnaPantalla( pantallas unaPantalla){
	printf("          %d           %s        %.2f        %d        %s \n",
			unaPantalla.idPantalla, unaPantalla.nombre, unaPantalla.precioPorDia,  unaPantalla.direccion.altura,  unaPantalla.direccion.calle);

	return 0;

}

int mostrarTodosLosContribuyentes(pantallas array[], int tamano){
	int retorno = -1;

		if(array != NULL && array > 0){
			printf(" ****************  DATOS PERSONALES DE EMPLEADOS  ***************** \n ");
			printf("        ID PANTALLA      NOMBRE      SALARIO     TIPO  \n");

			for(int i = 0; i < tamano ; i++){
				if(array[i].isEmpty == 0){

				mostrarUnaPantalla( array[i]);
				}
			}
			retorno = 0;
		}

	return retorno;

}



int agregarUnContribuyente( pantallas   array[], int tamanoDeArray, int *contadorDeLegajo ){
	int retorno = -1;
	int posicion;
	pantallas pantallaAuxiliar;

	if(array != NULL && tamanoDeArray > 0 && contadorDeLegajo != NULL)
	{
		posicion = buscarLibre(array, tamanoDeArray);
		if(posicion == -1)
		{
			printf("\n No hay espacio disponible para cargar alumnos");
		}else{

			if (// unaPantalla.direccion.altura
				  (utn_getString(pantallaAuxiliar.nombre,"\n Ingrese el nombre de la pantalla ", "\n Error intente nuevamente", 3) == 0) &&
				  (utn_getFloat(&pantallaAuxiliar.precioPorDia,"\n Ingrese el precioPorDia (Entre 10000 y 80000)", "\n Error, ingrese la nota1. Entre 100 y 5000", 100, 5000,3) == 0) &&
				  (utn_getNumero(&pantallaAuxiliar.direccion.altura, "\n Ingrese el precioPorDia (Entre 10000 y 80000)", "\n Error, ingrese la nota1. Entre 1 y 10000", 1, 10000, 3))

			   )
					{
				    pantallaAuxiliar.isEmpty = 0;
					pantallaAuxiliar.idPantalla= *contadorDeLegajo;
					array[posicion] = pantallaAuxiliar;
					(*contadorDeLegajo)++; //Aumenta el lejago en 1, inicializado en 1000

					printf("\n *** Empleado guardado *** \n");
					retorno = 0;
				}
		}

	}
	return retorno;
}


int buscarLegajo(pantallas array[], int tamanoDeArray)

{
	int retorno = -1;
	int legajoAuxiliar;
	if(array!=NULL && tamanoDeArray>0)
	{
		mostrarTodosLosContribuyentes(array, tamanoDeArray);
		printf("\n Ingrese un legajo   ");
		scanf("%d", &legajoAuxiliar);

		for(int i=0; i<tamanoDeArray; i++) //itera en el array pasado por parametro
		{
			if(array[i].idPantalla==legajoAuxiliar ) //revisa si existe
			{
				if(array[i].isEmpty==0){ // y si está ocupado

					printf(" El legajo '%d' ha sido encontrado  \n", legajoAuxiliar);
					retorno = i;

					break;
				}
			}
			else
			{
				printf("El legajo  '%d' no existe \n", legajoAuxiliar);
				break;
			}
		}// fin for

	}
	return retorno;
}
int borrarElEmpleado(pantallas array[], int tamano) {

	int retorno = -1;
	int posicion = -1;
	char respuesta;

	posicion = buscarLegajo(array, tamano);

	if (array != NULL ) {
		printf("\nDesea borrar este legajo? \n");
		printf("\n ****************  DATOS PERSONALES DE EMPLEADOS  *****************  ");
		printf("\n        LEGAJO      NOMBRE      APELLIDO      SALARIO     SECTOR ");
		mostrarUnaPantalla( array[posicion]);
		printf("\n ingrese 's' para dar de baja.");
		fflush(stdin);
		scanf("%c", &respuesta);
		if(respuesta=='s'){
			array[posicion].isEmpty = 1; // Pone el campo isEmpty array en 1, es decir que está libre.
			retorno = 0;
			printf("\n *** Empleado dado de baja *** \n");
		}
	}
	return retorno;
};

//case 4
int modificarAlumno( pantallas   array[], int tamanoDeArray, int posicion){
	int retorno = -1;
	int legajoAuxiliar;
	mostrarTodosLosContribuyentes(array, tamanoDeArray);
	printf("Ingrese el legajo del estudiante a modificar");
	fflush(stdin);
	scanf("%d", &legajoAuxiliar);
	for( int i = 0; i<tamanoDeArray ; i++ )
	{
		if(array[i].idPantalla == legajoAuxiliar ){
			mostrarUnaPantalla(array[i]);
		}

	};



	return retorno;
}
/* imprimes la lista pides legajo, submenu que dato
 * quieres mod, elije la opcion y un switch y uno pides
 * el numeo apellido y se lo asignas con el que tenía
 * recibes el array, largo legajo
 */


/*
	utn_getCharSexo(&alumno[posicion].sexo,"Ingrese el sexo -f -m\n", "Error, intente nuevamente",3);
	utn_getNumero(&alumno[posicion].edad,"Ingrese la edad\n", "Error, ingrese la edad. Entre 18 y 80\n", 18, 80,3);
	utn_getNumero(&alumno[posicion].nota1,"Ingrese la nota1\n", "Error, ingrese la nota1. Entre 1 y 10\n", 0, 10,3);
	utn_getNumero(&alumno[posicion].nota2,"Ingrese la nota2\n", "Error, ingrese la nota2. Entre 1 y 10\n", 0, 10,3);
	promediarNotas(&alumno[posicion].promedio, alumno[posicion].nota1, alumno[posicion].nota2);
	utn_getString(alumno[posicion].apellido,"Ingrese el apellido \n", "Error intente nuevamente", 3);
	alumno[posicion].isEmpty = 0;
*/




