#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* sig;
    Nodo* ant;

    Nodo(int v) : dato(v), sig(nullptr), ant(nullptr) {}
};

class Lista {
private:
    Nodo* cabeza;
    Nodo* cola;
    std::size_t tam;

public:
    Lista() : cabeza(nullptr), cola(nullptr), tam(0) {}
    ~Lista() { limpiar(); }

    void insertar_cabeza(int v) {
        Nodo* n = new Nodo(v);
        if (!cabeza) {
            cabeza = cola = n;
        } else {
            n->sig = cabeza;
            cabeza->ant = n;
            cabeza = n;
        }
        ++tam;
    }

    void insertar_cola(int v) {
        Nodo* n = new Nodo(v);
        if (!cola) {
            cabeza = cola = n;
        } else {
            cola->sig = n;
            n->ant = cola;
            cola = n;
        }
        ++tam;
    }

    bool eliminar_cabeza() {
        if (!cabeza) return false;
        Nodo* t = cabeza;
        cabeza = cabeza->sig;
        if (cabeza) cabeza->ant = nullptr;
        else cola = nullptr;
        delete t;
        --tam;
        return true;
    }

    bool eliminar_cola() {
        if (!cola) return false;
        Nodo* t = cola;
        cola = cola->ant;
        if (cola) cola->sig = nullptr;
        else cabeza = nullptr;
        delete t;
        --tam;
        return true;
    }

    void imprimir() const {
        Nodo* p = cabeza;
        while (p) {
            std::cout << p->dato;
            if (p->sig) std::cout << " -> ";
            p = p->sig;
        }
        std::cout << '\n';
    }

    std::size_t size() const { return tam; }

    void limpiar() {
        Nodo* p = cabeza;
        while (p) {
            Nodo* nx = p->sig;
            delete p;
            p = nx;
        }
        cabeza = cola = nullptr;
        tam = 0;
    }
};

// ejemplo de uso (puedes borrar o comentar en producción)
int main() {
    Lista L;
    L.insertar_cabeza(10);
    L.insertar_cabeza(20);
    L.insertar_cola(5);
    L.insertar_cola(1);
    std::cout << "Lista: ";
    L.imprimir();               // 20 -> 10 -> 5 -> 1
    L.eliminar_cabeza();
    L.eliminar_cola();
    std::cout << "Después de eliminar: ";
    L.imprimir();               // 10 -> 5
    std::cout << "Tamaño: " << L.size() << '\n';
}