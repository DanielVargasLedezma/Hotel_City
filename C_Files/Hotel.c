/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hotel.c
 * Author: Dani
 * 
 * Created on August 26, 2021, 6:11 PM
 */

#include "../Headers/Hotel.h"
#include <time.h>
#include <string.h>
Contenedora *hotel;

void iniciarHotel(int n, int m) {
    hotel = (Contenedora *) malloc(sizeof (Contenedora));

    hotel->col_count = m;

    hotel->row_count = n;

    (hotel->habitaciones) = malloc(n * sizeof (Habitacion *));

    for (int i = 0; i < n; i++) {
        (hotel->habitaciones)[i] = malloc(m * sizeof (Habitacion));
    }
    inicializarHabitaciones();
}

void inicializarHabitaciones() {
    srand(time(NULL));

    for (int i = 0; i < hotel->row_count; i++) {
        for (int j = 0; j < hotel->col_count; j++) {

            int clasificador = rand() % 3 + 1;
            if (clasificador == 1) {
                hotel->habitaciones[i][j].clasificacion[0] = 'P';
                hotel->habitaciones[i][j].clasificacion[1] = 'C';
            } else if (clasificador == 2) {
                hotel->habitaciones[i][j].clasificacion[0] = 'S';
                hotel->habitaciones[i][j].clasificacion[1] = 'C';
            } else {
                hotel->habitaciones[i][j].clasificacion[0] = 'T';
                hotel->habitaciones[i][j].clasificacion[1] = 'C';
            }

            char num1[3];
            char num2[3];
            sprintf(num1, "%d", i + 1);
            sprintf(num2, "%d", j + 1);

            char id[6] = {'P'};
            char tmp[2] = {'H'};

            strcat(id, num2);
            strcat(id, tmp);
            strcat(id, num1);

            for (int k = 0; k < 7; k++) {
                hotel->habitaciones[i][j].identificador[k] = id[k];
            }

            hotel->habitaciones[i][j].numCamas = rand() % 5 + 1;
        }
    }
}

void liberarMemoria() {
    for (int i = 0; i < hotel->row_count; i++) {
        free(hotel->habitaciones[i]);
    }
    free(hotel->habitaciones);

    free(hotel);
}
