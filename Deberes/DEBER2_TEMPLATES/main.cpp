#include <iostream>
#include "Fraccion.h"
using namespace std;

int main() {
    Fraccion<int> f1, f2;

    cout << "=== Multiplicacion de Fracciones ===" << endl;

    cout << "\nIngrese la primera fraccion (a/b):" << endl;
    f1.ingresar();

    cout << "\nIngrese la segunda fraccion (c/d):" << endl;
    f2.ingresar();

    cout << "\nFraccion 1: ";
    f1.mostrar();

    cout << "\nFraccion 2: ";
    f2.mostrar();

    Fraccion<int> resultado = f1.multiplicar(f2);

    cout << "\n\nResultado de (a/b * c/d): ";
    resultado.mostrar();
    cout << endl;

    return 0;
}
