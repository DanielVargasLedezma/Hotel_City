/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Archivos.h
 * Author: Dani
 *
 * Created on September 5, 2021, 2:38 AM
 */

#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "Hotel.h"

extern void guardarLista(ListaReservacion *lista);

extern void escribirNodo(Reservacion *data, FILE *reservaciones);

extern void guardarHabitaciones(Contenedora *contenedora);

extern void escribirHabitacion(Habitacion *data, FILE *habitaciones);

/*
Retorna -1 si el archivo esta vacio o si hubo un error al abrir el archivo;
Retorna 1 si la carga se realizo con exito
*/
extern int cargarLista();

extern void cargarNodo(Reservacion *data, FILE *reservaciones);

/*
Retorna -1 si el archivo esta vacio o si hubo un error al abrir el archivo;
Retorna 1 si la carga se realizo con exito
*/
extern int cargarHabitaciones();

extern void cargarHabitacion(Habitacion *data, FILE *habitaciones);

#endif /* ARCHIVOS_H */
