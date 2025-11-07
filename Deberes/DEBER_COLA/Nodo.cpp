#include <iostream>
#include "Nodo.hpp"

Nodo::Nodo(int dato){
    Siguiente=nullptr;
    Dato=dato;
}

Nodo::Nodo(int dato,Nodo* siguiente){
    Siguiente=siguiente;
    Dato=dato;
}

Nodo* Nodo::getSiguiente()const{
    return Siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente){
    Siguiente=siguiente;
}

int Nodo::getDato()const{
    return Dato;
}

void Nodo::setDato(int dato){
    Dato=dato;
}