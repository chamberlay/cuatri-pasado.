/*
 ============================================================================
 Author      : Vega chamberlay (D)
 Description :TP_1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"
#include "operacionesMatematicas.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	float primerNumero = 0;
	float segundoNumero = 0;

	do
	{
		opcion = menu();

		if(opcion == 1)
		{
			primerNumero = ingresarNumero();
			printf("Primer número: %.2f\n", primerNumero);
			printf("Segundo número: %.2f\n", segundoNumero);
		}

		if(opcion == 2)
		{
			segundoNumero = ingresarNumero();
			printf("Primer número: %.2f\n", primerNumero);
			printf("Segundo número: %.2f\n", segundoNumero);
		}

		eleccion(opcion, primerNumero, segundoNumero);

	}while(opcion != 5);


	return EXIT_SUCCESS;
}
