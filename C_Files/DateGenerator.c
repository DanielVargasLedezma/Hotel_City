/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DateGenerator.c
 * Author: Dani
 * 
 * Created on September 1, 2021, 5:35 PM
 */

#include "../Headers/DateGenerator.h"

time_t t;

void initializeT() 
{
	t = time(NULL);
};

int generateYear()
{
	initializeT();
	struct tm tm = *localtime(&t);
	
	return (tm.tm_year + 1900);
}

int generateMonth()
{
	initializeT();
	struct tm tm = *localtime(&t);

	return (tm.tm_mon + 1);
}

int generateDay()
{
	initializeT();
	struct tm tm = *localtime(&t);

	return tm.tm_mday;
}

int generateHour()
{
	initializeT();
	struct tm tm = *localtime(&t);

	return tm.tm_hour;
}

int generateMinutes()
{
	initializeT();
	struct tm tm = *localtime(&t);

	return tm.tm_min;
}

int generateSeconds()
{
	initializeT();
	struct tm tm = *localtime(&t);

	return tm.tm_sec;
}
