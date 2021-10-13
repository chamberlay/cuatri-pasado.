#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
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
} sEmployee;

void Employee_inicializar_Array(sEmployee arrayEmpleados[], int tam);
void Employee_mostrarEmpleado(sEmployee arrayEmpleados);
void Employee_printEmployees(sEmployee arrayEmpleados[], int tam);
void Employee_cargarEmpleado(sEmployee arrayEmpleados[], int i);


int Employee_initEmployees(sEmployee arrayEmpleados[], int tam);
int Employee_addEmployees(sEmployee arrayEmpleados[], int tam);


//verificar

void Employee_sortEmployees(sEmployee arrayEmpleados[], int tam);
float Employee_calcularTotalSalarios(sEmployee arrayEmpleados[], int tam);
float Employee_calcularPromedioSalario(sEmployee arrayEmpleados[], int tam);
int Employee_calcularEmpleadosConMayorSueldo(sEmployee arrayEmpleados[], int tam);
void Employee_ordenarPorSector(sEmployee arrayEmpleados[], int tam);
void Employee_ordenarPorApellido(sEmployee arrayEmpleados[], int tam);
#endif /* ARRAYEMPLOYEES_H_ */
