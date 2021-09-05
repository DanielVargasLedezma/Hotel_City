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

void iniciarHotel(int n, int m)
{
    hotel = (Contenedora *)malloc(sizeof(Contenedora));

    hotel->col_count = m;

    hotel->row_count = n;

    (hotel->habitaciones) = malloc(n * sizeof(Habitacion *));

    for (int i = 0; i < n; i++)
    {
        (hotel->habitaciones)[i] = malloc(m * sizeof(Habitacion));
    }

    inicializarHabitaciones();

    initList();
}

int liberarHabitacionCedula(int ced)
{
    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].cliente->identificacion == ced && hotel->habitaciones[i][j].estado == 'O')
            {
                hotel->habitaciones[i][j].estado = 'L';
                free(hotel->habitaciones[i][j].cliente);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

/*
Retorna el costo total si las validaciones son correctas;
Retorna -1 si la habitacion ya ha sido pagada y esta pendiente de liberar;
Retorna 0 si la habitacion no esta ocupada
*/
extern double pagarHabitacion(int ced, int i, int j)
{
    if (hotel->habitaciones[i][j].estado == 'O' && hotel->habitaciones[i][j].cliente->identificacion == ced)
    {
        if (hotel->habitaciones[i][j].informacion && hotel->habitaciones[i][j].cliente)
        {
            double costoTotal = terminarReservacion(hotel->habitaciones[i][j].cliente, hotel->habitaciones[i][j].informacion);
            free(hotel->habitaciones[i][j].informacion);
            return costoTotal;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

void inicializarHabitaciones()
{
    srand(time(NULL));

    char PC[3] = "PC";
    char SC[3] = "SC";
    char TC[3] = "TC";

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {

            hotel->habitaciones[i][j].estado = 'L';

            int clasificador = rand() % 3 + 1;

            if (clasificador == 1)
            {
                memcpy(hotel->habitaciones[i][j].clasificacion, PC, sizeof PC);
            }
            else if (clasificador == 2)
            {
                memcpy(hotel->habitaciones[i][j].clasificacion, SC, sizeof SC);
            }
            else
            {
                memcpy(hotel->habitaciones[i][j].clasificacion, TC, sizeof TC);
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

            for (int k = 0; k < 7; k++)
            {
                hotel->habitaciones[i][j].identificador[k] = id[k];
            }

            hotel->habitaciones[i][j].numCamas = rand() % 5 + 1;
        }
    }
}

void setearHabitacionesLibre()
{

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            hotel->habitaciones[i][j].estado = 'L';
        }
    }
}

int cantidadHabitacionesLibres()
{

    int contador = 0;

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].estado == 'L')
            {
                contador++;
            }
        }
    }

    return contador;
}

int cantidadHabitacionesEnMant()
{

    int contador = 0;

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].estado == 'M')
            {
                contador++;
            }
        }
    }

    return contador;
}

int cantidadHabitacionesOcupadas()
{

    int contador = 0;

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].estado == 'O')
            {
                contador++;
            }
        }
    }

    return contador;
}

int cantidadHabitacionesConEstadoTipo(int tipo)
{

    switch (tipo)
    {
    case 1:
        return cantidadHabitacionesLibres();
        break;
    case 2:
        return cantidadHabitacionesEnMant();
        break;
    case 3:
        return cantidadHabitacionesOcupadas();
        break;
    default:
        return 0;
        break;
    }
}

void checkIn(Cliente *c, Informacion *info, int piso, int numhab)
{
    hotel->habitaciones[numhab][piso].cliente = c;
    hotel->habitaciones[numhab][piso].estado = 'O';
    hotel->habitaciones[numhab][piso].informacion = info;

    registrarReservacion(c, info, piso, numhab);
}

void registrarReservacion(Cliente *c, Informacion *info, int piso, int numhab)
{

    Reservacion *reservacion = (Reservacion *)malloc(sizeof(Reservacion));

    reservacion->informacion.numOfAdults = info->numOfAdults;
    reservacion->informacion.numOfDays = info->numOfDays;
    reservacion->informacion.numOfKids = info->numOfKids;
    reservacion->informacion.typeOfInstance = info->typeOfInstance;

    reservacion->cliente.identificacion = c->identificacion;
    reservacion->cliente.modoDePago = c->modoDePago;
    memcpy(reservacion->cliente.nombreCliente, c->nombreCliente, sizeof reservacion->cliente.nombreCliente);
    reservacion->cliente.numeroTelefono = c->numeroTelefono;

    reservacion->estadoReservacion = 'G';

    reservacion->date_reserved[0] = generateDay();
    reservacion->date_reserved[1] = generateMonth();
    reservacion->date_reserved[2] = generateYear();
    reservacion->date_reserved[3] = generateHour();
    reservacion->date_reserved[4] = generateMinutes();
    reservacion->date_reserved[5] = generateSeconds();

    memcpy(reservacion->clasificacionHabitacionReservada, hotel->habitaciones[numhab][piso].clasificacion, sizeof reservacion->clasificacionHabitacionReservada);

    push(reservacion);
}

int estadoHabitacion(int i, int j)
{
    if (hotel->habitaciones[i][j].estado == 'O')
    {
        return 1;
    }
    else if (hotel->habitaciones[i][j].estado == 'M')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void liberarMemoria()
{
    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            if (hotel->habitaciones[i][j].cliente)
            {
                free(hotel->habitaciones[i][j].cliente);
            }

            if (hotel->habitaciones[i][j].informacion)
            {
                free(hotel->habitaciones[i][j].informacion);
            }
        }
    }

    for (int i = 0; i < hotel->row_count; i++)
    {
        free(hotel->habitaciones[i]);
    }

    free(hotel->habitaciones);

    free(hotel);

    freeList();
}
