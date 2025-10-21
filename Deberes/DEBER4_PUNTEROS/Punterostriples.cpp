#include <iostream>
using namespace std;

int main() {
    double a = 10;
    double* ptr;       // puntero simple
    double** ptr2;     // doble puntero
    double*** ptr3;    // triple puntero

    // Asignaciones encadenadas
    ptr = &a;
    ptr2 = &ptr;
    ptr3 = &ptr2;

    cout << "Valor inicial de a: " << a << endl;

    // Cambiar valor mediante el triple puntero
    cout << "Ingrese un nuevo valor para a: ";
    cin >> ***ptr3; // accedemos al valor de a a través del triple puntero

    cout << "\nNuevo valor de a: " << a << endl;
    cout << "Accediendo con *ptr: " << *ptr << endl;
    cout << "Accediendo con **ptr2: " << **ptr2 << endl;
    cout << "Accediendo con ***ptr3: " << ***ptr3 << endl;

    return 0;
}
