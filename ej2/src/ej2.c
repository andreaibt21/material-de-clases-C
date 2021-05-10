/*
 ============================================================================
 Name        : ej2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int sueldo;
	int sueldoMasDiezPorciento;

	printf("ingrese su sueldo");
	scanf("%d", &sueldo);
	printf("%d", sueldo);
	sueldoMasDiezPorciento = sueldo + (sueldo * 10 )/100;
	printf("Su sueldo más 10 porciento es: %d", sueldoMasDiezPorciento);
	return EXIT_SUCCESS;
}
