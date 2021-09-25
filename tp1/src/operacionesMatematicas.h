/*
 * operacionesMatematicas.h
 *
 *  Created on: 25 sep. 2021
 *      Author: chamb
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @fn int factorizarA(float)
 * @brief factoriza el valor de A.
 *
 * @param primerNumero es el valor de A, ingresado en el menu
 * @return devuelve el factorial de A.
 */
int factorizarA(float primerNumero);

/**
 * @fn int factorizarB(float)
 * @brief factoriza el valor de B.
 *
 * @param segundoNumero es el valor de B, ingresado en el menu
 * @return devuelve el factorial de B.
 */
int factorizarB(float segundoNumero);

/**
 * @fn float sumar(float, float)
 * @brief suma los dos numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la suma.
 */
float sumar(float primerNumero, float segundoNumero);

/**
 * @fn float restar(float, float)
 * @brief resta los numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la resta.
 */
float restar(float primerNumero, float segundoNumero);

/**
 * @fn float dividir(float, float)
 * @brief divide los numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la division.
 */
float dividir(float primerNumero, float segundoNumero);

/**
 * @fn float multiplicar(float, float)
 * @brief multiplica los numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la multiplicacion.
 */
float multiplicar(float primerNumero, float segundoNumero);


#endif /* OPERACIONESMATEMATICAS_H_ */
