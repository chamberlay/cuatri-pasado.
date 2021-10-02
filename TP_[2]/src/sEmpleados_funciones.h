#ifndef SEMPLEADOS_FUNCIONES_H_
#define SEMPLEADOS_FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cantidad de empleados
#define TAM_EMPLOYES 2

//name y lastName
#define TAM_NAMES 51

//isEmpty
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int id;
	char name[TAM_NAMES];
	char lastName[TAM_NAMES];
	float salary;
	int sector;
	int isEmpty;
} sEmpleados;

void empleados_inicializar_Array(sEmpleados arrayEmpleados[], int tam);
void empleados_mostrarEmpleado(sEmpleados arrayEmpleados);
void empleados_mostrarEmpleados(sEmpleados arrayEmpleados[], int tam);
void empleados_cargarEmpleado(sEmpleados arrayEmpleados[], int i);


int empleados_buscarDisponibilidad(sEmpleados arrayEmpleados[], int tam);
int empleados_cargarEmpleados(sEmpleados arrayEmpleados[], int tam);

#endif /* SEMPLEADOS_FUNCIONES_H_ */
