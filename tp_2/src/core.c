/*
 * core.c
 *
 *  Created on: 11 may. 2022
 *      Author: gabde
 */
#include "core.h"

void imprimirMenu(int *pointerOpcion){
	int auxOpcion;
	printf("Agencia de Viajes BuenosViajes \n"
				"******************************\n"
				"Seleccione entre las siguientes opciones\n"
				"1. Alta pasajero\n"
				"2. Modificar Pasajero\n"
				"3. Baja pasajero\n"
				"4. Informar\n"
				"5. Carga forzada de datos\n"
				"6. Salir\n");
	if(utn_getInt(&auxOpcion, "Opción: ", "Opción Inválida", 1, 6, 3)){
		*pointerOpcion = auxOpcion;
	}
}
