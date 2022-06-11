/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"

Passenger* Passenger_new(){
	Passenger* passenger;
	passenger = (Passenger*)malloc(sizeof(Passenger));
	return passenger;
}

Passenger* Passenger_newParametros(char idStr[],char nombreStr[],char tipoPasajeroStr[]){
	Passenger* passenger = Passenger_new();
	if(passenger != NULL){
		int id;
		id = PService_generarId(0);
		Passenger_setId(passenger, id);
		Passenger_setNombre(passenger, nombreStr);
	}
	return passenger;
}

int Passenger_setId(Passenger* this,int id){
	int retorno;
	retorno = -1;
	if(id){
		this->id = id;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char nombre[]){
	int retorno;
	retorno = 0;
	int i = 0;
	while(nombre[i] != '\0'){
		if(!((nombre[i] >= 65 && nombre[i] <=90)||(nombre[i] >= 97 && nombre[i] <= 122)||(nombre[i]==32))){
			retorno = -1;
			break;
		}
		i++;
	}
	if(retorno == 0){
		strcpy(this->nombre,nombre);
	}
	return retorno;
}
