/*
 * PassengerService.c
 *
 *  Created on: 6 jun. 2022
 *      Author: gabde
 */
#include "PassengerService.h"

int PService_generarId(int lastId){
	static int id;
	id = ++lastId;
	return id;
}
