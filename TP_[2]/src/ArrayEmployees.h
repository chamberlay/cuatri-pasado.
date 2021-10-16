#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cantidad de empleados
#define TAM_EMPLOYES 3

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

/**
 * @fn void Employee_inicializar_Array(sEmployee[], int)
 * @brief  assign empty to the arrays
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 */
void Employee_inicializar_Array(sEmployee arrayEmpleados[], int tam);

/**
 * @fn void Employee_mostrarEmpleado(sEmployee)
 * @brief is the format in which it will be shown to employees
 *
 * @param arrayEmpleados is the array of employees
 */
void Employee_mostrarEmpleado(sEmployee arrayEmpleados);

/**
 * @fn void Employee_printEmployees(sEmployee[], int)
 * @brief print the array of employees
 *
 * @param arrayEmpleados is the array of employee
 * @param tam is the number of employees
 */
void Employee_printEmployees(sEmployee arrayEmpleados[], int tam);

/**
 * @fn void Employee_OrdenarPorSectorAscendente(sEmployee[], int)
 * @brief sort the array of employees in ascending order
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 */
void Employee_OrdenarPorSectorAscendente(sEmployee arrayEmpleados[], int tam);

/**
 * @fn void Employee_OrdenarPorSectorDescendente(sEmployee[], int)
 * @brief sort the array of employees in descending order
 *
* @param arrayEmpleados is the array of employees
* @param tam is the number of employees
 */
void Employee_OrdenarPorSectorDescendente(sEmployee arrayEmpleados[], int tam);

/**
 * @fn void Employee_sortEmployees(sEmployee[], int)
 * @brief sorts the array of employees by last name and by sector in descending or ascending order
 *
* @param arrayEmpleados is the array of employees
* @param tam is the number of employees
 */
void Employee_sortEmployees(sEmployee arrayEmpleados[], int tam);

/**
 * @fn void Employee_ordenarPorSector(sEmployee[], int)
 * @brief sort the array of employees by sector
 *
* @param arrayEmpleados is the array of employees
* @param tam is the number of employees
 */
void Employee_ordenarPorSector(sEmployee arrayEmpleados[], int tam);

/**
 * @fn void Employee_ordenarPorApellido(sEmployee[], int)
 * @brief sort the array of employees by last name
 *
* @param arrayEmpleados is the array of employees
* @param tam is the number of employees
 */
void Employee_ordenarPorApellido(sEmployee arrayEmpleados[], int tam);


/**
 * @fn int Employee_cargarEmpleado(sEmployee[], int)
 * @brief ask for the data to load an employee
 *
* @param arrayEmpleados is the array of employees
* @param i is the position of array
 * @return returns -1 if registration was canceled or otherwise returns 0
 */
int Employee_cargarEmpleado(sEmployee arrayEmpleados[], int i);

/**
 * @fn int Employee_initEmployees(sEmployee[], int)
 * @brief check if the position is available
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @return returns -1 if the position is occupied or otherwise it returns the index of the position.
 */
int Employee_initEmployees(sEmployee arrayEmpleados[], int tam);

/**
 * @fn int Employee_addEmployees(sEmployee[], int)
 * @brief load the employees
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @return returns -1 if there is no space available or in case the employee was able to load returns 0
 */
int Employee_addEmployees(sEmployee arrayEmpleados[], int tam);

/**
 * @fn float Employee_calcularTotalSalarios(sEmployee[], int)
 * @brief calculates the total of all wages
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @return returns the total of all wages
 */
float Employee_calcularTotalSalarios(sEmployee arrayEmpleados[], int tam);

/**
 * @fn float Employee_calcularPromedioSalario(sEmployee[], int)
 * @brief calculates the average of all wages
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @return returns the average of all wages
 */
float Employee_calcularPromedioSalario(sEmployee arrayEmpleados[], int tam);

/**
 * @fn int Employee_calcularEmpleadosConMayorSueldo(sEmployee[], int)
 * @brief calculate how many employees earn more than the average salary
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @return returns how many employees earn more than the average salary
 */
int Employee_calcularEmpleadosConMayorSueldo(sEmployee arrayEmpleados[], int tam);

/**
 * @fn int Employee_removeEmployees(sEmployee[], int)
 * @brief logically delete an employee's data
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @return returns -1 if the operation was canceled or otherwise 0
 */
int Employee_removeEmployees(sEmployee arrayEmpleados[], int tam);

/**
 * @fn int Employee_findEmployeeById(sEmployee[], int, int)
 * @brief search for an employee by id
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @param id is the employee id entered
 * @return returns -1 if it did not find the position or otherwise the index of the position
 */
int Employee_findEmployeeById(sEmployee arrayEmpleados[], int tam, int id);

/**
 * @fn int Employee_modificarEmpleados(sEmployee[], int)
 * @brief modify the data of the employee id entered
 *
 * @param arrayEmpleados is the array of employees
 * @param tam is the number of employees
 * @return returns -1 if the operation was canceled or otherwise returns 0
 */
int Employee_modificarEmpleados(sEmployee arrayEmpleados[], int tam);
#endif /* ARRAYEMPLOYEES_H_ */
