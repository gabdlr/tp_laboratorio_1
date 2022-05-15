/*
 ============================================================================
 Name        : tp_2.c
 Author      : Gabriel De Los Rios
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "passenger.h"
#include "flight.h"
#define LIMITE_PASAJEROS 2000
#define LIMITE_VUELOS 3
int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu;
	Passenger passengersArray[LIMITE_PASAJEROS];
	Flight flightsArray[3];
	initPassengers(passengersArray, LIMITE_PASAJEROS);
	initFlights(flightsArray, LIMITE_VUELOS);

	//Pasajeros
	int index;
	int id;
	char name[51];
	char lastname[51];
	float price;
	int typePassenger;
	char flycode[10];
	do{
		imprimirMenu(&opcionMenu);
		switch(opcionMenu){
		case 1:
			if(findFreePassengerSlot(&index, passengersArray, LIMITE_PASAJEROS)){
				if(newPassenger(name, lastname, &price, &typePassenger, flycode)){
					//La estructura de addPassenger me obliga a hacer esto
					id = uuidPassenger();
					if(addPassenger(passengersArray, LIMITE_PASAJEROS, id, name, lastname, price, typePassenger, flycode, index)==0){
						printf("%s%d%s", "Pasajero agregado exitosamente! Id: ", id, "\n");
					}
				}
			}
			break;
		case 2:
			editPassenger(passengersArray, LIMITE_PASAJEROS);
			break;
		case 3:
			//La estructura de removePassenger me obliga a hacer esto
			if(isActivePassenger(passengersArray, LIMITE_PASAJEROS)){
				if(utn_getInt(&id, "Ingrese el id del pasajero que desea eliminar: ", "Debe ingresar un id válido", 0, 2147483646, 3)){
					index = findPassengerById(passengersArray, LIMITE_PASAJEROS, id);
					if((index = findPassengerById(passengersArray, LIMITE_PASAJEROS, id)) != -1){
							if(removePassenger(passengersArray, LIMITE_PASAJEROS, id, index)){
								printf("El pasajero con id %d ha sido eliminado", id);
						}
					}else{
						printf("No se encontro un pasajero activo con ese id: %d\n", id);
					}
				}
			}
			break;
		case 4:
			if(isActivePassenger(passengersArray,  LIMITE_PASAJEROS)){
				listPassengers(passengersArray, LIMITE_PASAJEROS);
			}
			break;
		case 5:
			if(cargaForzada(passengersArray, LIMITE_PASAJEROS)){
				printf("%s", "Operación exitosa\n");
			}
			break;
		}

		fflush(stdin);
	}while(opcionMenu != 6);
	printf("\n\n \\----------------------------------\\ \n "
			" \\                                  \\        __  \n"
			"   \\      Buen  viaje  con...         \\       | \\ \n"
			"    >                                  >------|  \\       ______ \n"
			"   /         BuenosViajes!!!          /       --- \\_____/**|_|_\\____  | \n"
			"  /                                  /          \\_______ --------- __>-} \n"
			" /----------------------------------/              /  \\_____|_____/   | \n"
			"                                                   *          \n"
			"Hasta luego!!!"
	);
	return EXIT_SUCCESS;
}
