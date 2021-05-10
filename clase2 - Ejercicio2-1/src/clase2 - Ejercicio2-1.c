/*

ANDREA BRICEÑO
 Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
aplicación con distintos valores.
Ejemplo 1: 3 - 5 - 7 - 9 - 1
Ejemplo 2: 2 - 1 - 8 -1 - 2

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int i;
	float promedio;
	int numeroIngresado;
	int acumulador = 0;

	for( i = 0; i < 5; i ++)
	{
		printf("%d, Ingrese un numero ", i);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
		acumulador += numeroIngresado;

	}
	promedio = (float)acumulador / i;

	printf("el promedio es %.2f", promedio);

}
