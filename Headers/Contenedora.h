/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contenedora.h
 * Author: Dani
 *
 * Created on August 26, 2021, 5:18 PM
 */

#ifndef CONTENEDORA_H
#define CONTENEDORA_H
#include "Habitacion.h"

Habitacion **habitaciones;

typedef struct Contenedora{
   
    int row_count; //n
    int col_count;//m
    
    
}Contenedora;

extern Habitacion getHabit(int n, int m);

#endif /* CONTENEDORA_H */
