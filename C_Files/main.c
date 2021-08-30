/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Dani
 *
 * Created on August 26, 2021, 1:06 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Hotel.h"

/*
 * 
 */

int main(int argc, char** argv) {

    iniciarHotelInterfaz();
    
    liberarMemoria();
    
    return (EXIT_SUCCESS);
}

