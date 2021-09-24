 /** Employee.h
 *
 *      Author: Andrea Briceño
 */

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
	int id_venta;
    char nombre_pelicula[300];
    int dia;
    char horario[20];
    int sala;
    int cantidad_entradas;
    int monto;
} Pelicula;



/** \brief reserva un espacio de memoria de tipo empleado y lo retorna
 *
 * \param this LinkedList* Puntero a la lista
 * \return Retorna un empleado nuevo
 *
 */
Pelicula* movie_new();


/** \brief Crea un empleado nuevo y lo devuelve por retorno
 *
 * \param char* idStr id del empleado
 * \param char* nombreStr nombre del empleado
 * \param char* horasTrabajadasStr horas de trabajo del empleado
 * \param char* sueldoStr sueldo del empleado
 * \return Retorna un empleado nuevo
 */
	//id_venta,
	//nombre_pelicula,
	//dia,
	//horario,
	//sala,
	//cantidad_entradas

Pelicula* movie_newParametros(char* id_ventaStr,char* nombre_peliculaStr,char* diaStr,char* horarioStr, char* salaStr,  char* cantidad_entradasStr);


/** \brief Asigna un id al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int id id del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setId(Pelicula* this,int id_venta);

/** \brief Asigna un id del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int id id del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getId(Pelicula* this,int* id_venta);


/** \brief Asigna un nombre al empleado pasado por parametro
 * \param Employee* this empleado
 * \param char* nombre nombre del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setNombre(Pelicula* this,char* nombre_pelicula);

/** \brief Asigna un nombre del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param char* nombre nombre del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getNombre(Pelicula* this,char* nombre_pelicula);


/** \brief Asigna  horas de trabajo al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int horasTrabajadas horas de trabajo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setHorario(Pelicula* this,char* horario);

/** \brief Asigna horas de trabajo del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int horasTrabajadas horas de trabajo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getHorario(Pelicula* this,char* horario);


/** \brief Asigna un nombre al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int sueldo sueldo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setSala(Pelicula* this,int sala);
/** \brief Asigna un id del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int sueldo sueldo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getSala(Pelicula* this,int* sala);

int movie_setDia(Pelicula* this,int dia);
int movie_getDia(Pelicula* this,int* dia);

int movie_getMonto(Pelicula* this,int* monto);
int movie_setMonto(Pelicula* this,int monto);

int movie_setCantidadEntradas(Pelicula* this,int cantidad_entradas);
int movie_getCantidadEntradas(Pelicula* this,int* cantidad_entradas);

/** \brief Imprime por consola un empleado
 * \param Employee* this empleado
 * \return void
 */
void movie_printfOne(Pelicula* this);



/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA horas de trabajo de un empleado
 * \param void* thisB horas de trabajo de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortHoras(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA nombre  de un empleado
 * \param void* thisB nombre de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortNombres(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA id de un empleado
 * \param void* thisB id de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortID(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA sueldo de un empleado
 * \param void* thisB sueldo de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortSala(void* thisA, void* thisB);
int obtenerDia(int numeroDeSector, char nombreDeDia[]);
void calcularMonto(void* this);
int calcularEntradasSala1( void* this);

#endif // employee_H_INCLUDED
