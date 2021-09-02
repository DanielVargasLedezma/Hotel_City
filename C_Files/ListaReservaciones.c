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

void freeList()
{

}
