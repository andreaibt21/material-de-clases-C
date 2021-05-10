/*
 * ANDREA BRICEÑO
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona
debemos obtener los siguientes datos:
número de cliente,
estado civil ('s'; para soltero, 'c' para casado o 'v' viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y sexo ('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado'viudo' de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
solo mostramos si corresponde.
https://www.onlinegdb.com/9ejUGjlDV
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numeroCliente, edadIngresada,temperaturaIngresada;
	char estadoIngresado, sexoIngresado, continuar;
	int contadorVSesenta;
	int esPrimerMujer, edadMasJoven, clienteSolteraMJoven;
	int contadorDePersonas, viajeTotal, viajePorPersona;
	int contadorPersonas60, mitadDePersonas;

	viajePorPersona = 600;
	contadorDePersonas = 0;
	esPrimerMujer = 1;
	contadorVSesenta = 0 ;
	continuar= 's';

	while(continuar == 's'){

	printf("Ingrese numero Cliente");
		scanf("%d", &numeroCliente);
		while(numeroCliente < 0)
		{
			printf("Error, numeroCliente");
				scanf("%d", &numeroCliente);
		};

	printf("Ingrese estado civil ('s'; para soltero, 'c' para casado o 'v' viudo)");
	scanf("%s", &estadoIngresado);
	while(estadoIngresado != 's' && estadoIngresado != 'c' && estadoIngresado != 'v' ){
		printf("Error, Ingrese estado civil ('s'; para soltero, 'c' para casado o 'v' viudo)");
			scanf("%s", &estadoIngresado);
	};

	printf("Ingrese edad (solo mayores de edad, más de 17)");
	scanf("%d", &edadIngresada);
	while(edadIngresada > 99 || edadIngresada < 18)
	{
		printf("Error, Ingrese edad ( solo mayores de edad, más de 17)");
			scanf("%d", &edadIngresada);
	};
	printf("Ingrese su temperatura");
	scanf("%d", &temperaturaIngresada);
	while(temperaturaIngresada > 40 || temperaturaIngresada < 32)
	{
		printf("Error, Ingrese su temperaturaa");
			scanf("%d", &temperaturaIngresada);
	};

	printf("Ingrese sexo ('f' para femenino, 'm' para masculino, 'o' para no binario)");
	scanf("%s", &sexoIngresado);
	while(sexoIngresado != 'f' && sexoIngresado != 'm' && sexoIngresado != 'o' ){
		printf("Error, Ingrese sexo ('f' para femenino, 'm' para masculino, 'o' para no binario)");
			scanf("%s", &sexoIngresado);
	};

	contadorDePersonas++


	printf("Desea continuar? 's' si, 'n' no");
	scanf("%s", &continuar);

	}

	/*
	Se debe informar (solo si corresponde):
	a) La cantidad de personas con estado'viudo' de más de 60 años.
	b) el número de cliente y edad de la mujer soltera más joven.
	c) cuánto sale el viaje total sin descuento.
	d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
	solo mostramos si corresponde.
	 */


	if(edadIngresada> 60){
		contadorPersonas60++;

		if(estadoIngresado == 'v')
		{
		contadorVSesenta ++;
		};
	}

	if (contadorVSesenta != 0){
		printf("a) La cantidad de personas con estado'viudo' de más de 60 años es: %d", contadorVSesenta);
	} else{
		printf("no hay viudos mayores de 60 años");
	}

	if(sexoIngresado == 'f' )
	{
		if(esPrimerMujer == 1 || edadIngresada < edadMasJoven)
		{
			edadMasJoven = edadIngresada;
			clienteSolteraMJoven = numeroCliente;
			esPrimerMujer = 0;
		}
	}
	if(esPrimerMujer != 1){
		printf("b) el número de cliente es %d y edad de la mujer soltera más joven es %d .", clienteSolteraMJoven, edadMasJoven);
	}

	viajeTotal = contadorDePersonas * viajePorPersona;
	printf("c) el viaje total sin descuento es %d", viajeTotal );
	//d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
	//solo mostramos si corresponde.
	mitadDePersonas = contadorDePersonas / 2;

	if( contadorPersonas60 > mitadDePersonas)
	{
		preciocon25 = viajeTotal + (viajeTotal * 25 ) / 100;

	}

	if (contadorPersonas60 > contadorDePersonas)
	return EXIT_SUCCESS;
}
