/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 Dueño-Mascota (Donde la mascota solo puede tener un único dueño)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int idDueno;
	char nombreDueno[30];
	int edad;
	char sexo;
	int isEmpty;
} Dueno;

typedef struct {
	int idRaza;
	char nombreraza[30];
	int isEmpty;
} RazaMascota;

typedef struct {
	int idMascota;
	int idDueno;
	RazaMascota raza;
	char sexo;
	char nombreDueno[30];
	int isEmpty;
} Mascota;





int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
