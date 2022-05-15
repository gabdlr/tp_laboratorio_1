/*
 * flight.c
 *
 *  Created on: 13 may. 2022
 *      Author: gabde
 */
#include "flight.h"

void initFlights(Flight flightsArray[],int len){
	char flycode1[7] = "DI3666\n";
	char flycode2[7] = "D0WN66\n";
	char flycode3[7] = "D3M0N6\n";
	if(flightsArray != NULL && len > 0){
		strncpy(flightsArray[0].flycode,flycode1,7);
		strncpy(flightsArray[1].flycode,flycode2,7);
		strncpy(flightsArray[2].flycode,flycode3,7);
		flightsArray[0].flyStatus = 0;
		flightsArray[1].flyStatus = 1;
		flightsArray[2].flyStatus = 1;
	}
}

void printFlightCodes(Flight flightsArray[],int len){
	if(flightsArray != NULL && len > 0){
		printf("Los vuelos disponibles son:\n");
		for(int i = 0; i < len; i++){
			printf("Vuelo %s", flightsArray[i].flycode);
		}
	}
}


