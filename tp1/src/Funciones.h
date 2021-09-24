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

void mostrarCalculos(float primerNumero, float segundoNumero);
void eleccion(int opcion, float primerNumero, float segundoNumero);


int menu(void);
int factorizar(float numero);
float ingresarNumero(void);
float sumar(float primerNumero, float segundoNumero);
float restar(float primerNumero, float segundoNumero);
float dividir(float primerNumero, float segundoNumero);
float multiplicar(float primerNumero, float segundoNumero);

#endif /* FUNCIONES_H_ */
