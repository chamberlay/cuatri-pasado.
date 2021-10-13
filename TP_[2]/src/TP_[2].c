/*
 ============================================================================
 Name        : TP_[2].c
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
				if(cantidadProductos > 0)
				{
					printf("Hay empleados cargados.\n");
				}
				else
				{
					printf("No hay empleados cargados.\n");
				}
			break;

			case 3:
				if(cantidadProductos > 0)
				{
					printf("Hay empleados cargados.\n");
				}
				else
				{
					printf("No hay empleados cargados.\n");
				}
			break;

			case 4:
				if(cantidadProductos > 0)
				{
					pedirEntero(&opcion, "-------------------------------------\n"
										"1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
										"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
										"--------------------------------------\n"
										"Ingrese una opcion: \n",
										"-------------------------------------\n"
										"1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
										"2. Total de los salarios, promedio de los salarios y cuántos empleados superan el salario promedio.\n"
										"--------------------------------------\n"
										"Error, ingrese una opcion valida: \n", 1, 5);

					/*switch(opcion)
					{
						case 1:
							Employee_sortEmployees(arrayEmpleados, TAM_EMPLOYES);
						break;

						case 2:
							printf("El total de los salarios es: %.2f\n"
									"El promedio de los salarios es de: %.2f\n"
									"La cantidad de empleados que superan el salario promedio es de: %d\n",
									Employee_calcularTotalSalarios(arrayEmpleados, TAM_EMPLOYES),
									Employee_calcularPromedioSalario(arrayEmpleados, TAM_EMPLOYES),
									Employee_calcularEmpleadosConMayorSueldo(arrayEmpleados, TAM_EMPLOYES)
									);
					}*/
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
