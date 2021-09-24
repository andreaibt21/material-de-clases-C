/*
 c-Control de Flujo
Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo,
'd'-divorciado)
Si ingresa una edad menor a 18 años y un estado civil distinto a "Soltero",
mostrar el siguiente mensaje: 'Es muy pequeño para NO ser soltero.'
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	 char c;

	    printf("Enter a character: ");
	    scanf("%c", &c);

	    if (isalpha(c) == 0){
	         printf("%c is not an alphabet.", c);
	    }else{
	         printf("%c is an alphabet.", c);
	    }
	    return 0;


	return EXIT_SUCCESS;
}
