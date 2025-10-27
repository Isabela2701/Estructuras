#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;   
    Nodo* fin;      
    size_t contador; 
};

void inicializarCola(Cola &cola) {
    cola.frente = nullptr;
    cola.fin = nullptr;
    cola.contador = 0;
}

bool empty(const Cola &cola) {
    return (cola.frente == nullptr);
}

void push(Cola &cola, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;

    if (empty(cola)) {
        cola.frente = nuevo;
        cola.fin = nuevo;
    } else {
        cola.fin->siguiente = nuevo;
        cola.fin = nuevo;
    }

    cola.contador++;  
}

void pop(Cola &cola) {
    if (empty(cola)) {
        cout << "La cola está vacía. No se puede eliminar.\n";
        return;
    }

    Nodo* temp = cola.frente;
    cola.frente = cola.frente->siguiente;
    delete temp;
    cola.contador--; 
}

size_t size(const Cola &cola) {
    return cola.contador;
}

void mostrarExtremos(const Cola &cola) {
    if (!empty(cola)) {
        cout << "Frente: " << cola.frente->dato << endl;
        cout << "Final : " << cola.fin->dato << endl;
    } else {
        cout << "Cola vacía\n";
    }
}

int main() {
    Cola miCola;
    inicializarCola(miCola);

    push(miCola, 10);
    push(miCola, 20);
    push(miCola, 30);

    cout << "Número de elementos en la cola: " << size(miCola) << endl;
    mostrarExtremos(miCola);

    pop(miCola);

    cout << "\nDespués de eliminar un elemento:\n";
    cout << "Número de elementos en la cola: " << size(miCola) << endl;
    mostrarExtremos(miCola);
}
