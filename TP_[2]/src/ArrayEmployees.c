#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "tp.2_Inputs.h"

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
		//arrayEmpleados[i].id = i; VERIFICAR ESTE ID
		if(arrayEmpleados[i].isEmpty == OCUPADO)
		{
			Employee_mostrarEmpleado(arrayEmpleados[i]);
		}
	}
}

void Employee_cargarEmpleado(sEmployee arrayEmpleados[], int i)
{
	pedirString(arrayEmpleados[i].name, "Ingrese el nombre del empleado: ", "Nombre invalido, hasta 50 caracteres, reingrese: ", TAM_NAMES);
	pedirString(arrayEmpleados[i].lastName, "Ingrese el apellido del empleado: ", "Apellido invalido, hasta 50 caracteres, reingrese: ", TAM_NAMES);
	pedirFloat(&arrayEmpleados[i].salary, "Ingrese el salario del empleado: ", "Error, ingrese un salario valido (1/100000)", 1, 100000);
	pedirEntero(&arrayEmpleados[i].sector, "Ingrese el sector del empleado: ", "Error, ingrese un sector valido: ", 1, 5);
	arrayEmpleados[i].isEmpty = OCUPADO;
}



int Employee_addEmployees(sEmployee arrayEmpleados[], int tam)
{
	int retorno = -1;
	int index = Employee_initEmployees(arrayEmpleados, TAM_EMPLOYES);

	if(index != -1)
	{
		printf("Agregando un empleado...\n\n");
		Employee_cargarEmpleado(arrayEmpleados, index);
		printf("\nSe agrego el empleado!!\n");
		printf("----------------------------------\n\n");
		retorno = 0;
	}
	else
	{
		printf("Error, no hay espacio disponible.");
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


//verificar

void Employee_sortEmployees(sEmployee arrayEmpleados[], int tam)
{
	Employee_ordenarPorSector(arrayEmpleados, TAM_EMPLOYES);
	Employee_ordenarPorApellido(arrayEmpleados, TAM_EMPLOYES);
}

float Employee_calcularTotalSalarios(sEmployee arrayEmpleados[], int tam)
{
	float totalSalarios = 0;
	int i;

	for(i=0; i<tam; i++)
	{
		printf("\n entro ");
		totalSalarios += arrayEmpleados[i].salary;
		printf("%.2f", totalSalarios);
	}

	return totalSalarios;
}

float Employee_calcularPromedioSalario(sEmployee arrayEmpleados[], int tam)
{
	float promedioSalario;

	promedioSalario = TAM_EMPLOYES / Employee_calcularTotalSalarios(arrayEmpleados, tam);

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

void Employee_ordenarPorSector(sEmployee arrayEmpleados[], int tam)
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
