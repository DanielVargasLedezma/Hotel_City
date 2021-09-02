/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Dani
 *
 * Created on August 26, 2021, 5:25 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente{
    
    char nombreCliente[10];
    int identificacion;
    int modoDePago;
    int numeroTelefono;
    
}Cliente;

#endif /* CLIENTE_H */
