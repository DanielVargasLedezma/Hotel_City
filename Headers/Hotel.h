/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hotel.h
 * Author: Dani
 *
 * Created on August 26, 2021, 6:11 PM
 */

#ifndef HOTEL_H
#define HOTEL_H
#include <time.h>
#include "Contenedora.h"
#include "ListaReservaciones.h"

extern Contenedora* hotel;

extern void iniciarHotel(int n, int m);
extern void inicializarHabitaciones();
extern void setearHabitacionesLibre();

/*
Retorna el costo total si las validaciones son correctas;
Retorna -1 si la habitacion ya ha sido pagada y esta pendiente de liberar;
Retorna 0 si la habitacion no esta ocupada
*/
extern double pagarHabitacion(int ced, int i, int j);

extern int liberarHabitacionCedula(int ced);
extern int cantidadHabitacionesLibres();
extern int cantidadHabitacionesEnMant();
extern int cantidadHabitacionesOcupadas();

//Retorna 0 si esta libre, 1 si esta ocupada o 2 si esta en mantenimiento
extern int estadoHabitacion(int j, int i);
extern int cantidadHabitacionesConEstadoTipo(int tipo);

extern void checkIn(Cliente* c, Informacion* info, int piso, int numhab);

extern void registrarReservacion(Cliente* c, Informacion* info, int piso, int numhab);

extern void liberarMemoria();

#endif /* HOTEL_H */
