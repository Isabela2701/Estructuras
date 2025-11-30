#ifndef LISTA_HPP
#define LISTA_HPP
#include "Nodo.hpp"

class Lista{
    private:
    Nodo* Cola;
    Nodo* Cabeza;

    public:
    Lista();
    Lista(int);
    ~Lista();

    void insertarListaInicio(int);
    void insertarListaFinal(int);
    void insertarListaEn(int, int);
    void eliminarListaInicio();
    void eliminarListaFinal();
    void eliminarListaEn(int);
    void editarCabeza(int);
    void editarCola(int);
    void editarMedios(int, int);
    void mostrarLista()const;
    int buscarPorIndice(int)const;
    int buscarPorDato(int)const;

    int mostrarTamanio()const;
    int consultarCabeza()const;
    int consultarCola()const;
    bool isEmpty()const;
    int getSize();
    Nodo* getNodo(int index) const;

    int sumarElementosLista()const;
    int multiplicarElementosLista()const;
    int sumarParesLista()const;
    int sumarImparesLista()const;
    int multiplicarParesLista() const;
    int multiplicarImparesLista() const;
    void mostrarParesLista() const;
    void mostrarImparesLista() const;
    int sumarImparesRecursivo() const;
    void mostrarImparesReversaFuncional() const;

    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void shellSort();

};

#endif 