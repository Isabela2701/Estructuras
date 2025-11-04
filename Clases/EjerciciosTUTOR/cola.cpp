#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo*&, int);
bool cola_vacia(Nodo *); 
void suprimirCola(Nodo *&, Nodo *&, int &);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;

    cout << "COLA DE NODOS - DATOS QUEMADOS\n\n";

    // Insertar datos quemados en la cola
    cout << "Insertando datos en la cola:\n";
    insertarCola(frente, fin, 10);
    insertarCola(frente, fin, 25);
    insertarCola(frente, fin, 37);
    insertarCola(frente, fin, 42);
    insertarCola(frente, fin, 56);

    getch();
    system("cls");

    // Eliminar todos los nodos de la cola
    cout << "Eliminando los nodos de la cola:\n";
    while (frente != NULL) {
        suprimirCola(frente, fin, dato);
        if (frente != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << " .\n";
        }
    }

    cout << "\n\nTodos los elementos fueron eliminados.\n";
    
    // Probar con una cola vacía
    cout << "\nProbando con cola vacía:\n";
    if (cola_vacia(frente)) {
        cout << "La cola está vacía (correcto)\n";
    } else {
        cout << "La cola no está vacía\n";
    }

    getch();
    return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if (cola_vacia(frente)){
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;

    cout << "Elemento " << n << " insertado a cola correctamente\n";
}

bool cola_vacia(Nodo *frente){
    return (frente == NULL)?true:false;
}

void suprimirCola(Nodo *&frente, Nodo *&fin, int &n){
    n = frente->dato;
    Nodo *aux = frente;

    if (frente == fin){
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
}