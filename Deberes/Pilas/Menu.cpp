#include "Menu.hpp"
#include <iostream>
#include <limits>

using namespace std;

Menu::Menu(pilas* pilaNueva) {
    pila = pilaNueva;
}

void Menu::mostrarMenu() {
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

void Menu::pushElemento() {
    int dato = obtenerEntero("Ingrese el valor a insertar: ");
    pila->push(dato);
    cout << "Elemento " << dato << " insertado en la pila." << endl;
}

void Menu::popElemento() {
    if (pila->isEmpty()) {
        cout << "Error: No se puede hacer pop, la pila esta vacia." << endl;
        return;
    }
    
    try {
        int valorEliminado = pila->peek(); // Mostramos qué vamos a eliminar
        pila->pop();
        cout << "Elemento " << valorEliminado << " eliminado de la pila." << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Menu::peekElemento() {
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

void Menu::editarTop() {
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

void Menu::imprimirPila() {
    cout << "\nContenido de la pila:" << endl;
    pila->display();
}

int Menu::obtenerEntero(const char* mensaje) {
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