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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contenedora.h"
#include "ListaReservaciones.h"

extern Contenedora* hotel;

extern void iniciarHotel(int n, int m);
extern void inicializarHabitaciones();
extern void setearHabitacionesLibre();

extern int cantidadHabitacionesLibres();
extern int cantidadHabitacionesEnMant();
extern int cantidadHabitacionesOcupadas();
extern int estaOcupada(int j, int i);
extern int cantidadHabitacionesConEstadoTipo(int tipo);


extern void checkIn(Cliente* c, Informacion* info, int piso, int numhab);


extern void liberarMemoria();

#endif /* HOTEL_H */
