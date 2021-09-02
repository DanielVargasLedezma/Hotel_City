/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DateGenerator.h
 * Author: Dani
 *
 * Created on September 1, 2021, 5:35 PM
 */

#ifndef DATEGENERATOR_H
#define DATEGENERATOR_H
#include <stdio.h>
#include <time.h>

extern time_t t;

extern void initializeT();

extern int generateYear();
extern int generateMonth();
extern int generateDay();

extern int generateHour();
extern int generateMinutes();
extern int generateSeconds();

#endif /* DATEGENERATOR_H */

//https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program