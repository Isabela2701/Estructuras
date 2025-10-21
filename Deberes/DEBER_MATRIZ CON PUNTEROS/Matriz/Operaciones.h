/***********************************************************************
 * Module:  Operaciones.h
 * Author:  danys
 * Modified: sábado, 10 de mayo de 2025 17:11:26
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#if !defined(__Programa_Matriz_Operaciones_h)
#define __Programa_Matriz_Operaciones_h

#include "Matriz.h"

class Operaciones {
public:
  virtual Matriz sumaChar(Matriz matriz1, Matriz matriz2, int fila,
                          int columna) = 0;
  virtual Matriz sumaDouble(Matriz matriz1, Matriz matriz2, int fila,
                            int columna) = 0;

protected:
private:
};

#endif
