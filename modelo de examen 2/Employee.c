 /** Employee.c
 *
 *      Author: Andrea Briceño
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

Pelicula* movie_new(){
	return (Pelicula*)malloc(sizeof(Pelicula));
}

Pelicula* movie_newParametros(char* id_ventaStr,char* nombre_peliculaStr,char* diaStr,char* horarioStr, char* salaStr,  char* cantidad_entradasStr){
	Pelicula* peliculaAuxiliar = movie_new();

	if( id_ventaStr != NULL && nombre_peliculaStr != NULL &&  horarioStr != NULL && salaStr != NULL && cantidad_entradasStr != NULL){
			if( (movie_setId( peliculaAuxiliar, atoi(id_ventaStr) )  ==0) &&
				(movie_setNombre( peliculaAuxiliar, nombre_peliculaStr) ==0) &&
				(movie_setHorario( peliculaAuxiliar, horarioStr) ==0) &&
				(movie_setSala( peliculaAuxiliar, atoi(salaStr) ) ==0) &&
				(movie_setDia( peliculaAuxiliar, atoi(diaStr) ) ==0) &&
				(movie_setCantidadEntradas(peliculaAuxiliar,atoi(cantidad_entradasStr) ) ==0)){

				}else{
					peliculaAuxiliar=NULL;

				}
	}
	return peliculaAuxiliar;
}

int movie_setId(Pelicula* this,int id_venta){
	int retorno=-1;
		if(this != NULL && id_venta > 0){
			this -> id_venta = id_venta;
			retorno = 0;
		}

	return retorno;
}

int movie_getId(Pelicula* this,int* id_venta){
	int retorno=-1;
	if( this != NULL && id_venta != NULL ){
		*id_venta = this -> id_venta;
		retorno = 0;
	}
	return retorno;
}


int movie_setNombre(Pelicula* this,char* nombre_pelicula){
	int retorno=-1;
	if( this != NULL && nombre_pelicula != NULL){
		strcpy( this -> nombre_pelicula , nombre_pelicula );
		retorno = 0;
	}
	return retorno;
}

int movie_getNombre(Pelicula* this, char* nombre_pelicula){
	int retorno=-1;
	if( this != NULL && nombre_pelicula != NULL){
		strcpy( nombre_pelicula , this -> nombre_pelicula );
		retorno = 0;
	}
	return retorno;
}


int movie_setHorario(Pelicula* this,char* horario){
	int retorno=-1;
		if( this != NULL && horario != NULL){
			strcpy( this -> horario , horario );
			retorno = 0;
		}
		return retorno;
}

int movie_getHorario(Pelicula* this, char* horario){
	int retorno=-1;
		if( this != NULL && horario != NULL){
			strcpy( horario , this -> horario );
			retorno = 0;
		}
		return retorno;
}


int movie_setSala(Pelicula* this,int sala){
	int retorno=-1;
	if( this != NULL &&  sala > -1){
		 this -> sala = sala ;
		retorno = 0;
	}
	return retorno;
}

int movie_getSala(Pelicula* this,int* sala){
	int retorno=-1;
	if( this != NULL &&  sala != NULL){
		*sala = this -> sala;
		retorno = 0;
	}
	return retorno;
}
int movie_setCantidadEntradas(Pelicula* this,int cantidad_entradas){
	int retorno=-1;
	if( this != NULL &&  cantidad_entradas > -1){
		 this -> cantidad_entradas = cantidad_entradas ;
		retorno = 0;
	}
	return retorno;
}

int movie_getCantidadEntradas(Pelicula* this,int* cantidad_entradas){
	int retorno=-1;
	if( this != NULL &&  cantidad_entradas != NULL){
		*cantidad_entradas = this -> cantidad_entradas;
		retorno = 0;
	}
	return retorno;
}
int movie_setDia(Pelicula* this,int dia){
	int retorno=-1;
	if( this != NULL &&  dia > -1){
		 this -> dia = dia ;
		retorno = 0;
	}
	return retorno;
}

int movie_getDia(Pelicula* this,int* dia){
	int retorno=-1;
	if( this != NULL &&  dia != NULL){
		*dia = this -> dia;
		retorno = 0;
	}
	return retorno;
}


int movie_setMonto(Pelicula* this,int monto){
	int retorno=-1;
	if( this != NULL &&  monto > -1){
		 this -> monto = monto ;
		retorno = 0;
		printf("MONTOOOOOOO:   %d", monto );

	}
	return retorno;
}

int movie_getMonto(Pelicula* this,int* monto){
	int retorno=-1;
	if( this != NULL &&  monto != NULL){
		*monto = this -> monto;
		retorno = 0;
	}
	return retorno;
}

void movie_printfOne(Pelicula* this){

	char nombreDia[50];

	obtenerDia((*(this)).dia, nombreDia);
	printf("\n  ****************  DATOS DE LA PELICULA  ***************** ");
	printf("\n Id venta %d.  Pelicula: %s,      dia: %s,      Horario: %s,         sala: $%d      cantidad de entradas: $%d ",
			(*(this)).id_venta,
			(*(this)).nombre_pelicula,
			nombreDia,
			(*(this)).horario,
			(*(this)).sala,
			(*(this)).cantidad_entradas);

}




int movie_sortHoras(void* thisA, void* thisB)
{
	int retorno=0;
	char auxiliarHorasA[20];
	char auxiliarHorasB[20];

		if(thisA!=NULL && thisB!=NULL)
		{
			if(     movie_getHorario(thisA, auxiliarHorasA)==0 &&
					movie_getHorario(thisB, auxiliarHorasB)==0)
			{
				if(strcmp (auxiliarHorasA , auxiliarHorasB) > 0)
				{
					retorno=1;
				}
				if(strcmp (auxiliarHorasA , auxiliarHorasB)  < 0)
				{
					retorno=-1;
				}
			}
		}
		return retorno;
}


int movie_sortNombres(void* thisA, void* thisB){
	int retorno=0;
	char auxiliarNombreA[130];
	char auxiliarNombreB[130];

		if(thisA!=NULL && thisB!=NULL){
			if(     movie_getNombre(thisA, auxiliarNombreA)==0 &&
					movie_getNombre(thisB, auxiliarNombreB)==0){
				if(strcmp (auxiliarNombreA , auxiliarNombreB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarNombreA , auxiliarNombreB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int movie_sortID(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarIdA;
	int auxiliarIdB;

		if(thisA!=NULL && thisB!=NULL){
			if(     movie_getId(thisA, &auxiliarIdA)==0 &&
					movie_getId(thisB, &auxiliarIdB)==0){
				if(auxiliarIdA > auxiliarIdB){
					retorno=1;
				}
				if(auxiliarIdA < auxiliarIdB){
					retorno=-1;
				}
			}
		}
		return retorno;
}


int movie_sortSala(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarSueldoA;
	int auxiliarSueldoB;

		if(thisA!=NULL && thisB!=NULL){
			if(     movie_getSala(thisA, &auxiliarSueldoA)==0 &&
					movie_getSala(thisB, &auxiliarSueldoB)==0){
				if(auxiliarSueldoA > auxiliarSueldoB){
					retorno=1;
				}
				if(auxiliarSueldoA < auxiliarSueldoB){
					retorno=-1;
				}
			}
		}
		return retorno;
}


int obtenerDia(int numeroDeSector, char nombreDeDia[]){

	int retorno = 1;
	if(numeroDeSector > -1	&& numeroDeSector <7){

		switch (numeroDeSector) {
			case 0:
					strcpy(nombreDeDia,"Domingo");
				break;
			case 1:
					strcpy(nombreDeDia,"Lunes");
			break;
			case 2:
					strcpy(nombreDeDia,"Martes");
				break;
			case 3:
					strcpy(nombreDeDia,"Miércoles");
				break;
			case 4:
					strcpy(nombreDeDia,"Jueves");
				break;
			case 5:
					strcpy(nombreDeDia,"Viernes");
				break;
			case 6:
					strcpy(nombreDeDia,"Sábado");
				break;
		}
		retorno = 0;

	}
	return retorno;
};

void calcularMonto(void* this){

	int diaAuxiliar;
	int cantidadEntradasAuxiliar;
	int monto;
	int total;

	if (this != NULL){
		printf("entró a calcularMonto");
		movie_getDia(this, &diaAuxiliar);
		movie_getCantidadEntradas(this, &cantidadEntradasAuxiliar);


		if( diaAuxiliar > 0 && diaAuxiliar < 4)
		{// 1. Los días Lunes, martes y miércoles el precio de cada entrada es de $240

			monto =  cantidadEntradasAuxiliar * 240;
			movie_setMonto( this, monto );
			printf("diaAuxiliar > 0 && diaAuxiliar < 4");
		}
		else
		{ // 2. El resto de los días el costo de cada entrada es de $350
			monto =  cantidadEntradasAuxiliar * 350;
			movie_setMonto( this, monto );

			printf("al else");
		}
		if( cantidadEntradasAuxiliar > 3 ){
  	  	  // 3. Si las entradas adquiridas fueron más de 3, se aplicará un descuento del 10%


			total = monto - ((monto * 10 )/100);
			movie_setMonto( this, total );
			printf("cantidadEntradasAuxiliar > 3 ");
		}

		}

}
/*
 * l usuario ingresará el número de sala y se imprimirá por pantalla:
• Cantidad de entradas vendidas para la sala.
• Monto total facturado para la sala.
• Listado de películas que se proyectaron en dicha sala (sin repetir).
 * */

/*
int calcularEntradasSala1( void* this){
	int retorno = 0;
	int cantidadEntradasAuxiliar;
	int sala1;
	if (this != NULL){

		movie_getSala(this, sala1);
		if(sala1 == 1){
			movie_getCantidadEntradas(this, &cantidadEntradasAuxiliar);
		}

	}

	return cantidadEntradasAuxiliar;
}

*/
