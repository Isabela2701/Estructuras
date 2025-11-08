#include "Lista.hpp"
#include <iostream>

Lista::Lista(){
    Cabeza=nullptr;
    Cola=nullptr;
}

Lista::Lista(int dato){
    Cabeza= new Nodo(dato);
    Cola=Cabeza;
}

Lista::~Lista(){
    Nodo* actual= Cabeza;
    while(actual!=nullptr){
        Nodo* siguiente=actual->getSiguiente();
        delete actual;
        actual=siguiente;
    }
    Cabeza=nullptr;
    Cola=nullptr;
}

bool Lista::isEmpty() const {
    return Cabeza == nullptr; 
}

void Lista::insertarListaInicio(int dato){
    Nodo* nuevo_nodo=new Nodo(dato);
    if(isEmpty()){
        Cabeza=nuevo_nodo;
        Cola=nuevo_nodo;
    }
    else{
        nuevo_nodo->setSiguiente(Cabeza);
        Cabeza=nuevo_nodo;
    }
}

void Lista::insertarListaFinal(int dato){
    Nodo* nuevo_nodo=new Nodo(dato);
    if(isEmpty()){
        Cabeza=nuevo_nodo;
        Cola=nuevo_nodo;
    }else{
        Cola->setSiguiente(nuevo_nodo);
        Cola=nuevo_nodo;
    }
}

void Lista::insertarListaEn(int dato, int posicion){
    if(posicion<=1||isEmpty()){
        insertarListaInicio(dato);
        return;
    }
    int tamanio=mostrarTamanio();
    if(posicion>tamanio){
        insertarListaFinal(dato);
        return;
    }
    Nodo* nuevo_nodo=new Nodo(dato);
    Nodo *actual=Cabeza;

    for(int i=1; i<posicion-1; i++){
        actual=actual->getSiguiente();
    }
    nuevo_nodo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevo_nodo);
}

void Lista::eliminarListaInicio(){
    if(isEmpty()){
        std::cout<<"\nLa lista esta vacia"<<std::endl;
        return;
    }
    Nodo* tmp=Cabeza;
    Cabeza=Cabeza->getSiguiente();
    delete tmp;

    if(Cabeza==nullptr){
        Cola==nullptr;
    }
}

void Lista::eliminarListaFinal(){
    if(isEmpty()){
        std::cout<<"\nLa lista esta vacia"<<std::endl;
        return;
    }
    if(Cabeza==Cola){
        delete Cabeza;
        Cabeza=nullptr;
        Cola=nullptr;
        return;
    }
    Nodo* actual= Cabeza;
    while(actual->getSiguiente()!=Cola){
        actual=actual->getSiguiente();
    }
    delete Cola;
    Cola=actual;
    Cola->setSiguiente(nullptr);
}

void Lista::eliminarListaEn(int posicion){
    if(isEmpty()){
        std::cout<<"\nLa lista esta vacia"<<std::endl;
        return;
    }
    if(posicion<=1){
        eliminarListaInicio();
        return;
    }
    if(posicion>=mostrarTamanio()){
        eliminarListaFinal();
        return;
    }

    Nodo* actual=Cabeza;
    for(int i=1; i<posicion-1;++i){
        actual=actual->getSiguiente();
    }
    Nodo* nodo_eliminar =actual->getSiguiente();
    actual->setSiguiente(nodo_eliminar->getSiguiente());
    delete nodo_eliminar;    
}

void Lista::editarCabeza(int nuevoDato){
    if (Cabeza!=nullptr){
        Cabeza->setDato(nuevoDato);
    }
}


void Lista::editarCola(int nuevoDato){
    if (Cola!=nullptr){
        Cola->setDato(nuevoDato);
    }
}


void Lista::editarMedios(int nuevoDato, int posicion){
    if (isEmpty()){
        std::cout<<"\nLa lista esta vacia"<<std::endl;
        return;
    }
    if(posicion>=mostrarTamanio()){
        editarCola(nuevoDato);
        return;
    }

    Nodo* actual=Cabeza;
    for(int i=1; i<posicion;++i){
        actual=actual->getSiguiente();
    }
    if(actual!=nullptr){
        actual->setDato(nuevoDato);
    }
}

