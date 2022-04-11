/*
 * guardarDatoNumerico.h
 *
 *  Created on: 2 abr. 2022
 *      Author: gdelosrios
 */

#ifndef CORE_H_
#define CORE_H_

/// @param pointer Puntero a la variable opcion
void imprimirMenu(int *pointer);
/// @param punteroAlDato puntero a la variable a setear o modificar
/// @param punteroAlControl puntero al flag asociado a la variable a setear o modificar
/// @param reintentos puntero a la variable de reintentos
void guardarDatoNumerico(float *punteroAlDato, int *punteroAlControl,int *reintentos);

/// @param punteroAlDato dato que se mostrara en el menu
/// @param punteroAlControl flag dato set/unset
/// @param dato texto que se refiera al dato que se mostrara en menu
void devolverSiEstaSeteado(float *punteroAlDato,int *punteroAlControl,char* dato);

#endif /* CORE_H_ */
