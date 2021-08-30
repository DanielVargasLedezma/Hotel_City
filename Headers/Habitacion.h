/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Habitacion.h
 * Author: Dani
 *
 * Created on August 26, 2021, 5:20 PM
 */

#ifndef HABITACION_H
#define HABITACION_H
#include "Cliente.h"
#include "Informacion.h"

typedef struct Habitacion{
    
    char identificador[5];
    char estado;
    Cliente *cliente;
    Informacion *informacion;
    int numCamas; //Random each time
    
}Habitacion;

#endif /* HABITACION_H */
