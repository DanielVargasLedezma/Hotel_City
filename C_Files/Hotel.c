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

Contenedora *hotel;

void iniciarHotelInterfaz(){
    
    int n, m;
    printf("Digite el numero de pisos que desea que hotel tenga: ");
    scanf("%d", m);
    
    printf("Digite el numero de cuartos que desea que hotel tenga por piso: ");
    scanf("%d", n);
    
    iniciarHotel(n, m);
}

void iniciarHotel(int n, int m){
    hotel = (Contenedora *) malloc(sizeof(Contenedora));
    
    hotel->col_count = m;
    
    hotel->row_count = n;
    
    (hotel->habitaciones) = malloc(n * sizeof(Habitacion *));
    
    for(int i =0; i < n; i++){
        (hotel->habitaciones)[i] = malloc(m * sizeof(Habitacion));
        
    }
}

void liberarMemoria(){
    
    for (int i = 0; i < hotel->row_count; i++) {
        free(hotel->habitaciones[i]);
    }
    
    free(hotel->habitaciones);
    
    free(hotel);
}