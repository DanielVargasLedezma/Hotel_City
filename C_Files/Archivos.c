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

    if (!reservaciones)
    {
        return;
    }

    if (lista->cantidadNodos > 0)
    {
        fprintf(reservaciones, "%d\n", lista->cantidadNodos);

        Nodo *tmp = lista->head;

        while (tmp)
        {
            escribirNodo(tmp->data, reservaciones);
            tmp = tmp->sig;
        }
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

    if (!habitaciones)
    {
        return;
    }

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
    fprintf(habitaciones, "%d\n", data->numCamas);

    if (data->cliente)
    {
        fprintf(habitaciones, "exists\n");
        fprintf(habitaciones, "%d\n", data->cliente->identificacion);
        fprintf(habitaciones, "%d\n", data->cliente->modoDePago);
        fprintf(habitaciones, "%s\n", data->cliente->nombreCliente);
        fprintf(habitaciones, "%d\n", data->cliente->numeroTelefono);
    }
    else
    {
        fprintf(habitaciones, "!exist\n");
        fprintf(habitaciones, "null\n");
        fprintf(habitaciones, "null\n");
        fprintf(habitaciones, "null\n");
        fprintf(habitaciones, "null\n");
    }

    if (data->informacion)
    {
        fprintf(habitaciones, "exists\n");
        fprintf(habitaciones, "%d\n", data->informacion->numOfAdults);
        fprintf(habitaciones, "%d\n", data->informacion->numOfDays);
        fprintf(habitaciones, "%d\n", data->informacion->numOfKids);
        fprintf(habitaciones, "%d\n", data->informacion->typeOfInstance);
    }
    else
    {
        fprintf(habitaciones, "!exist\n");
        fprintf(habitaciones, "null\n");
        fprintf(habitaciones, "null\n");
        fprintf(habitaciones, "null\n");
        fprintf(habitaciones, "null\n");
    }
}

/*
Retorna -1 si el archivo esta vacio o si hubo un error al abrir el archivo;
Retorna 1 si la carga se realizo con exito
*/
int cargarLista()
{
    FILE *reservaciones = fopen("Archivos/Reservaciones.txt", "r");

    int cantidadNodos = 0;

    if (!reservaciones)
    {
        return -1;
    }

    fseek(reservaciones, 0, SEEK_END);

    if (ftell(reservaciones) == 0)
    {
        fclose(reservaciones);
        return -1;
    }

    rewind(reservaciones);

    fscanf(reservaciones, "%d", &cantidadNodos);

    Reservacion *data;

    while (cantidadNodos != 0)
    {
        data = (Reservacion *)malloc(sizeof(Reservacion));
        cargarNodo(data, reservaciones);
        push(data);
        cantidadNodos--;
    }

    fclose(reservaciones);

    return 1;
}

void cargarNodo(Reservacion *data, FILE *reservaciones)
{
    fscanf(reservaciones, "%lf", &data->costoReservacion);
    fscanf(reservaciones, "%c", &data->estadoReservacion);
    fscanf(reservaciones, "%s", data->clasificacionHabitacionReservada);
    // fgets(data->clasificacionHabitacionReservada, 3, reservaciones);
    fscanf(reservaciones, "%d", &data->date_reserved[0]);
    fscanf(reservaciones, "%d", &data->date_reserved[1]);
    fscanf(reservaciones, "%d", &data->date_reserved[2]);
    fscanf(reservaciones, "%d", &data->date_reserved[3]);
    fscanf(reservaciones, "%d", &data->date_reserved[4]);
    fscanf(reservaciones, "%d", &data->date_reserved[5]);

    fscanf(reservaciones, "%d", &data->cliente.identificacion);
    fscanf(reservaciones, "%d", &data->cliente.modoDePago);
    fscanf(reservaciones, "%s", data->cliente.nombreCliente);
    // fgets(data->cliente.nombreCliente, 50, reservaciones);
    fscanf(reservaciones, "%d", &data->cliente.numeroTelefono);

    fscanf(reservaciones, "%d", &data->informacion.numOfAdults);
    fscanf(reservaciones, "%d", &data->informacion.numOfDays);
    fscanf(reservaciones, "%d", &data->informacion.numOfKids);
    fscanf(reservaciones, "%d", &data->informacion.typeOfInstance);
}

/*
Retorna -1 si el archivo esta vacio o si hubo un error al abrir el archivo;
Retorna 1 si la carga se realizo con exito
*/
int cargarHabitaciones()
{
    FILE *habitaciones = fopen("Archivos/Habitaciones.txt", "r");

    if (!habitaciones)
    {
        return -1;
    }

    fseek(habitaciones, 0, SEEK_END);

    if (ftell(habitaciones) == 0)
    {
        fclose(habitaciones);
        return -1;
    }

    rewind(habitaciones);

    int col = 0, row = 0;

    fscanf(habitaciones, "%d", &row);
    fscanf(habitaciones, "%d", &col);

    iniciarHotel(row, col);

    for (int i = 0; i < hotel->row_count; i++)
    {
        for (int j = 0; j < hotel->col_count; j++)
        {
            cargarHabitacion(&(hotel->habitaciones[i][j]), habitaciones);
        }
    }

    fclose(habitaciones);

    return 1;
}

void cargarHabitacion(Habitacion *data, FILE *habitaciones)
{
    fgets(data->identificador, 8, habitaciones);
    fgets(data->clasificacion, 2, habitaciones);
    fscanf(habitaciones, "%c", &data->estado);
    fscanf(habitaciones, "%d", &data->numCamas);

    data->cliente = (Cliente *)malloc(sizeof(Cliente));
    data->informacion = (Informacion *)malloc(sizeof(Informacion));

    char validation[8], exists[8] = "exists", not_exists[8] = "!exist";
    char trash[6];

    fscanf(habitaciones, "%s", validation);

    // fgets(validation, 8, habitaciones);

    if (strcmp(validation, exists) == 0)
    {
        fscanf(habitaciones, "%d", &data->cliente->identificacion);
        fscanf(habitaciones, "%d", &data->cliente->modoDePago);
        fscanf(habitaciones, "%s", data->cliente->nombreCliente);
        // fgets(data->cliente->nombreCliente, 50, habitaciones);
        fscanf(habitaciones, "%d", &data->cliente->numeroTelefono);
    }
    else
    {
        fscanf(habitaciones, "%s", trash);
        fscanf(habitaciones, "%s", trash);
        fscanf(habitaciones, "%s", trash);
        fscanf(habitaciones, "%s", trash);
        // fgets(trash, 6, habitaciones);
        // fgets(trash, 6, habitaciones);
        // fgets(trash, 6, habitaciones);
        // fgets(trash, 6, habitaciones);
    }

    fgets(validation, 8, habitaciones);

    if (strcmp(validation, exists) == 0)
    {
        fscanf(habitaciones, "%d", &data->informacion->numOfAdults);
        fscanf(habitaciones, "%d", &data->informacion->numOfDays);
        fscanf(habitaciones, "%d", &data->informacion->numOfKids);
        fscanf(habitaciones, "%d", &data->informacion->typeOfInstance);
    }
    else
    {
        fscanf(habitaciones, "%s", trash);
        fscanf(habitaciones, "%s", trash);
        fscanf(habitaciones, "%s", trash);
        fscanf(habitaciones, "%s", trash);
        // fgets(trash, 6, habitaciones);
        // fgets(trash, 6, habitaciones);
        // fgets(trash, 6, habitaciones);
        // fgets(trash, 6, habitaciones);
    }
}