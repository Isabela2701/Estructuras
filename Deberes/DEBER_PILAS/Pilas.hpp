#ifndef PILAS_HPP
#define PILAS_HPP

#include "Nodo.hpp"
class Pilas{
    private:
    Nodo* Cabeza;
    public:
    Pilas();
    Pilas(int);
    ~Pilas();

    void insertarPila(int);
    void eliminarPila();
    void editarCabeza(int);
    void mostrarPila()const;
    int mostrarTamanio()const;
    int consultarCabeza()const;
    bool isEmpty()const;

    int sumarElementospila()const;
    int multiplicarElementospila()const;
    void mostrarParesPila()const;
    void mostrarImparesPila()const;
    int sumarImparesRecursivo() const; 
    void mostrarImparesReversaFuncional()const;
};
#endif