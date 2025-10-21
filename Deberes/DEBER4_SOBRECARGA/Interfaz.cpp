#include "Numeros.h"
#include <iostream>
using namespace std;

// Prototipos
void mostrarMenu();
void ejecutarOpcion(int opcion, Numeros& n);

// Mostrar el menú
void mostrarMenu() {
    cout << "\n--- Menu de suma ---" << endl;
    cout << "1. Sumar tres int" << endl;
    cout << "2. Sumar tres float" << endl;
    cout << "3. Sumar tres double" << endl;
    cout << "4. Sumar combinacion int, float, double" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Ejecutar la opcion seleccionada
void ejecutarOpcion(int opcion, Numeros& n) {
    switch (opcion) {
        case 1:
            n.ingresarYSumarInt();
            break;
        case 2:
            n.ingresarYSumarFloat();
            break;
        case 3:
            n.ingresarYSumarDouble();
            break;
        case 4:
            n.ingresarYSumarMixto();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
    }
}