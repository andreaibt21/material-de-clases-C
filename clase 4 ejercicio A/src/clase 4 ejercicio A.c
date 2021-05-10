/*
 A- Hacer el menú de un programa con las siguientes opciones:
 1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
 */

#include <stdio.h>
#include <stdlib.h>

int ingresarOpcion();

int ingresarOpcion()
{
	int numero;
	printf("Ingrese un numero  1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir");
	scanf("\n%d", &numero);

	while ( numero > 5 || numero < 1)
	{
		printf("ERROR, Ingrese un numero  1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir");
			scanf("\n%d", &numero);
	}
	return numero;
}
int main(void) {

	setbuf(stdout,NULL);
	int opcion;

	opcion = ingresarOpcion();

	switch (opcion){

	case 1:
		printf("loguearse");
		break;
	case 2:
		printf("Comprar");
		break;
	case 3:
		printf("Ver mis compras");
		break;
	case 4:
		printf("Vender");
		break;
	case 5:
		printf("Salir");
		break;
	}

	return EXIT_SUCCESS;
}
