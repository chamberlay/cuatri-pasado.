#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "tp.2_Inputs.h"
#include "verificaciones.h"

void Employee_inicializar_Array(sEmployee arrayEmpleados[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		arrayEmpleados[i].isEmpty = VACIO;
	}
}

void Employee_mostrarEmpleado(sEmployee arrayEmpleados)
{
	printf("%-20d %-20s %-20s %-20.2f %-20d\n", arrayEmpleados.id, arrayEmpleados.name, arrayEmpleados.lastName, arrayEmpleados.salary, arrayEmpleados.sector);
}

void Employee_printEmployees(sEmployee arrayEmpleados[], int tam)
{
	int i;

	printf("%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");

	for(i=0; i<tam; i++)
	{
		if(arrayEmpleados[i].isEmpty == OCUPADO)
		{
			Employee_mostrarEmpleado(arrayEmpleados[i]);
		}
	}
}

void Employee_sortEmployees(sEmployee arrayEmpleados[], int tam)
{
	Employee_ordenarPorSector(arrayEmpleados, TAM_EMPLOYES);
	Employee_ordenarPorApellido(arrayEmpleados, TAM_EMPLOYES);
	Employee_printEmployees(arrayEmpleados, TAM_EMPLOYES);
}

void Employee_ordenarPorSector(sEmployee arrayEmpleados[], int tam)
{
	int opcion;

	pedirEntero(&opcion, "-------------------------------------\n"
						"1. Ordenar por sector de manera ascendente.\n"
						"2. Ordenar por sector de manera descendente.\n"
						"3. Atras\n"
						"--------------------------------------\n"
						"Ingrese una opcion: \n",
						"-------------------------------------\n"
						"1. Ordenar por sector de manera ascendente.\n"
						"2. Ordenar por sector de manera descendente.\n"
						"3. Atras\n"
						"--------------------------------------\n"
						"Error, ingrese una opcion valida: \n", 1, 3);

	switch (opcion)
	{
		case 1:
			Employee_OrdenarPorSectorAscendente(arrayEmpleados, TAM_EMPLOYES);
		break;

		case 2:
			Employee_OrdenarPorSectorDescendente(arrayEmpleados, TAM_EMPLOYES);
		break;

		case 3:
		break;
	}
}

void Employee_OrdenarPorSectorAscendente(sEmployee arrayEmpleados[], int tam)
{
	int i;
	int flagSwap;
	sEmployee auxArrayEmpleados;
	int nuevoLimite;

	nuevoLimite = tam - 1;
	do{
		flagSwap = 0;
		for(i=0; i<nuevoLimite; i++)
		{
			if(arrayEmpleados[i].sector > arrayEmpleados[i+1].sector)
			{
					auxArrayEmpleados = arrayEmpleados[i];
					arrayEmpleados[i] = arrayEmpleados[i+1];
					arrayEmpleados[i+1] = auxArrayEmpleados;
					flagSwap = 1;
			}
		}

		nuevoLimite--;
	}while(flagSwap);
}

void Employee_OrdenarPorSectorDescendente(sEmployee arrayEmpleados[], int tam)
{
	int i;
	int flagSwap;
	sEmployee auxArrayEmpleados;
	int nuevoLimite;

	nuevoLimite = tam - 1;
	do{
		flagSwap = 0;
		for(i=0; i<nuevoLimite; i++)
		{
			if(arrayEmpleados[i].sector < arrayEmpleados[i+1].sector)
			{
					auxArrayEmpleados = arrayEmpleados[i];
					arrayEmpleados[i] = arrayEmpleados[i+1];
					arrayEmpleados[i+1] = auxArrayEmpleados;
					flagSwap = 1;
			}
		}

		nuevoLimite--;
	}while(flagSwap);
}

