/*
 *
 * ANDREA BRICE�O
Ejercicio 2-2:
Ingresar 10 n�meros enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor n�mero ingresado.
c. De los pares el mayor n�mero ingresado.
d. Suma de los positivos.
e. Producto de los negativos.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int contador;
	int numeroIngresado;
	int cantidadDePares = 0;
	int cantidadDeImpares = 0;
	int numeroMayorDeLosPares;
	int numeroMenor;
	int sumaDeLosPositivos = 0;
	int productoDeLosNegativos = 1;
	int contadorDeLosNegativos = 0;



	for(contador = 0; contador < 5; contador++)
	{
		setbuf(stdout, NULL);

		printf("Inserte un numero");
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado == 0 )
		{
			printf("Error, Inserte un numero que no sea 0");
			fflush(stdin);
			scanf("%d", &numeroIngresado);

		}

		if(numeroIngresado %2 == 0)
		{

			if(cantidadDePares == 0 || numeroIngresado > numeroMayorDeLosPares)
			{
			numeroMayorDeLosPares = numeroIngresado;
			}
			cantidadDePares++;
		}
		else
		{
			cantidadDeImpares++;
		}

		if (contador == 0 || numeroIngresado < numeroMenor)
		{
			numeroMenor = numeroIngresado;

		}
		if(numeroIngresado > 0)
		{
			sumaDeLosPositivos += numeroIngresado;
		}
		else
		{
			contadorDeLosNegativos++;
			productoDeLosNegativos *= numeroIngresado;
		}

	}//fin de for

	//	a. Cantidad de pares e impares.
	if(cantidadDePares > 0)
	{
		printf("\n cantidad de pares ingresados %d", cantidadDePares);
	}else
	{

		printf("\n no se ingresaron numeros pares");
	}
	if(cantidadDeImpares > 0 )
	{
		printf("\n cantidad de impares ingresados %d", cantidadDeImpares);
	}else
	{
		printf("\n no se ingresaron numeros impares");
	}

	//c. De los pares el mayor n�mero ingresado.
	printf("\n el numero mayor de los pares es %d", numeroMayorDeLosPares);
	//b. El menor n�mero ingresado.
	printf("\n el numero menor es %d", numeroMenor);

	//	d. Suma de los positivos.
	if(sumaDeLosPositivos > 0)
	{
		printf("\n La suma de los positivos es %d", sumaDeLosPositivos);
	}
	else{
		printf("\n no se ingresaron numeros positivos");
	}

	//	e. Producto de los negativos.
	if(contadorDeLosNegativos> 0)
	{
		printf("\n el producto de los negativos es %d", productoDeLosNegativos);
	}else{
		printf("\n no se ingresaron numeros negativos");
	}

	return EXIT_SUCCESS;
}
