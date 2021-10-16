#ifndef VERIFICACIONES_H_
#define VERIFICACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @fn int verificarConfirmacion(char*)
 * @brief confirm if you really want to do something
 *
 * @param mensaje is the message that is displayed
 * @return returns 0 if the answer was loaded or -1 otherwise
 */
int verificarConfirmacion(char* mensaje);

#endif /* VERIFICACIONES_H_ */
