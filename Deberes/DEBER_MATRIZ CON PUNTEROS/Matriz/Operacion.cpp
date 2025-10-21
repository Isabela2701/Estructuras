/***********************************************************************
 * Module:  Operacion.cpp
 * Author:  danys
 * Modified: sábado, 10 de mayo de 2025 17:11:39
 * Purpose: Implementation of the class Operacion
 ***********************************************************************/

#include "Operacion.h"
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////
// Name:       Operacion::sumaChar(Matriz matriz1, Matriz matriz2, int fila, int
// columna) Purpose:    Implementation of Operacion::sumaChar() Parameters:
// - matriz1
// - matriz2
// - fila
// - columna
// Return:     Matriz
////////////////////////////////////////////////////////////////////////

Matriz Operacion::sumaDouble(Matriz matriz1, Matriz matriz2, int filas,
                             int columnas) {
  double **resultado = (double **)malloc(filas * sizeof(double *));
  for (int i = 0; i < filas; i++) {
    resultado[i] = (double *)malloc(columnas * sizeof(double));
  }

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      *(*(resultado + i) + j) = *(*(matriz1.getMatrizDouble() + i) + j) +
                                *(*(matriz2.getMatrizDouble() + i) + j);
    }
  }

  Matriz resultadoT(filas, columnas, 3);
  resultadoT.setMatrizDouble(resultado);

  return resultadoT;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operacion::sumaDouble(Matriz matriz1, Matriz matriz2, int fila,
// int columna) Purpose:    Implementation of Operacion::sumaDouble()
// Parameters:
// - matriz1
// - matriz2
// - fila
// - columna
// Return:     Matriz
////////////////////////////////////////////////////////////////////////

Matriz Operacion::sumaChar(Matriz matriz1, Matriz matriz2, int fila,
                           int columna) {

  char **resultado = (char **)malloc(fila * sizeof(char *));
  for (int i = 0; i < fila; i++) {
    resultado[i] = (char *)malloc(columna * (sizeof(char) + sizeof(char)));
  }

  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++) {
      *(*(resultado + i) + j) = *(*(matriz1.getMatrizDouble() + i) + j) +
                                *(*(matriz2.getMatrizDouble() + i) + j);
    }
  }

  Matriz resultadoT(fila, columna, 4);
  resultadoT.setMatrizChar(resultado);

  return resultadoT;
}
