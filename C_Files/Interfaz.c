/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.c
 * Author: Dani
 * 
 * Created on August 29, 2021, 7:51 PM
 */

#include "../Headers/Interfaz.h"

void iniciarHotelInterfaz() {

    int n, m;
    printf("Digite el numero de pisos que desea que hotel tenga: ");
    scanf("%d", &m);

    printf("Digite el numero de cuartos que desea que hotel tenga por piso: ");
    scanf("%d", &n);

    iniciarHotel(n, m);
}

void printHabitaciones() {

    int numc;

    for (int i = 0; i < hotel->row_count; i++) {
        for (int j = 0; j < hotel->col_count; j++) {
            numc = hotel->habitaciones[i][j].numCamas;
            printf("La habitacion %s", (hotel->habitaciones[i][j].identificador));
            printf(" tiene las siguientes camas: %i", numc);
            printf(", Clasificacion: %s \n", (hotel->habitaciones[i][j].clasificacion));
        }
    }
}