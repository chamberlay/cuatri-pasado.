/*
 * Funciones.c
 *
 *  Created on: 11 sep. 2021
 *      Author: chamb
 */
#include "operacionesMatematicas.h"
#include "Funciones.h"

void mostrarCalculos(float primerNumero, float segundoNumero)
{
	printf("El primer número es: %.2f\n", primerNumero);

	printf("\nEl segundo número es: %.2f\n", segundoNumero);

	printf("\nEl resultado de %.2f + %.2f es: %.2f\n", primerNumero, segundoNumero, sumar(primerNumero, segundoNumero));

	printf("\nEl resultado de %.2f - %.2f es: %.2f\n", primerNumero, segundoNumero, restar(primerNumero, segundoNumero));

	if((int)primerNumero != 0 && (int)segundoNumero != 0)
	{
		printf("\nEl resultado de %.2f / %.2f es: %.2f\n", primerNumero, segundoNumero, dividir(primerNumero, segundoNumero));
	}
	else
	{
		printf("\nNo se puede dividir entre 0.\n");
	}

	printf("\nEl resultado de %.2f * %.2f es: %.2f\n", primerNumero, segundoNumero, multiplicar(primerNumero, segundoNumero));

	if(primerNumero < 0)
	{
		printf("\nNo se puede calcular el factorial de un número negativo.\n");
	}
	else
	{
		if(factorizarA(primerNumero) == 0)
		{
			printf("\nNo se pudo calcular el factorial, intente con un número mas pequeño.\n");
		}
		else
		{
			printf("\nEl factorial de %d es: %d\n", (int)primerNumero, factorizarA((int)primerNumero));
		}
	}

	if(segundoNumero < 0)
	{
		printf("\nNo se puede calcular el factorial de un número negativo.\n");
	}
	else
	{
		if(factorizarB(segundoNumero) == 0)
		{
			printf("\nNo se pudo calcular el factorial, intente con un número mas pequeño.\n");
		}
		else
		{
			printf("\nEl factorial de %d es: %d\n", (int)segundoNumero, factorizarB((int)segundoNumero));
		}
	}
}

void eleccion(int opcion, float primerNumero, float segundoNumero)
{
	switch(opcion)
	{
	case 3:
		sumar(primerNumero, segundoNumero);
		restar(primerNumero, segundoNumero);
		multiplicar(primerNumero, segundoNumero);
		dividir(primerNumero, segundoNumero);
		factorizarA(primerNumero);
		factorizarB(segundoNumero);
		printf("Se hicieron los calculos.\n");
	break;

	case 4:
		mostrarCalculos(primerNumero, segundoNumero);
	break;

	case 5:
		printf("Hasta luego!!!!\n");
	break;

	default:
	break;
	}
}

int menu(void)

{
	int opcion;

	printf("############BIENVENIDO############\n");
	printf("1). Ingresar el primer número. \n");
	printf("2). Ingresar el segundo número. \n");
	printf("3). Hacer los calculos. \n");
	printf("4). Mostrar los resultados. \n");
	printf("5). Salir. \n");
	printf("########################################\n");
	fflush(stdin);
	printf("Ingrese una opción: ");
	fflush(stdin);
	scanf("%d", &opcion);

	if(isalpha(opcion) != 0 || opcion < 1 || opcion > 5)
	{
		printf("\nError. Ingrese una opción valida.\n");
	}

	return opcion;
}
float ingresarNumero(void)
{
	float numero;

	printf("Ingrese un número: ");
	fflush(stdin);
	scanf("%f", &numero);

	return numero;
}
