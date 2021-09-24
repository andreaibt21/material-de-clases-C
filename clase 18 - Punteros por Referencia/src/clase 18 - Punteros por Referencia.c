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
#define TAMANOSTRING 20

typedef struct {
	int	legajo;
	char nombre[TAMANOSTRING];
	int	edad;
	int	isEmpty;
} estructuraEstudiante;


/*4-Utilizar aritmética de punteros. Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
 * Realizar una función que cargue un array de 3 estudiantes. Recibe un puntero al array de estudiantes,
 * lo carga y retorna 0 si funcionó correctamente -1 mal. Una vez cargados los estudiantes mostrar el array
 * cargado
 * */
int agregarUnEstudiante(estructuraEstudiante *estudiantes);
int main(void) {
	estructuraEstudiante estudiantes[3];


	estructuraEstudiante alumno = -1;

	for(int i=0; i<3; i++)
		{
		   alumno[i] =  agregarUnEstudiante(&alumno);
			if(alumno==0)
			{
				continue;
			}
			else
			{
				printf("Hubo un error");
				break;
			}
		}

		for(int i=0; i<3; i++)
		{
			printf("\nel nombre es: %s, la edad es: %d, el legajo es: %d", (*(estudiantes+i)).nombre, (*(estudiantes+i)).edad, (*(estudiantes+i)).legajo);
		}





	return 0;

}

int agregarUnEstudiante(estructuraEstudiante *estudiantes){
	int retorno = -1;
	estructuraEstudiante estudianteAuxiliar;
		if (estudiantes != NULL ){
			printf("Ingrese un nombre \n");
			gets(estudianteAuxiliar.nombre);

			printf("Ingrese un nombre \n");
			scanf("%d", &estudianteAuxiliar.edad);

			printf("Ingrese un nombre \n");
			scanf("%d", &estudianteAuxiliar.legajo);
			retorno = 0;
		}
	return retorno;
};









/*
 * * 3-Utilizar aritmética de punteros. Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
 * Realizar una función que cargue un array de 3 estudiantes. Recibe un entero. Retorna el estudiante dado de
 * alta y por parámetro 0 si funcionó correctamente -1 mal. Una vez devuelto el estudiante cargarlo en una
 * posición del array. Al final mostrar el array cargado
 *
int agregarUnEstudiante(int *numero );
int agregarUnEstudiante(int *numero ){
	int retorno = -1;
	estructuraEstudiante estudianteAuxiliar;
		if (numero != NULL ){
			printf("Ingrese un nombre \n");
			gets(estudianteAuxiliar.nombre);

			printf("Ingrese un nombre \n");
			scanf("%d", &estudianteAuxiliar.edad);

			printf("Ingrese un nombre \n");
			scanf("%d", &estudianteAuxiliar.legajo);
			retorno = 0;
		}
	return retorno;
};
*/

