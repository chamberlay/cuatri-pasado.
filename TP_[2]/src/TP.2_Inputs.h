#ifndef TP_2_INPUTS_H_
#define TP_2_INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pedirString(char* cadena, char* mensaje, char* mensajeError, int max);


int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
float pedirFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max);

#endif /* TP_2_INPUTS_H_ */
