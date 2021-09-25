/*
 * Funciones.h
 *
 *  Created on: 11 sep. 2021
 *      Author: chamb
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @fn void mostrarCalculos(float, float)
 * @brief muestra todos los calculos realizados
 *
 * @param primerNumero es el valor de A
 * @param segundoNumero es el valor de B
 */
void mostrarCalculos(float primerNumero, float segundoNumero);


/**
 * @fn void eleccion(int, float, float)
 * @brief permite que sea ejecutado el codigo que corresponde, segun la opcion que se ingreso.
 *
 * @param opcion es la opcion que se ingreso en el menu.
 * @param primerNumero es el valor de A
 * @param segundoNumero es el valor de B
 */
void eleccion(int opcion, float primerNumero, float segundoNumero);



/**
 * @fn int menu(void)
 * @brief muestra el menu con las diferentes ocpiones a elegir.
 *
 * @return devuelve la opcion que se ingreso.
 */
int menu(void);

/**
 * @fn float ingresarNumero(void)
 * @brief solicita un numero al cliente para luego hacer los calculos.
 *
 * @return devuelve el numero que se ingreso.
 */
float ingresarNumero(void);

#endif /* FUNCIONES_H_ */
