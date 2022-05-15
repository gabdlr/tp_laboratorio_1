/*
 * passenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: gabde
 */

#include "passenger.h"
#include "utn_library.h"

int initPassengers(Passenger passengerArray[], int len){
	int retorno = -1;
	if(passengerArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			passengerArray[i].isEmpty = 1;
			//Evita que la basura retorne mal el index (...)
			passengerArray[i].id = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int findFreePassengerSlot(int* index,Passenger passengersArray[],int len){
	int retorno;
	retorno = 0;
	if(passengersArray != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(passengersArray[i].isEmpty){
				*index = i;
				retorno = 1;
				break;
			}
		}
	}
	if(!retorno){
		printf("No se encontraron espacios disponibles para agregar un nuevo pasajero!\n");
	}
	return retorno;
}

//Null da warning por el tipo de dato
int findPassengerById(Passenger* list, int len, int id){
	int index;
	index = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				index = i;
				break;
			}
		}
	}
	return index;
}

int uuidPassenger(){
	static int idCount = 0;
	idCount = idCount + 1;
	return idCount;
}

int newPassenger(char name[], char lastname[], float* price, int* typePassenger, char flycode[]){
	int retorno = 0;

	if(setPassengerName(name)){
		if(setPassengerLastname(lastname)){
			if(setPassengerTicketPrice(price)){
				if(setPassengerTypePassenger(typePassenger)){
					if(setPassengerFlycode(flycode)){
						retorno = 1;
					}
				}
			}
		}
	}
	return retorno;
}

int addPassenger(Passenger* list,
				int len,
				int id,
				char name[],
				char lastname[],
				float price,
				int typePassenger,
				char flycode[],
				int index)
{
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		list[index].id = id;
		strncpy(list[index].name,name,50);
		strncpy(list[index].lastname,lastname,50);
		list[index].typePassenger = typePassenger;
		list[index].price = price;
		strncpy(list[index].flycode, flycode,6);
		list[index].isEmpty = 0;
		retorno = 0;
	}
	return retorno;
}

void editPassenger(Passenger passengersArray[], int len){
	int id;
	int index;
	int opcionMenu;
	char name[51];
	char lastname[51];
	float price;
	int typePassenger;
	char flycode[10];
	if(isActivePassenger(passengersArray, len)){
		if(utn_getInt(&id, "Ingrese el id del pasajero que desea modificar: ", "Debe ingresar un id válido", 0, 2147483646, 3)){
			if((index = findPassengerById(passengersArray, len, id)) != -1){
				do{
				utn_getInt(&opcionMenu, "Seleccione que desea modificar\n"
						"1. Nombre\n"
						"2. Apellido\n"
						"3. Precio\n"
						"4. Tipo de pasajero\n"
						"5. Codigo de vuelo\n"
						"6. Salir\n"
						"Opcion: ",
						"Debe ingresar una opción válida", 1, 6, 3);
					switch(opcionMenu){
						case 0:
						case 6:
							opcionMenu = 6;
							break;
						case 1:
							if(setPassengerName(name)){
								strncpy(passengersArray[index].name,name,50);
							}
							break;
						case 2:
							if(setPassengerLastname(lastname)){
								strncpy(passengersArray[index].lastname,lastname,50);
							}
							break;
						case 3:
							if(setPassengerTicketPrice(&price)){
								passengersArray[index].price = price;
							}
							break;
						case 4:
							if(setPassengerTypePassenger(&typePassenger)){
								passengersArray[index].typePassenger = typePassenger;
							}
							break;
						case 5:
							if(setPassengerFlycode(flycode)){
								strncpy(passengersArray[index].flycode, flycode,6);
							}
							break;
					}
				}while(opcionMenu != 6);
			}else{
				printf("No se encontro un pasajero activo con ese id: %d\n", id);
			}
		}
	}
}

int removePassenger(Passenger* list, int len, int id, int index){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		list[index].isEmpty = 1;
		retorno = 1;
	}
	return retorno;
}

