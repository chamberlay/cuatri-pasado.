#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.2_Inputs.h"
#include "ArrayEmployees.h"
#include "verificaciones.h"

void pedirString(char* cadena, char* mensaje, char* mensajeError, int max)
{
	char cadenaSinValidar[200];
	int tam;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadenaSinValidar);
	tam = strlen(cadenaSinValidar);

	while(tam > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%[^\n]", cadenaSinValidar);
		tam = strlen(cadenaSinValidar);
	}

	strcpy(cadena, cadenaSinValidar);
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

float pedirFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int retorno = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
			printf("%s", mensaje);
			fflush(stdin);
			*caracter = getchar();
			retorno = 0;
	}

	return retorno;
}
