#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

// ==================== CLASE NODO ====================
class nodo {
private:
    nodo* Siguiente;
    nodo* Anterior;
    int Dato;

public:
    nodo(int dato) {
        Siguiente = nullptr;
        Anterior = nullptr;
        Dato = dato;
    }

    nodo(nodo* siguiente, int dato) {
        Dato = dato;
        Siguiente = siguiente;
        Anterior = nullptr;
    }

    nodo(nodo* siguiente, nodo* anterior, int dato) {
        Dato = dato;
        Siguiente = siguiente;
        Anterior = anterior;
    }

    nodo* getSiguiente() const { return Siguiente; }
    nodo* getAnterior() const { return Anterior; }
    int getDato() { return Dato; }
    void setSiguiente(nodo* siguiente) { Siguiente = siguiente; }
    void setAnterior(nodo* anterior) { Anterior = anterior; }
    void setDato(int dato) { Dato = dato; }
};

// ==================== CLASE PILAS ====================
class pilas {
private:
    nodo* Top;

public:
    pilas() {
        Top = nullptr;
    }

    pilas(int dato) {
        Top = new nodo(dato);
    }

    ~pilas() {
        while (Top != nullptr) {
            nodo* tmp = Top;
            Top = Top->getSiguiente();
            delete tmp;
        }
    }

    void push(int dato) {
        if (Top == nullptr) {
            Top = new nodo(dato);
        } else {
            nodo* nuevo = new nodo(dato);
            nuevo->setSiguiente(Top);
            Top->setAnterior(nuevo);
            Top = nuevo;
        }
    }

    void pop() {
        if (Top == nullptr) {
            cout << "Error, pila vacia" << endl;
            return;
        }
        nodo* nodoABorrar = Top;
        Top = Top->getSiguiente();
        if (Top != nullptr) {
            Top->setAnterior(nullptr);
        }
        delete nodoABorrar;
    }

    bool isEmpty() const {
        return Top == nullptr;
    }

    int peek() const {
        if (Top == nullptr) {
            throw runtime_error("Error: peek() llamado en una pila vacía.");
        }
        return Top->getDato();
    }

    void display() const {
        if (Top == nullptr) {
            cout << "Pila vacia" << endl;
            return;
        }
        nodo* actual = Top;
        cout << "Top -> ";
        while (actual != nullptr) {
            cout << actual->getDato();
            if (actual->getSiguiente() != nullptr) {
                cout << " -> ";
            }
            actual = actual->getSiguiente();
        }
        cout << " -> NULL" << endl;
    }

    void editTop(int nuevoDato) {
        if (Top != nullptr) {
            Top->setDato(nuevoDato);
        }
    }
};

// ==================== CLASE MENU ====================
class Menu {
private:
    pilas* pila;

    int obtenerEntero(const char* mensaje) {
        int valor;
        while (true) {
            cout << mensaje;
            cin >> valor;
            if (cin.fail()) {
                cout << "Error: Por favor ingrese un numero entero valido." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        return valor;
    }

public:
    Menu(pilas* pilaNueva) {
        pila = pilaNueva;
    }

    void pushElemento() {
        int dato = obtenerEntero("Ingrese el valor a insertar: ");
        pila->push(dato);
        cout << "Elemento " << dato << " insertado en la pila." << endl;
    }

    void popElemento() {
        if (pila->isEmpty()) {
            cout << "Error: No se puede hacer pop, la pila esta vacia." << endl;
            return;
        }
        try {
            int valorEliminado = pila->peek();
            pila->pop();
            cout << "Elemento " << valorEliminado << " eliminado de la pila." << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    void peekElemento() {
        if (pila->isEmpty()) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        try {
            int top = pila->peek();
            cout << "Elemento en el top: " << top << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    void editarTop() {
        if (pila->isEmpty()) {
            cout << "Error: No se puede editar, la pila esta vacia." << endl;
            return;
        }
        try {
            int viejoValor = pila->peek();
            int nuevoValor = obtenerEntero("Ingrese el nuevo valor: ");
            pila->editTop(nuevoValor);
            cout << "Elemento top cambiado de " << viejoValor << " a " << nuevoValor << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    void imprimirPila() {
        cout << "\nContenido de la pila:" << endl;
        pila->display();
    }

    void mostrarMenu() {
        int opcion;
        do {
            cout << "\n=== MENU DE PILA ===" << endl;
            cout << "1. Push (Insertar elemento)" << endl;
            cout << "2. Pop (Eliminar elemento)" << endl;
            cout << "3. Peek (Ver elemento top)" << endl;
            cout << "4. Editar elemento top" << endl;
            cout << "5. Imprimir pila" << endl;
            cout << "6. Verificar si esta vacia" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            
            cin >> opcion;
            
            switch(opcion) {
                case 1:
                    pushElemento();
                    break;
                case 2:
                    popElemento();
                    break;
                case 3:
                    peekElemento();
                    break;
                case 4:
                    editarTop();
                    break;
                case 5:
                    imprimirPila();
                    break;
                case 6:
                    if (pila->isEmpty()) {
                        cout << "La pila esta vacia." << endl;
                    } else {
                        cout << "La pila NO esta vacia." << endl;
                    }
                    break;
                case 0:
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opcion no valida. Intente de nuevo." << endl;
            }
            
            if (opcion != 0) {
                cout << "\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
            }
            
        } while (opcion != 0);
    }
};

// ==================== MAIN ====================
int main() {
    pilas* miPila = new pilas();
    Menu menu(miPila);
    menu.mostrarMenu();
    delete miPila;
    return 0;
}