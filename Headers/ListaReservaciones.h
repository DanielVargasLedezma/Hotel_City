/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaReservaciones.h
 * Author: Dani
 *
 * Created on September 1, 2021, 6:37 PM
 */

#ifndef LISTARESERVACIONES_H
#define LISTARESERVACIONES_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DateGenerator.h"
#include "Reservaciones.h"

typedef struct Nodo {

    Reservacion* data;
    struct Nodo* sig;

}Nodo;

typedef struct ListaReservacion {

    Nodo* head;

}ListaReservacion;

extern ListaReservacion* lista;

extern void initList();

extern void push(Reservacion* data);

extern int cantidadAdultosHoy();

extern int cantidadInfantesHoy();

//Total recaudado con todo incluido
extern int totalRecaudadoHoyTI();

//Total recaudado sin todo incluido
extern int totalRecaudadoHoyNTI();

//Total recaudado con todos los clientes de hoy
extern int totalRecaudadoHoy();

//Return 0 si son iguales, 1 si no lo son
extern int compararFechaConHoy(Reservacion *data);

//Return 0 si es reservado en la noche, 1 si no
extern int comprobarSiReservadoEnNoche(int horaReserva);

extern void calcularCostoTotalReservacion(Reservacion* data);

/*
Retorna el costo de la reservacion si cumple con las validaciones;
Retorna -1 si la lista no esta inicializada o si esta vacia;
Retorna 0 si no cumple con las validaciones
*/
extern double terminarReservacion(Cliente* cliente, Informacion * info);

//Return 0 si son iguales, 1 si no lo son
extern int compararSiEsigual(Reservacion* data, Cliente* cliente, Informacion* info);

extern void freeList();

#endif /* LISTARESERVACIONES_H */
