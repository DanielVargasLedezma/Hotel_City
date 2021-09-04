/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaReservaciones.c
 * Author: Dani
 * 
 * Created on September 1, 2021, 6:37 PM
 */

#include "../Headers/ListaReservaciones.h"

ListaReservacion* lista;

void initList()
{
	if (!lista) {
		lista = (ListaReservacion*)malloc(sizeof(ListaReservacion));
	}
}

void push(Reservacion* data)
{
	if (!data) {
		return;
	}

	if (!lista) {
		return;
	}

	calcularCostoTotalReservacion(data);

	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->data = data;
	nuevo->sig = NULL;

	if (!lista->head) {
		lista->head = nuevo;
	}
	else {
		Nodo* tmp = lista->head;
		
		while (tmp->sig) {
			tmp = tmp->sig;
		}

		tmp->sig = nuevo;
	}
}

int cantidadInfantesHoy()
{
        if (!lista || !lista->head) {
                    return 0;
            }

            int contadorInfantes = 0;

            Nodo* tmp = lista->head;

            while (tmp) {
                    if (compararFechaConHoy(tmp->data) == 0) {
                            if (tmp->data && tmp->data->informacion && tmp->data->informacion->numOfKids > 0) {
                                    contadorInfantes += tmp->data->informacion->numOfKids;
                            }
                    }
                    tmp = tmp->sig;
            }

            return contadorInfantes;
}

int cantidadAdultosHoy()
{
	if (!lista || !lista->head) {
		return 0;
	}

	int contadorAdultos = 0;
	
	Nodo* tmp = lista->head;

	while (tmp) {
		if (compararFechaConHoy(tmp->data) == 0) {
			if (tmp->data && tmp->data->informacion && tmp->data->informacion->numOfAdults > 0) {
				contadorAdultos += tmp->data->informacion->numOfAdults;
			}
		}
		tmp = tmp->sig;
	}

	return contadorAdultos;
}

//Total recaudado con todo incluido
int totalRecaudadoHoyTI()
{
	if (!lista || !lista->head) {
		return 0;
	}

	int totalRecaudado = 0;

	Nodo* tmp = lista->head;

	while (tmp) {
		if (compararFechaConHoy(tmp->data) == 0) {
			if (tmp->data->informacion->typeOfInstance == 1) {
				totalRecaudado += tmp->data->costoReservacion;
			}
		}
		tmp = tmp->sig;
	}

	return totalRecaudado;
}

//Total recaudado sin todo incluido
int totalRecaudadoHoyNTI()
{
	if (!lista || !lista->head) {
		return 0;
	}

	int totalRecaudado = 0;

	Nodo* tmp = lista->head;

	while (tmp) {
		if (compararFechaConHoy(tmp->data) == 0) {
			if (tmp->data->informacion->typeOfInstance == 2) {
				totalRecaudado += tmp->data->costoReservacion;
			}
		}
		tmp = tmp->sig;
	}

	return totalRecaudado;
}

//Total recaudado con todos los clientes de hoy
int totalRecaudadoHoy()
{
	return (totalRecaudadoHoyTI() + totalRecaudadoHoyNTI());
}

//Return 0 si son iguales, 1 si no lo son
int compararFechaConHoy(Reservacion* data)
{
	if (!data) {
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			if (data->date_reserved[i] != generateDay()) {
				return 1;
			}
		}
		else if (i == 1) {
			if (data->date_reserved[i] != generateMonth()) {
				return 1;
			}
		}
		else {
			if (data->date_reserved[i] != generateYear()) {
				return 1;
			}
		}
	}

	return 0;
}

//Return 0 si es reservado en la noche, 1 si no
int comprobarSiReservadoEnNoche(int horaReserva)
{
	if (horaReserva >= 19 && horaReserva < 0) {
		return 0;
	}

	return 1;
}

