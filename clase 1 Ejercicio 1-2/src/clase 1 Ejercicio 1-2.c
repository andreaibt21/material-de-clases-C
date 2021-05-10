/*
 * andrea briceño
Ejercicio 1-2:ingresar 3 números y mostrar el mayor de los tres.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroMayor, esPrimerNumero;
	esPrimerNumero = 1;
	for (int i = 0; i < 3; i++){

		int numeroIngresado;

		printf("Ingrese un numero ");

		scanf("%d", &numeroIngresado);

		if(numeroIngresado > numeroMayor || esPrimerNumero == 1)
		{
			numeroMayor = numeroIngresado;
			esPrimerNumero = 0;
		}
	}
	printf("El numero mayor es: %d ", numeroMayor);

	return EXIT_SUCCESS;
}
