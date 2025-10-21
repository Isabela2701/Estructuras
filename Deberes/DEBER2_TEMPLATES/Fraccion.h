#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
using namespace std;

// Clase plantilla (template) para representar una fracción
template <typename T>
class Fraccion {
private:
    T numerador;
    T denominador;

public:
    // Constructores
    Fraccion();             // Constructor por defecto
    Fraccion(T num, T den); // Constructor con parámetros

    // Setters y Getters
    void setNumerador(T num);
    void setDenominador(T den);
    T getNumerador();
    T getDenominador();

    // Métodos
    void ingresar();                            // Permite ingresar datos por teclado
    void mostrar();                             // Muestra la fracción
    Fraccion<T> multiplicar(Fraccion<T>& otra); // Multiplica fracciones
};

// Se incluye la implementación del template
#include "Fraccion.cpp"

#endif
