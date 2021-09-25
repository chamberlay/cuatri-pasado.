/*
 * operacionesMatematicas.c
 *
 *  Created on: 25 sep. 2021
 *      Author: chamb
 */

#include "operacionesMatematicas.h"
#include "Funciones.h"

float sumar(float primerNumero, float segundoNumero)
{
	float suma;

	suma = primerNumero + segundoNumero;

	return suma;
}
float restar(float primerNumero, float segundoNumero)
{
	float resta;

	resta = primerNumero - segundoNumero;

	return resta;
}
float dividir(float primerNumero, float segundoNumero)
{
	float division;

	division = primerNumero / segundoNumero;

	return division;
}
float multiplicar(float primerNumero, float segundoNumero)
{
	float multiplicacion;

	multiplicacion = primerNumero * segundoNumero;

	return multiplicacion;
}
int factorizarA(float primerNumero)
{
	primerNumero = (int)primerNumero;

	int factorialA = 1;

	if(primerNumero < 10)
	{
		if(primerNumero != 0 && primerNumero != 1)
		{
			factorialA = primerNumero * factorizarA(primerNumero-1);
		}
	}else
	{
		factorialA = 0;
	}



	return factorialA;
}
int factorizarB(float segundoNumero)
{
	segundoNumero = (int)segundoNumero;

	int factorialB = 1;

	if(segundoNumero < 10)
	{
		if(segundoNumero != 0 && segundoNumero != 1)
		{
			factorialB = segundoNumero * factorizarB(segundoNumero-1);
		}
	}else
	{
		factorialB = 0;
	}



	return factorialB;
}
