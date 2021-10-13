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
#include "ArrayEmployees.h"
#include "tp.2_Inputs.h"

int main(void) {
	setbuf(stdout, NULL);

	sEmployee arrayEmpleados[TAM_EMPLOYES];
	int opcion;
	int cantidadProductos = 0;

	Employee_inicializar_Array(arrayEmpleados, TAM_EMPLOYES);

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
				if(Employee_addEmployees(arrayEmpleados, TAM_EMPLOYES) == 0)
				{
					cantidadProductos ++;
				}
			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
				if(cantidadProductos > 0)
				{
					Employee_printEmployees(arrayEmpleados, TAM_EMPLOYES);
				}
				else
				{
					printf("No hay empleados cargados.\n");
				}
			break;

			case 5:
				printf("Terminando...\nPrograma terminado.\n");
			break;
		}
	}while(opcion != 5);

	/*for(int i=0; i<TAM_EMPLOYES; i++)
	{
		Employee_cargarEmpleados(arrayEmpleados, TAM_EMPLOYES);
	}

	Employee_sortEmployees(arrayEmpleados,TAM_EMPLOYES);
	Employee_printEmployees(arrayEmpleados, TAM_EMPLOYES);*/


	return EXIT_SUCCESS;
}
