/*
 * operacionesCostoBoletos.h
 *
 *  Created on: 4 abr. 2022
 *      Author: gabde
 */

#ifndef OPERACIONESCOSTOBOLETOS_H_
#define OPERACIONESCOSTOBOLETOS_H_

/// @param pointer1 puntero a la variable que contiene el precio de la aerolinea 1
/// @param pointerControl1 puntero al flag de la variable que contiene el precio de aerolinea 1
/// @param pointer2 puntero a la variable que contiene el precio de la aerolinea 2
/// @param pointerControl2 puntero al flag de la variable que contiene el precio de aerolinea 2
/// @param reintentos puntero a la variable de reintentos
void recibirPrecioAerolinea(float *pointer1, int *pointerControl1, float *pointer2, int *pointerControl2, int *reintentos);

/// @param punteroRegistro1 puntero a un flag
/// @param punteroRegistro2 puntero a un flag
/// @param punteroRegistro3 puntero a un flag
/// @return la suma de los flags
int verificarRegistros(int *punteroRegistro1,int *punteroRegistro2,int *punteroRegistro3);

/// @param precio boleto
/// @return precio boleto con ajuste debido
float calcularPrecioDebito(float precio);

/// @param precio boleto
/// @return precio boleto con ajuste crédito
float calcularPrecioCredito(float precio);

/// @param precio boleto
/// @return precio boleto expresado en BTC
float calcularPrecioBTC(float precio);

/// @param precio boleto
/// @param km viaje
/// @return precio por km del viaje
float calcularPrecioPorKm(float precio, float km);

/// @param precio1 precio boleto 1
/// @param precio2 precio boleto 2
/// @return modulo diferencia del precio entre los dos boletos
float calcularDiferenciaPrecio(float precio1, float precio2);

#endif /* OPERACIONESCOSTOBOLETOS_H_ */
