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
#include "Contenedora.h"
#include "ListaReservaciones.h"

extern void guardarLista(ListaReservacion *lista);

extern void escribirNodo(Reservacion *data, FILE *reservaciones);

extern void guardarHabitaciones(Contenedora *contenedora);

extern void escribirHabitacion(Habitacion *data, FILE *habitaciones);

extern void cargarLista();

extern void cargarNodo(Reservacion *data, FILE *reservaciones);

extern void cargarHabitaciones(Contenedora *contenedora);

extern Habitacion cargarHabitacion(Habitacion data, FILE *habitaciones);

#endif /* ARCHIVOS_H */
