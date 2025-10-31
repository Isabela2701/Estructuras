#include "nodo.hpp"

nodo::nodo(int dato){
    Siguiente=nullptr;
    Anterior=nullptr;
    Dato=dato;
}

nodo::nodo(nodo* siguiente, int dato){
    Dato=dato;
    Siguiente=siguiente;
    Anterior=nullptr;
}

nodo::nodo(nodo* siguiente, nodo* anterior, int dato){
    Dato=dato;
    Siguiente=siguiente;
    Anterior=anterior;
}

nodo* nodo::getAnterior(void)const{return Anterior;}
nodo* nodo::getSiguiente(void)const{return Siguiente;}
int nodo::getDato(){return Dato;}
void nodo::setAnterior(nodo* anterior){Anterior=anterior;}
void nodo::setSiguiente(nodo* siguiente){Siguiente=siguiente;}
void nodo::setDato(int dato){Dato=dato;}