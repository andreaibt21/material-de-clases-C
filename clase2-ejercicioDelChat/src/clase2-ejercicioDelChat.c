/*
 andrea briceño
 Aplicando el concepto de Operadores Lógicos con valores booleanos en el condicional:
Solicitar un número al usuario
Informar si el mismo es par o impar.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;

	printf("Ingrese un numero");
	fflush(stdin);
	scanf("%d", &numeroIngresado);
	printf("\n El numero ingresado es: %d", numeroIngresado);

	if(numeroIngresado % 2 == 0)
	{
		printf("\n El numero ingresado es par");

	}
	else
	{
		printf("\n El numero ingresado es impar");

	}


	return EXIT_SUCCESS;
}
