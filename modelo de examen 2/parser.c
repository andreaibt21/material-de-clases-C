#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pointerFile , LinkedList* pointerArrayListMovies){
	int retorno = 0;
	char buffer[4][130];

	Pelicula* pointerAuxEmpleado=NULL;

	if(pointerFile != NULL && pointerArrayListMovies != NULL){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));


	while( !feof(pointerFile) ){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));
		pointerAuxEmpleado = movie_newParametros(*(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));
		            //Pelicula* movie_newParametros(char* id_ventaStr,char* nombre_peliculaStr,char* siaStr,char* horarioStr, char* salaStr,  char* cantidad_entradasStr);

		if(pointerAuxEmpleado != NULL){

			ll_add(pointerArrayListMovies,pointerAuxEmpleado);

			retorno=0;
		}


	}

	}
  	 return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pointerFile , LinkedList* pointerArrayListEmployee)
{	int retorno;
	int retornoLeido;
	Pelicula* pointerAuxEmpleado=NULL;
	Pelicula auxiliarEmployee;

		if(pointerFile!=NULL && pointerArrayListEmployee!=NULL){

			while( !feof(pointerFile) ){

				retornoLeido = fread(&auxiliarEmployee,sizeof(Pelicula),1,pointerFile);
				pointerAuxEmpleado = movie_new();
				if (pointerAuxEmpleado != NULL ) {

					if(retornoLeido != 0){

						if(  (movie_setId(pointerAuxEmpleado, auxiliarEmployee.id_venta)   == 0) &&
							(movie_setNombre(pointerAuxEmpleado, auxiliarEmployee.nombre_pelicula)  == 0) &&
							(movie_setHorario(pointerAuxEmpleado, auxiliarEmployee.horario) == 0) &&
							(movie_setSala(pointerAuxEmpleado, auxiliarEmployee.sala) == 0) &&
							(movie_setCantidadEntradas(pointerAuxEmpleado, auxiliarEmployee.cantidad_entradas) == 0)
							)
						{

							ll_add(pointerArrayListEmployee, pointerAuxEmpleado);
							retorno = 0;
						}
					}

				}
			}
		}

    return retorno;
}