int Lista::buscarPorIndice(int indice)const{
    if(isEmpty()||indice<=0||indice>mostrarTamanio()){
        std::cout<<"\nIndice invalido o lista vacia"<<std::endl;
        return-1;
    }
    Nodo* actual=Cabeza;
    for(int i=1;i<indice;++i){
        actual=actual->getSiguiente();
    }
    return actual->getDato();
}

int Lista::buscarPorDato(int dato)const{
    int indice=1;
    Nodo* actual=Cabeza;
    while(actual!=nullptr){
        if(actual->getDato()==dato){
            return indice;
        }
        actual=actual->getSiguiente();
        indice++;
    }
    return -1;
}

int Lista::consultarCabeza()const{
    if(isEmpty()){
        std::cout<<"\nLa lista esta vacia"<<std::endl;
        return 0;
    }
    return Cabeza->getDato();
}

int Lista::consultarCola()const{
    if(isEmpty()){
        std::cout<<"\nLa lista esta vacia"<<std::endl;
        return 0;
    }
    return Cola->getDato();
}

int Lista::mostrarTamanio()const{
    int contador=0;
    Nodo* actual=Cabeza;
    while(actual!=nullptr){
        actual=actual->getSiguiente();
        contador++;
    }
    return contador;
}

void Lista::mostrarLista()const{
    Nodo* actual=Cabeza;
    std::cout<<"Lista: ";
    while (actual!=nullptr){
        std::cout<<actual->getDato();
        actual=actual->getSiguiente();
        if(actual!=nullptr){
            std::cout<<", ";
        }
    }
    std::cout<<std::endl;
}

int Lista::sumarElementosLista() const {
    int resultado = 0;
    Nodo* tmp = Cabeza;
    while(tmp != nullptr){
        resultado += tmp->getDato();
        tmp = tmp->getSiguiente();
    }
    return resultado;
}

int Lista::multiplicarElementosLista() const {
    int resultado = 1;
    Nodo* tmp = Cabeza;
    while(tmp != nullptr){
        resultado *= tmp->getDato();
        tmp = tmp->getSiguiente();
    }
    return resultado;
}

int Lista::sumarParesLista() const {
    int suma = 0;
    Nodo* tmp = Cabeza;
    while(tmp != nullptr){
        int dato = tmp->getDato(); 
        if ((dato % 2) == 0) {
            suma += dato;
        }
        tmp = tmp->getSiguiente();
    }
    return suma;
}

int Lista::sumarImparesLista() const {
    int suma = 0;
    Nodo* tmp = Cabeza;
    while(tmp != nullptr){
        int dato = tmp->getDato();
        if ((dato % 2) != 0) {
            suma += dato;
        }
        tmp = tmp->getSiguiente();
    }
    return suma;
}

int Lista::multiplicarParesLista() const {
    int producto = 1;
    Nodo* tmp = Cabeza;
    bool hay_pares = false;
    while(tmp != nullptr){
        int dato = tmp->getDato();
        if ((dato % 2) == 0) {
            producto *= dato;
            hay_pares = true;
        }
        tmp = tmp->getSiguiente();
    }
    if (!hay_pares && !isEmpty()) {
        return 0; 
    }
    return producto;
}

int Lista::multiplicarImparesLista() const {
    int producto = 1;
    Nodo* tmp = Cabeza;
    bool hay_impares = false;
    while(tmp != nullptr){
        int dato = tmp->getDato();
        if ((dato % 2) != 0) {
            producto *= dato;
            hay_impares = true;
        }
        tmp = tmp->getSiguiente();
    }
    if (!hay_impares && !isEmpty()) {
        return 0;
    }
    return producto;
}

void Lista::mostrarParesLista() const {
    std::cout << "Pares: ";
    Nodo* actual = Cabeza;
    while (actual != nullptr) {
        if ((actual->getDato() % 2) == 0) {
            std::cout << actual->getDato() << " ";
        }
        actual = actual->getSiguiente();
    }
    std::cout << std::endl;
}

void Lista::mostrarImparesLista() const {
    std::cout << "Impares: ";
    Nodo* actual = Cabeza;
    while (actual != nullptr) {
        if ((actual->getDato() % 2) != 0) {
            std::cout << actual->getDato() << " ";
        }
        actual = actual->getSiguiente();
    }
    std::cout << std::endl;
}