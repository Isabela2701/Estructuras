#include <iostream>
using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    // Constructor por defecto
    Fraccion() : numerador(0), denominador(1) {}

    // Constructor parametrizado
    Fraccion(int num, int den) {
        setNumerador(num);
        setDenominador(den);
    }

    // Setters
    void setNumerador(int num) {
        numerador = num;
    }

    void setDenominador(int den) {
        if (den == 0) {
            cout << "Error: el denominador no puede ser cero. Se asigna 1 por defecto." << endl;
            denominador = 1;
        } else {
            denominador = den;
        }
    }

    // Getters
    int getNumerador() const {
        return numerador;
    }

    int getDenominador() const {
        return denominador;
    }

    // Sobrecarga del operador *
    Fraccion operator*(const Fraccion& otra) const {
        Fraccion resultado;
        resultado.setNumerador(this->numerador * otra.numerador);
        resultado.setDenominador(this->denominador * otra.denominador);
        return resultado;
    }

    // Mostrar fracción
    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }
};