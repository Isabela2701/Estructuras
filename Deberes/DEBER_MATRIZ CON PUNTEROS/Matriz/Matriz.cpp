/***********************************************************************
 * Module:  Matriz.cpp
 * Author:  danys
 * Modified: s�bado, 10 de mayo de 2025 17:11:39
 * Purpose: Implementation of the class Matriz
 ***********************************************************************/

#include "Matriz.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::getFilas()
// Purpose:    Implementation of Matriz::getFilas()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Matriz::getFilas(void) { return filas; }

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::setFilas(int newFilas)
// Purpose:    Implementation of Matriz::setFilas()
// Parameters:
// - newFilas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Matriz::setFilas(int newFilas) { filas = newFilas; }

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::getColumnas()
// Purpose:    Implementation of Matriz::getColumnas()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Matriz::getColumnas(void) { return columnas; }

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::setColumnas(int newColumnas)
// Purpose:    Implementation of Matriz::setColumnas()
// Parameters:
// - newColumnas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Matriz::setColumnas(int newColumnas) { columnas = newColumnas; }

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::getMatrizChar()
// Purpose:    Implementation of Matriz::getMatrizChar()
// Return:     char**
////////////////////////////////////////////////////////////////////////

char **Matriz::getMatrizChar(void) { return matrizChar; }

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::setMatrizChar(char** newMatrizChar)
// Purpose:    Implementation of Matriz::setMatrizChar()
// Parameters:
// - newMatrizChar
// Return:     void
////////////////////////////////////////////////////////////////////////

void Matriz::setMatrizChar(char **newMatrizChar) { matrizChar = newMatrizChar; }

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::getMatrizDouble()
// Purpose:    Implementation of Matriz::getMatrizDouble()
// Return:     double**
////////////////////////////////////////////////////////////////////////

double **Matriz::getMatrizDouble(void) { return matrizDouble; }

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::setMatrizDouble(double** newMatrizDouble)
// Purpose:    Implementation of Matriz::setMatrizDouble()
// Parameters:
// - newMatrizDouble
// Return:     void
////////////////////////////////////////////////////////////////////////

void Matriz::setMatrizDouble(double **newMatrizDouble) {
  matrizDouble = newMatrizDouble;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::Matriz(int deFilas, int defColumnas, int flag)
// Purpose:    Implementation of Matriz::Matriz()
// Parameters:
// - deFilas
// - defColumnas
// - flag
// Return:
////////////////////////////////////////////////////////////////////////
/*CONSTRUCTOR*/
Matriz::Matriz(int deFilas, int defColumnas, int flag) {

  setFilas(deFilas);
  setColumnas(defColumnas);

  if (flag == 1 || flag == 2 || flag == 3) {

    double **matriz4 = (double **)malloc(getFilas() * sizeof(double *));

    for (int i = 0; i < getFilas(); i++) {

      matriz4[i] = (double *)malloc(getColumnas() * sizeof(double));

    }
    matrizDouble = matriz4;

  } else if (flag == 4) {

    char **matriz2 = (char **)malloc(getFilas() * sizeof(char *));
    for (int i = 0; i < getFilas(); i++) {

      matriz2[i] = (char *)malloc(getColumnas() * sizeof(char));

    }
    matrizChar = matriz2;
  }
}

void Matriz::setValues(int flag, char *string) {

  cout << "\n\t Valores para la matriz " << string << endl << endl;

  if (flag == 1 || flag == 2 || flag == 3) {
    for (int i = 0; i < getFilas(); i++) {
      for (int j = 0; j < getColumnas(); j++) {
        double valor;
        cout << "Digite un valor para [" << i << "][" << j << "]: ";
        cin >> valor;
        matrizDouble[i][j] = valor;
      }
    }
  } else if (flag == 4) {
    for (int i = 0; i < getFilas(); i++) {
      for (int j = 0; j < getColumnas(); j++) {
        char valor;
        cout << "Digite un caracter para [" << i << "][" << j << "]: ";
        cin >> valor;
        matrizChar[i][j] = valor;
      }
    }
  }
}

/*METODO DE IMPRIMIR MATRIZ, NO DEVUELVE NADA SOLO IMPRESION*/
void Matriz::imprimirMatriz(int flag, char *string) {

  cout << "\nImprimiendo la matriz " << string << endl << endl;
  for (int i = 0; i < getFilas(); i++) {
    for (int j = 0; j < getColumnas(); j++) {

      if (flag == 1) {
        cout << (int)matrizDouble[i][j] << " ";
      } else if (flag == 2) {
        cout << (float)matrizDouble[i][j] << " ";
      } else if (flag == 3) {
        cout << matrizDouble[i][j] << " ";
      } else if (flag == 4) {
        cout << matrizChar[i][j] << " ";
      }
    }
    cout << endl;
  }
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::~Matriz()
// Purpose:    Implementation of Matriz::~Matriz()
// Return:
////////////////////////////////////////////////////////////////////////

/*DESTRUCTOR*/

Matriz::~Matriz() {
  // TODO : implement
}