void listPassengers(Passenger passengersArray[], int len){
	int opcionMenu;
	do{
		utn_getInt(&opcionMenu, "Seleccione la opción deseada\n"
				"1. Ordenar pasajeros por apellido y tipo de pasajero [A-Z]\n"
				"2. Ordenar pasajeros por apellido y tipo de pasajero [Z-A]\n"
				"3. Total y promedio del precio de los pasajes\n"
				"4. Ordenar pasajeros por código de vuelo con vuelo activo\n"
				"5. Salir\n"
				"Opcion: ",
				"Debe ingresar una opción válida", 1, 5, 3);
		switch(opcionMenu){
			case 0:
			case 5:
				opcionMenu = 5;
				break;
			case 1:
				if(sortPassengerByLastnameAndTypePassenger(passengersArray, len, 1)){
					printPassengers(passengersArray, len);
				}
				break;
			case 2:
				if(sortPassengerByLastnameAndTypePassenger(passengersArray, len, 2)){
					printPassengers(passengersArray, len);
				}
				break;
			case 3:
				getTotalAndAverageFromTicketPrices(passengersArray, len);
				break;
			case 4:
				printf("Funcionalidad no disponible :(\n");
				break;
		}
		}while(opcionMenu != 5);
}

int setPassengerName(char name[]){
	int retorno;
	retorno = 0;
	if((retorno = utn_getString(name, "Introduzca el nombre del pasajero, máximo 40 caracteres: ",
			"El nombre ingresado es inválido", 1, 40, 3, 1))){
			printf("%s\n", name);
			printf("Guardado!\n");
	}
	return retorno;
}

int setPassengerLastname(char lastname[]){
	int retorno;
	retorno = 0;
	if((retorno = utn_getString(lastname, "Introduzca el apellido del pasajero, máximo 40 caracteres: ",
			"El apellido ingresado es inválido", 1, 40, 3, 1))){
			printf("%s\n", lastname);
			printf("Guardado!\n");
	}
	return retorno;
}

int setPassengerTicketPrice(float* price){
	int retorno;
	retorno = 0;
	if((retorno = utn_getFloat(price, "Introduzca el precio del boleto: ",
			"El precio ingresado es inválido", 1, 999999, 3))){
			printf("%.2f\n", *price);
			printf("Guardado!\n");
	}
	return retorno;
}

int setPassengerTypePassenger(int* typePassenger){
	int retorno;
	retorno = 0;
	if((retorno = utn_getInt(typePassenger,
			"Ingrese el tipo de pasajero\n"
			"1.Primera Clase\n"
			"2.Business\n"
			"3.Turista\n"
			"Opcion: ",
			"Tipo de pasajero ingresado inválido", 1, 3, 3))){
			typePassengerToString(*typePassenger);
			printf("\nGuardado!\n");
	}
	return retorno;
}

int setPassengerFlycode(char flycode[]){
	int retorno;
	retorno = 0;
	if((retorno = utn_getString(flycode,
			"Ingrese el código de vuelo del pasajero, 6 caracteres alfanumericos: ",
			"Código de vuelo inválido", 6, 7, 3, 3))){
			printf("%s\n", flycode);
			printf("Guardado!\n");
	}
	return retorno;
}

int isActivePassenger(Passenger passengersArray[],int len){
	int retorno;
	retorno = 0;
	for(int i = 0; i < len; i++){
		if(!(passengersArray[i].isEmpty)){
			retorno = 1;
			break;
		}
	}
	if(!retorno){
		printf("Aún no ha añadido ningún pasajero.\n");
	}
	return retorno;
}

