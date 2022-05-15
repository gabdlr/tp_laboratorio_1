/*
 * flight.h
 *
 *  Created on: 13 may. 2022
 *      Author: gabde
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char flycode[10];
	int flyStatus;
} Flight;

/// @param flightsArray Arreglo de Flights
/// @param len longitud del arreglo
/// Inicializa el arreglo
void initFlights(Flight flightsArray[],int len);

/// @param flightsArray arreglo de Flight
/// @param len longitud del arreglo
/// Imprime el codigo de vuelo de los Flight
void printFlightCodes(Flight flightsArray[],int len);
#endif /* FLIGHT_H_ */
