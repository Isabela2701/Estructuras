#include <iostream>
using namespace std;

// ------------------------------
// CLASE NodoArbol
// ------------------------------
class NodoArbol {
public:
    int datos;                // valor del nodo
    NodoArbol* nodoIzquierdo; // hijo izquierdo
    NodoArbol* nodoDerecho;   // hijo derecho

    // Constructor: nodo hoja
    NodoArbol(int valor) {
        datos = valor;
        nodoIzquierdo = nullptr;
        nodoDerecho = nullptr;
    }

    // Insertar un valor en el subárbol
    void insertar(int valorInsertar) {
        if (valorInsertar < datos) {
            // Insertar en el subárbol izquierdo
            if (nodoIzquierdo == nullptr)
                nodoIzquierdo = new NodoArbol(valorInsertar);
            else
                nodoIzquierdo->insertar(valorInsertar);
        }
        else if (valorInsertar > datos) {
            // Insertar en el subárbol derecho
            if (nodoDerecho == nullptr)
                nodoDerecho = new NodoArbol(valorInsertar);
            else
                nodoDerecho->insertar(valorInsertar);
        }
        // Si es igual, no lo insertamos (ABB sin repetidos)
    }
};


// ------------------------------
// CLASE Arbol
// ------------------------------
class Arbol {
public:
    NodoArbol* raiz;

    Arbol() {
        raiz = nullptr;
    }

    // Insertar nodo en el ABB
    void insertarNodo(int valorInsertar) {
        if (raiz == nullptr)
            raiz = new NodoArbol(valorInsertar);
        else
            raiz->insertar(valorInsertar);
    }

    // ------------------------------
    // RECORRIDO PREORDEN
    // ------------------------------
    void recorridoPreorden() {
        ayudantePreorden(raiz);
        cout << endl;
    }

    void ayudantePreorden(NodoArbol* nodo) {
        if (nodo == nullptr) return;

        cout << nodo->datos << " ";
        ayudantePreorden(nodo->nodoIzquierdo);
        ayudantePreorden(nodo->nodoDerecho);
    }

    // ------------------------------
    // RECORRIDO INORDEN
    // ------------------------------
    void recorridoInorden() {
        ayudanteInorden(raiz);
        cout << endl;
    }

    void ayudanteInorden(NodoArbol* nodo) {
        if (nodo == nullptr) return;

        ayudanteInorden(nodo->nodoIzquierdo);
        cout << nodo->datos << " ";
        ayudanteInorden(nodo->nodoDerecho);
    }

    // ------------------------------
    // RECORRIDO POSTORDEN
    // ------------------------------
    void recorridoPostorden() {
        ayudantePostorden(raiz);
        cout << endl;
    }

    void ayudantePostorden(NodoArbol* nodo) {
        if (nodo == nullptr) return;

        ayudantePostorden(nodo->nodoIzquierdo);
        ayudantePostorden(nodo->nodoDerecho);
        cout << nodo->datos << " ";
    }
};


// ------------------------------
// FUNCIÓN PRINCIPAL
// ------------------------------
int main() {
    Arbol arbol;
    int valor;

    cout << "Insertar los valores al arbol (10 valores):\n";

    for (int i = 0; i < 10; i++) {
        cin >> valor;
        arbol.insertarNodo(valor);
    }

    cout << "\nRecorrido PREORDEN:\n";
    arbol.recorridoPreorden();

    cout << "\nRecorrido INORDEN:\n";
    arbol.recorridoInorden();

    cout << "\nRecorrido POSTORDEN:\n";
    arbol.recorridoPostorden();

    return 0;
}
