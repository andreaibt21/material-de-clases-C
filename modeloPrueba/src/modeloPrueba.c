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
	} direccion;

	typedef struct {
		int idPantalla;
		int tipoDePantalla;
		char nombre[50];
		direccion direccion;
		float precioPorDia;
		int isEmpty;
	}pantallas;

	typedef struct {
		int tipoDePantalla;
		int cuitDeCliente;
		int diasPublicados;


		int isEmpty;
	}contrato;



int main(void) {
    setbuf(stdout,NULL);


	return EXIT_SUCCESS;
}
