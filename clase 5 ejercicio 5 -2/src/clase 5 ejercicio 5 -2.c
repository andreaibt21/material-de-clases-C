/*
 ============================================================================
 Name        : clase.c
 Author      : ANDREA BRICEÑO
 Version     :

 Ejercicio 5-2:Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 Determinar:Cantidad de positivos y negativos. Sumatoria de los pares.
 El mayor de los impares.
 Listado de los números ingresados.
 Listado de los números pares.
 Listado de los números de las posiciones impares.
 Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define NUMEROS 5
int main(void) {
	setbuf(stdout, NULL);

	int numeros[NUMEROS];
	int cantidadPositivos = 0;
	int cantidadNegativos = 0;
	int sumaDePares = 0;
	int mayorImpar;
	int contadorImpares = 0;



	for(int i = 0; i < NUMEROS; i++)
	{
		printf("%d.Ingrese un numero entre -1000 y 1000\n", i);
		scanf("%d", &numeros[i]);

		while( numeros[i]> 1001 ||  numeros[i] < -1000){
			printf("%d. ERROR, Ingrese un numero entre -1000 y 1000\n", i);
			scanf("%d", &numeros[i]);
		};

		 if(numeros[i] < 0){
			 cantidadNegativos++;
		 }
		 if(numeros[i]> 0){
			 cantidadPositivos++;
		 }

		 if(numeros[i] % 2 == 0){
			 sumaDePares+= numeros[i];
		 }else{

			 contadorImpares++;
			  //El mayor de los impares
			 if(i == 0 || numeros[i] > mayorImpar ){
				 mayorImpar = numeros[i];
			 };

		 };



	};
	printf("La cantidad de positivos ingresados es %d \n", cantidadPositivos);
	printf("La cantidad de negativos ingresados es %d \n", cantidadNegativos);
	printf("La suma de los pares es %d \n", sumaDePares);

	if(contadorImpares != 0 ){
	printf("El mayor de los impares es %d \n", mayorImpar);
	} else {
		printf("No se ingresaron numeros impares\n");
	}
	//Listado de los números ingresados.
	printf("Lista de numeros ingresados: \n");
	for(int i = 0; i < NUMEROS; i++){
		printf("%d \n", numeros[i]);
	}
	// Listado de los números de las posiciones impares.
	printf(" Listado de los números de las posiciones impares. \n");
	for(int i = 0; i < NUMEROS; i++){
			if(i % 2 == 1){
			printf("%d \n", numeros[i]);
		};
	}

	//YA FUNCIONA AHORA VOY A REFACTORIZARLO CON FUNCIONES
	return EXIT_SUCCESS;
}
