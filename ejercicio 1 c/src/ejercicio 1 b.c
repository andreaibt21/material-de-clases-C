/*
 andrea brice�o

b-Entrada/salida
Pedir el sueldo al usuario. Sumarle un 10% e informarle cu�l ser� su sueldo con aumento.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int sueldo;
	int sueldoMasDiezPorciento;

	printf("ingrese su sueldo");
	scanf("%d", &sueldo);
	printf("%d", sueldo);
	sueldoMasDiezPorciento = sueldo + (sueldo * 10 )/100;
	printf("Su sueldo m�s 10 porciento es: %d", sueldoMasDiezPorciento);
	return EXIT_SUCCESS;
}
