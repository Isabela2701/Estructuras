/***********************************************************************
 * Module:  Menu.cpp
 * Author:  danys
 * Modified: jueves, 8 de mayo de 2025 19:14:57
 * Purpose: Implementation of the class Menu
 ***********************************************************************/

#include "Menu.h"
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Menu::getFilas()
// Purpose:    Implementation of Menu::getFilas()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Menu::getFilas(void) { return filas; }

////////////////////////////////////////////////////////////////////////
// Name:       Menu::setFilas(int newFilas)
// Purpose:    Implementation of Menu::setFilas()
// Parameters:
// - newFilas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Menu::setFilas(int newFilas) { filas = newFilas; }

////////////////////////////////////////////////////////////////////////
// Name:       Menu::getColumnas()
// Purpose:    Implementation of Menu::getColumnas()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Menu::getColumnas(void) { return columnas; }

////////////////////////////////////////////////////////////////////////
// Name:       Menu::setColumnas(int newColumnas)
// Purpose:    Implementation of Menu::setColumnas()
// Parameters:
// - newColumnas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Menu::setColumnas(int newColumnas) { columnas = newColumnas; }

////////////////////////////////////////////////////////////////////////
// Name:       Menu::Menu()
// Purpose:    Implementation of Menu::Menu()
// Return:
////////////////////////////////////////////////////////////////////////

  /*CONSTRUCTOR*/

Menu::Menu() {}

////////////////////////////////////////////////////////////////////////
// Name:       Menu::~Menu()
// Purpose:    Implementation of Menu::~Menu()
// Return:
////////////////////////////////////////////////////////////////////////

/*DESTRUCTOR*/

Menu::~Menu() {
  // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Menu::getFlag()
// Purpose:    Implementation of Menu::getFlag()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Menu::getFlag(void) { return flag; }

////////////////////////////////////////////////////////////////////////
// Name:       Menu::setFlag(int newFlag)
// Purpose:    Implementation of Menu::setFlag()
// Parameters:
// - newFlag
// Return:     void
////////////////////////////////////////////////////////////////////////

void Menu::setFlag(int newFlag) { flag = newFlag; }

void Menu::setFlag() {
  int flagTemp;
  do {

    cout << "\tOperaciones con Matrices" << endl << endl;
    cout << "1.Matrices de valores Enteros" << endl;
    cout << "2.Matrices de valores Flotantes" << endl;
    cout << "3.Matrices de valores Double" << endl;
    cout << "4.Matrices de valores Char" << endl;
    cout << "\n[+] Opcion: ";
    cin >> flagTemp;

    if ((flagTemp <= 0) || (flagTemp > 4)) {

      cout << "\n[!]Digite una opcion valida....\n";
      system("sleep 4");
      system("clear");
    }

  } while ((flagTemp <= 0) || (flagTemp > 4));

  flag = flagTemp;
}

void Menu::setDim(char *string) {

  int fil, colm;

  do {

    cout << "\n\tDimeciones de la matriz " << string << endl << endl;
    cout << "Digite el numero de filas: ";
    cin >> fil;
    cout << "Digite el numero de columnas: ";
    cin >> colm;

    if (fil != colm) {
      cout << "\n\n[+] Recuerde que para las operaciones la matriz tiene que "
              "ser "
              "cuadrada...\n";
      system("sleep 3");
      system("clear");
    }
  } while (fil != colm);

  setFilas(fil);
  setColumnas(colm);
}
