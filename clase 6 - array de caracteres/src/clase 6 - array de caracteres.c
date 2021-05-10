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
#include <string.h> //
#include <ctype.h> //
int main(void) {

	setbuf(stdout, NULL);
/*
	char texto[] = "Nonna mama";
	printf("\n %s", texto);
	strcpy(texto, "Andrea");
	printf("\n %s", texto);
	printf("\ntexto %s TAMAÑO  %d",texto, sizeof(texto));
	printf("\nLONGITUD  %d", strlen(texto));
	char conjuntoCaracteres[] = {'N', 'o', 'n','n', 'a', '\0'};
	printf("\nconjuntoCaracteres: %s", conjuntoCaracteres);

	printf("\nconjuntoCaracteres %s TAMAÑO  %d",conjuntoCaracteres, sizeof(conjuntoCaracteres));
	printf("\nLONGITUD  %d", strlen(conjuntoCaracteres));

	*/

	/*
	//validacion de caantidad de caraterds con gets

	char nombre[6];
	char auxCad[10];

	printf("ingrese un nombre");
	fflush(stdin);
	gets(auxCad);
	while(strlen(auxCad) >= 6){
		printf("Nombre demasiado largo, ingrese uno mas corto");
		fflush(stdin);
		gets(auxCad);
	}
	strcpy(nombre,auxCad);


	printf("%s", nombre);

*/


/*
	char letras[] ="123";
	int numeroEntero;
	numeroEntero = atoi(letras);
	printf("texto convertido a numero entero %d", numeroEntero);
	return EXIT_SUCCESS;
*/

	int numero =1234;
	char cadena[20];
	itoa(numero, cadena, 10);
	printf("texto convertido a numero entero %d", numero);
	return EXIT_SUCCESS;


	char letra='t';
	printf("letra = %c", letra, islower(letra));






}
