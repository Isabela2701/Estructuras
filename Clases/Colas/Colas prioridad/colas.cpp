#include <iostream>
#include <stdexcept>

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo* padre;

    Nodo(int v) : valor(v), izq(nullptr), der(nullptr), padre(nullptr) {}
};

class ColaPrioridad {
private:
    Nodo* raiz = nullptr;
    int tam = 0;

    // Encuentra el nodo donde insertar el siguiente elemento (por posición completa)
    Nodo* encontrarPosicion(int index) {
        std::string camino = "";
        while (index > 1) {
            camino = ((index % 2 == 0) ? "L" : "R") + camino;
            index /= 2;
        }
        Nodo* actual = raiz;
        for (char dir : camino) {
            actual = (dir == 'L') ? actual->izq : actual->der;
        }
        return actual;
    }

    void subir(Nodo* nodo) {
        while (nodo->padre && nodo->valor < nodo->padre->valor) {
            std::swap(nodo->valor, nodo->padre->valor);
            nodo = nodo->padre;
        }
    }

    void bajar(Nodo* nodo) {
        while (true) {
            Nodo* menor = nodo;
            if (nodo->izq && nodo->izq->valor < menor->valor) menor = nodo->izq;
            if (nodo->der && nodo->der->valor < menor->valor) menor = nodo->der;
            if (menor == nodo) break;
            std::swap(nodo->valor, menor->valor);
            nodo = menor;
        }
    }

public:
    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        tam++;
        if (!raiz) {
            raiz = nuevo;
            return;
        }
        Nodo* padre = encontrarPosicion(tam / 2);
        nuevo->padre = padre;
        if (!padre->izq) padre->izq = nuevo;
        else padre->der = nuevo;
        subir(nuevo);
    }

    int extraerMin() {
        if (!raiz) throw std::underflow_error("Cola vacía");
        int min = raiz->valor;

        if (tam == 1) {
            delete raiz;
            raiz = nullptr;
            tam = 0;
            return min;
        }

        Nodo* ultimo = encontrarPosicion(tam);
        raiz->valor = ultimo->valor;

        if (ultimo->padre->der == ultimo) ultimo->padre->der = nullptr;
        else ultimo->padre->izq = nullptr;
        delete ultimo;

        tam--;
        bajar(raiz);
        return min;
    }

    void mostrar(Nodo* nodo, int nivel = 0) const {
        if (!nodo) return;
        mostrar(nodo->der, nivel + 1);
        std::cout << std::string(nivel * 4, ' ') << nodo->valor << "\n";
        mostrar(nodo->izq, nivel + 1);
    }

    void mostrarArbol() const {
        mostrar(raiz);
    }
};

int main() {
    ColaPrioridad cp;
    cp.insertar(30);
    cp.insertar(16);
    cp.insertar(45);
    cp.insertar(20);

    std::cout << "Árbol actual:\n";
    cp.mostrarArbol();

    std::cout << "\nElemento con menor prioridad: " << cp.extraerMin() << "\n";
    std::cout << "Árbol después de extracción:\n";
    cp.mostrarArbol();

    return 0;
}