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

typedef struct {
	int idProducto;
	char descripcion[30];
	int precio;
	int isEmpty;
	int idProveedor;   //estoy vinculando el proveedor al producto
} producto;

typedef struct {
	char calle[30];
	int numero;
	char localidad[30];
	int isEmpty;
} direccion;

typedef struct {
	int idProveedor;
	char razonSocial[30];
	direccion direccion;
	int isEmpty;
} Proveedor;





int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
