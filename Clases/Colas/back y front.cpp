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

    if (cola.frente == nullptr) { 
        cola.fin = nullptr;
    }
}

int front(const Cola &cola) {
    if (empty(cola)) {
        cout << "Cola vacía. No hay elemento al frente.\n";
        return -1; 
    }
    return cola.frente->dato;
}

int back(const Cola &cola) {
    if (empty(cola)) {
        cout << "Cola vacía. No hay elemento al final.\n";
        return -1; 
    }
    return cola.fin->dato;
}

void mostrarCola(const Cola &cola) {
    if (empty(cola)) {
        cout << "Cola vacía.\n";
        return;
    }

    Nodo* aux = cola.frente;
    cout << "Cola: ";
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

int main() {
    Cola miCola;
    inicializarCola(miCola);

    push(miCola, 5);
    push(miCola, 10);
    push(miCola, 15);

    mostrarCola(miCola);

    cout << "Elemento en el frente: " << front(miCola) << endl;
    cout << "Elemento en el final : " << back(miCola) << endl;

    cout << "\nEliminando un elemento...\n";
    pop(miCola);

    mostrarCola(miCola);
    cout << "Nuevo frente: " << front(miCola) << endl;
    cout << "Nuevo final : " << back(miCola) << endl;
}
