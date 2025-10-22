#include <iostream>
#include "Fraccion.h"
using namespace std;

int main() {
    Fraccion f1, f2;

    int num1, den1, num2, den2;

    cout << "Ingrese numerador de la primera fracción: ";
    cin >> num1;
    cout << "Ingrese denominador de la primera fracción: ";
    cin >> den1;

    cout << "Ingrese numerador de la segunda fracción: ";
    cin >> num2;
    cout << "Ingrese denominador de la segunda fracción: ";
    cin >> den2;

    f1.setNumerador(num1);
    f1.setDenominador(den1);

    f2.setNumerador(num2);
    f2.setDenominador(den2);

    Fraccion resultado = f1 * f2;

    cout << "Resultado de la multiplicación: ";
    resultado.mostrar();

    return 0;
}