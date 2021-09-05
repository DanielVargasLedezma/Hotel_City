/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Archivos.c
 * Author: Dani
 * 
 * Created on September 5, 2021, 2:38 AM
 */

#include "../Headers/Archivos.h"

void guardarLista(ListaReservacion *lista)
{
    FILE *reservaciones = fopen("Archivos/Reservaciones.txt", "w");

    fprintf(reservaciones, "%d\n", lista->cantidadNodos);

    Nodo *tmp = lista->head;

    while (tmp)
    {
        escribirNodo(tmp->data, reservaciones);
        tmp = tmp->sig;
    }

    fclose(reservaciones);
}

void escribirNodo(Reservacion *data, FILE *reservaciones)
{
    fprintf(reservaciones, "%lf\n", data->costoReservacion);
    fprintf(reservaciones, "%c\n", data->estadoReservacion);
    fprintf(reservaciones, "%s\n", data->clasificacionHabitacionReservada);
    fprintf(reservaciones, "%d\n", data->date_reserved[0]);
    fprintf(reservaciones, "%d\n", data->date_reserved[1]);
    fprintf(reservaciones, "%d\n", data->date_reserved[2]);
    fprintf(reservaciones, "%d\n", data->date_reserved[3]);
    fprintf(reservaciones, "%d\n", data->date_reserved[4]);
    fprintf(reservaciones, "%d\n", data->date_reserved[5]);
    fprintf(reservaciones, "%d\n", data->date_reserved[6]);

    fprintf(reservaciones, "%d\n", data->cliente.identificacion);
    fprintf(reservaciones, "%d\n", data->cliente.modoDePago);
    fprintf(reservaciones, "%s\n", data->cliente.nombreCliente);
    fprintf(reservaciones, "%d\n", data->cliente.numeroTelefono);

    fprintf(reservaciones, "%d\n", data->informacion.numOfAdults);
    fprintf(reservaciones, "%d\n", data->informacion.numOfDays);
    fprintf(reservaciones, "%d\n", data->informacion.numOfKids);
    fprintf(reservaciones, "%d\n", data->informacion.typeOfInstance);
}

void guardarHabitaciones(Contenedora *contenedora)
{
    FILE *habitaciones = fopen("Archivos/Habitaciones.txt", "w");

    fprintf(habitaciones, "%d\n", contenedora->row_count);
    fprintf(habitaciones, "%d\n", contenedora->col_count);

    for (int i = 0; i < contenedora->row_count; i++)
    {
        for (int j = 0; j < contenedora->col_count; j++)
        {
            escribirHabitacion(&(contenedora->habitaciones[i][j]), habitaciones);
        }
    }

    fclose(habitaciones);
}

void escribirHabitacion(Habitacion *data, FILE *habitaciones)
{
    fprintf(habitaciones, "%s\n", data->identificador);
    fprintf(habitaciones, "%s\n", data->clasificacion);
    fprintf(habitaciones, "%c\n", data->estado);
    fprintf(habitaciones, "%c\n", data->numCamas);

    if (data->cliente)
    {
        fprintf(habitaciones, "%d\n", data->cliente->identificacion);
        fprintf(habitaciones, "%d\n", data->cliente->modoDePago);
        fprintf(habitaciones, "%s\n", data->cliente->nombreCliente);
        fprintf(habitaciones, "%d\n", data->cliente->numeroTelefono);
    }
    else
    {
        fprintf(habitaciones, "null");
        fprintf(habitaciones, "null");
        fprintf(habitaciones, "null");
        fprintf(habitaciones, "null");
    }

    if (data->informacion)
    {
        fprintf(habitaciones, "%d\n", data->informacion->numOfAdults);
        fprintf(habitaciones, "%d\n", data->informacion->numOfDays);
        fprintf(habitaciones, "%d\n", data->informacion->numOfKids);
        fprintf(habitaciones, "%d\n", data->informacion->typeOfInstance);
    }
    else
    {
        fprintf(habitaciones, "null");
        fprintf(habitaciones, "null");
        fprintf(habitaciones, "null");
        fprintf(habitaciones, "null");
    }
}

void cargarLista()
{
    FILE *reservaciones = fopen("Archivos/Reservaciones.txt", "r");

    int cantidadNodos = 0;

    fscanf(reservaciones, "%d", cantidadNodos);

    Reservacion *data;

    while (cantidadNodos != 0)
    {
        data = (Reservacion *)malloc(sizeof(Reservacion));
        cargarNodo(data, reservaciones);
        push(data);
    }
}

void cargarNodo(Reservacion *data, FILE *reservaciones)
{
    fscanf(reservaciones, "%lf", data->costoReservacion);
    fscanf(reservaciones, "%c", data->estadoReservacion);
    fgets(data->clasificacionHabitacionReservada, 3, reservaciones);
    fscanf(reservaciones, "%d", data->date_reserved[0]);
    fscanf(reservaciones, "%d", data->date_reserved[1]);
    fscanf(reservaciones, "%d", data->date_reserved[2]);
    fscanf(reservaciones, "%d", data->date_reserved[3]);
    fscanf(reservaciones, "%d", data->date_reserved[4]);
    fscanf(reservaciones, "%d", data->date_reserved[5]);

    fscanf(reservaciones, "%d", data->cliente.identificacion);
    fscanf(reservaciones, "%d", data->cliente.modoDePago);
    fgets(data->cliente.nombreCliente, 50, reservaciones);
    fscanf(reservaciones, "%d", data->cliente.numeroTelefono);

    fscanf(reservaciones, "%d", data->informacion.numOfAdults);
    fscanf(reservaciones, "%d", data->informacion.numOfDays);
    fscanf(reservaciones, "%d", data->informacion.numOfKids);
    fscanf(reservaciones, "%d", data->informacion.typeOfInstance);
}

void cargarHabitaciones(Contenedora *contenedora)
{

}

Habitacion cargarHabitacion(Habitacion data, FILE *habitaciones)
{
    return data;
}