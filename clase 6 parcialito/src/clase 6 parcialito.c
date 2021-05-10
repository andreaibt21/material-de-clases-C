/*
 *parcialito
ANDREA BRICEÑO
Realizar el prototipo, el desarrollo y la
llamada de una función que reciba por parámetro
dos números enteros y retorne por referencia el
mayor y por valor el menor.


*/
#include <stdio.h>
int mayorYMenor(int numero1, int numero2, int* numeroMayor);
int main()
{
    int numeroMayor;
    int numeroMenor;
    int num1;
    int num2;
    setbuf(stdout, NULL);
    printf("Inserte el primer numero");
    scanf("%d", &num1);
    printf("Inserte el segundo numero");
    scanf("%d", &num2);
    numeroMenor =  mayorYMenor(num1,num2, &numeroMayor);

printf("numeroMayor :%d \n", numeroMayor);
printf("numeroMenor :%d \n", numeroMenor);
    return 0;
};

int mayorYMenor(int numero1, int numero2, int* numeroMayor){

        int numeroMenor;

        if( numero1 > numero2 ){
    			*numeroMayor = numero1;
    	}else{
    			numeroMenor = numero1;
    	};

        if( numero2 > numero1 ){
    			*numeroMayor = numero2;
    	    }else{
    			numeroMenor = numero1;
    	};
        return numeroMenor;
    };



