#include "Fraccion.h"
#include <iostream>
using namespace std;

// Constructor por defecto
template <typename T>
Fraccion<T>::Fraccion() {
    numerador = 0;
    denominador = 1;
}

// Constructor con parámetros
template <typename T>
Fraccion<T>::Fraccion(T num, T den) {
    numerador = num;
    setDenominador(den);  // ✅ Usa el setter (ya valida el 0)
}

// Setter del numerador
template <typename T>
void Fraccion<T>::setNumerador(T num) {
    numerador = num;
}

// Setter del denominador (mejorado)
template <typename T>
void Fraccion<T>::setDenominador(T den) {
    if (den == 0) {
        cout << "⚠️ Error: el denominador no puede ser 0. Se asignará 1 por defecto." << endl;
        denominador = 1;
    } else {
        denominador = den;
    }
}

// Getter del numerador
template <typename T>
T Fraccion<T>::getNumerador() {
    return numerador;
}

// Getter del denominador
template <typename T>
T Fraccion<T>::getDenominador() {
    return denominador;
}

// Método para ingresar datos por teclado
template <typename T>
void Fraccion<T>::ingresar() {
    cout << "Ingrese numerador: ";
    cin >> numerador;

    T den;
    do {
        cout << "Ingrese denominador (no puede ser 0): ";
        cin >> den;
        if (den == 0) {
            cout << "❌ Error: el denominador no puede ser cero." << endl;
        }
    } while (den == 0);

    setDenominador(den);  // ✅ Usa el setter validado
}

// Método para mostrar la fracción
template <typename T>
void Fraccion<T>::mostrar() {
    cout << numerador << "/" << denominador;
}

// Método para multiplicar dos fracciones
template <typename T>
Fraccion<T> Fraccion<T>::multiplicar(Fraccion<T>& otra) {
    T nuevoNum = numerador * otra.numerador;
    T nuevoDen = denominador * otra.denominador;
    return Fraccion<T>(nuevoNum, nuevoDen);
}
