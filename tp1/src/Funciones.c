/*
 * Funciones.c
 *
 *  Created on: 11 sep. 2021
 *      Author: chamb
 */
#include "Funciones.h"

/**
 * @fn void mostrarCalculos(float, float)
 * @brief muestra todos los calculos realizados
 *
 * @param primerNumero es el valor de A
 * @param segundoNumero es el valor de B
 */
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
		if(factorizar(primerNumero) == 0)
		{
			printf("\nNo se pudo calcular el factorial, intente con un número mas pequeño.\n");
		}
		else
		{
			printf("\nEl factorial de %d es: %d\n", (int)primerNumero, factorizar((int)primerNumero));
		}
	}

	if(segundoNumero < 0)
	{
		printf("\nNo se puede calcular el factorial de un número negativo.\n");
	}
	else
	{
		if(factorizar(segundoNumero) == 0)
		{
			printf("\nNo se pudo calcular el factorial, intente con un número mas pequeño.\n");
		}
		else
		{
			printf("\nEl factorial de %d es: %d\n", (int)segundoNumero, factorizar((int)segundoNumero));
		}
	}
}

/**
 * @fn void eleccion(int, float, float)
 * @brief permite que sea ejecutado el codigo que corresponde, segun la opcion que se ingreso.
 *
 * @param opcion es la opcion que se ingreso en el menu.
 * @param primerNumero es el valor de A
 * @param segundoNumero es el valor de B
 */
void eleccion(int opcion, float primerNumero, float segundoNumero)
{
	switch(opcion)
	{
	case 3:
		mostrarCalculos(primerNumero, segundoNumero);
	break;

	case 4:
		printf("Hasta luego!!!!\n");
	break;

	default:
	break;
	}
}


/**
 * @fn int menu(void)
 * @brief muestra el menu con las diferentes ocpiones a elegir.
 *
 * @return devuelve la opcion que se ingreso.
 */
int menu(void)

{
	int opcion;

	printf("############BIENVENIDO############\n");
	printf("1). Ingresar el primer número. \n");
	printf("2). Ingresar el segundo número. \n");
	printf("3). Mostrar los resultados. \n");
	printf("4). Salir. \n");
	printf("########################################\n");
	fflush(stdin);
	printf("Ingrese una opción: ");
	fflush(stdin);
	scanf("%d", &opcion);

	if(isalpha(opcion) != 0 || opcion < 1 || opcion > 4)
	{
		printf("\nError. Ingrese una opción valida.\n");
	}

	return opcion;
}

/**
 * @fn float ingresarNumero(void)
 * @brief solicita un numero al cliente para luego hacer los calculos.
 *
 * @return devuelve el numero que se ingreso.
 */
float ingresarNumero(void)
{
	float numero;

	printf("Ingrese un número: ");
	fflush(stdin);
	scanf("%f", &numero);

	return numero;
}

/**
 * @fn float sumar(float, float)
 * @brief suma los dos numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la suma.
 */
float sumar(float primerNumero, float segundoNumero)
{
	float suma;

	suma = primerNumero + segundoNumero;

	return suma;
}

/**
 * @fn float restar(float, float)
 * @brief resta los numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la resta.
 */
float restar(float primerNumero, float segundoNumero)
{
	float resta;

	resta = primerNumero - segundoNumero;

	return resta;
}

/**
 * @fn float dividir(float, float)
 * @brief divide los numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la division.
 */
float dividir(float primerNumero, float segundoNumero)
{
	float division;

	division = primerNumero / segundoNumero;

	return division;
}

/**
 * @fn float multiplicar(float, float)
 * @brief multiplica los numeros ingresados.
 *
 * @param primerNumero es el valor de A.
 * @param segundoNumero es el valor de B.
 * @return devuelve el resultado de la multiplicacion.
 */
float multiplicar(float primerNumero, float segundoNumero)
{
	float multiplicacion;

	multiplicacion = primerNumero * segundoNumero;

	return multiplicacion;
}

/**
 * @fn int factorizar(float)
 * @brief factoriza el numero que se le envie.
 *
 * @param numero es el valor de A o B, segun lo que se envie.
 * @return devuelve el factorial del numero ingresado.
 */
int factorizar(float numero)
{
	numero = (int)numero;

	int factorial = 1;

	if(numero < 10)
	{
		if(numero != 0 && numero != 1)
		{
			factorial = numero * factorizar(numero-1);
		}
	}else
	{
		factorial = 0;
	}



	return factorial;
}
