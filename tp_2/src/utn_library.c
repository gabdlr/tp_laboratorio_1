/*
 * utn_library.c
 *
 *  Created on: 7 may. 2022
 *      Author: gabde
 */
#include "utn_library.h"

int utn_getChar(char* pResultado,char* mensaje,char* mensajeError, int reintentos){
	int retorno = 0;
	char inputBuffer[60];
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fgets(inputBuffer, 60, stdin);
			if(strlen(inputBuffer) == 2){
				buffer = inputBuffer[0];
				if(utn_isValidChar(buffer)){
					*pResultado = buffer;
					retorno = 1;
					fflush(stdin);
					break;
				}
			}

			printf("%s\n", mensajeError);
			reintentos--;
			fflush(stdin);
		}while(reintentos>=0);
	}
	return retorno;
}

//No lo tomamos como int porque toma decimales y hace el casting
int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = 0;
	char buffer[12];
	int aux;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fgets(buffer, 11, stdin);
					if(utn_isValidInt(buffer, &aux)){
						if(aux <= maximo && aux >= minimo){
						*pResultado = aux;
						retorno = 1;
						fflush(stdin);
						break;
					}
				}

			printf("%s\n", mensajeError);
			reintentos--;
			fflush(stdin);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int retorno = 0;
	char buffer[8];
	float aux;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fgets(buffer,7,stdin);
			if(utn_isValidFloat(buffer, &aux)){
				if(aux <= maximo && aux>=minimo){
					*pResultado = aux;
					retorno = 1;
					fflush(stdin);
					break;
				}
			}
			printf("%s\n", mensajeError);
			reintentos--;
			fflush(stdin);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getString(char* pResultado, char* mensaje,char* mensajeError, int minLen, int maxLen, int reintentos, int stringType){
	int retorno;
	retorno = 1;
	char auxBuffer[maxLen];
	char buffer[maxLen];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minLen > 0){
		do{
			retorno = 1;
			printf("%s", mensaje);
			scanf("%[^\n]%*c", auxBuffer);
			//buffer-1 porque el enter es ese 1 fantasma
			if(!(strlen(auxBuffer) <= maxLen - 1 && strlen(auxBuffer) >= minLen)){
				printf("%s\n", mensajeError);
				reintentos--;
			}else{
				strncpy(buffer,auxBuffer,sizeof(buffer));
				switch(stringType){
					case 0:
						for(int i = 0; i < strlen(buffer) - 1; i++){
							if(!utn_isValidChar(buffer[i])){
								retorno = 0;
								break;
							}
						}
					break;
					case 1:
						if(!utn_isValidCharWithSpaces(buffer, strlen(buffer))){
							retorno = 0;
							break;
						}
					break;
					case 2:
						for(int i = 0; i < strlen(buffer) - 1; i++){
							if(!isdigit(buffer[i])){
								retorno = 0;
								break;
							}
						}
					break;
					case 3:
						if(!utn_isValidCharWithDigits(buffer, strlen(buffer))){
							retorno = 0;
							break;
						}
					break;
				}

				if(!retorno){
					printf("%s\n", mensajeError);
					reintentos--;
				}else{
					break;
				}
			}
			fflush(stdin);
		}while(reintentos);
	}

	if(retorno){
		strncpy(pResultado, buffer, maxLen);
	}
	fflush(stdin);
	return retorno;

}

void utn_getDNI(int* pResultado){
	if(utn_getInt(pResultado,
						"Ingrese numero de documento sin puntos ni guiones",
						"Debe ingresar un número de documento válido",
						1,
						99999999,
						3))
	{
		printf("Numero de documento guardado exitosamente. DNI %d", *pResultado);
	}
}

//Le damos 11 para que le quede espacio para el enter :C
void utn_getTelefono(char* pResultado[]){
	if(utn_getString(*pResultado,
						"Ingrese un número de teléfono, debe contener 10 digitos sin puntos ni guiones",
						"Debe ingresar un número de teléfono válido",
						11, 11, 3, 2))
	{
		printf("Numero de teléfono guardado exitosamente. Teléfono %s", *pResultado);
	}
}
int utn_isValidChar(char input){
	int validacionRetorno = 1;
				int aux;
				aux = (int)input;
				if(!((aux >= 65 && aux <=90)||(aux >= 97 && aux <= 122))){
					validacionRetorno = 0;
				}
	return validacionRetorno;
}

int utn_isValidCharWithSpaces(char input[], int len){
	int validacionRetorno;
	validacionRetorno = 1;
	int contadorEspacios;
	contadorEspacios = 0;
	int aux;
	for(int i = 0; i < len ; i++){
		aux = (int)input[i];
		if(!((aux >= 65 && aux <=90)||(aux >= 97 && aux <= 122)||(aux==32))){
			validacionRetorno = 0;
			break;
		}
		if(aux==32){
			contadorEspacios++;
		}
		if(contadorEspacios > 1 || (aux==32 && (i==0 || i==len))){
			validacionRetorno = 0;
			break;
		}
	}
	return validacionRetorno;
}

int utn_isValidCharWithDigits(char input[], int len){
	int validacionRetorno;
	validacionRetorno = 1;
	int aux;
	for(int i = 0; i < len ; i++){
		aux = (int)input[i];
		if(!((aux >= 65 && aux <=90)||(aux >= 97 && aux <= 122)||(aux >= 48 && aux <= 57))){
			validacionRetorno = 0;
			break;
		}
	}
	return validacionRetorno;
}


int utn_isValidInt(char* buffer, int* auxResultado){
	int retorno;
	retorno = 1;
	int aux;
	if(buffer != NULL){
		if(strlen(buffer) <= 1){
			retorno = 0;
		}else{
			for(int i = 0; i < strlen(buffer) - 1; i++){
				aux = (int)buffer[i];
				if(aux < 48 || aux > 57){
					retorno = 0;
					break;
				}
			}
		}
	}
	if(retorno){
		*auxResultado = atoi(buffer);
	}
	return retorno;
}

float utn_isValidFloat(char* buffer, float* auxResultado){
	int retorno;
	retorno = 1;
	int contadorPunto;
	contadorPunto = 0;
	int aux;

	if(buffer != NULL){
		if(strlen(buffer) <= 1){
			retorno = 0;
		}else{
			for(int i = 0; i < strlen(buffer) - 1; i++){
				aux = (int)buffer[i];
				if(((aux < 48 || aux > 57) && aux != 46) || contadorPunto > 1){
					retorno = 0;
					break;
				}
				if(aux == 46){
					++contadorPunto;
				}
			}
		}

	}
	if(retorno){
		*auxResultado = atof(buffer);
	}
	return retorno;
}