void Employee_ordenarPorApellido(sEmployee arrayEmpleados[], int tam)
{
	int i;
	int flagSwap;
	sEmployee auxArrayEmpleados;
	int nuevoLimite;

		nuevoLimite = tam - 1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(strcmp(arrayEmpleados[i].lastName, arrayEmpleados[i+1].lastName) == 1)
				{
						auxArrayEmpleados = arrayEmpleados[i];
						arrayEmpleados[i] = arrayEmpleados[i+1];
						arrayEmpleados[i+1] = auxArrayEmpleados;
						flagSwap = 1;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
}




int Employee_cargarEmpleado(sEmployee arrayEmpleados[], int i)
{
	int retorno = -1;

	pedirString(arrayEmpleados[i].name, "Ingrese el nombre del empleado: ", "Nombre invalido, hasta 50 caracteres, reingrese: ", TAM_NAMES);
	pedirString(arrayEmpleados[i].lastName, "Ingrese el apellido del empleado: ", "Apellido invalido, hasta 50 caracteres, reingrese: ", TAM_NAMES);
	pedirFloat(&arrayEmpleados[i].salary, "Ingrese el salario del empleado: ", "Error, ingrese un salario valido (1/100000)", 1, 100000);
	pedirEntero(&arrayEmpleados[i].sector, "Ingrese el sector del empleado: ", "Error, ingrese un sector valido: ", 1, 5);

	printf("\nEmpleado a agregar:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
	Employee_mostrarEmpleado(arrayEmpleados[i]);

	if(!verificarConfirmacion("\nIngrese 's' para confirmar el alta del empleado: "))
	{
		arrayEmpleados[i].isEmpty = OCUPADO;
		retorno = 0;
	}

	return retorno;
}

int Employee_addEmployees(sEmployee arrayEmpleados[], int tam)
{
	int retorno = -1;
	int index = Employee_initEmployees(arrayEmpleados, TAM_EMPLOYES);

	if(index != -1)
	{
		printf("Agregando un empleado...\n\n");

		if(!Employee_cargarEmpleado(arrayEmpleados, index))
		{
			printf("\nSe agrego el empleado!!\n");
			printf("----------------------------------\n\n");
		}
		else
		{
			printf("\nSe cancelo el alta del empleado!!\n");
		}
		retorno = 0;
	}
	else
	{
		printf("Error, no hay espacio disponible.\n");
	}

	return retorno;
}

int Employee_initEmployees(sEmployee arrayEmpleados[], int tam)

{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(arrayEmpleados[i].isEmpty == VACIO)
		{
			arrayEmpleados[i].id = i+1;
			index = i;
			break;
		}
	}

	return index;
}

float Employee_calcularTotalSalarios(sEmployee arrayEmpleados[], int tam)
{
	float totalSalarios = 0;
	int i;

	for(i=0; i<tam; i++)
	{
		totalSalarios += arrayEmpleados[i].salary;
	}

	return totalSalarios;
}

float Employee_calcularPromedioSalario(sEmployee arrayEmpleados[], int tam)
{
	float promedioSalario;

	promedioSalario = Employee_calcularTotalSalarios(arrayEmpleados, tam) / TAM_EMPLOYES;

	return promedioSalario;
}

int Employee_calcularEmpleadosConMayorSueldo(sEmployee arrayEmpleados[], int tam)
{
	int empleadosConMayorSueldo = 0;
	int i;

	for(i=0; i<tam; i++)
	{
		if(arrayEmpleados[i].salary > Employee_calcularPromedioSalario(arrayEmpleados, tam))
		{
			empleadosConMayorSueldo ++;
		}
	}

	return empleadosConMayorSueldo;
}

int Employee_removeEmployees(sEmployee arrayEmpleados[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;

	pedirEntero(&idIngresado, "Ingrese el id del empleado a borrar (1-1000)", "Error. Reingrese el id del empleado a borrar (1-1000)", 1, 1000);

	index = Employee_findEmployeeById(arrayEmpleados, TAM_EMPLOYES, idIngresado);

	if(index != -1)
	{
		printf("\nEmpleado a eliminar:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
		Employee_mostrarEmpleado(arrayEmpleados[index]);

		if(!verificarConfirmacion("\nIngrese 's' para confirmar la baja del empleado: "))
		{
			arrayEmpleados[index].isEmpty = VACIO;
			printf("\nEmpleado dado de baja correctamente.\n");
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la baja del empleado.\n\n");
		}
	}
	else
	{
		printf("\nNo se encontro el empleado!!");
	}

	return retorno;
}

int Employee_findEmployeeById(sEmployee arrayEmpleados[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(arrayEmpleados[i].isEmpty == OCUPADO && arrayEmpleados[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int Employee_modificarEmpleados(sEmployee arrayEmpleados[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;
	int opcion;
	sEmployee auxEmployee;

	pedirEntero(&idIngresado, "Ingrese el id del empleado a modificar (1-1000)", "Error. Reingrese el id del empleado a modificar (1-1000)", 1, 1000);
	index = Employee_findEmployeeById(arrayEmpleados, TAM_EMPLOYES, idIngresado);

	if(index != -1)
	{
		auxEmployee = arrayEmpleados[index];
		do{
			pedirEntero(&opcion, "-------------------------------------\n"
										"1. Modificar nombre\n"
										"2. Modificar apellido\n"
										"3. Modificar salario\n"
										"4. Modificar sector\n"
										"5. Atras\n"
										"--------------------------------------\n"
										"Ingrese una opcion: \n",
										"-------------------------------------\n"
										"1. Modificar nombre\n"
										"2. Modificar apellido\n"
										"3. Modificar salario\n"
										"4. Modificar sector\n"
										"5. Atras\n"
										"--------------------------------------\n"
										"Error, ingrese una opcion valida: \n", 1, 5);

			switch(opcion)
			{
				case 1:
					printf("\nEmpleado a modificar:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(arrayEmpleados[index]);

					pedirString(auxEmployee.name, "Ingrese el nuevo nombre del empleado: ", "Error. ingrese hasta 50 caracteres, reingrese nuevo nombre: ", TAM_NAMES);
					printf("\nEmpleado luego de la modificación:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(auxEmployee);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificación del empleado: "))
					{
						arrayEmpleados[index] = auxEmployee;
						printf("\nEmpleado modificado correctamente.\n");
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificación del empleado.\n\n");
					}
				break;

				case 2:
					printf("\nEmpleado a modificar:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(arrayEmpleados[index]);

					pedirString(auxEmployee.lastName, "Ingrese el nuevo apellido del empleado: ", "Error. ingrese hasta 50 caracteres, reingrese nuevo apellido: ", TAM_NAMES);
					printf("\nEmpleado luego de la modificación:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(auxEmployee);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificación del empleado: "))
					{
						arrayEmpleados[index]= auxEmployee;
						printf("\nEmpleado modificado correctamente.\n");
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificación del empleado.\n\n");
					}
				break;

				case 3:
					printf("\nEmpleado a modificar:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(arrayEmpleados[index]);

					pedirFloat(&auxEmployee.salary, "Ingrese el nuevo salario del empleado: ", "Error, ingrese un nuevo salario valido (1/100000)", 1, 100000);
					printf("\nEmpleado luego de la modificación:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(auxEmployee);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificación del empleado: "))
					{
						arrayEmpleados[index]= auxEmployee;
						printf("\nEmpleado modificado correctamente.\n");
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificación del empleado.\n\n");
					}
				break;

				case 4:
					printf("\nEmpleado a modificar:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(arrayEmpleados[index]);

					pedirEntero(&auxEmployee.sector, "Ingrese el nuevo sector del empleado: ", "Error, ingrese un nuevo sector valido: ", 1, 5);
					printf("\nEmpleado luego de la modificación:\n\n%-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					Employee_mostrarEmpleado(auxEmployee);

					if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificación del empleado: "))
					{
						arrayEmpleados[index]= auxEmployee;
						printf("\nEmpleado modificado correctamente.\n");
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificación del empleado.\n\n");
					}
				break;

				case 5:
				break;
			}

		}while(opcion != 5);
	}
	else
	{
		printf("\nNo se encontro el empleado!!");
	}

	return retorno;
}
