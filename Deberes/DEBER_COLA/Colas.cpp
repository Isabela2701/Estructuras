#include <iostream>
#include "Colas.hpp"

Colas::Colas(){
    Cabeza=nullptr;
    Cola=nullptr;
}

Colas::Colas(int dato){
    Cabeza=new Nodo(dato);
    Cola=Cabeza;
}

Colas::~Colas(){

    while(Cabeza!=nullptr){
        Nodo* tmp=Cabeza;
        Cabeza=Cabeza->getSiguiente();
        delete tmp;
    }
    Cola=nullptr;
}

void Colas::insertarColas(int dato){
    Nodo* nuevo_nodo =new Nodo(dato);
    if(isEmpty()){
        Cabeza=nuevo_nodo;
        Cola=nuevo_nodo;
    }
    else{
        Cola->setSiguiente(nuevo_nodo);
        Cola=nuevo_nodo;    
    }
}

void Colas::eliminarColas(){
    if(Cabeza==nullptr){
        std::cout<<"\nLa cola esta vacia"<<std::endl;
        return;
    }
    Nodo* tmp=Cabeza;
    Cabeza=Cabeza->getSiguiente();
    delete tmp;

    if(Cabeza==nullptr){
        Cola=nullptr;
    }
}

void Colas::editarCola(int nuevoDato){
    if (Cola != nullptr) {
        Cola->setDato(nuevoDato);
    }
}

void Colas::mostrarColas()const{
    Nodo* actual=Cabeza;
    while(actual!=nullptr){
        std::cout<<actual->getDato()<<" ";
        actual=actual->getSiguiente();
    }
}

bool Colas::isEmpty()const{
    if(Cabeza==nullptr)
    return true;
    return false;

}

int Colas::consultarCabeza()const{
    if(Cabeza==nullptr){
        std::cout<<"\nCola vacia"<<std::endl;
        return 0;
    }
    return Cabeza->getDato();
}


int Colas::consultarCola()const{
    if(Cola==nullptr){
        std::cout<<"\nCola vacia"<<std::endl;
        return 0;
    }
    return Cola->getDato();
}

int Colas::mostrarTamanio()const{
    int contador=0;
    Nodo* actual=Cabeza;
    while(actual!=nullptr){
        actual=actual->getSiguiente();
        contador++;
    }
    return contador;
}

int Colas::sumarElementosCola()const{
    int resultado=0;
    Nodo* tmp=Cabeza;
    while(tmp!=nullptr){
        int vtmp=tmp->getDato();
        resultado=vtmp+resultado;
        tmp=tmp->getSiguiente();
    }
    return resultado;
}

int Colas::multiplicarElementosCola()const{
    int resultado=1;
    Nodo* tmp=Cabeza;
    while(tmp!=nullptr){
        int vtmp=tmp->getDato();
        resultado=vtmp*resultado;
        tmp=tmp->getSiguiente();
    }
    return resultado;

}


int Colas::sumarParesCola()const{
    int suma = 0;
    const Nodo* tmp = Cabeza;
    
    while(tmp != nullptr){
        int dato = tmp->getDato(); 
        
        if ((dato % 2) == 0) {
            suma =dato+suma;
        }
        tmp = tmp->getSiguiente();
    }
    return suma;
}

int Colas::sumarImparesCola()const{
    int suma = 0;
    const Nodo* tmp = Cabeza;
    
    while(tmp != nullptr){
        int dato = tmp->getDato();
        
        if ((dato % 2) != 0) {
            suma = dato+suma;
        }
        tmp = tmp->getSiguiente();
    }
    return suma;
}

int Colas::multiplicarParesCola()const{
    
    int producto = 1;
    const Nodo* tmp = Cabeza;
    bool pares_encontrados = false; 
    while(tmp != nullptr){
        int dato = tmp->getDato();
        
        if ((dato % 2) == 0) {
            producto= dato*producto;
            pares_encontrados = true;
        }
        tmp = tmp->getSiguiente();
    }
    return producto;
}

int Colas::multiplicarImparesCola()const{
    
    int producto = 1;
    const Nodo* tmp = Cabeza;
    bool pares_encontrados = false; 
    while(tmp != nullptr){
        int dato = tmp->getDato();
        
        if ((dato % 2)!= 0) {
            producto= dato*producto;
            pares_encontrados = true;
        }
        tmp = tmp->getSiguiente();
    }
    return producto;
}

void Colas::mostrarParesCola()const {
    
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
        std::cout << "La cola esta vacia.";
    }
    std::cout << std::endl;
}

void Colas::mostrarImparesCola()const {
    
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
        std::cout << "La cola esta vacia.";
    }
    std::cout << std::endl;
}