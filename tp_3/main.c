#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn_library.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	printf("Programa en construcción!");
	exit(666);
    int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    //printf("%d", ll_len(listaPasajeros));



    char nombre[50];
    utn_getString(nombre, "Ingrese el nombre", "Debe ingresar un nombre válido", 2, 50, 3, 1);

    Passenger* pasajero1 = Passenger_newParametros("as", nombre, "asas");
    printf("Imprimo el id: \n");
    printf("%d", pasajero1->id);
    printf("Imprimo el nombre: \n");
    printf("%s", pasajero1->nombre);


    //printf("%p", pasajero1);
    //ll_add(listaPasajeros, (void*)&pasajero1);
    //printf("%d", ll_len(listaPasajeros));
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
        }
    }while(option != 10);
    return 0;
}