void calcularCostoTotalReservacion(Reservacion* data)
{
	if (!data) {
		return;
	}

	double costoTotal = 0;

	char PC[3] = "PC";
	char SC[3] = "SC";
	char TC[3] = "TC";

	int totalAdults = data->informacion->numOfAdults;
	int totalKids = data->informacion->numOfKids;
	
	if (comprobarSiReservadoEnNoche(data->date_reserved[3] == 0)) {
		if (strcmp(data->clasificacionHabitacionReservada, PC) == 0) {
			if (data->informacion->typeOfInstance == 1) {
				costoTotal = totalAdults * 300 + totalKids * 200;
				costoTotal += (costoTotal * 0.30);
			}
			else {
				int totalPersonas = totalAdults + totalKids;

				if (totalPersonas == 1) {
					costoTotal = 150;
					costoTotal -= (costoTotal * 0.25);
					costoTotal += (costoTotal * 0.30);
				}
				else if (totalPersonas == 2) {
					costoTotal = 250;
					costoTotal -= (costoTotal * 0.20);
					costoTotal += (costoTotal * 0.30);
				}
				else if (totalPersonas == 3) {
					costoTotal = 350;
					costoTotal -= (costoTotal * 0.15);
					costoTotal += (costoTotal * 0.30);
				}
				else {
					costoTotal = 400;
					costoTotal -= (costoTotal * 0.10);
					costoTotal += (costoTotal * 0.30);
				}
			}
		}
		else if (strcmp(data->clasificacionHabitacionReservada, SC) == 0) {
			if (data->informacion->typeOfInstance == 1) {
				costoTotal = totalAdults * 300 + totalKids * 200;
				costoTotal += (costoTotal * 0.20);
			}
			else {
				int totalPersonas = totalAdults + totalKids;

				if (totalPersonas == 1) {
					costoTotal = 150;
					costoTotal -= (costoTotal * 0.25);
					costoTotal += (costoTotal * 0.20);
				}
				else if (totalPersonas == 2) {
					costoTotal = 250;
					costoTotal -= (costoTotal * 0.20);
					costoTotal += (costoTotal * 0.20);
				}
				else if (totalPersonas == 3) {
					costoTotal = 350;
					costoTotal -= (costoTotal * 0.15);
					costoTotal += (costoTotal * 0.20);
				}
				else {
					costoTotal = 400;
					costoTotal -= (costoTotal * 0.10);
					costoTotal += (costoTotal * 0.20);
				}
			}
		}
		else {
			if (data->informacion->typeOfInstance == 1) {
				costoTotal = totalAdults * 300 + totalKids * 200;
			}
			else {
				int totalPersonas = totalAdults + totalKids;

				if (totalPersonas == 1) {
					costoTotal = 150;
					costoTotal -= (costoTotal * 0.25);
				}
				else if (totalPersonas == 2) {
					costoTotal = 250;
					costoTotal -= (costoTotal * 0.20);
				}
				else if (totalPersonas == 3) {
					costoTotal = 350;
					costoTotal -= (costoTotal * 0.15);
				}
				else {
					costoTotal = 400;
					costoTotal -= (costoTotal * 0.10);
				}
			}
		}
	}
	else {
		if (strcmp(data->clasificacionHabitacionReservada, PC) == 0) {
			if (data->informacion->typeOfInstance == 1) {
				costoTotal = totalAdults * 300 + totalKids * 200;
				costoTotal += (costoTotal * 0.30);
			}
			else {
				int totalPersonas = totalAdults + totalKids;

				if (totalPersonas == 1) {
					costoTotal = 150;
					costoTotal += (costoTotal * 0.30);
				}
				else if (totalPersonas == 2) {
					costoTotal = 250;
					costoTotal += (costoTotal * 0.30);
				}
				else if (totalPersonas == 3) {
					costoTotal = 350;
					costoTotal += (costoTotal * 0.30);
				}
				else {
					costoTotal = 400;
					costoTotal += (costoTotal * 0.30);
				}
			}
		}
		else if (strcmp(data->clasificacionHabitacionReservada, SC) == 0) {
			if (data->informacion->typeOfInstance == 1) {
				costoTotal = totalAdults * 300 + totalKids * 200;
				costoTotal += (costoTotal * 0.20);
			}
			else {
				int totalPersonas = totalAdults + totalKids;

				if (totalPersonas == 1) {
					costoTotal = 150;
					costoTotal += (costoTotal * 0.20);
				}
				else if (totalPersonas == 2) {
					costoTotal = 250;
					costoTotal += (costoTotal * 0.20);
				}
				else if (totalPersonas == 3) {
					costoTotal = 350;
					costoTotal += (costoTotal * 0.20);
				}
				else {
					costoTotal = 400;
					costoTotal += (costoTotal * 0.20);
				}
			}
		}
		else {
			if (data->informacion->typeOfInstance == 1) {
				costoTotal = totalAdults * 300 + totalKids * 200;
			}
			else {
				int totalPersonas = totalAdults + totalKids;

				if (totalPersonas == 1) {
					costoTotal = 150;
				}
				else if (totalPersonas == 2) {
					costoTotal = 250;
				}
				else if (totalPersonas == 3) {
					costoTotal = 350;
				}
				else {
					costoTotal = 400;
				}
			}
		}
	}

	data->costoReservacion = costoTotal;
}

void terminarReservacion(Cliente* cliente)
{
	if (!lista || !lista->head) {
		return;
	}

	Nodo* tmp = lista->head;

	while (tmp) {
		if (tmp->data->cliente == cliente) {
			tmp->data->estadoReservacion = 'D';
			return;
		}
		tmp = tmp->sig;
	}
}

void freeList()
{
	if (!lista || !lista->head) {
		return;
	}

	Nodo* tmp = lista->head;

	while (tmp) {
		if (tmp->data) {
			if (tmp->data->informacion) {
				free(tmp->data->informacion);
			}
			if (tmp->data->cliente) {
				free(tmp->data->cliente);
			}
			free(tmp->data);
		}

		lista->head = lista->head->sig;
		free(tmp);
		tmp = lista->head;
	}

	free(lista);
}