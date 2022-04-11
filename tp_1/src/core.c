/*
 * guardarDatoNumerico.c
 *
 *  Created on: 2 abr. 2022
 *      Author: gdelosrios
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void imprimirMenu(int *pointerOpcion){
	printf("Agencia de Viajes BuenosViajes \n"
				"******************************\n"
				"Seleccione entre las siguientes opciones\n"
				"1. Ingresar kilometros\n"
				"2. Ingresar precio de vuelos\n"
				"3. Calcular todos los costos\n"
				"4. Informar resultados\n"
				"5. Carga forzada de datos\n"
				"6. Salir\n");
	printf("Opción: ");
	scanf("%d", pointerOpcion);
}

void guardarDatoNumerico(float *punteroAlDato, int *punteroAlControl, int *reintentos){
	float auxDatoNumerico;
	if (scanf("%f", &auxDatoNumerico) == 1){
		if(auxDatoNumerico > 0){
			printf("Valor registrado: %.2f\n\n", auxDatoNumerico);
			*punteroAlDato = auxDatoNumerico;
			*punteroAlControl = 1;
			sleep(1);
		}
		else{
			printf("Ha ingresado un dato inválido, intente nuevamente\n\n");
			*reintentos = *reintentos + 1;
			sleep(1);
		}
	}
	else{
		printf("Ha ingresado un dato inválido, intente nuevamente\n\n");
		*reintentos = *reintentos + 1;
		sleep(1);
	}
	fflush(stdin);
}

void devolverSiEstaSeteado(float *punteroAlDato,int *punteroAlControl,char* dato){
	if(*punteroAlControl){
		printf("(%s=%0.f)\n", dato, *punteroAlDato);
	} else {
		printf("%s=No informado\n", dato);
	}
}

