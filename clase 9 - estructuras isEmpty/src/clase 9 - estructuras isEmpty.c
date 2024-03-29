/*
 ============================================================================
 ANDREA BRICE�O
 Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.
 Se debe utilizar estructuras, permitiendo al usuario trabajar con los datos a trav�s de un ABM.
 Hacer con estructuras - Crear un men�

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANTIDADALUMNOS 3
#include <string.h>
#include <ctype.h>

//almunos.h en el punto c incluyo el .h para que las funciones me sirven
typedef struct {
	int legajo;
	char sexo;
	int edad;
	int nota1;
	int nota2;
	float promedio;
	char apellido[30];
	int isEmpty;

} datosPersonales;

int inicializarEstructura(datosPersonales array[], int tamano);
int mostrarSiCargoBien(datosPersonales array[], int tamano);
int buscarLibre(datosPersonales array[], int tamano);
int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos);
int utn_getSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos);
//void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
int mostrarMenu(int *respuesta);
int mostrarUnEmpleados( datosPersonales unAlumno);
int mostrarTodosLosEmpleados(datosPersonales array[], int tamano);
int promediarNotas(float *promedio, int nota1, int nota2);
int agregarAlumno( datosPersonales   array[], int tamanoDeArray, int *contadorDeLegajo );
int modificarAlumno( datosPersonales   array[], int tamanoDeArray, int posicion);
int buscarLegajo(datosPersonales array[], int tamanoDeArray);

///MAIN


int main(void) {
	setbuf(stdout, NULL); //ESTO VA SIEMPRE

	datosPersonales alumno[CANTIDADALUMNOS];

	inicializarEstructura(alumno, CANTIDADALUMNOS);

	//mostrarSiCargoBien(alumno, CANTIDADALUMNOS);

	int respuesta = 0;
	int legajo;
    int contadorDeLegajo = 1000;
		do {
		mostrarMenu(&respuesta);

		switch (respuesta) {

		case 1: //AGREGAR ALUMNOS

			agregarAlumno( alumno, CANTIDADALUMNOS, &contadorDeLegajo );


			//mostrarSiCargoBien(alumno, 1);
			break;

		case 2: // MOSTRAR ALUMNOS

			mostrarTodosLosEmpleados(alumno, CANTIDADALUMNOS);
			break;

		case 3: // BAJA / BORRAR ALUMNO

			legajo = buscarLegajo(alumno, CANTIDADALUMNOS);
			printf("------------  %d", legajo);

			break;

		case 4:  // MODIFICAR UN ALUMNO
			//modificarAlumno(alumno, CANTIDADALUMNOS );
			break;

		case 5: // ORDENAR
			break;

		case 6: // SALIR
			break;


		}

	} while (respuesta != 6);

	return EXIT_SUCCESS;
};


//INICIALIZACION
int mostrarMenu(int *respuesta) {
	int auxRespuesta;
	printf(" \n          MEN� ABM \n");
	printf("1. ALTA     \n2. LISTAR      \n3. BAJA       \n4. MODIFICAR  "
			" \n5. ORDENAR      \n6. SALIR\n");

	utn_getNumero(&auxRespuesta, "\n\n  Ingrese una opcion \n","\nError, ingrese un numero del 1 al 6 \n\n", 1, 6,3);
	*respuesta = auxRespuesta;

	return 0;

};

int inicializarEstructura(datosPersonales array[], int tamano) {

	int retorno = -1;
	if (array != NULL) {

		for (int i = 0; i < tamano; i++) {
			array[i].isEmpty = 1; // Pone cada campo isEmpty array en 1, es decir que est� libre.
		}
		retorno = 0;
	}
	return retorno;
};

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

int buscarLibre(datosPersonales array[], int tamanoDeArray) {
	int retorno = -1;

	if (array != NULL) {
		for (int i = 0; i < tamanoDeArray; i++) {
			if (array[i].isEmpty == 1) {
				retorno = i;
				break; //si encontr� una posicion libre rompo el for
			};
		};
	};
	return retorno;
};


// INGRESO - ALTA
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

int mostrarUnEmpleados( datosPersonales unAlumno){
	printf("        %d      %s       %c         %d        %d     %.2f    \n", unAlumno.legajo, unAlumno.apellido, unAlumno.sexo, unAlumno.nota1, unAlumno.nota2, unAlumno.promedio);

	return 0;

}

int mostrarTodosLosEmpleados(datosPersonales array[], int tamano){
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

}


int promediarNotas(float *promedio, int nota1, int nota2){

	int retorno = -1;
	float auxiliarpromedio;

	if (promedio != NULL){
		auxiliarpromedio = ((float)nota1 + nota2)/ 2;
		*promedio= auxiliarpromedio;
		retorno = 0;
	};
	return retorno;
}


int agregarAlumno( datosPersonales   array[], int tamanoDeArray, int *contadorDeLegajo ){
	int retorno = -1;
	int posicion;
	datosPersonales alumnoAuxiliar;

	if(array != NULL && tamanoDeArray > 0 && contadorDeLegajo != NULL)
	{
		posicion = buscarLibre(array, tamanoDeArray);
		if(posicion == -1)
		{
			printf("\n No hay espacio disponible para cargar alumnos");
		}else{

			if (  (utn_getSoN(&alumnoAuxiliar.sexo,"Ingrese el sexo -f -m\n", "Error, intente nuevamente",3) == 0) &&
				  (utn_getNumero(&alumnoAuxiliar.edad,"Ingrese la edad\n", "Error, ingrese la edad. Entre 18 y 80\n", 18, 80,3) == 0) &&
				  (utn_getNumero(&alumnoAuxiliar.nota1,"Ingrese la nota1\n", "Error, ingrese la nota1. Entre 1 y 10\n", 0, 10,3) == 0) &&
				  (utn_getNumero(&alumnoAuxiliar.nota2,"Ingrese la nota2\n", "Error, ingrese la nota2. Entre 1 y 10\n", 0, 10,3) == 0) &&
				  (promediarNotas(&alumnoAuxiliar.promedio, alumnoAuxiliar.nota1, alumnoAuxiliar.nota2) == 0 ) &&
				  (utn_getString(alumnoAuxiliar.apellido,"Ingrese el apellido \n", "Error intente nuevamente", 3) == 0) )
					{
					 alumnoAuxiliar.isEmpty = 0;
					alumnoAuxiliar.legajo= *contadorDeLegajo;
					array[posicion] = alumnoAuxiliar;
					(*contadorDeLegajo)++; //Aumenta el lejago en 1, inicializado en 1

					printf("Funcion�");
					retorno = 0;
				}
		}

	}
	return retorno;
}


int buscarLegajo(datosPersonales array[], int tamanoDeArray)

{
	int retorno = -1;
	int legajoAuxiliar;
	if(array!=NULL && tamanoDeArray>0)
	{
		mostrarTodosLosEmpleados(array, tamanoDeArray);
		printf("Ingrese un legajo \n");
		scanf("%d", &legajoAuxiliar);

		for(int i=0; i<tamanoDeArray; i++) //itera en el array pasado por parametro
		{
			if(array[i].legajo==legajoAuxiliar && array[i].isEmpty==0) //revisa si existe y si est� ocupado
			{
				scanf(" El legajo '%d' ha sido encontrado  \n", &legajoAuxiliar);
				retorno = i;

				break;
			}
			else
			{
				printf("El legajo  '%d' no existe \n", legajoAuxiliar);
				break;
			}
		}// fin for
		printf("printf fentro de funcion %d", retorno);
	}
	return retorno;
}



int modificarAlumno( datosPersonales   array[], int tamanoDeArray, int posicion){
	int retorno = -1;
	int legajoAuxiliar;
	mostrarTodosLosEmpleados(array, tamanoDeArray);
	printf("Ingrese el legajo del estudiante a modificar");
	fflush(stdin);
	scanf("%d", &legajoAuxiliar);
	for( int i = 0; i<tamanoDeArray ; i++ )
	{
		if(array[i].legajo == legajoAuxiliar ){
			mostrarUnEmpleados(array[i]);
		}

	};



	return retorno;
}


/*


utn_getCharSexo(&alumno[posicion].sexo,"Ingrese el sexo -f -m\n", "Error, intente nuevamente",3);
	utn_getNumero(&alumno[posicion].edad,"Ingrese la edad\n", "Error, ingrese la edad. Entre 18 y 80\n", 18, 80,3);
	utn_getNumero(&alumno[posicion].nota1,"Ingrese la nota1\n", "Error, ingrese la nota1. Entre 1 y 10\n", 0, 10,3);
	utn_getNumero(&alumno[posicion].nota2,"Ingrese la nota2\n", "Error, ingrese la nota2. Entre 1 y 10\n", 0, 10,3);
	promediarNotas(&alumno[posicion].promedio, alumno[posicion].nota1, alumno[posicion].nota2);
	utn_getString(alumno[posicion].apellido,"Ingrese el apellido \n", "Error intente nuevamente", 3);
	alumno[posicion].isEmpty = 0;

*/





//recoro stgrin  con el strlen y te fijas con is alfa paara ver si es




