#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "Modelo.h"

class Controlador {
public:
    template<typename T>
    void ejecutarMultiplicacion() {
        int x, y, z;
        cout << "Ingrese dimensiones X Y Z de las matrices: ";
        cin >> x >> y >> z;

        Matriz3D<T> A(x, y, z), B(y, x, z);

        cout << "\n--- Matriz A ---\n";
        A.ingresar();
        cout << "\n--- Matriz B ---\n";
        B.ingresar();

        Matriz3D<T> C = A * B;

        cout << "\n=== Resultado de la multiplicación ===\n";
        C.mostrar();
    }
};

#endif
