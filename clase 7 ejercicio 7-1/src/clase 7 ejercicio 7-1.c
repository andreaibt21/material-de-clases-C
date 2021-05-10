/*
 Ejercicio 7-1:Pedirle al usuario su nombre y apellido (en variables separadas,
  una para el nombre y otra para el apellido). Ninguna de las dos variables se
  puede modificar.Debemos lograr guardar en una tercer variable el apellido y
  el nombre con el siguiente formato:Por ejemplo: Si el nombre es juan ignacio
  y el apellido es gOmEz, la salida debería ser:Gomez, Juan Ignacio

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);
	char nombre[10];
	char apellido[10];
	char nombreCompleto[30];
	int longitudNombre ;
	int longitudApellido ;
	char nombreAux[10];
	char apellidoAux[10];

	printf("ingrese un nombre\n");
	gets(nombre);
	printf("Nombre ingresado %s \n", nombre);
	printf("ingrese un apellido");
	gets(apellido);
	printf("Apellido ingresado %s \n", apellido);

	 longitudNombre = sizeof(nombre);
	 longitudApellido = sizeof(apellido);

	 printf("longitud nombre %d longitud apellido %d \n",longitudNombre , longitudApellido);

	 strncpy(nombreAux,nombre,longitudNombre);
	 strncpy(apellidoAux, apellido, longitudApellido);

	 for(int i = 0; i < longitudNombre; i++){
		if (i == 0){
			nombreAux[i]= toupper(nombreAux[i]);
		}else{
			nombreAux[i]= tolower(nombreAux[i]);
		}
	}
		printf("Nombre ingresado cambiado %s \n", nombreAux);
	for(int i = 0; i < longitudApellido; i++){
			if (i == 0){
				apellidoAux[i]= toupper(apellidoAux[i]);
			}else{
				apellidoAux[i]= tolower(apellidoAux[i]);
			}
		}
		printf("Apellido ingresado cambiado %s \n", apellidoAux);

		//la salida debería ser:Gomez, Juan Ignacio

		strcpy(nombreCompleto,apellidoAux);


		strcat( nombreCompleto, ", " );
		strcat( nombreCompleto, nombreAux);
		printf("Nombre completo ingresado %s \n", nombreCompleto);

	return EXIT_SUCCESS;
}
