/*
 ============================================================================
 Name        : TP_2.c
 Author      : Vega chamberlay (D)
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sEmpleados_funciones.h"
#include "tp.2_Inputs.h"

int main(void) {
	setbuf(stdout, NULL);

	sEmpleados arrayEmpleados[TAM_EMPLOYES];
	int opcion;

	empleados_inicializar_Array(arrayEmpleados, TAM_EMPLOYES);

	do
	{
		pedirEntero(&opcion, "-------------------------------------\n"
							"1. ALTA\n"
							"2. MODIFICAR\n"
							"3. BAJA\n"
							"4. INFORMAR\n"
							"5. SALIR\n"
							"--------------------------------------\n"
							"Ingrese una opcion: \n",
							"-------------------------------------\n"
							"1. ALTA\n"
							"2. MODIFICA\n"
							"3. BAJA\n"
							"4. INFORMAR\n"
							"5. SALIR\n"
							"--------------------------------------\n"
							"Error, ingrese una opcion valida: \n", 1, 5);

		switch(opcion)
		{
			case 1:
				empleados_cargarEmpleados(arrayEmpleados, TAM_EMPLOYES);
			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
				empleados_mostrarEmpleados(arrayEmpleados, TAM_EMPLOYES);
			break;

			case 5:
				printf("Terminando...\nPrograma terminado.\n");
			break;
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
