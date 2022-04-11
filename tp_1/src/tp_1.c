/*
 ============================================================================
 Name        : tp_1.c
 Author      : Gabriel De Los Rios
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : TP 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "core.h"
#include "operacionesCostoBoletos.h"

int main(void) {
	setbuf(stdout, NULL);
	int continuarPrograma;
	continuarPrograma = 1;

	int opcion;

	float numeroKm;
	int controlNumeroKm;
	controlNumeroKm = 0;

	float precioAerolineas;
	int controlPrecioAerolineas;
	controlPrecioAerolineas = 0;

	float precioLatam;
	int controlPrecioLatam;
	controlPrecioLatam = 0;

	int verificacionRegistros;
	verificacionRegistros = 0;

	float precioAerolineasDebito;
	float precioLatamDebito;
	float precioAerolineasCredito;
	float precioLatamCredito;
	float precioAerolineasBTC;
	float precioLatamBTC;
	float precioAerolineasPorKm;
	float precioLatamPorKm;
	float diferenciaPrecio;

	int reintentos;
	reintentos = 0;

	while(continuarPrograma){

		imprimirMenu(&opcion);
		switch(opcion)
		{
			case 1:
				printf("Ingresar Kilómetros: ");
				devolverSiEstaSeteado(&numeroKm, &controlNumeroKm, "km");
				guardarDatoNumerico(&numeroKm, &controlNumeroKm, &reintentos);
				break;
			case 2:
				printf("Ingresar precio de vuelos: ");
				devolverSiEstaSeteado(&precioAerolineas, &controlPrecioAerolineas, "Aerolineas");
				devolverSiEstaSeteado(&precioLatam, &controlPrecioLatam, "Latam");
				printf("1.Precio Aerolineas Argentinas\n"
						"2.Precio Latam\n"
						"3.Para volver\n");
				recibirPrecioAerolinea(&precioAerolineas,
										&controlPrecioAerolineas,
										&precioLatam,
										&controlPrecioLatam,
										&reintentos);
				break;
			case 3:

				verificacionRegistros = verificarRegistros(&controlNumeroKm,
															&controlPrecioAerolineas,
															&controlPrecioLatam
										);
				if(verificacionRegistros == 3){
					precioAerolineasDebito = calcularPrecioDebito(precioAerolineas);
					precioLatamDebito = calcularPrecioDebito(precioLatam);
					precioAerolineasCredito = calcularPrecioCredito(precioAerolineas);
					precioLatamCredito = calcularPrecioCredito(precioLatam);
					precioAerolineasBTC = calcularPrecioBTC(precioAerolineas);
					precioLatamBTC = calcularPrecioBTC(precioLatam);
					precioAerolineasPorKm = calcularPrecioPorKm(precioAerolineas,numeroKm);
					precioLatamPorKm = calcularPrecioPorKm(precioLatam,numeroKm);
					diferenciaPrecio = calcularDiferenciaPrecio(precioLatam,precioAerolineas);
					printf("\nCalculando...\n\n");
					sleep(1);
				} else {
					printf("\nDebe ingresar km y precios!\n\n");
					sleep(1);
				}
				break;
			case 4:
				if(verificacionRegistros == 3){
					printf(
							"\nKMs Ingresados: %.0f \n"
							"\nPrecio Aerolineas: $ %.2f"
							"\na) Precio con tarjeta de débito: $ %.2f"
							"\nb) Precio con tarjeta de crédito: $ %.2f"
							"\nc) Precio pagando con bitcoin: $ %.2f"
							"\nd) Mostrar precio unitario: $ %.2f\n"
							"\nPrecio Latam: %.2f"
							"\na) Precio con tarjeta de débito: $ %.2f"
							"\nb) Precio con tarjeta de crédito: $ %.2f"
							"\nc) Precio pagando con bitcoin: $ %.2f"
							"\nd) Mostrar precio unitario: $ %.2f\n"
							"\nLa diferencia de precio es: $ %.2f\n",
							numeroKm,
							precioAerolineas,
							precioAerolineasDebito,
							precioAerolineasCredito,
							precioAerolineasBTC,
							precioAerolineasPorKm,
							precioLatam,
							precioLatamDebito,
							precioLatamCredito,
							precioLatamBTC,
							precioLatamPorKm,
							diferenciaPrecio
							);
					printf("\n");
					sleep(3);
				} else {
					printf("\nDebe calcular los costos previamente!\n\n");
					sleep(1);
				}
				break;
			case 5:
				numeroKm = 7090;
				controlNumeroKm = 1;
				precioAerolineas = 162965;
				controlPrecioAerolineas = 1;
				precioLatam = 159339;
				controlPrecioLatam = 1;
				printf("Carga forzada exitosa\n\n");
				sleep(1);
				break;
			case 6:
				continuarPrograma = 0;
				break;
			default:
				printf("Debe ingresar una opcion válida");
				reintentos = reintentos + 1;
				sleep(1);
				break;
		}
		if(reintentos == 3){
			continuarPrograma = 0;
		}
	}


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
