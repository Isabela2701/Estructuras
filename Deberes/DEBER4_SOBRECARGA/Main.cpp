#include "Numeros.h"
#include <iostream>

// Prototipos desde Interfaz.cpp
void mostrarMenu();
void ejecutarOpcion(int opcion, Numeros& n);

using namespace std;

int main() {
    Numeros n;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        ejecutarOpcion(opcion, n);
    } while (opcion != 0);

    return 0;
}
