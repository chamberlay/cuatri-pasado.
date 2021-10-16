#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.2_Inputs.h"
#include "ArrayEmployees.h"
#include "verificaciones.h"

int verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);

	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}
	return retorno;
}
