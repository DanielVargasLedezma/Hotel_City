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
#include <stdlib.h>
#include "Contenedora.h"

Contenedora *hotel;

extern void iniciarHotel(int n, int m);

extern void liberarMemoria();
#endif /* HOTEL_H */
