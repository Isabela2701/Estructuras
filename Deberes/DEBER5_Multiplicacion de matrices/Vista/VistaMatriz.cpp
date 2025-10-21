#include "../Controlador/ControladorMatriz.h"
#include <iostream>
using namespace std;

void ejecutarMultiplicacion() {
    try {
        Matriz<double> A, B, C;
        ControladorMatriz<double> controlador;

        int f1, c1, f2, c2;
        cout << "Filas y columnas de la matriz A: ";
        cin >> f1 >> c1;
        cout << "Filas y columnas de la matriz B: ";
        cin >> f2 >> c2;

        A.setFilas(f1);
        A.setColumnas(c1);
        B.setFilas(f2);
        B.setColumnas(c2);

        A.segmentar();
        B.segmentar();
        A.encerar();
        B.encerar();

        cout << "\n--- Ingrese valores para A ---\n";
        controlador.llenarMatriz(A);

        cout << "\n--- Ingrese valores para B ---\n";
        controlador.llenarMatriz(B);

        cout << "\nMatriz A:\n";
        A.mostrar();
        cout << "\nMatriz B:\n";
        B.mostrar();

        C = A * B;

        cout << "\nResultado A * B:\n";
        C.mostrar();

        A.liberar();
        B.liberar();
        C.liberar();
    } catch (const char* error) {
        cout << "Error: " << error << endl;
    }
}
