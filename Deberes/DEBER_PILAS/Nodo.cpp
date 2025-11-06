#include "./Nodo.hpp"
#include <iostream>

Nodo::Nodo(int dato){
    Siguiente=nullptr;
    Dato=dato;
}

Nodo::Nodo(Nodo* siguiente, int dato){
    Siguiente=siguiente;
    Dato=dato;
}

Nodo* Nodo::getSiguiente()const{
    return Siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente){
    Siguiente=siguiente;
}

int Nodo::getDato(){
    return Dato;
}

void Nodo::setDato(int dato){
    Dato=dato;
}