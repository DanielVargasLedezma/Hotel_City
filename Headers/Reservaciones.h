/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reservaciones.h
 * Author: Dani
 *
 * Created on August 26, 2021, 5:49 PM
 */

#ifndef RESERVACIONES_H
#define RESERVACIONES_H
#include "Informacion.h"
#include "Cliente.h"

typedef struct Reservacion {

    Informacion informacion;

    //[0] day - [1] month - [2] year - [3] hour - [4] minutes - [5] seconds
    int date_reserved[6];

    Cliente cliente;

    double costoReservacion;

    //G por going, D for done
    char estadoReservacion;

    //PC, SC, TC
    char clasificacionHabitacionReservada[3];

} Reservacion;

#endif /* RESERVACIONES_H */
