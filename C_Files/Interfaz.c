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

void iniciarPrograma() {
    
    iniciarHotelInterfaz();

    menu();

    liberarMemoria();
}

void iniciarHotelInterfaz() {

    int n = 0, m = 0;
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

void realizarReservacion() {
    char nombreCliente[10];
    int identificacion = 0, modoDePago = 0, numeroTelefono = 0, numAdultos = 0, numInfantes = 0, dias = 0, todoIncluido = 0, p = 0, n = 0;


    printf("\n   Ingrese el piso de la habitación:");
    scanf("%d", &p);

    printf("\n   Ingrese el número de la habitación:");
    scanf("%d", &n);

    if (estadoHabitacion(n, p) == 1) {
        printf("\n   La habitacion no está disponible:");

    } else {
        Informacion *inf = (Informacion*) malloc(sizeof (Informacion));
        Cliente* c = (Cliente*) malloc(sizeof (Cliente));

        printf("\n   Ingrese el nombre del cliente:");
        scanf("%s", nombreCliente);

        printf("\n   Ingrese la identificacion del cliente:");
        scanf("%d", &identificacion);

        printf("\n   Ingrese el numero de adultos:");
        scanf("%d", &numAdultos);

        printf("\n   Ingrese el numero de infantes:");
        scanf("%d", &numInfantes);

        printf("\n   Ingrese la cantidad de dias:");
        scanf("%d", &dias);

        printf("\n   ¿Desea adquirir el servicio todo incluido?");
        printf("\n   1. Si");
        printf("\n   2. No");
        scanf("%d", &todoIncluido);

        printf("\n   Los metodos de pago son:");
        printf("\n   1. Efectivo");
        printf("\n   2. Tarjeta de debito");
        printf("\n   3. Tarjeta de credito");
        printf("\n   Ingrese el numero correspondiente al metodo de pago:");
        scanf("%i", &modoDePago);

        inf->numOfAdults = numAdultos;
        inf->numOfDays = dias;
        inf->numOfKids = numInfantes;
        inf->typeOfInstance = todoIncluido;

        memcpy(c->nombreCliente, nombreCliente, sizeof c->nombreCliente);

        c->numeroTelefono = numeroTelefono;
        c->identificacion = identificacion;
        c->modoDePago = modoDePago;

        checkIn(c, inf, p, n);
    }
}

void cantidadHabitacionesLibresConNCamas(int numeroDeCamas) {

    int contadorPC = 0, contadorSC = 0, contadorTC = 0;
    char PC[3] = "PC";
    char SC[3] = "SC";
    char TC[3] = "TC";
    //For class 1

    printf("\nHabitaciones de primera clase con %i camas: \n", numeroDeCamas);

    for (int i = 0; i < hotel->row_count; i++) {
        for (int j = 0; j < hotel->col_count; j++) {
            if (hotel->habitaciones[i][j].estado == 'L' && hotel->habitaciones[i][j].numCamas == numeroDeCamas && (strcmp(hotel->habitaciones[i][j].clasificacion, PC) == 0)) {
                contadorPC++;
                printf(" La habitacion %s \n", (hotel->habitaciones[i][j].identificador));
            }
        }
    }

    if (contadorPC == 0) {
        printf(" No hay ninguna habitacion disponible \n");
    }

    //For class 2

    printf("\nHabitaciones de segunda clase con %i camas: \n", numeroDeCamas);
    for (int i = 0; i < hotel->row_count; i++) {
        for (int j = 0; j < hotel->col_count; j++) {
            if (hotel->habitaciones[i][j].estado == 'L' && hotel->habitaciones[i][j].numCamas == numeroDeCamas && (strcmp(hotel->habitaciones[i][j].clasificacion, SC) == 0)) {
                contadorSC++;
                printf(" La habitacion %s \n", (hotel->habitaciones[i][j].identificador));
            }
        }
    }

    if (contadorSC == 0) {
        printf(" No hay ninguna habitacion disponible \n");
    }

    //For class 3

    printf("\nHabitaciones de tercera clase con %i camas: \n", numeroDeCamas);
    for (int i = 0; i < hotel->row_count; i++) {
        for (int j = 0; j < hotel->col_count; j++) {
            if (hotel->habitaciones[i][j].estado == 'L' && hotel->habitaciones[i][j].numCamas == numeroDeCamas && (strcmp(hotel->habitaciones[i][j].clasificacion, TC) == 0)) {
                contadorTC++;
                printf(" La habitacion %s \n", (hotel->habitaciones[i][j].identificador));
            }
        }
    }

    if (contadorTC == 0) {
        printf(" No hay ninguna habitacion disponible \n");
    }
}

void menu() {
    int opcion = 0;
    int continuar = 0;
    
    do {
        printf("\n  01. Cuantas habitaciones estan libres");
        printf("\n  02. Cuantas habitaciones estan en mantenimiento");
        printf("\n  03. Cuantas habitaciones ocupadas");
        printf("\n  04. Cuantas hay desocupadas por cantidad de camas");
        printf("\n  05. Check in");
        printf("\n  06. Pagar la habitación ");
        printf("\n  07. Liberar la habitación");
        printf("\n  08. Cuantas personas adultas hay el dia de hoy. ");
        printf("\n  09. Cuantos niños existen al dia de hoy en el hotel");
        printf("\n  10. Recaudacion del dia");
        printf("\n  00. Salir");
        printf("\n\n   Introduzca opcion (0-10): ");

        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                printf("\n   1. Cuantas habitaciones estan libres");
                printf("\n   Numero de habitaciones desocupadas: %i", cantidadHabitacionesLibres());
                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                scanf("%i", &continuar);
                break;


            case 2:
                printf("\n   2. Cuantas habitaciones estan en mantenimiento");
                printf("\n   Habitaciones en mantenimiento: %i", cantidadHabitacionesEnMant());
                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                scanf("%i", &continuar);
                break;


            case 3:
                printf("\n   3. Cuántas habitaciones ocupadas");
                printf("\n   Las siguientes habitachioes estan ocupadas: %i", cantidadHabitacionesOcupadas());
                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                scanf("%i", &continuar);
                break;


            case 4:
            {
                printf("\n   4. Cuántas hay desocupadas por cantidad de camas.");
                printf("\n   Ingrese la cantidad de camas deseada: ");
                int numc = 0;
                scanf("%d", &numc);
                
                if (numc > 5 && numc < 1) {
                    printf("\n Cantidad de camas no valida");
                    break;
                } else {
                    printf("\n   Cantidad de habitaciones desocupadas por cantidad de camas: \n");
                    cantidadHabitacionesLibresConNCamas(numc);
                }
                scanf("%i", &continuar);

                break;
            }

            case 5:
                printf("\n   5. Check in ");
                realizarReservacion();
                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                scanf("%i", &continuar);
                break;


            case 6:
                printf("\n   6. Pagar la habitación ");\

                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                scanf("%i", &continuar);
                break;


            case 7:
                printf("\n   7. Liberar la habitacion");

                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                scanf("%i", &continuar);

                break;


            case 8:
                printf("\n   8. Cuantas personas adultas hay el dia de hoy. ");

                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
                scanf("%i", &continuar);
                break;


            case 9:
                printf("\n   9. Cuantos niños existen al dia de hoy en el hotel");
                printf("\n   Cantidad de niños en el hotel hoy: ");

                printf("\n   Ingrese cualquier caracter y enter para continuar: ");
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
            case 0:
                break;

            default:
                break;
        }
    } while (opcion != 0);
}