int sortPassengerByLastnameAndTypePassenger(Passenger passengersArray[], int len, int order){
	int retorno = 0;
	int isOrdered;
	Passenger passenger1;
	Passenger passenger2;
	Passenger auxPassenger;

	if(passengersArray != NULL && len > 0){
		retorno = 1;
		switch(order){
		case 1:
			do{
				isOrdered = 1;
				len--;
				for(int i = 0; i < len; i++){
					passenger1 = passengersArray[i];
					passenger2 = passengersArray[i+1];
					if(stricmp(passenger1.lastname,passenger2.lastname) > 0){
						auxPassenger = passengersArray[i];
						passengersArray[i] = passengersArray[i+1];
						passengersArray[i+1] = auxPassenger;
						isOrdered = 0;
					}else if(stricmp(passenger1.lastname,passenger2.lastname) == 0
							&& passenger1.typePassenger > passenger2.typePassenger){
						auxPassenger = passengersArray[i];
						passengersArray[i] = passengersArray[i+1];
						passengersArray[i+1] = auxPassenger;
						isOrdered = 0;
					}
				}
			}while(!isOrdered);
			break;
		case 2:
			do{
				isOrdered = 1;
				len--;
				for(int i = 0; i < len; i++){
					passenger1 = passengersArray[i];
					passenger2 = passengersArray[i+1];
					if(stricmp(passenger1.lastname,passenger2.lastname) < 0){
						auxPassenger = passengersArray[i];
						passengersArray[i] = passengersArray[i+1];
						passengersArray[i+1] = auxPassenger;
						isOrdered = 0;
					}else if(stricmp(passenger1.lastname,passenger2.lastname) == 0
							&& passenger1.typePassenger > passenger2.typePassenger){
						auxPassenger = passengersArray[i];
						passengersArray[i] = passengersArray[i+1];
						passengersArray[i+1] = auxPassenger;
						isOrdered = 0;
					}
				}
			}while(!isOrdered);
			break;
		default:
			printf("Unhandled Exception");
			break;
		}

	}

	return retorno;
}

void getTotalAndAverageFromTicketPrices(Passenger passengersArray[],int len){
	if(passengersArray != NULL && len > 0){
		float totalSumPrices;
		int totalTickets;
		float averagePrice;
		int pplAboveAverage;
		totalSumPrices = 0;
		totalTickets = 0;
		pplAboveAverage = 0;

		for(int i = 0; i < len; i++){
			if(!(passengersArray[i].isEmpty)){
				totalSumPrices += passengersArray[i].price;
				totalTickets++;
			}
		}
		if(totalTickets > 0){
			averagePrice = totalSumPrices/totalTickets;
		}
		for(int i = 0; i < len; i++){
			if(!(passengersArray[i].isEmpty) && passengersArray[i].price > averagePrice){
				pplAboveAverage++;
			}
		}
		printf("Suma total de precio boletos: %.2f\n", totalSumPrices);
		printf("Precio promedio boletos: %.2f\n", averagePrice);
		printf("Total pasajeros con tickets con costo por encima del promedio: %d\n", pplAboveAverage);

	}

}

void printPassengers(Passenger passengersArray[], int len){
	for(int i = 0; i < len; i++){
		if(!(passengersArray[i].isEmpty)){
			printf("%s|", passengersArray[i].name);
			printf("%s|", passengersArray[i].lastname);
			printf("%.2f|", passengersArray[i].price);
			typePassengerToString(passengersArray[i].typePassenger);
			printf("|%s|\n", passengersArray[i].flycode);
		}
	}
}

void typePassengerToString(int typePassenger){
	switch(typePassenger){
		case 1:
			printf("Primera clase");
			break;
		case 2:
			printf("Business");
			break;
		case 3:
			printf("Turista");
			break;
		default:
			printf("Unhandled Exception");
			break;
	}
}

int cargaForzada(Passenger passengersArray[], int len){
	int retorno;
	int opcion;
	retorno = 0;
	if(utn_getInt(&opcion, "Esto va a sobreescribir todos los registros existentes, desea continuar? 1 Si o 2 No\nOpción: ", "Debe ingresar una opción válida", 1, 2, 3)){
		if(opcion == 1){
			if(passengersArray != NULL && len > 0){
				for(int i = 0; i < len; i++){
					char aux[5];
					itoa(i, aux, 10);
					char name[45] = "Nombre";
					strcat(name, aux);
					char lastname[45] = "Apellido";
					char flycode[7] = "666666";
					strcat(lastname, aux);
					passengersArray[i].id = uuidPassenger();
					strncpy(passengersArray[i].name,name,50);
					strncpy(passengersArray[i].lastname,lastname,50);
					passengersArray[i].typePassenger = 1;
					passengersArray[i].price = i*10;
					strncpy(passengersArray[i].flycode,flycode,7);
					passengersArray[i].isEmpty = 0;
				}
				retorno = 1;
			}
		}
		if(opcion == 2){
			retorno = 0;
		}
	}
	return retorno;
}
