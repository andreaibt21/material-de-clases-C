/*
 * ANDREA BRICEÑO
Ejercicio 1-3:
ingresar 3 números y mostrar el número del medio, sólo si existe. En caso de que no
exista también informarlo.

exista también informarlo.
Ejemplo:
1 5 3 el 3 es del medio
5 1 5 no hay numero del medio
3 5 1 el 3 es del medio
3 1 5 el 3 es del medio
5 3 1 el 3 es del medio
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int primerNumero, segundoNumero, tercerNumero;


		printf("Ingrese el primer numero");
		scanf("%d", &primerNumero);
		printf("Ingrese el segundo numero");
		scanf("%d", &segundoNumero);
		printf("Ingrese el tercer numero");
		scanf("%d", &tercerNumero);

		if((primerNumero > segundoNumero && primerNumero < tercerNumero) ||
		   (primerNumero < segundoNumero && primerNumero > tercerNumero))
		{
			printf("El numero medio es %d", primerNumero);
		}else{
				if((segundoNumero > primerNumero && segundoNumero < tercerNumero) ||
				   (segundoNumero < primerNumero && segundoNumero > tercerNumero))
				{
					printf("El numero medio es %d", segundoNumero);
				} else
				{
					if((tercerNumero > primerNumero && tercerNumero < segundoNumero) ||
					   (tercerNumero < primerNumero && tercerNumero > segundoNumero))
					{
						printf("El numero medio es %d", tercerNumero);
					}else{

						printf("No hay numero medio");
					};
				};
		};



	return EXIT_SUCCESS;
}
