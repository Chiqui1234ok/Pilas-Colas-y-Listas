#include "funciones.h"

ST_NODO *insertarOrdenadoNoDuplicado(ST_NODO **cabecera, ST_TXT dato)
{
    ST_NODO *aux = *cabecera;
    ST_NODO *nuevaCarrera = NULL;
    ST_ALUMNO *nuevoAlumno = NULL;
    while( aux )
    {
        if( aux->idCarrera != dato.idCarrera ) // Hay que crear carrera
        {
            nuevaCarrera = crearCarrera(aux, dato.idCarrera); // crea un nodo dónde ste = NULL y dato.idCarrera = idCarrera
            aux->ste = nuevaCarrera; // el último nodo de carrera apunta al nuevo nodo de carrera
        }
        else // Hay que crear al alumno
        {
            nuevoAlumno = crearAlumno(aux->bot, dato.idAlumno); // crea un nodo dónde bot = NULL y dato.idAlumno = idAlumno
            aux->bot = nuevoAlumno; // el último nodo leído de alumno apunta al nuevo nodo de alumno
        } 
    }
    if( aux == NULL ) // Si no hay ninguna carrera, la creamos por primera vez <3
    {
        nuevaCarrera = crearCarrera(aux, dato.idCarrera);
        aux = nuevaCarrera;
    }
}

ST_NODO *crearCarrera(ST_NODO *aux, int idCarrera)
{
    ST_NODO *nuevaCarrera = (ST_NODO*) malloc(sizeof(ST_NODO));
    aux->ste = nuevaCarrera;
    nuevaCarrera->ste = NULL;
    // nuevaCarrera->bot = NULL;
    nuevaCarrera->bot = aux->bot; // en la misma línea del txt, levanto un legajo y lo meto junto con la carrera
    return nuevaCarrera;
}

ST_ALUMNO *crearAlumno(ST_ALUMNO *bot, int idAlumno)
{
    ST_ALUMNO *nuevoAlumno = (ST_ALUMNO*) malloc(sizeof(ST_ALUMNO));
    bot->bot = nuevoAlumno->bot;

    nuevoAlumno->idAlumno = idAlumno;
    nuevoAlumno->bot = NULL;
    return nuevoAlumno;
}

// void crearTxtSalida(ST_NODO **cabecera)