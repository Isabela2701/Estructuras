#ifndef NODO_HPP
#define NODO_HPP

class Nodo{
    private:
    Nodo* Siguiente;
    int Dato;

    public:
    Nodo(int);
    Nodo(int, Nodo*);

    int getDato()const;
    void setDato(int);
    Nodo* getSiguiente()const;
    void setSiguiente(Nodo*);
};
#endif