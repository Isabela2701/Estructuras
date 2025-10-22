#ifndef VISTA_H
#define VISTA_H
#include "Controlador.h"

class Vista {
public:
    void menu() {
        Controlador c;
        int opcion;

        do {
            cout << "\n=== MULTIPLICACIÓN DE MATRICES 3D (TDA + Punteros) ===\n";
            cout << "1. Usar tipo INT\n";
            cout << "2. Usar tipo FLOAT\n";
            cout << "3. Usar tipo DOUBLE\n";
            cout << "0. Salir\n";
            cout << "Opción: ";
            cin >> opcion;

            switch (opcion) {
                case 1: c.ejecutarMultiplicacion<int>(); break;
                case 2: c.ejecutarMultiplicacion<float>(); break;
                case 3: c.ejecutarMultiplicacion<double>(); break;
                case 0: cout << "Saliendo...\n"; break;
                default: cout << "Opción inválida.\n";
            }
        } while (opcion != 0);
    }
};

#endif
