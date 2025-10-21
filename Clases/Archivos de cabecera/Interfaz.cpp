#include "Interfaz.h"
#include <iostream>

using namespace std;

template <typename T>
 T sumarNumeros(T num1,T num2){
    return num1 + num2;
 }

template <typename T>

 T restarNumeros(T num1,T num2){
    return num1 - num2;
}

template <typename T>
  T multiplicarNumeros(T num1,T num2){
    return num1 * num2;
}

template <typename T>
 T ingresoNumeros(){
    T numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    return numero;
 }

 template <typename T>
 void mostrarResultado(T resultado){
    cout << "El resultado es: " << resultado << endl;
 }
