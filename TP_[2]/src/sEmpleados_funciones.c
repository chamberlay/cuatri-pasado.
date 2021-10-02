#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sEmpleados_funciones.h"
#include "tp.2_Inputs.h"

void empleados_inicializar_Array(sEmpleados arrayEmpleados[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		arrayEmpleados[i].isEmpty = VACIO;
	}
}

void empleados_mostrarEmpleado(sEmpleados arrayEmpleados)
{
	printf("Id: %d / Nombre: %s / Apellido: %s / Sueldo: %.2f / Sector: %d\n", arrayEmpleados.id, arrayEmpleados.name, arrayEmpleados.lastName, arrayEmpleados.salary, arrayEmpleados.sector);
}

void empleados_mostrarEmpleados(sEmpleados arrayEmpleados[], int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		//arrayEmpleados[i].id = i; VERIFICAR ESTO
		empleados_mostrarEmpleado(arrayEmpleados[i]);
	}
}

/*void empleados_ordenarPorApellidoYSector(sEmpleados* arrayEmpleados, int tam)
{
	int i;
	int flagSwap;
	sEmpleados auxArrayEmpleados;
	int nuevoLimite;

	if(arrayEmpleados != NULL && tam > -1)
	{
		nuevoLimite = tam - 1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(arrayEmpleados[i].sector > arrayEmpleados[i+1].sector)
				{
					if(strcmp(arrayEmpleados[i].lastName, arrayEmpleados[i+1].lastName) == 1)
					{
						auxArrayEmpleados = arrayEmpleados[i];
						arrayEmpleados[i] = arrayEmpleados[i+1];
						arrayEmpleados[i+1] = auxArrayEmpleados;
						flagSwap = 1;
					}
				}
			}
			nuevoLimite--;
		}while(flagSwap);
	}
}*/

void empleados_cargarEmpleado(sEmpleados arrayEmpleados[], int i)
{
	pedirString(arrayEmpleados[i].name, "Ingrese el nombre del empleado: ", "Nombre invalido, hasta 50 caracteres, reingrese: ", TAM_NAMES);
	pedirString(arrayEmpleados[i].lastName, "Ingrese el apellido del empleado: ", "Apellido invalido, hasta 50 caracteres, reingrese: ", TAM_NAMES);
	pedirFloat(&arrayEmpleados[i].salary, "Ingrese el salario del empleado: ", "Error, ingrese un salario valido (1/100000)", 1, 100000);
	pedirEntero(&arrayEmpleados[i].sector, "Ingrese el sector del empleado: ", "Error, ingrese un sector valido: ", 1, 5);
	arrayEmpleados[i].isEmpty = OCUPADO;
}






int empleados_cargarEmpleados(sEmpleados arrayEmpleados[], int tam)
{
	int retorno = -1;
	int index = empleados_buscarDisponibilidad(arrayEmpleados, TAM_EMPLOYES);

	if(index != -1)
	{
		printf("Agregando un empleado...\n\n");
		empleados_cargarEmpleado(arrayEmpleados, index);
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

int empleados_buscarDisponibilidad(sEmpleados arrayEmpleados[], int tam)

{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(arrayEmpleados[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}
