/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 Alumno-Localidad (Donde un alumno solo vive en una localidad)

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int idAlumno;
	char nombre[30];
	int isEmpty;
} Alumno;

typedef struct {
	int idAlumno;
	int idLocalidad;
	char descripcion[30];
	int codigoPostal;
	int isEmpty;
} Localidad;






int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
