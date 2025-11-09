#include <iostream>
#include <functional>
#include "Pilas.hpp"

Pilas::Pilas(){
    Cabeza=nullptr;
}

Pilas::Pilas(int dato){
    Cabeza=new Nodo(dato);
}

Pilas::~Pilas(){

    while(Cabeza!=nullptr){
        Nodo* tmp=Cabeza;
        Cabeza=Cabeza->getSiguiente();
        delete tmp;
    }
}

void Pilas::insertarPila(int dato){
    Nodo* nuevo_nodo =new Nodo(dato);
    nuevo_nodo->setSiguiente(Cabeza);
    Cabeza=nuevo_nodo;
}

void Pilas::eliminarPila(){
    if(Cabeza==nullptr){
        std::cout<<"\nLa pila esta vacia"<<std::endl;
        return;
    }
    Nodo* tmp=Cabeza;
    Cabeza=Cabeza->getSiguiente();
    delete tmp;
}

void Pilas::mostrarPila()const{
    Nodo* actual=Cabeza;
    while(actual!=nullptr){
        std::cout<<actual->getDato()<<" ";
        actual=actual->getSiguiente();
    }

}

bool Pilas::isEmpty()const{
    if(Cabeza==nullptr)
    return true;
    return false;

}

int Pilas::consultarCabeza()const{
    if(Cabeza==nullptr){
        std::cout<<"\nPila vacia"<<std::endl;
        return 0;
    }
    return Cabeza->getDato();
}

int Pilas::mostrarTamanio()const{
    int contador=0;
    Nodo* actual=Cabeza;
    while(actual!=nullptr){
        actual=actual->getSiguiente();
        contador++;
    }
    return contador;
}

void Pilas::editarCabeza(int nuevoDato){
     if (Cabeza != nullptr) {
        Cabeza->setDato(nuevoDato);
    }

}

int Pilas::sumarElementospila()const{
    int resultado=0;
    Nodo* tmp=Cabeza;
    while(tmp!=nullptr){
        int vtmp=tmp->getDato();
        resultado=vtmp+resultado;
        tmp=tmp->getSiguiente();
    }
    return resultado;
}

int Pilas::multiplicarElementospila()const{
    int resultado=1;
    Nodo* tmp=Cabeza;
    while(tmp!=nullptr){
        int vtmp=tmp->getDato();
        resultado=vtmp*resultado;
        tmp=tmp->getSiguiente();
    }
    return resultado;

}

void Pilas::mostrarParesPila()const {
    
    Nodo* actual = Cabeza;
    bool hay_pares = false;

    while (actual != nullptr) {
        int dato = actual->getDato();
        
        if ((dato % 2) == 0) {
            std::cout << dato << " ";
            hay_pares = true;
        }
        
        actual = actual->getSiguiente();
    }
        if (!hay_pares && Cabeza != nullptr) {
        std::cout << "No hay numeros pares.";
    } else if (Cabeza == nullptr) {
        std::cout << "La pila esta vacia.";
    }
    
    std::cout << std::endl;
}

void Pilas::mostrarImparesPila()const {
    
    Nodo* actual = Cabeza;
    bool hay_pares = false;

    while (actual != nullptr) {
        int dato = actual->getDato();
        
        if ((dato % 2)!= 0) {
            std::cout << dato << " ";
            hay_pares = true;
        }
        
        actual = actual->getSiguiente();
    }
        if (!hay_pares && Cabeza != nullptr) {
        std::cout << "No hay numeros impares.";
    } else if (Cabeza == nullptr) {
        std::cout << "La pila esta vacia.";
    }
    
    std::cout << std::endl;
}

int Pilas::sumarImparesRecursivo() const {
    
    std::function<int(const Nodo*)> sumar_impares = [&](const Nodo* actual) -> int {
        
        if (actual == nullptr) {
            return 0;
        }

        int dato = actual->getDato();
        int suma_actual = 0;

        if ((dato % 2) != 0) {
            suma_actual = dato;
        }
        return suma_actual + sumar_impares(actual->getSiguiente());
    };
    return sumar_impares(Cabeza);
}



void Pilas::mostrarImparesReversaFuncional() const {

    std::function<void(const Nodo*)> mostrar_reverso = [&](const Nodo* actual) -> void {
        
        if (actual == nullptr) {
            return;
        }
        mostrar_reverso(actual->getSiguiente());
        int dato = actual->getDato();
        if ((dato % 2) != 0) { 
            std::cout << dato << " ";
        }
    };

    std::cout << "Impares en Reversa (Pila): ";
    mostrar_reverso(Cabeza);
    std::cout << std::endl;
}