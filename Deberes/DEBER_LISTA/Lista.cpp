#include "Lista.hpp"
#include <iostream>
#include <functional>

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

int Lista::sumarImparesRecursivo() const {
    
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

void Lista::mostrarImparesReversaFuncional() const {
   
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

    std::cout << "Impares en Reversa: ";
    mostrar_reverso(Cabeza);
    std::cout << std::endl;
}

void Lista::insertionSort() {
    if (isEmpty() || Cabeza->getSiguiente() == nullptr) {
        return; // Ya está ordenada
    }

    Nodo* listaOrdenada = nullptr;  // Nueva lista ordenada
    Nodo* actual = Cabeza;

    while (actual != nullptr) {
        Nodo* siguiente = actual->getSiguiente();

        // Caso 1: insertar al inicio de la lista ordenada
        if (listaOrdenada == nullptr || actual->getDato() < listaOrdenada->getDato()) {
            actual->setSiguiente(listaOrdenada);
            listaOrdenada = actual;
        }
        else {
            // Buscar posición correcta
            Nodo* temp = listaOrdenada;
            while (temp->getSiguiente() != nullptr &&
                   temp->getSiguiente()->getDato() < actual->getDato()) {
                temp = temp->getSiguiente();
            }

            // Insertar el nodo
            actual->setSiguiente(temp->getSiguiente());
            temp->setSiguiente(actual);
        }

        actual = siguiente;
    }

    // Actualizar cabeza y cola reales
    Cabeza = listaOrdenada;

    // Actualizar la cola
    Nodo* tmp = Cabeza;
    while (tmp->getSiguiente() != nullptr) {
        tmp = tmp->getSiguiente();
    }
    Cola = tmp;
}

void Lista::bubbleSort() {
    if (isEmpty() || Cabeza->getSiguiente() == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Nodo* actual = Cabeza;
        Nodo* siguiente = actual->getSiguiente();

        while (siguiente != nullptr) {
            if (actual->getDato() > siguiente->getDato()) {
                int temp = actual->getDato();
                actual->setDato(siguiente->getDato());
                siguiente->setDato(temp);
                swapped = true;
            }
            actual = siguiente;
            siguiente = siguiente->getSiguiente();
        }
    } while (swapped);
}

void Lista::selectionSort() {
    if (isEmpty() || Cabeza->getSiguiente() == nullptr) return;

    for (Nodo* i = Cabeza; i != nullptr; i = i->getSiguiente()) {
        Nodo* minNode = i;

        for (Nodo* j = i->getSiguiente(); j != nullptr; j = j->getSiguiente()) {
            if (j->getDato() < minNode->getDato())
                minNode = j;
        }

        // Intercambio de valores
        int temp = i->getDato();
        i->setDato(minNode->getDato());
        minNode->setDato(temp);
    }
}


int Lista::getSize() {
    int c = 0;
    for (Nodo* t = Cabeza; t != nullptr; t = t->getSiguiente()) c++;
    return c;
}


Nodo* Lista::getNodo(int index) const {
    if (index < 1) return nullptr;
    Nodo* actual = Cabeza;
    int c = 1;
    while (actual != nullptr && c < index) {
        actual = actual->getSiguiente();
        c++;
    }
    return actual;
}


void Lista::shellSort() {
    int n = getSize();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Nodo* nodoI = getNodo(i);
            int temp = nodoI->getDato();

            int j = i;
            while (j >= gap && getNodo(j - gap)->getDato() > temp) {
                getNodo(j)->setDato(getNodo(j - gap)->getDato());
                j -= gap;
            }
            getNodo(j)->setDato(temp);
        }
    }
}

Nodo* dividir(Nodo* cabeza) {
    Nodo* rapido = cabeza->getSiguiente();
    Nodo* lento = cabeza;

    while (rapido != nullptr && rapido->getSiguiente() != nullptr) {
        rapido = rapido->getSiguiente()->getSiguiente();
        lento = lento->getSiguiente();
    }

    Nodo* mitad = lento->getSiguiente();
    lento->setSiguiente(nullptr);
    return mitad;
}


Nodo* merge(Nodo* a, Nodo* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->getDato() <= b->getDato()) {
        a->setSiguiente(merge(a->getSiguiente(), b));
        return a;
    } else {
        b->setSiguiente(merge(a, b->getSiguiente()));
        return b;
    }
}


Nodo* mergeSortRec(Nodo* cabeza) {
    if (!cabeza || !cabeza->getSiguiente())
        return cabeza;

    Nodo* mitad = dividir(cabeza);
    Nodo* izquierda = mergeSortRec(cabeza);
    Nodo* derecha   = mergeSortRec(mitad);

    return merge(izquierda, derecha);
}

