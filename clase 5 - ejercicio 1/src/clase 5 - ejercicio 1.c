/*
 ============================================================================
 Name        : clase.c
 Author      : ANDREA BRICEÑO

 Ejercicio 5-1:Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
// 0 1 2 3 4
// 7 5 3 4 4
int main(void) {
	setbuf(stdout, NULL);
	int numeros[5];
	int suma = 0;
	for(int i = 0; i < 5; i++)
	{
		printf("%d. Ingrese un numero \n", i);
		scanf("%d", &numeros[i]);

		suma += numeros[i];

	}
	printf("La suma de todos los numero es %d \n", suma);


	return EXIT_SUCCESS;
}
