/*
 A- Hacer el menú de un programa con las siguientes opciones:
 1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int usuarioLogueado;
	usuarioLogueado = 0;
	do{


		printf("Ingrese un numero  1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir");
		scanf("\n%d", &opcion);

		switch (opcion){

		case 1:
			printf("loguearse");
			usuarioLogueado = 1;
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

	}
	while( opcion != 5);

	return EXIT_SUCCESS;
}
