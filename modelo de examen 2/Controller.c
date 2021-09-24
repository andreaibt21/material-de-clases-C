 /** controller.c
 *
 *      Author: Andrea Brice�o
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


int controller_addMovie(LinkedList* pointerArrayListMovies){

	int retorno = -1;
    Pelicula *peliculaAuxiliar = NULL;
    int  auxiliarId = 0;
	int idMaximo;
	char auxiliarNombre[200];
	char auxiliarHorasTrabajadas[20];
	int auxiliarSala;
	int cantidadEmployees;
	int auxiliarCantidad_entradas;

    		if (pointerArrayListMovies != NULL){

    			printf("is empty de ll ?  %d",ll_isEmpty(pointerArrayListMovies));
    				printf("\n    ---------------- Alta de un empleado nuevo ------------- \n");
    				if (  (utn_getString(auxiliarNombre,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
					      (utn_getString(auxiliarHorasTrabajadas,"\n Ingrese las horas trabajadas (Entre 0 y 500) ", "\n Error, intente nuevamente",3) == 0) &&
					      (utn_getNumero(&auxiliarSala,"\n Ingrese el sueldo (Entre 1 y 90000) ", "\n Error, intente nuevamente", 1, 90000,3) == 0) &&
					      (utn_getNumero(&auxiliarCantidad_entradas,"\n Ingrese el sueldo (Entre 1 y 90000) ", "\n Error, intente nuevamente", 1, 90000,3) == 0)
				       ){
    					if( ll_isEmpty(pointerArrayListMovies) == 0){

    						cantidadEmployees = ll_len(pointerArrayListMovies);

							for(int i=0; i<cantidadEmployees ; i++){

								peliculaAuxiliar =ll_get(pointerArrayListMovies, i);
								movie_getId(peliculaAuxiliar, &idMaximo);

								if(  auxiliarId>idMaximo ){
									idMaximo = auxiliarId;
								};
							};
    					};
    					printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    					idMaximo++;
    				    printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    					peliculaAuxiliar = movie_new();

    					if(   (movie_setId(peliculaAuxiliar, idMaximo) == 0) &&
  							  (movie_setNombre(peliculaAuxiliar, auxiliarNombre) == 0) &&
							  (movie_setHorario(peliculaAuxiliar, auxiliarHorasTrabajadas) == 0) &&
							  (movie_setSala(peliculaAuxiliar, auxiliarSala) == 0) &&
							  (movie_setCantidadEntradas(peliculaAuxiliar, auxiliarCantidad_entradas) == 0)

    					){
    						ll_add(pointerArrayListMovies, peliculaAuxiliar);
							printf("\nEl empleado cargado es: \n");
							movie_printfOne(peliculaAuxiliar);
							retorno=0;
    					}else{
    						printf("\nHubo un error al cargar el empleado \n");

    					};
    				};
    		};
	return retorno;
}


int controller_editMovie(LinkedList* pointerArrayListMovies)
{

	int retorno = -1;
	Pelicula *peliculaAuxiliar = NULL;
	char auxiliarNombre[200];
	char auxiliarHorasTrabajadas[20];
	int auxiliarSueldo;
	int datoACambiar;
	int idEmployeeACambiar;
	int cantidadEmployees;
	int  auxiliarId = 0;
	int idMaximo;
	if(ll_isEmpty(pointerArrayListMovies) == 0 && pointerArrayListMovies != NULL){

			printf("\n    ---------------- Modificaci�n de un empleado ------------- \n");


				cantidadEmployees = ll_len(pointerArrayListMovies);
				for(int i=0; i<cantidadEmployees ; i++){
					peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
					movie_getId(peliculaAuxiliar, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;


					};
				};


				if(	utn_getNumero(&idEmployeeACambiar, "\nIngrese el id del Empleado a cambiar    ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadEmployees; i++) {
						peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
						movie_getId(peliculaAuxiliar, &auxiliarId);

						if (idEmployeeACambiar == auxiliarId) {
							printf("\nEmpleado encontrado");
							movie_printfOne(peliculaAuxiliar);
							break;
						}
					}
					do{
						utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar horas trabajadas \n3- modificar salario, \n4-  Volver al men� principal        ", "\n Error, ingrese nuevamente", 1, 4, 3);

						switch (datoACambiar) {
							case 1:
								if (  (utn_getString(auxiliarNombre,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
									  (movie_setNombre(peliculaAuxiliar, auxiliarNombre) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											movie_printfOne(peliculaAuxiliar);
											retorno=0;
								}
								break;
							case 2:
								if (  (utn_getString(auxiliarHorasTrabajadas,"\n Ingrese las horas trabajadas  ", "\n Error, intente nuevamente",3) == 0) &&
									  (movie_setHorario(peliculaAuxiliar, auxiliarHorasTrabajadas) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											movie_printfOne(peliculaAuxiliar);
											retorno=0;
								}
								break;
							case 3:
								if (  (utn_getNumero(&auxiliarSueldo,"\n Ingrese el sueldo  ", "\n Error, intente nuevamente", 1, 90000,3) == 0) &&
									  (movie_setSala(peliculaAuxiliar, auxiliarSueldo) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											movie_printfOne(peliculaAuxiliar);
											retorno=0;
								}
							break;
							case 4:
							break;
						}
					 }while(  datoACambiar != 4);


				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay empleados cargados");

	}

	return retorno;
}


int controller_removeMovie(LinkedList* pointerArrayListMovies)
{

	int retorno = -1;
	Pelicula *peliculaAuxiliar = NULL;
	int  auxiliarId = 0;
	char validacion;
	int idEmployeeACambiar;
	int cantidadEmployees;
	int idMaximo;

	int indexEmployee;
	if(ll_isEmpty(pointerArrayListMovies) == 0 && pointerArrayListMovies != NULL){

			printf("\n    ---------------- Baja de un empleado ------------- \n");


				cantidadEmployees = ll_len(pointerArrayListMovies);
				for(int i=0; i<cantidadEmployees ; i++){
					peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
					movie_getId(peliculaAuxiliar, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;
					};
				};


				if(	utn_getNumero(&idEmployeeACambiar, "\nIngrese el id del Empleado a dar de baja  ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadEmployees; i++) {
						peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
						movie_getId(peliculaAuxiliar, &auxiliarId);

						if (idEmployeeACambiar == auxiliarId) {
							printf("\nEmpleado encontrado");
							movie_printfOne(peliculaAuxiliar);
							indexEmployee =  ll_indexOf(pointerArrayListMovies, peliculaAuxiliar);
							break;
						}

					}
							utn_getCharAceptar(&validacion, "\n�Est� seguro que desea borrar este empleado?  ('s' o 'n')        ", "\n Error, ingrese nuevamente", 3);
							switch (validacion) {

								case 's':
									ll_remove(pointerArrayListMovies, indexEmployee);
									printf("\n Empleado eliminado");
								break;
								case 'n':
									printf("\n Operaci�n cancelada");
								break;
							}
				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay empleados cargados");

	}

	return retorno;
}

int controller_ListMovie(LinkedList* pointerArrayListMovies){
	int retorno = -1;
	int  auxiliarId;
	char auxiliarNombre[200];
	char auxiliarHorario[20];
	int auxiliarSala;
	int auxiliarEntradas;
	int auxiliarDia;
	char nombreDia[50];
	int auxiliarMonto;



	int lenghtEmployees = ll_len(pointerArrayListMovies);
	if (pointerArrayListMovies != NULL && lenghtEmployees > 0){
		printf("\n  ****************  DATOS PERSONALES DE EMPLEADOS  ***************** ");


		for(int i = 0; i < lenghtEmployees; i++ ){
			Pelicula*  peliculaAuxiliar= ll_get(pointerArrayListMovies, i);

			movie_getId( peliculaAuxiliar, &auxiliarId);
			movie_getNombre(peliculaAuxiliar, auxiliarNombre);
			movie_getHorario(peliculaAuxiliar, auxiliarHorario);
			movie_getSala(peliculaAuxiliar, &auxiliarSala);
			movie_getCantidadEntradas(peliculaAuxiliar, &auxiliarEntradas);
			movie_getDia(peliculaAuxiliar, &auxiliarDia);
			movie_getMonto(peliculaAuxiliar, &auxiliarMonto);
			obtenerDia(auxiliarDia, nombreDia);

			printf("\n Id venta %d.  Pelicula: %s,      Horario: %s,      dia: %s,      sala: %d      cantidad de entradas: %d      monto: %d",
																	   auxiliarId,
																	   auxiliarNombre,
																	   auxiliarHorario,
																	   nombreDia,
																	   auxiliarSala,
																	   auxiliarEntradas,
																	   auxiliarMonto);
		};
		retorno = 0;
	}else{
		printf("No hay empleados cargados");

	}


    return retorno;
}


int controller_sortMovie(LinkedList* pointerArrayListMovies)
{
		int retorno = -1;
		int(*funcionTipoOrden)(void*,void*);
		int tipodeSort;


		int lenghtEmployees = ll_len(pointerArrayListMovies);
		if (pointerArrayListMovies != NULL && lenghtEmployees > 0){



			utn_getNumero(&tipodeSort, "\n Ingrese una opcion del 1 al 8 "
					"\n1- Ordenar ID de forma ascendente "
					"\n2- Ordenar ID de forma descendente "
					"\n3- Ordenar Nombres de forma ascendente "
					"\n4- Ordenar Nombres de forma descendente "
					"\n5- Ordenar Horario de forma ascendente "
					"\n6- Ordenar Horario de forma descendente "
					"\n7- Ordenar Sala de forma ascendente "
					"\n8- Ordenar Sala de forma descendente "
					"\n9-  Volver al men� principal        ", "\n Error, ingrese nuevamente", 1, 9, 3);

					switch (tipodeSort) {
						case 1:
						case 2:
							funcionTipoOrden = movie_sortID;
							break;
						case 3:
						case 4:
							funcionTipoOrden = movie_sortNombres;
							break;
						case 5:
						case 6:
							funcionTipoOrden = movie_sortHoras;
							break;
						case 7:
						case 8:
							funcionTipoOrden = movie_sortSala;
							break;
						case 9:
							break;
					}//Fin switch

			if(tipodeSort % 2 != 0){
				ll_sort(pointerArrayListMovies, funcionTipoOrden, 1);
			}else{
				ll_sort(pointerArrayListMovies, funcionTipoOrden, 0);
			}
			printf("\n               ** Lista ordenada ** ");
			retorno = 0;
		}else{
			printf("No hay empleados cargados");

		}

    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pointerArrayListMovies)
{
	int retorno = -1;
	int  auxiliarId;
	char auxiliarNombre[200];
	char horario[20];
	int auxiliarDia;
	int auxiliarSala;
	int auxiliarCantidad_entradas ;
	int auxiliarMonto;

	if(ll_isEmpty(pointerArrayListMovies) == 0){
	FILE *pointerFile = fopen(path,"w");
		if (path != NULL && pointerArrayListMovies != NULL && pointerFile != NULL){
			fprintf( pointerFile,"id,    nombre,    dia,  horario,    sala,   cantidad de entradas,    monto\n");
			for(int i = 0; i < ll_len(pointerArrayListMovies); i++){

				Pelicula  *peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
				if(		movie_getId( peliculaAuxiliar, &auxiliarId) == 0 &&
						movie_getNombre(peliculaAuxiliar, auxiliarNombre) == 0 &&
						movie_getHorario(peliculaAuxiliar, horario) == 0 &&
						movie_getDia(peliculaAuxiliar, &auxiliarDia) == 0 &&
						movie_getCantidadEntradas(peliculaAuxiliar, &auxiliarCantidad_entradas) == 0 &&
						movie_getSala(peliculaAuxiliar, &auxiliarSala) == 0  &&
						movie_getMonto(peliculaAuxiliar, &auxiliarMonto)== 0
					)
				{
				fprintf( pointerFile,"%d, %s, %s, %d,  %d, %d, %d\n",
														 auxiliarId,
														 auxiliarNombre,
														 horario,
														 auxiliarDia,
														 auxiliarSala,
														 auxiliarCantidad_entradas,
														 auxiliarMonto);
				}
			}

			fclose(pointerFile);
			printf("\nDatos guardados en %s", path);
			retorno = 0;
		};
	}else{
		printf("Error, No hay datos para guardar");

	}

	return retorno;


}


int controller_saveAsBinary(char* path , LinkedList* pointerArrayListMovies)
{
	int retorno = -1;
	int cantidadEscrita;

	if(ll_isEmpty(pointerArrayListMovies) == 0){
		if (path != NULL && pointerArrayListMovies != NULL){
			FILE *pointerFile=fopen(path,"wb");

			int lenghtEmployees = ll_len(pointerArrayListMovies);

			for(int i = 0; i < lenghtEmployees; i++ ){

				Pelicula*  peliculaAuxiliar= ll_get(pointerArrayListMovies, i);
				if(pointerFile != NULL){
					cantidadEscrita = fwrite(peliculaAuxiliar, sizeof(Pelicula),1, pointerFile);
				};
			}
			if (cantidadEscrita < 1){
				printf("\nError al escribir el archivo");
			}else{
				printf("\nDatos guardados en %s", path);
				retorno = 0;
			}
			fclose(pointerFile);
		};
	}else{
		printf("Error, No hay datos para guardar");

	}
	return retorno;
}


int controller_loadFromText(char* path , LinkedList* pointerArrayListMovies){

	int retorno = -1;
	char validacion = 's';
	if (path != NULL && pointerArrayListMovies != NULL){


		if(ll_isEmpty (pointerArrayListMovies ) == 1){

			FILE *pointerFile=fopen(path,"r");

			if(pointerFile != NULL &&
			   parser_EmployeeFromText(pointerFile, pointerArrayListMovies) == 0 ){
				printf("\nArchivo leido y cerrado con �xito");
				retorno = 0;

			}else{
				printf("\nNo se pudo leer el archivo");
			}
			fclose(pointerFile);

		}else{

			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
			switch (validacion)
			{
				case 'n':
					printf("\nSe han borrado los datos cargados anteriormente.  ");
					ll_clear(pointerArrayListMovies);
					FILE *pointerFile=fopen(path,"r");

					if(pointerFile != NULL && parser_EmployeeFromText(pointerFile, pointerArrayListMovies) == 0 )
					{
						printf("\nArchivo nuevo leido y cerrado con �xito");
						fclose(pointerFile);
						retorno = 0;
					}
				break;
				case 's':
					if(controller_saveAsText( "respaldo.csv", pointerArrayListMovies) == 0){

						ll_clear(pointerArrayListMovies);

						FILE *pointerFile=fopen(path,"r");

						if(pointerFile != NULL && parser_EmployeeFromText(pointerFile, pointerArrayListMovies) == 0 )
						{
							printf("\nArchivo nuevo leido y cerrado con �xito");
							fclose(pointerFile);
							retorno = 0;
						}


					}
				break;
				}
			}
	}
    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pointerArrayListMovies){

	    int retorno = -1;
	    	char validacion = 's';
	    	if (path != NULL && pointerArrayListMovies != NULL){


	    		if(ll_isEmpty (pointerArrayListMovies ) == 1){

	    			FILE *pointerFile=fopen(path,"rb");

	    			if(pointerFile != NULL &&
	    				parser_EmployeeFromBinary(pointerFile, pointerArrayListMovies) == 0 ){
	    				printf("\nArchivo leido y cerrado con �xito");
	    				retorno = 0;

	    			}else{
	    				printf("\nNo se pudo leer el archivo");
	    			}
	    			fclose(pointerFile);

	    		}else{

	    			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
	    			switch (validacion)
	    			{
	    				case 'n':
	    					printf("\nSe han borrado los datos cargados anteriormente.  ");
	    					ll_clear(pointerArrayListMovies);
	    					FILE *pointerFile=fopen(path,"rb");

	    					if(  pointerFile != NULL &&
	    					     parser_EmployeeFromBinary(pointerFile, pointerArrayListMovies)  == 0  )
	    					{
	    						printf("\nArchivo nuevo leido y cerrado con �xito");
	    						fclose(pointerFile);
	    						retorno = 0;
	    					}
	    				break;
	    				case 's':
	    					if ( controller_saveAsBinary("respaldo.bin",pointerArrayListMovies) == 0 )
	    					{
								ll_clear(pointerArrayListMovies);
								FILE *pointerFile=fopen(path,"rb");

								if(  pointerFile != NULL &&
									 parser_EmployeeFromBinary(pointerFile, pointerArrayListMovies)  == 0  )
								{
									printf("\nArchivo nuevo leido y cerrado con �xito");
									fclose(pointerFile);
									retorno = 0;
								}
	    					}
	    				break;
	    				}
	    			}
	    	}
	        return retorno;


}


int controller_Contador(LinkedList* pointerArrayListMovies){
	int retorno = -1;

	if (pointerArrayListMovies != NULL){}


	return retorno;
}


/*
int controller_Informes(LinkedList* pointerArrayListMovies){
	Pelicula *peliculaAuxiliar = NULL;
	int retorno = -1;
	int tipodeInforme;
	int  auxiliarSala = 0;
	int salaMaxima;

	utn_getNumero(&tipodeInforme,
			"\n _________Ingrese una opcion del 1 al 8 "
			"\n | 1- Cantidad de entradas vendidas para la sala."
			"\n | 2- Monto total facturado para la sala.  "
			"\n | 3- Listado de pel�culas que se proyectaron en dicha sala  "
			"\n | 4-  Volver al men� principal    \n |    ", "\n Error, ingrese nuevamente", 1, 5, 3);

	if (pointerArrayListMovies != NULL && ll_isEmpty(pointerArrayListMovies == 0)){


			if(ll_isEmpty(pointerArrayListMovies) == 0 && pointerArrayListMovies != NULL){

					printf("\n    ---------------- Modificaci�n de un empleado ------------- \n");



						for(int i=0; i< ll_len(pointerArrayListMovies); i++){
							peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
							movie_getSala(peliculaAuxiliar, &salaMaxima);
							if(  auxiliarSala>salaMaxima )
							{
								salaMaxima = auxiliarSala;
							};
						};


						if(	utn_getNumero(&idEmployeeACambiar, "\nIngrese el id del Empleado a cambiar    ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){


						}}


		//usuario ingresar� el n�mero de sala y se imprimir� por pantalla:
		//"\n | 1- Cantidad de entradas vendidas para la sala."

		switch (tipodeInforme) {
			case 1:

				utn_getNumero(&tipodeInforme,
							"\n Ingrese el numero de sala", "\n Error, ingrese nuevamente", 1, 5, 3);
				for(int i = 0; i < ll_len(pointerArrayListMovies); i++){

								Pelicula  *peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
								//movie_getSala(peliculaAuxiliar, &auxiliarSala)
				}



				break;
			default:
				break;
		}



		 retorno = 0;
	}

	return retorno;

}*/
