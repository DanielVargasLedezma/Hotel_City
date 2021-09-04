/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.h
 * Author: Dani
 *
 * Created on August 29, 2021, 7:51 PM
 */

#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <stdio.h>
#include <string.h>
#include "Hotel.h"

extern void iniciarPrograma();

extern void iniciarHotelInterfaz();
extern void printHabitaciones();

extern void realizarReservacion();

extern void cantidadHabitacionesLibresConNCamas(int numeroDeCamas);

extern void menu();

#endif /* INTERFAZ_H */
