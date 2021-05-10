/*
 a-Funciones
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
- Muestre el resultado por pantalla
 */

#include <stdio.h>
#include <stdlib.h>
#define DESCUENTO 25

int realizarDescuento(int numero, int descuento);

int main(void) {

	setbuf(stdout,NULL);

	int numeroIngresado;
	float res;

	printf("Ingrese un numero entre 10 y 100");
	scanf("%d", &numeroIngresado);

	while(numeroIngresado> 100 || numeroIngresado < 10)
	{
		printf("\n Error, Ingrese un numero entre 10 y 100");
		scanf("%d", &numeroIngresado);
	}

	res = numeroIngresado - realizarDescuento(numeroIngresado, DESCUENTO);

	printf("El numero con descuento de %d es: %.2f", DESCUENTO, res);

	return EXIT_SUCCESS;
};

realizarDescuento(int numero, int numero2){

	int resultado;

	resultado = (float) numero * numero2 /100;

	return resultado;
};



