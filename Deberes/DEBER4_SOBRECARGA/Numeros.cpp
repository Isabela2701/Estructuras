#include "Numeros.h"
#include <iostream>
using namespace std;

// Constructor
Numeros::Numeros(double v) {
    valor = v;
}

// Setter
void Numeros::setValor(double v) {
    valor = v;
}

// Getter
double Numeros::getValor() {
    return valor;
}

// Ingresar y sumar tres int
void Numeros::ingresarYSumarInt() {
    int a, b, c;
    cout << "Ingrese tres numeros enteros: ";
    cin >> a >> b >> c;
    cout << "Suma (int): " << a + b + c << endl;
}

// Ingresar y sumar tres float
void Numeros::ingresarYSumarFloat() {
    float a, b, c;
    cout << "Ingrese tres numeros float: ";
    cin >> a >> b >> c;
    cout << "Suma (float): " << a + b + c << endl;
}

// Ingresar y sumar tres double
void Numeros::ingresarYSumarDouble() {
    double a, b, c;
    cout << "Ingrese tres numeros double: ";
    cin >> a >> b >> c;
    cout << "Suma (double): " << a + b + c << endl;
}

// Ingresar y sumar combinación int, float, double
void Numeros::ingresarYSumarMixto() {
    int a;
    float b;
    double c;
    cout << "Ingrese un int, un float y un double: ";
    cin >> a >> b >> c;
    cout << "Suma (mixto): " << a + b + c << endl;
}