#include <iostream>
#include "Fraccion.h"
using namespace std;

Fraccion::Fraccion() : numerador(0), denominador(1) {}

Fraccion::Fraccion(int num, int den) {
    setNumerador(num);
    setDenominador(den);
}

void Fraccion::setNumerador(int num) {
    numerador = num;
}

void Fraccion::setDenominador(int den) {
    if (den == 0) {
        cout << "Error: el denominador no puede ser cero. Se asigna 1 por defecto." << endl;
        denominador = 1;
    } else {
        denominador = den;
    }
}

int Fraccion::getNumerador() const {
    return numerador;
}

int Fraccion::getDenominador() const {
    return denominador;
}

Fraccion Fraccion::operator*(const Fraccion& otra) const {
    Fraccion resultado;
    resultado.setNumerador(this->numerador * otra.numerador);
    resultado.setDenominador(this->denominador * otra.denominador);
    return resultado;
}

void Fraccion::mostrar() const {
    cout << numerador << "/" << denominador << endl;
}