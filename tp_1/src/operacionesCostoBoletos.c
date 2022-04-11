
/*
 * operacionesCostoBoletos.c
 *
 *  Created on: 4 abr. 2022
 *      Author: gabde
 */
#define PRECIOBTC 4606954.55
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "core.h"

void recibirPrecioAerolinea(float *pointer1,
							int *pointerControl1,
							float *pointer2,
							int *pointerControl2,
							int *reintentos
							)
{
	int opcion;
	printf("Opción: ");
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			printf("Ingrese el valor para Aerolineas Argentina: ");
			guardarDatoNumerico(pointer1, pointerControl1, reintentos);
			break;
		case 2:
			printf("Ingrese el valor para Latam: ");
			guardarDatoNumerico(pointer2, pointerControl2, reintentos);
			break;
		case 3:
			break;
		default:
			*reintentos = *reintentos + 1;
			printf("Debe ingresar una opción válida\n\n");
			sleep(1);
			break;
	}
	fflush(stdin);
}

int verificarRegistros(int *punteroRegistro1,int *punteroRegistro2,int *punteroRegistro3){
	return *punteroRegistro1+*punteroRegistro2+*punteroRegistro3;
}

float calcularPrecioDebito(float precio){
	return precio*0.9;
}

float calcularPrecioCredito(float precio){
	return precio*1.25;
}

float calcularPrecioBTC(float precio){
	return (float)(precio/PRECIOBTC);
}

float calcularPrecioPorKm(float precio, float km){
	return precio/km;
}

float calcularDiferenciaPrecio(float precioLatam, float precioAerolineas){
	float diferenciaPrecio;
	diferenciaPrecio = precioLatam - precioAerolineas;
	if(diferenciaPrecio < 0){
		diferenciaPrecio = diferenciaPrecio * -1;
	}
		return diferenciaPrecio;
}


