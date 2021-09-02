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

extern void freeList();

#endif /* LISTARESERVACIONES_H */
