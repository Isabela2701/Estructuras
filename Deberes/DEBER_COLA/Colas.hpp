#ifndef COLAS_HPP
#define COLAS_HPP

#include "Nodo.hpp"
class Colas{
    private:
    Nodo* Cabeza;
    Nodo* Cola;
    public:
    Colas();
    Colas(int);
    ~Colas();

    void insertarColas(int);
    void eliminarColas();
    void editarCola(int);
    void mostrarColas()const;
    int mostrarTamanio()const;
    int consultarCabeza()const;
    int consultarCola()const;
    bool isEmpty()const;

    int sumarElementosCola()const;
    int multiplicarElementosCola()const;
};
#endif