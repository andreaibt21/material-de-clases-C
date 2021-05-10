/*
 ============================================================================
 Name        : clase.c
 Author      : ANDREA BRICEÑO
 de los 10 empleados de una fabrica se registra:
 numero de legajo(coincidente con el indice), edad, sueldo.
 Se pide ingresara datos consecutivamente y calcular el sueldo promedio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define EMPLEADOS 3

int main(void) {
	setbuf(stdout, NULL);

	int edad[EMPLEADOS];
	float sueldo[EMPLEADOS];
	float sumaSueldo = 0;
	float promedio;


	for(int i = 0 ; i < EMPLEADOS; i++)
	{
		printf("%d . Ingrese su edad\n", i);
		scanf("%d", &edad[i]);
		printf("%d . Ingrese su sueldo\n", i);
		scanf("%f", &sueldo[i]);

		sumaSueldo += sueldo[i];
	};


	for(int i = 0 ; i < EMPLEADOS; i++ ){
		printf("Su legajo es %d, su edad es %d y su sueldo es %.2f \n", i, edad[i], sueldo[i]);
	};

	promedio = sumaSueldo / EMPLEADOS;
		printf("El sueldo promedio es %.2f \n" , promedio);



	return EXIT_SUCCESS;
}
