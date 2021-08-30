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
Contenedora *hotel;

void iniciarHotelInterfaz(){
    
    int n, m;
    printf("Digite el numero de pisos que desea que hotel tenga: ");
    scanf("%d", &m);
    
    printf("Digite el numero de cuartos que desea que hotel tenga por piso: ");
    scanf("%d", &n);
    
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
    inicializarCamas();

}

void inicializarCamas(){
    srand (time(NULL));
    for (int i=0;i<hotel->row_count;i++){
        for(int j=0;j<hotel->col_count;j++){
            char id[5]={'P',j+1+'0','H',(i+1)+'0'};
            printf(id);
            printf("\n");
            for (int k=0;k<5;k++){
                hotel->habitaciones[i][j].identificador[k]=id[k];
            }
            hotel->habitaciones[i][j].numCamas=rand()%5+1;
        }
    }
        printcamas();
}

void printcamas(){
    int numc;
    for (int i=0;i<hotel->row_count;i++){
        for(int j=0;j<hotel->col_count;j++){
            numc=hotel->habitaciones[i][j].numCamas;
            printf("La habitacion %s",(hotel->habitaciones[i][j].identificador));
            printf(" tiene las siguientes camas: %i\n",numc);
        }
    }

}
void liberarMemoria(){
    
    for (int i = 0; i < hotel->row_count; i++) {
        free(hotel->habitaciones[i]);
    }
    
    free(hotel->habitaciones);
    
    free(hotel);
}
