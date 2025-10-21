
#include "Matriz.h"
#include "Menu.h"
#include "Operacion.h"
#include <iostream>
using namespace std;

void imprimir(int, Matriz, Matriz);

int main() {

  char uno[] = "Uno";
  char dos[] = "Dos";

  Menu menu;
  menu.setFlag();
  menu.setDim(uno);

  Matriz matriz1(menu.getFilas(), menu.getColumnas(), menu.getFlag());
  matriz1.setValues(menu.getFlag(), uno);

  menu.setDim(dos);

  Matriz matriz2(menu.getFilas(), menu.getColumnas(), menu.getFlag());
  matriz2.setValues(menu.getFlag(), dos);

  matriz1.imprimirMatriz(menu.getFlag(), uno);
  matriz2.imprimirMatriz(menu.getFlag(), dos);

  imprimir(menu.getFlag(), matriz1, matriz2);

  return 0;
}

void imprimir(int flag, Matriz matriz1, Matriz matriz2) {

  char resultadoStr[] = "Resultado";
  Operacion suma;

  if (flag == 1 || flag == 2 || flag == 3) {

    Matriz resultado = suma.sumaDouble(matriz1, matriz2, matriz1.getFilas(),
                                       matriz2.getColumnas());

    resultado.imprimirMatriz(flag, resultadoStr);

  } else if (flag == 4) {

    Matriz resultado = suma.sumaChar(matriz1, matriz2, matriz1.getFilas(),
                                     matriz2.getColumnas());
    resultado.imprimirMatriz(flag, resultadoStr);
  }
}
