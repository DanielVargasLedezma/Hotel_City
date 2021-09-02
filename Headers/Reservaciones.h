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

typedef struct Reservacion {

    Informacion* informacion;

    //[0] dia - [1] mes - [2] año - [3] hora - [4] minutos - [5] segundos
    int date_reserved[6];

    //[0] dia - [1] mes - [2] año - [3] hora - [4] minutos - [5] segundos
    int date_finished[6];

    char nombreCliente[10];

    int costoReservacion;

    char estadoReservacion;

}Reservacion;

#endif /* RESERVACIONES_H */
