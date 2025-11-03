#include "pilas.hpp"
#include <iostream>
#include <stdexcept>

pilas::pilas() {
    Top = nullptr;
}

pilas::pilas(int dato) {
    Top = new nodo(dato);
}

pilas::~pilas() {
    while (Top != nullptr) {
        nodo* tmp = Top;
        Top = Top->getSiguiente();  
        delete tmp;
    }
}

void pilas::push(int dato) {
    nodo* nuevo = new nodo(dato);
    nuevo->setSiguiente(Top);  
    Top = nuevo;               
}

void pilas::pop() {
    if (Top == nullptr) {
        std::cout << "Error, pila vacia" << std::endl;
        return;
    }
    nodo* nodoABorrar = Top;
    Top = Top->getSiguiente();  
    delete nodoABorrar;         
}

bool pilas::isEmpty() const {
    return Top == nullptr;
}

int pilas::peek() const {
    if (Top == nullptr) {
        throw std::runtime_error("Error: peek() llamado en una pila vacía.");
    }
    return Top->getDato();
}

void pilas::display() const {
    nodo* actual = Top;
    while (actual != nullptr) {
        std::cout << actual->getDato() << " ";
        actual = actual->getSiguiente();
    }
    std::cout << std::endl;
}

void pilas::editTop(int nuevoDato) {
    if (Top != nullptr) {
        Top->setDato(nuevoDato);
    }
}