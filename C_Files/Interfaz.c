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
#include <unistd.h>

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

void menu() {
    int opcion;
    int continuar;
    do {
        printf("\n   1. Cuantas habitaciones estan libres");
        printf("\n   2. Cuantas habitaciones estan en mantenimiento");
        printf("\n   3. Cuántas habitaciones ocupadas");
        printf("\n   4. Cuántas hay desocupadas por cantidad de camas.");
        printf("\n   5. Check in");
        printf("\n   6. Pagar la habitación ");
        printf("\n   7. Liberar la habitación");
        printf("\n   8. Cuántas personas adultas hay el día de hoy. ");
        printf("\n   9. Cuántos niños existen al día de hoy en el hotel");
        printf("\n  10. Recaudacion del dia");
        printf("\n   0. Salir");
        printf("\n\n   Introduzca opcion (0-10): ");

        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                printf("\n   1. Cuantas habitaciones estan libres");
                printf("\n   Numero de habitaciones desocupadas: ");
                printf("\n   Habitaciones en mantenimiento: %i", cantidadHabitacionesLibres());
                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);
                break;


            case 2:
                printf("\n   2. Cuantas habitaciones estan en mantenimiento");
                printf("\n   Habitaciones en mantenimiento: %i", cantidadHabitacionesEnMant());
                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);
                break;


            case 3:
                printf("\n   3. Cuántas habitaciones ocupadas");
                printf("\n   Las siguientes habitachioes estan ocupadas: %i", cantidadHabitacionesOcupadas());
                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);
                break;


            case 4:
            {
                printf("\n   4. Cuántas hay desocupadas por cantidad de camas.");
                printf("\n   Ingrese la cantidad de camas deseada: ");
                int numc=0;
                scanf("%d", &numc);
                if(numc>5&&numc<1){
                    printf("\n Cantidad de camas no valida");
                    break;
                }else{
                printf("\n   Cantidad de habitaciones desocupadas por cantidad de camas: ");
                cantidadHabitacionesLibresConNcamas(numc);
                }
                scanf("%i", &continuar);
                
                break;
            }

            case 5:
                printf("\n   5. Check in ");

                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);
                break;


            case 6:
                printf("\n   6. Pagar la habitación ");\

                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);
                break;


            case 7:
                printf("\n   7. Liberar la habitacion");

                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);

                break;


            case 8:
                printf("\n   8. Cuantas personas adultas hay el dia de hoy. ");

                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);
                break;


            case 9:
                printf("\n   9. Cuantos niños existen al dia de hoy en el hotel");
                printf("\n   Cantidad de niños en el hotel hoy: ");

                printf("\n   Ingrese 1 y enter para continuar");
                scanf("%i", &continuar);
                break;


            case 10:
            {
                int opcion2;
                do {

                    printf("\n  Recaudacion del dia: ");
                    printf("\n   1. Con los clientes, “TODO INCLUIDO”");
                    printf("\n   2. Con los clientes, “Sin TODO INCLUIDO”");
                    printf("\n   3. Con todos los clientes  que hay en el hotel");
                    printf("\n   0. Salir");
                    printf("\n   Introduzca una opcion (0-3): ");
                    scanf("%d", &opcion2);
                    switch (opcion2) {

                        case 1:
                            break;


                        case 2:
                            break;


                        case 3:
                            break;


                        case 0:
                            break;

                    }
                } while (opcion2 != 0);
                break;
            }



        }
    } while (opcion != 0);




}