/*
 * passenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: gabde
 */
#include <stdlib.h>

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[7];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

/// @param PassengerArray arreglo de Passenger
/// @param len logitud del arreglo
/// @return 0 en caso de exito -1 en caso de error
int initPassengers(Passenger PassengerArray[], int len);

/// @param index Dir. de memoria donde se guardara el resultado
/// @param passengersArray arreglo de Passenger
/// @param len logitud del arreglo
/// @return 0 si no hay posiciones disponibles, 1 en caso contrario
int findFreePassengerSlot(int* index,Passenger passengersArray[],int len);

/// @return un id único
int uuidPassenger();

/// @param list arreglo de Passenger
/// @param len logitud del arreglo
/// @param id id generado por uuidPassenger
/// @param name nombre del pasajero
/// @param lastname apellido del pasajero
/// @param price precio del boleto
/// @param typePassenger tipo de pasajero
/// @param flycode código de vuelo
/// @param index indice donde se guardara el pasajero
/// @return -1 en caso de error, 0 en caso de exito
int addPassenger(Passenger* list, int len, int id, char name[], char lastname[], float price, int typePassenger, char flycode[], int index);

/// @param list arreglo de Passenger
/// @param len logitud del arreglo
/// @param id id del pasajero que se desea recuperar
/// @return -1 si no existe indice del pasajero soliciado, caso contrario el indice
int findPassengerById(Passenger* list, int len, int id);

/// @param passengerArray arreglo de Passenger
/// @param len logitud del arreglo
void editPassenger(Passenger passengerArray[], int len);

/// @param name nombre del pasajero
/// @return 1 caso de guadarse, 0 en el caso contrario
int setPassengerName(char name[]);

/// @param lastname apellido del pasajero
/// @return 1 caso de guadarse, 0 en el caso contrario
int setPassengerLastname(char lastname[]);

/// @param price precio del boleto
/// @return 1 caso de guadarse, 0 en el caso contrario
int setPassengerTicketPrice(float* price);

/// @param typePassenger tipo de pasajero (1 primera clase, 2 business, 3 turista)
/// @return 1 caso de guadarse, 0 en el caso contrario
int setPassengerTypePassenger(int* typePassenger);

/// @param flycode codigo del vuelo del pasajero
/// @return 1 caso de guadarse, 0 en el caso contrario
int setPassengerFlycode(char flycode[]);

/// @param typePassenger recibe el tipo de pasajero como int e imprime su valor como arreglo de char
void typePassengerToString(int typePassenger);

/// @param list arreglo de Passenger
/// @param len logitud del arreglo
/// @param id id del pasajero que se eliminara
/// @param index indice del pasajero que se eliminara
/// @return -1 en caso de no encontrar al pasajero, 1 en caso de exito
int removePassenger(Passenger* list, int len, int id, int index);

/// @param passengersArray arreglo de Passenger
/// @param len logitud del arreglo
/// @return 1 en caso de que hayan pasajeros con isEmpty = 1 (ocupado), 0 en caso contrario
int isActivePassenger(Passenger passengersArray[],int len);

/// @param passengersArray arreglo de Passenger
/// @param len logitud del arreglo
/// Acceso a los distintos listados de pasajeros
void listPassengers(Passenger passengersArray[], int len);

/// @param passengersArray arreglo de Passenger
/// @param len logitud del arreglo
/// @param order 0 de la A a la Z, o 1 de la Z a la A
/// @return 1 si se mostro exitosamente, 0 en caso contrario
int sortPassengerByLastnameAndTypePassenger(Passenger passengersArray[], int len, int order);

/// @param passengersArray arreglo de Passenger
/// @param len logitud del arreglo
/// imprime los pasajeros
void printPassengers(Passenger passengersArray[], int len);

/// @param list arreglo de Passenger
/// @param len logitud del arreglo
/// @param order 0 de la A a la Z, o 1 de la Z a la A
/// @return Undeveloped (se implementa sortPassengerByLastnameAndTypePassenger en su lugar)
int sortPassenger(Passenger* list, int len, int order);

/// @param list arreglo de Passenger
/// @param len logitud del arreglo
/// @param order 0 de la A a la Z, o 1 de la Z a la A
/// @return Undeveloped
int sortPassengersByCode(Passenger* list, int len, int order);

/// @param passengersArray arreglo de Passenger
/// @param len logitud del arreglo
/// Imprime precio promedio de los boletos, total del precio de los boletos, cuantos pasajeros tiene un boleto mas caro que el promedio
void getTotalAndAverageFromTicketPrices(Passenger passengersArray[],int len);

/// @param name nombre del pasajero
/// @param lastname apellido del pasajero
/// @param price precio del boleto
/// @param typePassenger tipo de pasajero
/// @param flycode código de vuelo
/// @return 1 si el pasajero se creo exitosamente, 0 en caso contrario
int newPassenger(char name[], char lastname[], float* price, int* typePassenger, char flycode[]);

/// @param passengersArray arreglo de Passenger
/// @param len logitud del arreglo
/// @return 1 en caso de que la operación se exitosa, 0 en caso contrario
int cargaForzada(Passenger passengersArray[], int len);
#endif /* PASSENGER_H_ */
